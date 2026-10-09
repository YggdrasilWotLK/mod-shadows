/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_ACCEPTINVITATIONACTION_H
#define _SHADOW_ACCEPTINVITATIONACTION_H

#include "Action.h"
#include "UseMeetingStoneAction.h"

class ShadowAI;

class AcceptInvitationAction : public SummonAction
{
public:
    AcceptInvitationAction(ShadowAI* botAI) : SummonAction(botAI, "accept invitation") {}

    bool Execute(Event event) override;
};

#endif
