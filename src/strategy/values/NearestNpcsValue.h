/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_NEARESTNPCSVALUE_H
#define _SHADOW_NEARESTNPCSVALUE_H

#include "NearestUnitsValue.h"
#include "ShadowAIConfig.h"

class ShadowAI;

class NearestNpcsValue : public NearestUnitsValue
{
public:
    NearestNpcsValue(ShadowAI* botAI, float range = sShadowAIConfig->sightDistance)
        : NearestUnitsValue(botAI, "nearest npcs", range)
    {
    }

protected:
    void FindUnits(std::list<Unit*>& targets) override;
    bool AcceptUnit(Unit* unit) override;
};

class NearestHostileNpcsValue : public NearestUnitsValue
{
public:
    NearestHostileNpcsValue(ShadowAI* botAI, float range = sShadowAIConfig->sightDistance)
        : NearestUnitsValue(botAI, "nearest hostile npcs", range)
    {
    }

protected:
    void FindUnits(std::list<Unit*>& targets) override;
    bool AcceptUnit(Unit* unit) override;
};

class NearestVehiclesValue : public NearestUnitsValue
{
public:
    NearestVehiclesValue(ShadowAI* botAI, float range = sShadowAIConfig->sightDistance)
        : NearestUnitsValue(botAI, "nearest vehicles", range)
    {
    }

protected:
    void FindUnits(std::list<Unit*>& targets) override;
    bool AcceptUnit(Unit* unit) override;
};

class NearestTriggersValue : public NearestUnitsValue
{
public:
    NearestTriggersValue(ShadowAI* botAI, float range = sShadowAIConfig->sightDistance)
        : NearestUnitsValue(botAI, "nearest triggers", range)
    {
    }

protected:
    void FindUnits(std::list<Unit*>& targets) override;
    bool AcceptUnit(Unit* unit) override;
};

class NearestTotemsValue : public NearestUnitsValue
{
public:
    NearestTotemsValue(ShadowAI* botAI, float range = 30.0f)
        : NearestUnitsValue(botAI, "nearest totems", range, true)
    {
    }

protected:
    void FindUnits(std::list<Unit*>& targets) override;
    bool AcceptUnit(Unit* unit) override;
};

#endif
