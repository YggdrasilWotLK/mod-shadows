/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_ISMOVINGVALUE_H
#define _SHADOW_ISMOVINGVALUE_H

#include "NamedObjectContext.h"
#include "Value.h"

class ShadowAI;

class IsMovingValue : public BoolCalculatedValue, public Qualified
{
public:
    IsMovingValue(ShadowAI* botAI, std::string const name = "is moving") : BoolCalculatedValue(botAI, name) {}

    bool Calculate() override;
};

class IsSwimmingValue : public BoolCalculatedValue, public Qualified
{
public:
    IsSwimmingValue(ShadowAI* botAI, std::string const name = "is swimming") : BoolCalculatedValue(botAI, name) {}

    bool Calculate() override;
};

#endif
