/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_TELLTARGETACTION_H
#define _SHADOW_TELLTARGETACTION_H

#include "Action.h"

class ShadowAI;

class TellTargetAction : public Action
{
public:
    TellTargetAction(ShadowAI* botAI) : Action(botAI, "tell target") {}

    bool Execute(Event event) override;
};

class TellAttackersAction : public Action
{
public:
    TellAttackersAction(ShadowAI* botAI) : Action(botAI, "tell attackers") {}

    bool Execute(Event event) override;
};

#endif
