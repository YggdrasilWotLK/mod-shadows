/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_REPAIRALLACTION_H
#define _SHADOW_REPAIRALLACTION_H

#include "Action.h"

class ShadowAI;

class RepairAllAction : public Action
{
public:
    RepairAllAction(ShadowAI* botAI) : Action(botAI, "repair") {}

    bool Execute(Event event) override;
};

#endif
