/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_NEARESTADSVALUE_H
#define _SHADOW_NEARESTADSVALUE_H

#include "ShadowAIConfig.h"
#include "PossibleTargetsValue.h"

class ShadowAI;

class NearestAddsValue : public PossibleTargetsValue
{
public:
    NearestAddsValue(ShadowAI* botAI, float range = sShadowAIConfig->tooCloseDistance)
        : PossibleTargetsValue(botAI, "nearest adds", range, true)
    {
    }

protected:
    bool AcceptUnit(Unit* unit) override;
};

#endif
