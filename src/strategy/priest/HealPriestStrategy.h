/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_HEALPRIESTSTRATEGY_H
#define _SHADOW_HEALPRIESTSTRATEGY_H

#include "GenericPriestStrategy.h"

class ShadowAI;

class HealPriestStrategy : public GenericPriestStrategy
{
public:
    HealPriestStrategy(ShadowAI* botAI);

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    NextAction** getDefaultActions() override;
    std::string const getName() override { return "heal"; }
    uint32 GetType() const override { return STRATEGY_TYPE_HEAL | STRATEGY_TYPE_RANGED; }
};

#endif
