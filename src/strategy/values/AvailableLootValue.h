/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_AVAILABLELOOTVALUE_H
#define _SHADOW_AVAILABLELOOTVALUE_H

#include "LootObjectStack.h"
#include "Value.h"

class ShadowAI;

class AvailableLootValue : public ManualSetValue<LootObjectStack*>
{
public:
    AvailableLootValue(ShadowAI* botAI, std::string const name = "available loot");
    virtual ~AvailableLootValue();
};

class LootTargetValue : public ManualSetValue<LootObject>
{
public:
    LootTargetValue(ShadowAI* botAI, std::string const name = "loot target");
};

class CanLootValue : public BoolCalculatedValue
{
public:
    CanLootValue(ShadowAI* botAI, std::string const name = "can loot") : BoolCalculatedValue(botAI, name) {}

    bool Calculate() override;
};

#endif
