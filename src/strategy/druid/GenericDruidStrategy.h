/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_GENERICDRUIDSTRATEGY_H
#define _SHADOW_GENERICDRUIDSTRATEGY_H

#include "CombatStrategy.h"

class ShadowAI;

class GenericDruidStrategy : public CombatStrategy
{
protected:
    GenericDruidStrategy(ShadowAI* botAI);

public:
    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
};

class DruidCureStrategy : public Strategy
{
public:
    DruidCureStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "cure"; }
};

class DruidBoostStrategy : public Strategy
{
public:
    DruidBoostStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "boost"; }
};

class DruidCcStrategy : public Strategy
{
public:
    DruidCcStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "cc"; }
};

class DruidHealerDpsStrategy : public Strategy
{
public:
    DruidHealerDpsStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "healer dps"; }
};

#endif
