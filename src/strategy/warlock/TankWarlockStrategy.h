/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_TANKWARLOCKSTRATEGY_H
#define _SHADOW_TANKWARLOCKSTRATEGY_H

#include "GenericWarlockStrategy.h"

class ShadowAI;

class TankWarlockStrategy : public GenericWarlockStrategy
{
public:
    TankWarlockStrategy(ShadowAI* botAI);

    std::string const getName() override { return "tank"; }
    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    NextAction** getDefaultActions() override;
};

#endif
