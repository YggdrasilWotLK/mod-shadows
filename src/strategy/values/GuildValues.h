/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_GUILDVALUES_H
#define _SHADOW_GUILDVALUES_H

#include "Value.h"

class ShadowAI;

class PetitionSignsValue : public SingleCalculatedValue<uint8>
{
public:
    PetitionSignsValue(ShadowAI* botAI) : SingleCalculatedValue<uint8>(botAI, "petition signs") {}

    uint8 Calculate();
};

#endif
