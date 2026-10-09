/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_TRAVELSTRATEGY_H
#define _SHADOW_TRAVELSTRATEGY_H

#include "Strategy.h"

class ShadowAI;

class TravelStrategy : public Strategy
{
public:
    TravelStrategy(ShadowAI* botAI);

    std::string const getName() override { return "travel"; }

    NextAction** getDefaultActions() override;
    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
};

class ExploreStrategy : public Strategy
{
public:
    ExploreStrategy(ShadowAI* botAI) : Strategy(botAI){};

    std::string const getName() override { return "explore"; }
};

class MapStrategy : public Strategy
{
public:
    MapStrategy(ShadowAI* botAI) : Strategy(botAI){};

    std::string const getName() override { return "map"; }
};

class MapFullStrategy : public Strategy
{
public:
    MapFullStrategy(ShadowAI* botAI) : Strategy(botAI){};

    std::string const getName() override { return "map full"; }
};

#endif
