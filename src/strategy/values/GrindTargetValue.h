/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_GRINDTARGETVALUE_H
#define _SHADOW_GRINDTARGETVALUE_H

#include "TargetValue.h"

class ShadowAI;
class Unit;

class GrindTargetValue : public TargetValue
{
public:
    GrindTargetValue(ShadowAI* botAI, std::string const name = "grind target") : TargetValue(botAI, name) {}

    Unit* Calculate() override;

private:
    uint32 GetTargetingPlayerCount(Unit* unit);
    Unit* FindTargetForGrinding(uint32 assistCount);
    bool needForQuest(Unit* target);
};

#endif
