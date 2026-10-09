/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_GUILDACCEPTACTION_H
#define _SHADOW_GUILDACCEPTACTION_H

#include "Action.h"

class ShadowAI;

class GuildAcceptAction : public Action
{
public:
    GuildAcceptAction(ShadowAI* botAI) : Action(botAI, "guild accept") {}

    bool Execute(Event event) override;
};

#endif
