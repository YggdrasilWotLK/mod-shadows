/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_RANDOMBOTUPDATEACTION_H
#define _SHADOW_RANDOMBOTUPDATEACTION_H

#include "Action.h"

class ShadowAI;

class RandomBotUpdateAction : public Action
{
public:
    RandomBotUpdateAction(ShadowAI* botAI) : Action(botAI, "random bot update") {}

    bool Execute(Event event) override;
    bool isUseful() override;
};

#endif
