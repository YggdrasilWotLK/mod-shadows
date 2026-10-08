/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_KITESTRATEGY_H
#define _SHADOW_KITESTRATEGY_H

#include "Strategy.h"

class ShadowAI;

class KiteStrategy : public Strategy
{
public:
    KiteStrategy(ShadowAI* botAI);

    std::string const getName() override { return "kite"; }
    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
};

#endif
