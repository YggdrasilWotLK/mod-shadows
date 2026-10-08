/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_GUILDBANKACTION_H
#define _SHADOW_GUILDBANKACTION_H

#include "InventoryAction.h"

class GameObject;
class Item;
class ShadowAI;

class GuildBankAction : public InventoryAction
{
public:
    GuildBankAction(ShadowAI* botAI) : InventoryAction(botAI, "guild bank") {}

    bool Execute(Event event) override;

private:
    bool Execute(std::string const text, GameObject* bank);
    bool MoveFromCharToBank(Item* item, GameObject* bank);
};

#endif
