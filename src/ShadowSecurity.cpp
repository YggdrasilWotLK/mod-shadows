/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#include "ShadowSecurity.h"

#include "LFGMgr.h"
#include "ShadowAIConfig.h"
#include "Shadows.h"

ShadowSecurity::ShadowSecurity(Player* const bot) : bot(bot)
{
    if (bot)
        account = sCharacterCache->GetCharacterAccountIdByGuid(bot->GetGUID());
}

ShadowSecurityLevel ShadowSecurity::LevelFor(Player* from, DenyReason* reason, bool ignoreGroup)
{
    auto botAI = GET_SHADOW_AI(bot);
    if (!botAI)
    {
        return SHADOW_SECURITY_DENY_ALL;
    }
    
    //if (botAI->IsOpposing(from))
    //{
    //    if (reason)
    //        *reason = SHADOW_DENY_OPPOSING;
    //
    //    return SHADOW_SECURITY_DENY_ALL;
    //}

    if (sShadowAIConfig->IsInRandomAccountList(account))
    {
        //if (botAI->IsOpposing(from))
        //{
        //    if (reason)
        //        *reason = SHADOW_DENY_OPPOSING;
        //
        //    return SHADOW_SECURITY_DENY_ALL;
        //}

        // if (sLFGMgr->GetState(bot->GetGUID()) != lfg::LFG_STATE_NONE)
        // {
        //     if (!bot->GetGuildId() || bot->GetGuildId() != from->GetGuildId())
        //     {
        //         if (reason)
        //             *reason = SHADOW_DENY_LFG;

        //         return SHADOW_SECURITY_TALK;
        //     }
        // }

        Group* group = from->GetGroup();
        if (group && group == bot->GetGroup() && !ignoreGroup && botAI->GetMaster() == from)
        {
            return SHADOW_SECURITY_ALLOW_ALL;
        }

        if (group && group == bot->GetGroup() && !ignoreGroup && botAI->GetMaster() != from)
        {
            if (reason)
                *reason = SHADOW_DENY_NOT_YOURS;
            return SHADOW_SECURITY_TALK;
        }

        if (sShadowAIConfig->groupInvitationPermission <= 0)
        {
            if (reason)
                *reason = SHADOW_DENY_NONE;

            return SHADOW_SECURITY_TALK;
        }

        if (sShadowAIConfig->groupInvitationPermission <= 1 && (int32)bot->GetLevel() - (int8)from->GetLevel() > 5)
        {
            if (!bot->GetGuildId() || bot->GetGuildId() != from->GetGuildId())
            {
                if (reason)
                    *reason = SHADOW_DENY_LOW_LEVEL;

                return SHADOW_SECURITY_TALK;
            }
        }

        int32 botGS = (int32)botAI->GetEquipGearScore(bot/*, false, false*/);
        int32 fromGS = (int32)botAI->GetEquipGearScore(from/*, false, false*/);
        if (sShadowAIConfig->gearscorecheck)
        {
            if (botGS && bot->GetLevel() > 15 && botGS > fromGS &&
                static_cast<float>(100 * (botGS - fromGS) / botGS) >=
                    static_cast<float>(12 * sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL) / from->GetLevel()))
            {
                if (reason)
                    *reason = SHADOW_DENY_GEARSCORE;
                return SHADOW_SECURITY_TALK;
            }
        }

        if (bot->InBattlegroundQueue())
        {
            if (!bot->GetGuildId() || bot->GetGuildId() != from->GetGuildId())
            {
                if (reason)
                    *reason = SHADOW_DENY_BG;

                return SHADOW_SECURITY_TALK;
            }
        }

        /*if (bot->isDead())
        {
            if (reason)
                *reason = SHADOW_DENY_DEAD;

            return SHADOW_SECURITY_TALK;
        }*/

        group = bot->GetGroup();
        if (!group)
        {
            /*if (bot->GetMapId() != from->GetMapId() || bot->GetDistance(from) > sShadowAIConfig->whisperDistance)
            {
                if (!bot->GetGuildId() || bot->GetGuildId() != from->GetGuildId())
                {
                    if (reason)
                        *reason = SHADOW_DENY_FAR;

                    return SHADOW_SECURITY_TALK;
                }
            }*/

            if (reason)
                *reason = SHADOW_DENY_INVITE;

            return SHADOW_SECURITY_INVITE;
        }

        if (!ignoreGroup && group->IsFull())
        {
            if (reason)
                *reason = SHADOW_DENY_FULL_GROUP;

            return SHADOW_SECURITY_TALK;
        }

        if (!ignoreGroup && group->GetLeaderGUID() != bot->GetGUID())
        {
            if (reason)
                *reason = SHADOW_DENY_NOT_LEADER;

            return SHADOW_SECURITY_TALK;
        }
        else
        {
            if (reason)
                *reason = SHADOW_DENY_IS_LEADER;

            return SHADOW_SECURITY_INVITE;
        }

        if (reason)
            *reason = SHADOW_DENY_INVITE;
        
        return SHADOW_SECURITY_INVITE;
    }

    if (botAI->GetMaster() == from)
        return SHADOW_SECURITY_ALLOW_ALL;

    if (reason)
        *reason = SHADOW_DENY_NOT_YOURS;

    return SHADOW_SECURITY_INVITE;
}

