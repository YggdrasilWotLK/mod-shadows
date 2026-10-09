/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_SENDMAILACTION_H
#define _SHADOW_SENDMAILACTION_H

#include "InventoryAction.h"

class ShadowAI;

class SendMailAction : public InventoryAction
{
public:
    SendMailAction(ShadowAI* botAI) : InventoryAction(botAI, "sendmail") {}

    bool Execute(Event event) override;
};

#endif
