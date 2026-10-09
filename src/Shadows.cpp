/*
 * This file is part of the AzerothCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Affero General Public License as published by the
 * Free Software Foundation; either version 3 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU Affero General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "Shadows.h"

#include "Channel.h"
#include "Config.h"
#include "DatabaseEnv.h"
#include "DatabaseLoader.h"
#include "GuildTaskMgr.h"
#include "Metric.h"
#include "PlayerScript.h"
#include "ShadowAIConfig.h"
#include "RandomShadowMgr.h"
#include "ScriptMgr.h"
#include "cs_shadows.h"
#include "cmath"
#include "BattleGroundTactics.h"

class ShadowsDatabaseScript : public DatabaseScript
{
public:
    ShadowsDatabaseScript() : DatabaseScript("ShadowsDatabaseScript") {}

    bool OnDatabasesLoading() override
    {
        DatabaseLoader shadowLoader("server.shadows");
        shadowLoader.SetUpdateFlags(sConfigMgr->GetOption<bool>("Shadows.Updates.EnableDatabases", true)
                                           ? DatabaseLoader::DATABASE_SHADOWS
                                           : 0);
        shadowLoader.AddDatabase(ShadowsDatabase, "Shadows");

        return shadowLoader.Load();
    }

    void OnDatabasesKeepAlive() override { ShadowsDatabase.KeepAlive(); }

    void OnDatabasesClosing() override { ShadowsDatabase.Close(); }

    void OnDatabaseWarnAboutSyncQueries(bool apply) override { ShadowsDatabase.WarnAboutSyncQueries(apply); }

    void OnDatabaseSelectIndexLogout(Player* player, uint32& statementIndex, uint32& statementParam) override
    {
        statementIndex = CHAR_UPD_CHAR_OFFLINE;
        statementParam = player->GetGUID().GetCounter();
    }

    void OnDatabaseGetDBRevision(std::string& revision) override
    {
        if (QueryResult resultShadow =
                ShadowsDatabase.Query("SELECT date FROM version_db_shadows ORDER BY date DESC LIMIT 1"))
        {
            Field* fields = resultShadow->Fetch();
            revision = fields[0].Get<std::string>();
        }

        if (revision.empty())
        {
            revision = "Unknown Shadows Database Revision";
        }
    }
};

class ShadowsPlayerScript : public PlayerScript
{
public:
    ShadowsPlayerScript() : PlayerScript("ShadowsPlayerScript", {
        PLAYERHOOK_ON_LOGIN,
        PLAYERHOOK_ON_AFTER_UPDATE,
        PLAYERHOOK_ON_CHAT,
        PLAYERHOOK_ON_CHAT_WITH_CHANNEL,
        PLAYERHOOK_ON_CHAT_WITH_GROUP,
        PLAYERHOOK_ON_BEFORE_CRITERIA_PROGRESS,
        PLAYERHOOK_ON_BEFORE_ACHI_COMPLETE,
        PLAYERHOOK_CAN_PLAYER_USE_PRIVATE_CHAT,
        PLAYERHOOK_ON_GIVE_EXP,
        PLAYERHOOK_ON_BEFORE_TELEPORT
    }) {}

    void OnPlayerLogin(Player* player) override
    {
        if (!player->GetSession()->IsBot())
        {
            sShadowsMgr->AddShadowData(player, false);
            sRandomShadowMgr->OnPlayerLogin(player);
        }
    }

    bool OnPlayerBeforeTeleport(Player* player, uint32 mapid, float /*x*/, float /*y*/, float /*z*/, float /*orientation*/, uint32 /*options*/, Unit* /*target*/) override
    {
        // Only apply to bots to prevent affecting real players
        if (!player || !player->GetSession()->IsBot())
            return true;

        // If changing maps, proactively clean visibility references to prevent
        // stale pointers in other players' visibility maps during the teleport.
        // This fixes a race condition where:
        // 1. Bot A teleports and its visible objects start getting cleaned up
        // 2. Bot B is simultaneously updating visibility and tries to access objects in Bot A's old visibility map
        // 3. Those objects may already be freed, causing a segmentation fault
        if (player->GetMapId() != mapid && player->IsInWorld())
        {
            player->GetObjectVisibilityContainer().CleanVisibilityReferences();
        }

        return true;  // Allow teleport to continue
    }

    void OnPlayerAfterUpdate(Player* player, uint32 diff) override
    {
        if (!player || !player->IsInWorld() || player->IsDuringRemoveFromWorld() || !player->GetSession() ||
            player->GetSession()->isLogingOut())
            return;

        if (auto botAI = GET_SHADOW_AI(player))
        {
            if (botAI->IsAlive())
                botAI->UpdateAI(diff);
        }

        if (auto shadowMgr = GET_SHADOW_MGR(player))
        {
            if (shadowMgr->IsAlive())
                shadowMgr->UpdateAI(diff);
        }
    }

    bool OnPlayerCanUseChat(Player* player, uint32 type, uint32 /*lang*/, std::string& msg, Player* receiver) override
    {
        if (type == CHAT_MSG_WHISPER)
        {
            if (auto botAI = GET_SHADOW_AI(receiver))
            {
                botAI->HandleCommand(type, msg, player);

                return false;
            }
        }

        return true;
    }

    void OnPlayerChat(Player* player, uint32 type, uint32 /*lang*/, std::string& msg, Group* group) override
    {
        for (GroupReference* itr = group->GetFirstMember(); itr != nullptr; itr = itr->next())
        {
            if (Player* member = itr->GetSource())
            {
                if (auto botAI = GET_SHADOW_AI(member))
                {
                    if (botAI->GetMaster() != player)
                        continue;

                    botAI->HandleCommand(type, msg, player);
                }
            }
        }
    }

    void OnPlayerChat(Player* player, uint32 type, uint32 /*lang*/, std::string& msg) override
    {
        if (type == CHAT_MSG_GUILD)
        {
            if (auto shadowMgr = GET_SHADOW_MGR(player))
            {
                for (ShadowMap::const_iterator it = shadowMgr->GetShadowsBegin();
                     it != shadowMgr->GetShadowsEnd(); ++it)
                {
                    if (Player* const bot = it->second)
                    {
                        if (bot->GetGuildId() == player->GetGuildId())
                        {
                            if (auto guildBotAI = GET_SHADOW_AI(bot))
                                guildBotAI->HandleCommand(type, msg, player);
                        }
                    }
                }
            }
        }
    }

    void OnPlayerChat(Player* player, uint32 type, uint32 /*lang*/, std::string& msg, Channel* channel) override
    {
        if (auto shadowMgr = GET_SHADOW_MGR(player))
        {
            if (channel->GetFlags() & 0x18)
            {
                shadowMgr->HandleCommand(type, msg);
            }
        }

        sRandomShadowMgr->HandleCommand(type, msg, player);
    }

    bool OnPlayerBeforeAchievementComplete(Player* player, AchievementEntry const* achievement) override
    {
        if ((sRandomShadowMgr->IsRandomBot(player) || sRandomShadowMgr->IsAddclassBot(player)) &&
            (achievement->flags & (ACHIEVEMENT_FLAG_REALM_FIRST_REACH | ACHIEVEMENT_FLAG_REALM_FIRST_KILL)))
        {
            return false;
        }

        return true;
    }

    void OnPlayerGiveXP(Player* player, uint32& amount, Unit* /*victim*/, uint8 /*xpSource*/) override
    {
        // early return
        if (sShadowAIConfig->randomBotXPRate == 1.0 || !player)
            return;

        // no XP multiplier, when player is no bot.
        if (!player->GetSession()->IsBot() || !sRandomShadowMgr->IsRandomBot(player))
            return;

        // no XP multiplier, when bot is in a group with a real player.
        if (Group* group = player->GetGroup())
        {
            for (GroupReference* gref = group->GetFirstMember(); gref; gref = gref->next())
            {
                Player* member = gref->GetSource();
                if (!member)
                {
                    continue;
                }

                if (!member->GetSession()->IsBot())
                {
                    return;
                }
            }
        }

        // otherwise apply bot XP multiplier.
        amount = static_cast<uint32>(std::round(static_cast<float>(amount) * sShadowAIConfig->randomBotXPRate));
    }
};

