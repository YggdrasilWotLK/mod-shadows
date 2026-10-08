/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_GROUPSTRATEGY_H
#define _SHADOW_GROUPSTRATEGY_H

#include "NonCombatStrategy.h"

class ShadowAI;

class GroupStrategy : public NonCombatStrategy
{
public:
    GroupStrategy(ShadowAI* botAI) : NonCombatStrategy(botAI) {}

    std::string const getName() override { return "group"; }
    uint32 GetType() const override { return STRATEGY_TYPE_GENERIC; }
    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
};

#endif
