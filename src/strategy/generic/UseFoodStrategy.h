/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_USEFOODSTRATEGY_H
#define _SHADOW_USEFOODSTRATEGY_H

#include "Strategy.h"

class ShadowAI;

class UseFoodStrategy : public Strategy
{
public:
    UseFoodStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "food"; }
};

#endif
