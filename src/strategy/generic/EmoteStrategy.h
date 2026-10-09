/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_EMOTESTRATEGY_H
#define _SHADOW_EMOTESTRATEGY_H

#include "Strategy.h"

class ShadowAI;

class EmoteStrategy : public Strategy
{
public:
    EmoteStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "emote"; }
};

#endif
