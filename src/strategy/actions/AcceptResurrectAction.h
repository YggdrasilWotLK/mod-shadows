/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_ACCEPTRESURRECTACTION_H
#define _SHADOW_ACCEPTRESURRECTACTION_H

#include "Action.h"

class ShadowAI;

class AcceptResurrectAction : public Action
{
public:
    AcceptResurrectAction(ShadowAI* botAI) : Action(botAI, "accept resurrect") {}

    bool Execute(Event event) override;
};

#endif
