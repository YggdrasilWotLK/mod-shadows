/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_GENERICMAGESTRATEGY_H
#define _SHADOW_GENERICMAGESTRATEGY_H

#include "CombatStrategy.h"
#include "RangedCombatStrategy.h"

class ShadowAI;

class GenericMageStrategy : public RangedCombatStrategy
{
public:
    GenericMageStrategy(ShadowAI* botAI);

    std::string const getName() override { return "mage"; }
    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    uint32 GetType() const override
    {
        return RangedCombatStrategy::GetType() | STRATEGY_TYPE_RANGED | STRATEGY_TYPE_DPS;
    }
};

class MageCureStrategy : public Strategy
{
public:
    MageCureStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "cure"; }
};

class MageBoostStrategy : public Strategy
{
public:
    MageBoostStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "boost"; }
};

class MageCcStrategy : public Strategy
{
public:
    MageCcStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "cc"; }
};

class MageAoeStrategy : public CombatStrategy
{
public:
    MageAoeStrategy(ShadowAI* botAI) : CombatStrategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "aoe"; }
};

#endif
