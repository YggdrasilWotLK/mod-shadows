/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_ISBEHINDVALUE_H
#define _SHADOW_ISBEHINDVALUE_H

#include "NamedObjectContext.h"
#include "Value.h"

class ShadowAI;

class IsBehindValue : public BoolCalculatedValue, public Qualified
{
public:
    IsBehindValue(ShadowAI* botAI) : BoolCalculatedValue(botAI) {}

    bool Calculate() override;
};

#endif
