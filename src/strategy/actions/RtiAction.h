/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_RTIACTION_H
#define _SHADOW_RTIACTION_H

#include "Action.h"

class ShadowAI;

class RtiAction : public Action
{
public:
    RtiAction(ShadowAI* botAI) : Action(botAI, "rti") {}

    bool Execute(Event event) override;

private:
    void AppendRti(std::ostringstream& out, std::string const type);
};

class MarkRtiAction : public Action
{
public:
    MarkRtiAction(ShadowAI* botAI) : Action(botAI, "mark rti") {}

    bool Execute(Event event) override;
};

#endif
