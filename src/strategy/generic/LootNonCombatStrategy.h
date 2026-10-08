/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_LOOTNONCOMBATSTRATEGY_H
#define _SHADOW_LOOTNONCOMBATSTRATEGY_H

#include "Strategy.h"

class ShadowAI;

class LootNonCombatStrategy : public Strategy
{
public:
    LootNonCombatStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "loot"; }
};

class GatherStrategy : public Strategy
{
public:
    GatherStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "gather"; }
};

class RevealStrategy : public Strategy
{
public:
    RevealStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "reveal"; }
};

#endif
