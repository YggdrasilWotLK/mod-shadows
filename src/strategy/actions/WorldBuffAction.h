/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_WORLDBUFFACTION_H
#define _SHADOW_WORLDBUFFACTION_H

#include "Action.h"

class ShadowAI;
class Unit;

class WorldBuffAction : public Action
{
public:
    WorldBuffAction(ShadowAI* botAI) : Action(botAI, "world buff") {}

    bool Execute(Event event) override;

    static std::vector<uint32> NeedWorldBuffs(Unit* unit);
};

#endif
