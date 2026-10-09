/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_SELFTARGETVALUE_H
#define _SHADOW_SELFTARGETVALUE_H

#include "Value.h"

class ShadowAI;
class Unit;

class SelfTargetValue : public UnitCalculatedValue
{
public:
    SelfTargetValue(ShadowAI* botAI, std::string const name = "self target") : UnitCalculatedValue(botAI, name) {}

    Unit* Calculate() override;
};

#endif
