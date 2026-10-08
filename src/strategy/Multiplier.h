/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_MULTIPLIER_H
#define _SHADOW_MULTIPLIER_H

#include "AiObject.h"

class Action;
class ShadowAI;

class Multiplier : public AiNamedObject
{
public:
    Multiplier(ShadowAI* botAI, std::string const name) : AiNamedObject(botAI, name) {}
    virtual ~Multiplier() {}

    virtual float GetValue([[maybe_unused]] Action* action) { return 1.0f; }
};

#endif
