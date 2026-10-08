/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_LASTSPELLCASTTIMEVALUE_H
#define _SHADOW_LASTSPELLCASTTIMEVALUE_H

#include "NamedObjectContext.h"
#include "Value.h"

class ShadowAI;

class LastSpellCastTimeValue : public ManualSetValue<time_t>, public Qualified
{
public:
    LastSpellCastTimeValue(ShadowAI* botAI) : ManualSetValue<time_t>(botAI, 0), Qualified() {}
};

#endif
