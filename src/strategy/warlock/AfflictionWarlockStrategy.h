/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_AFFLICTIONWARLOCKSTRATEGY_H
#define _SHADOW_AFFLICTIONWARLOCKSTRATEGY_H

#include "GenericWarlockStrategy.h"
#include "CombatStrategy.h"

class ShadowAI;

class AfflictionWarlockStrategy : public GenericWarlockStrategy
{
public:
    AfflictionWarlockStrategy(ShadowAI* botAI);

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "affli"; }
    NextAction** getDefaultActions() override;
};

#endif
