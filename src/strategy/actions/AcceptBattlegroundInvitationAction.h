/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_ACCEPTBATTLEGROUNDINVITATIONACTION_H
#define _SHADOW_ACCEPTBATTLEGROUNDINVITATIONACTION_H

#include "Action.h"

class ShadowAI;

class AcceptBgInvitationAction : public Action
{
public:
    AcceptBgInvitationAction(ShadowAI* botAI) : Action(botAI, "accept bg invitation") {}

    bool Execute(Event event) override;
};

#endif
