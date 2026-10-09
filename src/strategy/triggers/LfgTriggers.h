/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_LFGTRIGGERS_H
#define _SHADOW_LFGTRIGGERS_H

#include "Trigger.h"

class ShadowAI;

class LfgProposalActiveTrigger : public Trigger
{
public:
    LfgProposalActiveTrigger(ShadowAI* botAI) : Trigger(botAI, "lfg proposal active", 20 * 2000) {}

    bool IsActive() override;
};

class UnknownDungeonTrigger : public Trigger
{
public:
    UnknownDungeonTrigger(ShadowAI* botAI) : Trigger(botAI, "unknown dungeon", 20 * 2000) {}

    bool IsActive() override;
};

#endif
