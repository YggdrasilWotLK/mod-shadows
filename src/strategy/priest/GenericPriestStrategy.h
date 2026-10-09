/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_GENERICPRIESTSTRATEGY_H
#define _SHADOW_GENERICPRIESTSTRATEGY_H

#include "CombatStrategy.h"
#include "RangedCombatStrategy.h"

class ShadowAI;

class GenericPriestStrategy : public RangedCombatStrategy
{
public:
    GenericPriestStrategy(ShadowAI* botAI);

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
};

class PriestCureStrategy : public Strategy
{
public:
    PriestCureStrategy(ShadowAI* botAI);

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "cure"; }
};

class PriestBoostStrategy : public Strategy
{
public:
    PriestBoostStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "boost"; }
};

class PriestCcStrategy : public Strategy
{
public:
    PriestCcStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "cc"; }
};

class PriestHealerDpsStrategy : public Strategy
{
public:
    PriestHealerDpsStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "healer dps"; }
};

#endif
