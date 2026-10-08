/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_RTSCVALUE_H
#define _SHADOW_RTSCVALUE_H

#include "NamedObjectContext.h"
#include "TravelMgr.h"
#include "Value.h"

class ShadowAI;

class SeeSpellLocationValue : public LogCalculatedValue<WorldPosition>
{
public:
    SeeSpellLocationValue(ShadowAI* botAI, std::string const name = "see spell location")
        : LogCalculatedValue(botAI, name){};

    bool EqualToLast(WorldPosition value) override;
    WorldPosition Calculate() override;
};

class RTSCSelectedValue : public ManualSetValue<bool>
{
public:
    RTSCSelectedValue(ShadowAI* botAI, bool defaultvalue = false, std::string const name = "RTSC selected")
        : ManualSetValue(botAI, defaultvalue, name){};
};

class RTSCNextSpellActionValue : public ManualSetValue<std::string>
{
public:
    RTSCNextSpellActionValue(ShadowAI* botAI, std::string const defaultvalue = "",
                             std::string const name = "RTSC next spell action")
        : ManualSetValue(botAI, defaultvalue, name){};
};

class RTSCSavedLocationValue : public ManualSetValue<WorldPosition>, public Qualified
{
public:
    RTSCSavedLocationValue(ShadowAI* botAI, WorldPosition defaultvalue = WorldPosition(),
                           std::string const name = "RTSC saved location")
        : ManualSetValue(botAI, defaultvalue, name){};

    std::string const Save() override;
    bool Load(std::string const text) override;
};

#endif
