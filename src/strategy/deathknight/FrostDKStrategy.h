/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_FROSTDKSTRATEGY_H
#define _SHADOW_FROSTDKSTRATEGY_H

#include "GenericDKStrategy.h"

class ShadowAI;

class FrostDKStrategy : public GenericDKStrategy
{
public:
    FrostDKStrategy(ShadowAI* botAI);

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "frost"; }
    NextAction** getDefaultActions() override;
    uint32 GetType() const override { return STRATEGY_TYPE_COMBAT | STRATEGY_TYPE_DPS | STRATEGY_TYPE_MELEE; }
};

class FrostDKAoeStrategy : public CombatStrategy
{
public:
    FrostDKAoeStrategy(ShadowAI* botAI) : CombatStrategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "frost aoe"; }
};

#endif
