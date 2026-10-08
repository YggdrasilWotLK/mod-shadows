/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_DISTANCEVALUE_H
#define _SHADOW_DISTANCEVALUE_H

#include "NamedObjectContext.h"
#include "Value.h"

class ShadowAI;

class DistanceValue : public FloatCalculatedValue, public Qualified
{
public:
    DistanceValue(ShadowAI* botAI, std::string const name = "distance") : FloatCalculatedValue(botAI, name) {}

    float Calculate() override;
};

class InsideTargetValue : public BoolCalculatedValue, public Qualified
{
public:
    InsideTargetValue(ShadowAI* botAI, std::string const name = "inside target") : BoolCalculatedValue(botAI, name)
    {
    }

    bool Calculate() override;
};

#endif
