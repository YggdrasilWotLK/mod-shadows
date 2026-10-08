/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_THREATVALUES_H
#define _SHADOW_THREATVALUES_H

#include "NamedObjectContext.h"
#include "Value.h"

class ShadowAI;
class Unit;

class ThreatValue : public Uint8CalculatedValue, public Qualified
{
public:
    ThreatValue(ShadowAI* botAI, std::string const name = "threat") : Uint8CalculatedValue(botAI, name) {}

    uint8 Calculate() override;

protected:
    uint8 Calculate(Unit* target);
};

class NeglectThreatResetValue : public ManualSetValue<bool>
{
public:
    NeglectThreatResetValue(ShadowAI* ai, bool defaultValue = false, std::string name = "neglect threat")
        : ManualSetValue<bool>(ai, defaultValue, name)
    {
    }
    virtual bool Get()
    {
        bool ret = value;
        Reset();
        return ret;
    }
};

#endif
