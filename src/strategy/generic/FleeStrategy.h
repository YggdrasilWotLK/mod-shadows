/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_FLEESTRATEGY_H
#define _SHADOW_FLEESTRATEGY_H

#include "Strategy.h"

class ShadowAI;

class FleeStrategy : public Strategy
{
public:
    FleeStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "flee"; };
};

class FleeFromAddsStrategy : public Strategy
{
public:
    FleeFromAddsStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "flee from adds"; };
};

#endif
