/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_IMBUEACTION_H
#define _SHADOW_IMBUEACTION_H

#include "Action.h"

class ShadowAI;

class ImbueWithPoisonAction : public Action
{
public:
    ImbueWithPoisonAction(ShadowAI* botAI);

    bool Execute(Event event) override;
};

class ImbueWithStoneAction : public Action
{
public:
    ImbueWithStoneAction(ShadowAI* botAI);

    bool Execute(Event event) override;
};

class ImbueWithOilAction : public Action
{
public:
    ImbueWithOilAction(ShadowAI* botAI);

    bool Execute(Event event) override;
};

class TryEmergencyAction : public Action
{
public:
    TryEmergencyAction(ShadowAI* botAI);

    bool Execute(Event event) override;
};

#endif
