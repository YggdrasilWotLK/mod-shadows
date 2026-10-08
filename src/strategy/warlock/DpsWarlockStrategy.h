/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_DPSWARLOCKSTRATEGY_H
#define _SHADOW_DPSWARLOCKSTRATEGY_H

#include "GenericWarlockStrategy.h"
#include "Strategy.h"

class ShadowAI;

class DpsWarlockStrategy : public GenericWarlockStrategy
{
public:
    DpsWarlockStrategy(ShadowAI* botAI);

    std::string const getName() override { return "dps"; }
    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    NextAction** getDefaultActions() override;
    uint32 GetType() const override { return GenericWarlockStrategy::GetType() | STRATEGY_TYPE_DPS; }
};

class DpsAoeWarlockStrategy : public CombatStrategy
{
public:
    DpsAoeWarlockStrategy(ShadowAI* botAI) : CombatStrategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "aoe"; }
};

class DpsWarlockDebuffStrategy : public CombatStrategy
{
public:
    DpsWarlockDebuffStrategy(ShadowAI* botAI) : CombatStrategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "dps debuff"; }
};

#endif
