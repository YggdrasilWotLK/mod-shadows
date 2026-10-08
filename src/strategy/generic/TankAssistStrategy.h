/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_TANKASSISTSTRATEGY_H
#define _SHADOW_TANKASSISTSTRATEGY_H

#include "Strategy.h"

class ShadowAI;

class TankAssistStrategy : public Strategy
{
public:
    TankAssistStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    std::string const getName() override { return "tank assist"; }
    uint32 GetType() const override { return STRATEGY_TYPE_TANK; }
    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
};

#endif
