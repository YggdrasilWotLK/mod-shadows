/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_MARKRTISTRATEGY_H
#define _SHADOW_MARKRTISTRATEGY_H

#include "Strategy.h"

class ShadowAI;

class MarkRtiStrategy : public Strategy
{
public:
    MarkRtiStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    std::string const getName() override { return "mark rti"; }
    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
};

#endif
