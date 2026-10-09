/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_GENERICSHAMANSTRATEGY_H
#define _SHADOW_GENERICSHAMANSTRATEGY_H

#include "CombatStrategy.h"

class ShadowAI;

class GenericShamanStrategy : public CombatStrategy
{
public:
    GenericShamanStrategy(ShadowAI* botAI);

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
};

class ShamanCureStrategy : public Strategy
{
public:
    ShamanCureStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "cure"; }
};

class ShamanBoostStrategy : public Strategy
{
public:
    ShamanBoostStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "boost"; }
};

class ShamanAoeStrategy : public CombatStrategy
{
public:
    ShamanAoeStrategy(ShadowAI* botAI) : CombatStrategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "aoe"; }
};

#endif
