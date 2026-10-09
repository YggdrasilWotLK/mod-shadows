/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_MOVETOTRAVELTARGETACTION_H
#define _SHADOW_MOVETOTRAVELTARGETACTION_H

#include "MovementActions.h"

class ShadowAI;

class MoveToTravelTargetAction : public MovementAction
{
public:
    MoveToTravelTargetAction(ShadowAI* botAI) : MovementAction(botAI, "move to travel target") {}

    bool Execute(Event event) override;
    bool isUseful() override;
};

#endif
