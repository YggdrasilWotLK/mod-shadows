/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_SETHOMEACTION_H
#define _SHADOW_SETHOMEACTION_H

#include "MovementActions.h"

class ShadowAI;

class SetHomeAction : public MovementAction
{
public:
    SetHomeAction(ShadowAI* botAI) : MovementAction(botAI, "home") {}

    bool Execute(Event event) override;
};

#endif
