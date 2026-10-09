/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_GENERICMAGENONCOMBATSTRATEGY_H
#define _SHADOW_GENERICMAGENONCOMBATSTRATEGY_H

#include "NonCombatStrategy.h"

class ShadowAI;

class GenericMageNonCombatStrategy : public NonCombatStrategy
{
public:
    GenericMageNonCombatStrategy(ShadowAI* botAI);

    std::string const getName() override { return "nc"; }
    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
};

class MageBuffManaStrategy : public Strategy
{
public:
    MageBuffManaStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "bmana"; }
};

class MageBuffDpsStrategy : public Strategy
{
public:
    MageBuffDpsStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "bdps"; }
};

class MageBuffStrategy : public Strategy
{
public:
    MageBuffStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "buff"; }
};

#endif
