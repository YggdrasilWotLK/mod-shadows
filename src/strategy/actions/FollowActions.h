/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_FOLLOWACTIONS_H
#define _SHADOW_FOLLOWACTIONS_H

#include "MovementActions.h"

class ShadowAI;

class FollowAction : public MovementAction
{
public:
    FollowAction(ShadowAI* botAI, std::string const name = "follow") : MovementAction(botAI, name) {}

    bool Execute(Event event) override;
    bool isUseful() override;
    bool CanDeadFollow(Unit* target);
};

class FleeToMasterAction : public FollowAction
{
public:
    FleeToMasterAction(ShadowAI* botAI) : FollowAction(botAI, "flee to master") {}

    bool Execute(Event event) override;
    bool isUseful() override;
};

#endif