class ShadowsMiscScript : public MiscScript
{
public:
    ShadowsMiscScript() : MiscScript("ShadowsMiscScript", {MISCHOOK_ON_DESTRUCT_PLAYER}) {}

    void OnDestructPlayer(Player* player) override
    {
        // Erase-then-release: the GUID is captured while player is still valid
        // at this hook. Invalidating + erasing first makes the entry
        // undiscoverable to concurrent map readers; the locals keep the
        // objects alive until scope end (no manual delete under shared_ptr).
        ObjectGuid const guid = player->GetGUID();
        if (auto botAI = GET_SHADOW_AI(player))
        {
            botAI->Invalidate();
            sShadowsMgr->RemoveShadowData(guid, true);
        }

        if (auto shadowMgr = GET_SHADOW_MGR(player))
        {
            shadowMgr->Invalidate();
            sShadowsMgr->RemoveShadowData(guid, false);
        }
    }
};

class ShadowsServerScript : public ServerScript
{
public:
    ShadowsServerScript() : ServerScript("ShadowsServerScript", {
        SERVERHOOK_CAN_PACKET_RECEIVE
    }) {}

    void OnPacketReceived(WorldSession* session, WorldPacket const& packet) override
    {
        if (Player* player = session->GetPlayer())
            if (auto shadowMgr = GET_SHADOW_MGR(player))
                shadowMgr->HandleMasterIncomingPacket(packet);
    }
};