bool ShadowSecurity::CheckLevelFor(ShadowSecurityLevel level, bool silent, Player* from, bool ignoreGroup)
{
    DenyReason reason = SHADOW_DENY_NONE;
    ShadowSecurityLevel realLevel = LevelFor(from, &reason, ignoreGroup);
    if (realLevel >= level || from == bot)
        return true;

    auto fromBotAI = GET_SHADOW_AI(from);
    if (silent || (fromBotAI && !fromBotAI->IsRealPlayer()))
        return false;

    auto botAI = GET_SHADOW_AI(bot);
    Player* master = botAI->GetMaster();
    //if (master && botAI && botAI->IsOpposing(master) && master->GetSession()->GetSecurity() < SEC_GAMEMASTER)
    //    return false;

    std::ostringstream out;
    switch (realLevel)
    {
        case SHADOW_SECURITY_DENY_ALL:
            out << "I'm kind of busy now";
            break;
        case SHADOW_SECURITY_TALK:
            switch (reason)
            {
                case SHADOW_DENY_NONE:
                    out << "I'll do it later";
                    break;
                case SHADOW_DENY_LOW_LEVEL:
                    out << "You are too low level: |cffff0000" << (uint32)from->GetLevel() << "|cffffffff/|cff00ff00"
                        << (uint32)bot->GetLevel();
                    break;
                case SHADOW_DENY_GEARSCORE:
                {
                    int botGS = (int)botAI->GetEquipGearScore(bot/*, false, false*/);
                    int fromGS = (int)botAI->GetEquipGearScore(from/*, false, false*/);
                    int diff = (100 * (botGS - fromGS) / botGS);
                    int req = 12 * sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL) / from->GetLevel();
                    out << "Your gearscore is too low: |cffff0000" << fromGS << "|cffffffff/|cff00ff00" << botGS
                        << " |cffff0000" << diff << "%|cffffffff/|cff00ff00" << req << "%";
                }
                break;
                case SHADOW_DENY_NOT_YOURS:
                    out << "I have a master already";
                    break;
                case SHADOW_DENY_IS_BOT:
                    out << "You are a bot";
                    break;
                case SHADOW_DENY_OPPOSING:
                    out << "You are the enemy";
                    break;
                case SHADOW_DENY_DEAD:
                    out << "I'm dead. Will do it later";
                    break;
                case SHADOW_DENY_INVITE:
                    out << "Invite me to your group first";
                    break;
                case SHADOW_DENY_FAR:
                {
                    out << "You must be closer to invite me to your group. I am in ";

                    if (AreaTableEntry const* entry = sAreaTableStore.LookupEntry(bot->GetAreaId()))
                    {
                        out << " |cffffffff(|cffff0000" << entry->area_name[0] << "|cffffffff)";
                    }
                }
                break;
                case SHADOW_DENY_FULL_GROUP:
                    out << "I am in a full group. Will do it later";
                    break;
                case SHADOW_DENY_IS_LEADER:
                    out << "I am currently leading a group. I can invite you if you want.";
                    break;
                case SHADOW_DENY_NOT_LEADER:
                    if (botAI->GetGroupMaster())
                    {
                        out << "I am in a group with " << botAI->GetGroupMaster()->GetName()
                            << ". You can ask him for invite.";
                    }
                    else
                    {
                        out << "I am in a group with someone else. You can ask him for invite.";
                    }
                    break;
                case SHADOW_DENY_BG:
                    out << "I am in a queue for BG. Will do it later";
                    break;
                case SHADOW_DENY_LFG:
                    out << "I am in a queue for dungeon. Will do it later";
                    break;
                default:
                    out << "I can't do that";
                    break;
            }
            break;
        case SHADOW_SECURITY_INVITE:
            //out << "Invite me to your group first"; // absolutely useless feedback
            break;
        default:
            out << "I can't do that";
            break;
    }

    std::string const text = out.str();
    ObjectGuid guid = from->GetGUID();
    time_t lastSaid = whispers[guid][text];
    if (!lastSaid || (time(nullptr) - lastSaid) >= sShadowAIConfig->repeatDelay / 1000)
    {
        whispers[guid][text] = time(nullptr);
        bot->Whisper(text, LANG_UNIVERSAL, from);
    }

    return false;
}
