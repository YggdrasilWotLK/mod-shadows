/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_LOOTSTRATEGYACTION_H
#define _SHADOW_LOOTSTRATEGYACTION_H

#include "Action.h"

class ShadowAI;

class LootStrategyAction : public Action
{
public:
    LootStrategyAction(ShadowAI* botAI) : Action(botAI, "ll") {}

    bool Execute(Event event) override;
};

#endif
