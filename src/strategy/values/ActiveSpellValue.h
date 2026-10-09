/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_ACTIVESPELLVALUE_H
#define _SHADOW_ACTIVESPELLVALUE_H

#include "Value.h"

class ShadowAI;

class ActiveSpellValue : public CalculatedValue<uint32>
{
public:
    ActiveSpellValue(ShadowAI* botAI, std::string const name = "active spell") : CalculatedValue<uint32>(botAI, name)
    {
    }

    uint32 Calculate() override;
};

#endif
