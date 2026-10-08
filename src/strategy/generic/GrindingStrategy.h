/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_GRINDINGSTRATEGY_H
#define _SHADOW_GRINDINGSTRATEGY_H

#include "NonCombatStrategy.h"

class ShadowAI;

class GrindingStrategy : public NonCombatStrategy
{
public:
    GrindingStrategy(ShadowAI* botAI) : NonCombatStrategy(botAI) {}

    std::string const getName() override { return "grind"; }
    uint32 GetType() const override { return STRATEGY_TYPE_DPS; }
    NextAction** getDefaultActions() override;
    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
};

class MoveRandomStrategy : public NonCombatStrategy
{
public:
    MoveRandomStrategy(ShadowAI* botAI) : NonCombatStrategy(botAI) {}
    std::string const getName() override { return "move random"; }
    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
};
#endif
