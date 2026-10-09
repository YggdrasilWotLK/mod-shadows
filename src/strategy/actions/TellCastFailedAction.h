/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_TELLCASTFAILEDACTION_H
#define _SHADOW_TELLCASTFAILEDACTION_H

#include "Action.h"

class ShadowAI;

class TellSpellAction : public Action
{
public:
    TellSpellAction(ShadowAI* botAI) : Action(botAI, "spell") {}

    bool Execute(Event event) override;
};

class TellCastFailedAction : public Action
{
public:
    TellCastFailedAction(ShadowAI* botAI) : Action(botAI, "tell cast failed") {}

    bool Execute(Event event) override;
};

#endif
