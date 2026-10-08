/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_TELLLOSACTION_H
#define _SHADOW_TELLLOSACTION_H

#include "Action.h"

class ShadowAI;

class TellLosAction : public Action
{
public:
    TellLosAction(ShadowAI* botAI) : Action(botAI, "los") {}

    bool Execute(Event event) override;

private:
    void ListUnits(std::string const title, GuidVector units);
    void ListGameObjects(std::string const title, GuidVector gos);
};

class TellAuraAction : public Action
{
public:
    TellAuraAction(ShadowAI* ai) : Action(ai, "aura") {}

    virtual bool Execute(Event event);
};

class TellEstimatedDpsAction : public Action
{
public:
    TellEstimatedDpsAction(ShadowAI* ai) : Action(ai, "tell estimated dps") {}

    virtual bool Execute(Event event);
};

class TellCalculateItemAction : public Action
{
public:
    TellCalculateItemAction(ShadowAI* ai) : Action(ai, "calculate item") {}

    virtual bool Execute(Event event);
};

#endif
