/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_NEARESTNONBOTPLAYERSVALUE_H
#define _SHADOW_NEARESTNONBOTPLAYERSVALUE_H

#include "NearestUnitsValue.h"
#include "ShadowAIConfig.h"

class ShadowAI;

class NearestNonBotPlayersValue : public NearestUnitsValue
{
public:
    NearestNonBotPlayersValue(ShadowAI* botAI, float range = sShadowAIConfig->grindDistance)
        : NearestUnitsValue(botAI, "nearest non bot players", range, true)
    {
    }

protected:
    void FindUnits(std::list<Unit*>& targets) override;
    bool AcceptUnit(Unit* unit) override;
};

#endif
