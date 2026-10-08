/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_FIREMAGESTRATEGY_H
#define _SHADOW_FIREMAGESTRATEGY_H

#include "GenericMageStrategy.h"

class ShadowAI;

class FireMageStrategy : public GenericMageStrategy
{
public:
    FireMageStrategy(ShadowAI* botAI);

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "fire"; }
    NextAction** getDefaultActions() override;
};

class FirestarterStrategy : public CombatStrategy
{
public:
    FirestarterStrategy(ShadowAI* botAI);

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "firestarter"; }
};
#endif
