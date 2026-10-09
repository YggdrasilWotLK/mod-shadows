/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_DUELSTRATEGY_H
#define _SHADOW_DUELSTRATEGY_H

#include "PassTroughStrategy.h"

class ShadowAI;

class DuelStrategy : public PassTroughStrategy
{
public:
    DuelStrategy(ShadowAI* botAI);

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "duel"; }
};

class StartDuelStrategy : public Strategy
{
public:
    StartDuelStrategy(ShadowAI* botAI);

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "start duel"; }
};

#endif
