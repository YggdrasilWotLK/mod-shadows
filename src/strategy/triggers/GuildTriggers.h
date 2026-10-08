/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_GUILDTRIGGER_H
#define _SHADOW_GUILDTRIGGER_H

#include "Trigger.h"

class ShadowAI;

class PetitionTurnInTrigger : public Trigger
{
public:
    PetitionTurnInTrigger(ShadowAI* botAI) : Trigger(botAI) {}

    bool IsActive() override;
};

class BuyTabardTrigger : public Trigger
{
public:
    BuyTabardTrigger(ShadowAI* botAI) : Trigger(botAI) {}

    bool IsActive() override;
};

class LeaveLargeGuildTrigger : public Trigger
{
public:
    LeaveLargeGuildTrigger(ShadowAI* botAI) : Trigger(botAI) {}

    bool IsActive();
};

#endif
