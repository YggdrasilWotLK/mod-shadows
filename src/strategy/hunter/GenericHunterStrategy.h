/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_GENERICHUNTERSTRATEGY_H
#define _SHADOW_GENERICHUNTERSTRATEGY_H

#include "CombatStrategy.h"
#include "Strategy.h"

class ShadowAI;

class GenericHunterStrategy : public CombatStrategy
{
public:
    GenericHunterStrategy(ShadowAI* botAI);

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "hunter"; }
    uint32 GetType() const override { return CombatStrategy::GetType() | STRATEGY_TYPE_RANGED | STRATEGY_TYPE_DPS; }
};


class AoEHunterStrategy : public CombatStrategy
{
public:
    AoEHunterStrategy(ShadowAI* botAI);

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "aoe"; }
};

class HunterBoostStrategy : public Strategy
{
public:
    HunterBoostStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    std::string const getName() override { return "boost"; }
    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
};

class HunterCcStrategy : public Strategy
{
public:
    HunterCcStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "cc"; }
};

class HunterTrapWeaveStrategy : public Strategy
{
public:
    HunterTrapWeaveStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "trap weave"; }
};


#endif
