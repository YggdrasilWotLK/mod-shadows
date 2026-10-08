/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_LEASTHPTARGETVALUE_H
#define _SHADOW_LEASTHPTARGETVALUE_H

#include "TargetValue.h"

class ShadowAI;
class Unit;

class LeastHpTargetValue : public TargetValue
{
public:
    LeastHpTargetValue(ShadowAI* botAI, std::string const name = "least hp target") : TargetValue(botAI, name) {}

    Unit* Calculate() override;
};

#endif
