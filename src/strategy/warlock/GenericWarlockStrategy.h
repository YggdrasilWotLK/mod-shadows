/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_GENERICWARLOCKSTRATEGY_H
#define _SHADOW_GENERICWARLOCKSTRATEGY_H

#include "CombatStrategy.h"

class ShadowAI;

class GenericWarlockStrategy : public CombatStrategy
{
public:
    GenericWarlockStrategy(ShadowAI* botAI);

    std::string const getName() override { return "warlock"; }
    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    NextAction** getDefaultActions() override;
    uint32 GetType() const override { return CombatStrategy::GetType() | STRATEGY_TYPE_RANGED | STRATEGY_TYPE_DPS; }
};

class AoEWarlockStrategy : public CombatStrategy
{
public:
    AoEWarlockStrategy(ShadowAI* botAI) : CombatStrategy(botAI) {}

    std::string const getName() override { return "aoe"; }
    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
};

class WarlockBoostStrategy : public Strategy
{
public:
    WarlockBoostStrategy(ShadowAI* botAI) : Strategy(botAI){};

    std::string const getName() override { return "boost"; }
    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
};

class WarlockPetStrategy : public Strategy
{
public:
    WarlockPetStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    std::string const getName() override { return "pet"; }
    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
};

class WarlockCcStrategy : public Strategy
{
public:
    WarlockCcStrategy(ShadowAI* botAI) : Strategy(botAI){};

    std::string const getName() override { return "cc"; }
    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
};

class WarlockCurseOfAgonyStrategy : public Strategy
{
public:
    WarlockCurseOfAgonyStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    std::string const getName() override { return "curse of agony"; }
    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
};

class WarlockCurseOfTheElementsStrategy : public Strategy
{
public:
    WarlockCurseOfTheElementsStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    std::string const getName() override { return "curse of elements"; }
    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
};

class WarlockCurseOfDoomStrategy : public Strategy
{
public:
    WarlockCurseOfDoomStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    std::string const getName() override { return "curse of doom"; }
    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
};

class WarlockCurseOfExhaustionStrategy : public Strategy
{
public:
    WarlockCurseOfExhaustionStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    std::string const getName() override { return "curse of exhaustion"; }
    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
};

class WarlockCurseOfTonguesStrategy : public Strategy
{
public:
    WarlockCurseOfTonguesStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    std::string const getName() override { return "curse of tongues"; }
    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
};

class WarlockCurseOfWeaknessStrategy : public Strategy
{
public:
    WarlockCurseOfWeaknessStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    std::string const getName() override { return "curse of weakness"; }
    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
};

#endif
