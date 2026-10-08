/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_AOEHEALVALUES_H
#define _SHADOW_AOEHEALVALUES_H

#include "NamedObjectContext.h"
#include "Value.h"

class ShadowAI;

class AoeHealValue : public Uint8CalculatedValue, public Qualified
{
public:
    AoeHealValue(ShadowAI* botAI, std::string const name = "aoe heal") : Uint8CalculatedValue(botAI, name) {}

    uint8 Calculate() override;
};

#endif
