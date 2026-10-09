/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_BLOODDKSTRATEGY_H
#define _SHADOW_BLOODDKSTRATEGY_H

#include "GenericDKStrategy.h"

class ShadowAI;

class BloodDKStrategy : public GenericDKStrategy
{
public:
    BloodDKStrategy(ShadowAI* botAI);

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "blood"; }
    NextAction** getDefaultActions() override;
    uint32 GetType() const override { return STRATEGY_TYPE_TANK | STRATEGY_TYPE_MELEE; }
};

#endif
