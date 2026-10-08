/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_TRADEACTION_H
#define _SHADOW_TRADEACTION_H

#include "InventoryAction.h"

class Item;
class ShadowAI;

class TradeAction : public InventoryAction
{
public:
    TradeAction(ShadowAI* botAI) : InventoryAction(botAI, "trade") {}

    bool Execute(Event event) override;

private:
    bool TradeItem(Item const* item, int8 slot);

    static std::map<std::string, uint32> slots;
};

#endif
