/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_RPGSTRATEGY_H
#define _SHADOW_RPGSTRATEGY_H

#include "Strategy.h"

class ShadowAI;

class RpgActionMultiplier : public Multiplier
{
public:
    RpgActionMultiplier(ShadowAI* botAI) : Multiplier(botAI, "rpg action") {}

    float GetValue(Action* action) override;
};

class RpgStrategy : public Strategy
{
public:
    RpgStrategy(ShadowAI* botAI);

    std::string const getName() override { return "rpg"; }
    NextAction** getDefaultActions() override;
    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    void InitMultipliers(std::vector<Multiplier*>& multipliers) override;
};

#endif
