/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_DEMONOLOGYWARLOCKSTRATEGY_H
#define _SHADOW_DEMONOLOGYWARLOCKSTRATEGY_H

#include "GenericWarlockStrategy.h"
#include "CombatStrategy.h"

class ShadowAI;

class DemonologyWarlockStrategy : public GenericWarlockStrategy
{
public:
    DemonologyWarlockStrategy(ShadowAI* botAI);

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "demo"; }
    NextAction** getDefaultActions() override;
};

class MetaMeleeAoeStrategy : public CombatStrategy
{
public:
    MetaMeleeAoeStrategy(ShadowAI* botAI);

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "meta melee"; }
};
#endif
