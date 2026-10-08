/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_SHADOWMGR_H
#define _SHADOW_SHADOWMGR_H

#include "Common.h"
#include "ObjectGuid.h"
#include "Player.h"
#include "ShadowAIBase.h"
#include "QueryHolder.h"
#include "QueryResult.h"

#include <memory>
#include <shared_mutex>

class ChatHandler;
class ShadowAI;
class ShadowLoginQueryHolder;
class WorldPacket;

typedef std::map<ObjectGuid, Player*> ShadowMap;
typedef std::map<std::string, std::set<std::string> > ShadowErrorMap;

class ShadowHolder : public ShadowAIBase
{
public:
    ShadowHolder();
    virtual ~ShadowHolder(){};

    void AddShadow(ObjectGuid guid, uint32 masterAccountId);
    bool IsAccountLinked(uint32 accountId, uint32 masterAccountId);
    void HandleShadowLoginCallback(ShadowLoginQueryHolder const& holder);

    void LogoutShadow(ObjectGuid guid);
    void DisableShadow(ObjectGuid guid);
    void RemoveFromShadowsMap(ObjectGuid guid);
    Player* GetShadow(ObjectGuid guid) const;
    Player* GetShadow(ObjectGuid::LowType lowGuid) const;
    ShadowMap::const_iterator GetShadowsBegin() const { return shadows.begin(); }
    ShadowMap::const_iterator GetShadowsEnd() const { return shadows.end(); }

    void UpdateAIInternal([[maybe_unused]] uint32 elapsed, [[maybe_unused]] bool minimal = false) override{};
    void UpdateSessions();
    void HandleBotPackets(WorldSession* session);

    void LogoutAllBots();
    void OnBotLogin(Player* const bot);

    std::vector<std::string> HandleShadowCommand(char const* args, Player* master = nullptr);
    std::string const ProcessBotCommand(std::string const cmd, ObjectGuid guid, ObjectGuid masterguid, bool admin,
                                        uint32 masterAccountId, uint32 masterGuildId);
    uint32 GetAccountId(std::string const name);
    uint32 GetAccountId(ObjectGuid guid);
    std::string const ListBots(Player* master);
    std::string const LookupBots(Player* master);
    uint32 GetShadowsCount() { return shadows.size(); }
    uint32 GetShadowsCountByClass(uint32 cls);

protected:
    virtual void OnBotLoginInternal(Player* const bot) = 0;

    ShadowMap shadows;
    std::unordered_set<ObjectGuid> botLoading;
};

class ShadowMgr : public ShadowHolder
{
public:
    ShadowMgr(Player* const master);
    virtual ~ShadowMgr();

    static bool HandleShadowMgrCommand(ChatHandler* handler, char const* args);
    void HandleMasterIncomingPacket(WorldPacket const& packet);
    void HandleMasterOutgoingPacket(WorldPacket const& packet);
    void HandleCommand(uint32 type, std::string const text);
    void OnPlayerLogin(Player* player);
    void CancelLogout();

    void UpdateAIInternal(uint32 elapsed, bool minimal = false) override;
    void TellError(std::string const botName, std::string const text);

    Player* GetMaster() const { return master; };

    void SaveToDB();

    void HandleSetSecurityKeyCommand(Player* player, const std::string& key);
    void HandleLinkAccountCommand(Player* player, const std::string& accountName, const std::string& key);
    void HandleViewLinkedAccountsCommand(Player* player);
    void HandleUnlinkAccountCommand(Player* player, const std::string& accountName);

protected:
    void OnBotLoginInternal(Player* const bot) override;
    void CheckTellErrors(uint32 elapsed);

private:
    Player* const master;
    // GUID copy: ~ShadowMgr runs while master may be partially destructed,
    // so it must never dereference master to unregister itself.
    ObjectGuid const masterGuid;
    ShadowErrorMap errors;
    time_t lastErrorTell;
};

class ShadowsMgr
{
public:
    ShadowsMgr() {}
    ~ShadowsMgr() {}

    static ShadowsMgr* instance()
    {
        static ShadowsMgr instance;
        return &instance;
    }

    void AddShadowData(Player* player, bool isBotAI);
    void RemoveShadowData(ObjectGuid const& guid, bool is_AI);

    // Shared ownership: the returned ref keeps the AI/Mgr alive past map
    // erase (logout/destruct racing map-thread ticks). Hold it in a local
    // for the whole use; never store the raw pointer across ticks.
    std::shared_ptr<ShadowAI> GetShadowAI(Player* player);
    std::shared_ptr<ShadowMgr> GetShadowMgr(Player* player);

private:
    std::unordered_map<ObjectGuid, std::shared_ptr<ShadowAIBase>> _shadowsAIMap;
    std::unordered_map<ObjectGuid, std::shared_ptr<ShadowAIBase>> _shadowsMgrMap;
    // Guards both maps. Readers (map worker threads) take shared_lock;
    // writers (login/logout/destruct) take unique_lock. Never hold across
    // ObjectAccessor calls or UpdateAI to avoid lock-order inversion.
    mutable std::shared_mutex _mapsMutex;
};

#define sShadowsMgr ShadowsMgr::instance()

#endif
