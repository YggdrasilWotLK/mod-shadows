/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_CHANGESTRATEGYACTION_H
#define _SHADOW_CHANGESTRATEGYACTION_H

#include "Action.h"

class ShadowAI;

class ChangeCombatStrategyAction : public Action
{
public:
    ChangeCombatStrategyAction(ShadowAI* botAI, std::string const name = "co") : Action(botAI, name) {}

    bool Execute(Event event) override;
};

class ChangeNonCombatStrategyAction : public Action
{
public:
    ChangeNonCombatStrategyAction(ShadowAI* botAI) : Action(botAI, "nc") {}

    bool Execute(Event event) override;
};

class ChangeDeadStrategyAction : public Action
{
public:
    ChangeDeadStrategyAction(ShadowAI* botAI) : Action(botAI, "de") {}

    bool Execute(Event event) override;
};

#endif