class ShadowsWorldScript : public WorldScript
{
public:
    ShadowsWorldScript() : WorldScript("ShadowsWorldScript", {
        WORLDHOOK_ON_BEFORE_WORLD_INITIALIZED
    }) {}

    void OnBeforeWorldInitialized() override
    {
        // Before modifying the following messages, please make sure it does not violate the AGPLv3.0 license
        // especially if you are distributing a repack or hosting a public server
        // e.g. you can replace the URL with your own repository,
        // but it should be publicly accessible and include all modifications you've made
        LOG_INFO("server.loading", "╔══════════════════════════════════════════════════════════╗");
        LOG_INFO("server.loading", "║                                                          ║");
        LOG_INFO("server.loading", "║              AzerothCore Shadows Module               ║");
        LOG_INFO("server.loading", "║                                                          ║");
        LOG_INFO("server.loading", "╟──────────────────────────────────────────────────────────╢");
        LOG_INFO("server.loading", "║     mod-shadows is a community-driven open-source     ║");
        LOG_INFO("server.loading", "║  project based on AzerothCore, licensed under AGPLv3.0   ║");
        LOG_INFO("server.loading", "╟──────────────────────────────────────────────────────────╢");
        LOG_INFO("server.loading", "║      https://github.com/mod-shadows/mod-shadows    ║");
        LOG_INFO("server.loading", "╚══════════════════════════════════════════════════════════╝");

        uint32 oldMSTime = getMSTime();

        LOG_INFO("server.loading", " ");
        LOG_INFO("server.loading", "Load Shadows Config...");

        sShadowAIConfig->Initialize();

        LOG_INFO("server.loading", ">> Loaded shadows config in {} ms", GetMSTimeDiffToNow(oldMSTime));
        LOG_INFO("server.loading", " ");
    }
};

class ShadowsScript : public ShadowScript
{
public:
    ShadowsScript() : ShadowScript("ShadowsScript") {}

