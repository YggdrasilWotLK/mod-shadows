/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_GENERICPALADINSTRATEGY_H
#define _SHADOW_GENERICPALADINSTRATEGY_H

#include "CombatStrategy.h"

class ShadowAI;

class GenericPaladinStrategy : public CombatStrategy
{
public:
    GenericPaladinStrategy(ShadowAI* botAI);

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "paladin"; }
};

class PaladinCureStrategy : public Strategy
{
public:
    PaladinCureStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "cure"; }
};

class PaladinBoostStrategy : public Strategy
{
public:
    PaladinBoostStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "boost"; }
};

class PaladinCcStrategy : public Strategy
{
public:
    PaladinCcStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "cc"; }
};

class PaladinHealerDpsStrategy : public Strategy
{
public:
    PaladinHealerDpsStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "healer dps"; }
};

#endif
