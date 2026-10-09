/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_GENERICHUNTERNONCOMBATSTRATEGY_H
#define _SHADOW_GENERICHUNTERNONCOMBATSTRATEGY_H

#include "NonCombatStrategy.h"

class ShadowAI;

class GenericHunterNonCombatStrategy : public NonCombatStrategy
{
public:
    GenericHunterNonCombatStrategy(ShadowAI* botAI);

    std::string const getName() override { return "nc"; }
    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
};

class HunterPetStrategy : public Strategy
{
public:
    HunterPetStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    std::string const getName() override { return "pet"; }
    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
};

#endif
