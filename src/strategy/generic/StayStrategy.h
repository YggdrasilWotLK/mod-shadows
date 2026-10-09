/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_STAYSTRATEGY_H
#define _SHADOW_STAYSTRATEGY_H

#include "NonCombatStrategy.h"

class ShadowAI;

class StayStrategy : public Strategy
{
public:
    StayStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    std::string const getName() override { return "stay"; }
    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    NextAction** getDefaultActions() override;
};

class SitStrategy : public NonCombatStrategy
{
public:
    SitStrategy(ShadowAI* botAI) : NonCombatStrategy(botAI) {}

    std::string const getName() override { return "sit"; }
    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
};

#endif