    bool OnShadowCheckLFGQueue(lfg::Lfg5Guids const& guidsList) override
    {
        bool nonBotFound = false;
        for (ObjectGuid const& guid : guidsList.guids)
        {
            Player* player = ObjectAccessor::FindPlayer(guid);
            if (guid.IsGroup() || (player && !GET_SHADOW_AI(player)))
            {
                nonBotFound = true;
                break;
            }
        }

        return nonBotFound;
    }

    void OnShadowCheckKillTask(Player* player, Unit* victim) override
    {
        if (player)
            sGuildTaskMgr->CheckKillTask(player, victim);
    }

    void OnShadowCheckPetitionAccount(Player* player, bool& found) override
    {
        if (found && GET_SHADOW_AI(player))
            found = false;
    }

    bool OnShadowCheckUpdatesToSend(Player* player) override
    {
        if (auto botAI = GET_SHADOW_AI(player))
            return botAI->IsRealPlayer();

        return true;
    }

    void OnShadowPacketSent(Player* player, WorldPacket const* packet) override
    {
        if (!player)
            return;

        if (auto botAI = GET_SHADOW_AI(player))
        {
            botAI->HandleBotOutgoingPacket(*packet);
        }
        if (auto shadowMgr = GET_SHADOW_MGR(player))
        {
            shadowMgr->HandleMasterOutgoingPacket(*packet);
        }
    }

    void OnShadowUpdate(uint32 diff) override
    {
        sRandomShadowMgr->UpdateAI(diff);
        sRandomShadowMgr->UpdateSessions();
    }

    void OnShadowUpdateSessions(Player* player) override
    {
        if (player)
            if (auto shadowMgr = GET_SHADOW_MGR(player))
                shadowMgr->UpdateSessions();
    }

    void OnShadowLogout(Player* player) override
    {
        if (auto shadowMgr = GET_SHADOW_MGR(player))
        {
            auto botAI = GET_SHADOW_AI(player);
            if (!botAI || botAI->IsRealPlayer())
            {
                shadowMgr->LogoutAllBots();
            }
        }

        sRandomShadowMgr->OnPlayerLogout(player);
    }

    void OnShadowLogoutBots() override
    {
        LOG_INFO("shadows", "Logging out all bots...");
        sRandomShadowMgr->LogoutAllBots();
    }
};

class ShadowsBGScript : public BGScript
{
public:
    ShadowsBGScript() : BGScript("ShadowsBGScript") {}

    void OnBattlegroundStart(Battleground* bg) override
    {
        BGStrategyData data;

        switch (bg->GetBgTypeID())
        {
            case BATTLEGROUND_WS:
                data.allianceStrategy = urand(0, WS_STRATEGY_MAX - 1);
                data.hordeStrategy = urand(0, WS_STRATEGY_MAX - 1);
                break;
            case BATTLEGROUND_AB:
                data.allianceStrategy = urand(0, AB_STRATEGY_MAX - 1);
                data.hordeStrategy = urand(0, AB_STRATEGY_MAX - 1);
                break;
            case BATTLEGROUND_AV:
                data.allianceStrategy = urand(0, AV_STRATEGY_MAX - 1);
                data.hordeStrategy = urand(0, AV_STRATEGY_MAX - 1);
                break;
            case BATTLEGROUND_EY:
                data.allianceStrategy = urand(0, EY_STRATEGY_MAX - 1);
                data.hordeStrategy = urand(0, EY_STRATEGY_MAX - 1);
                break;
            default:
                break;
        }

        bgStrategies[bg->GetInstanceID()] = data;
    }

    void OnBattlegroundEnd(Battleground* bg, TeamId /*winnerTeam*/) override { bgStrategies.erase(bg->GetInstanceID()); }
};

void AddShadowsScripts()
{
    new ShadowsDatabaseScript();
    new ShadowsPlayerScript();
    new ShadowsMiscScript();
    new ShadowsServerScript();
    new ShadowsWorldScript();
    new ShadowsScript();
    new ShadowsBGScript();

    AddSC_shadows_commandscript();
}
