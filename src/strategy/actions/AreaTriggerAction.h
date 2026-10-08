/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_AREATRIGGERACTION_H
#define _SHADOW_AREATRIGGERACTION_H

#include "MovementActions.h"

class ShadowAI;

class ReachAreaTriggerAction : public MovementAction
{
public:
    ReachAreaTriggerAction(ShadowAI* botAI) : MovementAction(botAI, "reach area trigger") {}

    bool Execute(Event event) override;
};

class AreaTriggerAction : public MovementAction
{
public:
    AreaTriggerAction(ShadowAI* botAI) : MovementAction(botAI, "area trigger") {}

    bool Execute(Event event) override;
};

#endif
