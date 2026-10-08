/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_PETSACTION_H
#define _SHADOW_PETSACTION_H

#include <string>

#include "Action.h"
#include "ShadowFactory.h"
#include "Unit.h"

class ShadowAI;

class PetsAction : public Action
{
public:
    PetsAction(ShadowAI* botAI, const std::string& defaultCmd = "") : Action(botAI, "pet"), defaultCmd(defaultCmd) {}

    bool Execute(Event event) override;

private:
    bool warningEnabled = true;
    std::string defaultCmd;
};

#endif
