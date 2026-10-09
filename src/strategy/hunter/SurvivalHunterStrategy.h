/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_SURVIVALHUNTERSTRATEGY_H
#define _SHADOW_SURVIVALHUNTERSTRATEGY_H

#include "GenericHunterStrategy.h"
#include "CombatStrategy.h"

class ShadowAI;

class SurvivalHunterStrategy : public GenericHunterStrategy
{
public:
    SurvivalHunterStrategy(ShadowAI* botAI);

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "surv"; }
    NextAction** getDefaultActions() override;
};

#endif
