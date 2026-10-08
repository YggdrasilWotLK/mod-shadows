/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_UNHOLYDKSTRATEGY_H
#define _SHADOW_UNHOLYDKSTRATEGY_H

#include "GenericDKStrategy.h"

class ShadowAI;

class UnholyDKStrategy : public GenericDKStrategy
{
public:
    UnholyDKStrategy(ShadowAI* botAI);

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "unholy"; }
    NextAction** getDefaultActions() override;
    uint32 GetType() const override { return STRATEGY_TYPE_COMBAT | STRATEGY_TYPE_DPS | STRATEGY_TYPE_MELEE; }
};

class UnholyDKAoeStrategy : public CombatStrategy
{
public:
    UnholyDKAoeStrategy(ShadowAI* botAI) : CombatStrategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "unholy aoe"; }
};

#endif
