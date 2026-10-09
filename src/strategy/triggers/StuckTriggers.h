/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_STUCKTRIGGERS_H
#define _SHADOW_STUCKTRIGGERS_H

#include "Trigger.h"

class MoveStuckTrigger : public Trigger
{
public:
    MoveStuckTrigger(ShadowAI* botAI) : Trigger(botAI, "move stuck", 5) {}

    bool IsActive() override;
};

class MoveLongStuckTrigger : public Trigger
{
public:
    MoveLongStuckTrigger(ShadowAI* botAI) : Trigger(botAI, "move long stuck", 5) {}

    bool IsActive() override;
};

class CombatStuckTrigger : public Trigger
{
public:
    CombatStuckTrigger(ShadowAI* botAI) : Trigger(botAI, "combat stuck", 5) {}

    bool IsActive() override;
};

class CombatLongStuckTrigger : public Trigger
{
public:
    CombatLongStuckTrigger(ShadowAI* botAI) : Trigger(botAI, "combat long stuck", 5) {}

    bool IsActive() override;
};

#endif
