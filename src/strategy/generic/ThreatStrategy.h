/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_THREATSTRATEGY_H
#define _SHADOW_THREATSTRATEGY_H

#include "Strategy.h"

class ShadowAI;

class ThreatMultiplier : public Multiplier
{
public:
    ThreatMultiplier(ShadowAI* botAI) : Multiplier(botAI, "threat") {}

    float GetValue(Action* action) override;
};

class ThreatStrategy : public Strategy
{
public:
    ThreatStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    void InitMultipliers(std::vector<Multiplier*>& multipliers) override;
    std::string const getName() override { return "threat"; }
};

class FocusMultiplier : public Multiplier
{
public:
    FocusMultiplier(ShadowAI* botAI) : Multiplier(botAI, "focus") {}

    float GetValue(Action* action) override;
};

class FocusStrategy : public Strategy
{
public:
    FocusStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    void InitMultipliers(std::vector<Multiplier*>& multipliers) override;
    std::string const getName() override { return "focus"; }
};

#endif
