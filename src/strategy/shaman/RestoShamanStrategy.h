/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_RESTOSHAMANSTRATEGY_H
#define _SHADOW_RESTOSHAMANSTRATEGY_H

#include "GenericShamanStrategy.h"
#include "Strategy.h"

class ShadowAI;

class RestoShamanStrategy : public GenericShamanStrategy
{
public:
    RestoShamanStrategy(ShadowAI* botAI);

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "resto"; }
    uint32 GetType() const override { return STRATEGY_TYPE_RANGED | STRATEGY_TYPE_HEAL; }
};

class ShamanHealerDpsStrategy : public Strategy
{
public:
    ShamanHealerDpsStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "healer dps"; }
};

#endif
