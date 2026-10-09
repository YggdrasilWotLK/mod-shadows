/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_CHECKMAILACTION_H
#define _SHADOW_CHECKMAILACTION_H

#include "Action.h"
#include "DatabaseEnvFwd.h"

class ShadowAI;

struct Mail;

class CheckMailAction : public Action
{
public:
    CheckMailAction(ShadowAI* botAI) : Action(botAI, "check mail") {}

    bool Execute(Event event) override;
    bool isUseful() override;

private:
    void ProcessMail(Mail* mail, Player* owner, CharacterDatabaseTransaction trans);
};

#endif
