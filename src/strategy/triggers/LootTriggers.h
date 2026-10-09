/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_LOOTTRIGGERS_H
#define _SHADOW_LOOTTRIGGERS_H

#include "Trigger.h"

class ShadowAI;

class LootAvailableTrigger : public Trigger
{
public:
    LootAvailableTrigger(ShadowAI* botAI) : Trigger(botAI, "loot available") {}

    bool IsActive() override;
};

class FarFromCurrentLootTrigger : public Trigger
{
public:
    FarFromCurrentLootTrigger(ShadowAI* botAI) : Trigger(botAI, "far from current loot") {}

    bool IsActive() override;
};

class CanLootTrigger : public Trigger
{
public:
    CanLootTrigger(ShadowAI* botAI) : Trigger(botAI, "can loot") {}

    bool IsActive() override;
};

#endif
