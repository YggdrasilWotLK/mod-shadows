/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_GENERICWARRIORNONCOBATSTRATEGY_H
#define _SHADOW_GENERICWARRIORNONCOBATSTRATEGY_H

#include "NonCombatStrategy.h"

class ShadowAI;

class GenericWarriorNonCombatStrategy : public NonCombatStrategy
{
public:
    GenericWarriorNonCombatStrategy(ShadowAI* botAI) : NonCombatStrategy(botAI) {}

    std::string const getName() override { return "nc"; }
    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
};

#endif
