/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_SHADOWSECURITY_H
#define _SHADOW_SHADOWSECURITY_H

#include <map>

#include "Common.h"
#include "ObjectGuid.h"

class Player;

enum ShadowSecurityLevel : uint32
{
    SHADOW_SECURITY_DENY_ALL = 0,
    SHADOW_SECURITY_TALK = 1,
    SHADOW_SECURITY_INVITE = 2,
    SHADOW_SECURITY_ALLOW_ALL = 3
};

enum DenyReason
{
    SHADOW_DENY_NONE,
    SHADOW_DENY_LOW_LEVEL,
    SHADOW_DENY_GEARSCORE,
    SHADOW_DENY_NOT_YOURS,
    SHADOW_DENY_IS_BOT,
    SHADOW_DENY_OPPOSING,
    SHADOW_DENY_DEAD,
    SHADOW_DENY_FAR,
    SHADOW_DENY_INVITE,
    SHADOW_DENY_FULL_GROUP,
    SHADOW_DENY_NOT_LEADER,
    SHADOW_DENY_IS_LEADER,
    SHADOW_DENY_BG,
    SHADOW_DENY_LFG
};

class ShadowSecurity
{
public:
    ShadowSecurity(Player* const bot);

    ShadowSecurityLevel LevelFor(Player* from, DenyReason* reason = nullptr, bool ignoreGroup = false);
    bool CheckLevelFor(ShadowSecurityLevel level, bool silent, Player* from, bool ignoreGroup = false);

private:
    Player* const bot;
    uint32 account;
    std::map<ObjectGuid, std::map<std::string, time_t> > whispers;
};

#endif
