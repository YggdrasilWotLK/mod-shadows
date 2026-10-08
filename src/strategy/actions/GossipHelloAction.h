/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_GOSSIPHELLOACTION_H
#define _SHADOW_GOSSIPHELLOACTION_H

#include "Action.h"

class ShadowAI;

class GossipHelloAction : public Action
{
public:
    GossipHelloAction(ShadowAI* botAI) : Action(botAI, "gossip hello") {}

    bool Execute(Event event) override;
    // Overload for direct usage
    bool Execute(ObjectGuid guid, int32 menuToSelect, bool silent = false);

private:
    void TellGossipMenus();
    bool ProcessGossip(int32 menuToSelect, bool silent);
    void TellGossipText(uint32 textId);
};

#endif
