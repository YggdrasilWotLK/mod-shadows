/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_COLLISIONVALUE_H
#define _SHADOW_COLLISIONVALUE_H

#include "NamedObjectContext.h"
#include "Value.h"

class ShadowAI;

class CollisionValue : public BoolCalculatedValue, public Qualified
{
public:
    CollisionValue(ShadowAI* botAI, std::string const name = "collision")
        : BoolCalculatedValue(botAI, name), Qualified()
    {
    }

    bool Calculate() override;
};

#endif
