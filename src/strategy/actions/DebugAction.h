/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_DEBUGACTION_H
#define _SHADOW_DEBUGACTION_H

#include "Action.h"
#include "ObjectGuid.h"
#include "TravelMgr.h"

class ShadowAI;
class Unit;

class DebugAction : public Action
{
public:
    DebugAction(ShadowAI* botAI) : Action(botAI, "Debug") {}

    bool Execute(Event event) override;

    void FakeSpell(uint32 spellId, Unit* truecaster, Unit* caster, ObjectGuid target = ObjectGuid::Empty,
                   GuidVector otherTargets = {}, GuidVector missTargets = {}, WorldPosition source = WorldPosition(),
                   WorldPosition dest = WorldPosition(), bool forceDest = false);
    void addAura(uint32 spellId, Unit* target);
};

#endif
