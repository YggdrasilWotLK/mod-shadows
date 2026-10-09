/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_RPGVALUES_H
#define _SHADOW_RPGVALUES_H

#include "Value.h"

class ShadowAI;

class NextRpgActionValue : public ManualSetValue<std::string>
{
public:
    NextRpgActionValue(ShadowAI* botAI, std::string const defaultValue = "",
                       std::string const name = "next rpg action")
        : ManualSetValue(botAI, defaultValue, name){};
};

#endif
