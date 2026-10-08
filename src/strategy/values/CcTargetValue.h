/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_CCTARGETVALUE_H
#define _SHADOW_CCTARGETVALUE_H

#include "NamedObjectContext.h"
#include "TargetValue.h"

class ShadowAI;
class Unit;

class CcTargetValue : public TargetValue, public Qualified
{
public:
    CcTargetValue(ShadowAI* botAI, std::string const name = "cc target") : TargetValue(botAI, name) {}

    Unit* Calculate() override;
};

#endif
