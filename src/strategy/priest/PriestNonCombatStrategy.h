/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_PRIESTNONCOMBATSTRATEGY_H
#define _SHADOW_PRIESTNONCOMBATSTRATEGY_H

#include "NonCombatStrategy.h"

class ShadowAI;

class PriestNonCombatStrategy : public NonCombatStrategy
{
public:
    PriestNonCombatStrategy(ShadowAI* botAI);

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "nc"; }
};

class PriestBuffStrategy : public NonCombatStrategy
{
public:
    PriestBuffStrategy(ShadowAI* botAI) : NonCombatStrategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "buff"; }
};

class PriestShadowResistanceStrategy : public NonCombatStrategy
{
public:
    PriestShadowResistanceStrategy(ShadowAI* botAI) : NonCombatStrategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "rshadow"; }
};

#endif
