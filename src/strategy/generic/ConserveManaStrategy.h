/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_CONSERVEMANASTRATEGY_H
#define _SHADOW_CONSERVEMANASTRATEGY_H

#include "Strategy.h"

class ShadowAI;

class HealerAutoSaveManaMultiplier : public Multiplier
{
public:
    HealerAutoSaveManaMultiplier(ShadowAI* botAI) : Multiplier(botAI, "save mana") {}

    float GetValue(Action* action) override;
};

class HealerAutoSaveManaStrategy : public Strategy
{
public:
    HealerAutoSaveManaStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    void InitMultipliers(std::vector<Multiplier*>& multipliers) override;
    std::string const getName() override { return "save mana"; }
};

#endif
