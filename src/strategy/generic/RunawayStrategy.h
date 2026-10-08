/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_RUNAWAYSTRATEGY_H
#define _SHADOW_RUNAWAYSTRATEGY_H

#include "NonCombatStrategy.h"

class ShadowAI;

class RunawayStrategy : public NonCombatStrategy
{
public:
    RunawayStrategy(ShadowAI* botAI) : NonCombatStrategy(botAI) {}

    std::string const getName() override { return "runaway"; }
    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
};

#endif
