/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_BUYACTION_H
#define _SHADOW_BUYACTION_H

#include "InventoryAction.h"

class FindItemVisitor;
class ObjectGuid;
class Item;
class Player;
class ShadowAI;

struct ItemTemplate;
struct VendorItemData;

class BuyAction : public InventoryAction
{
public:
    BuyAction(ShadowAI* botAI) : InventoryAction(botAI, "buy") {}

    bool Execute(Event event) override;

private:
    bool BuyItem(VendorItemData const* tItems, ObjectGuid vendorguid, ItemTemplate const* proto);
    bool TradeItem(FindItemVisitor* visitor, int8 slot);
    bool TradeItem(Item const* item, int8 slot);
};

#endif
