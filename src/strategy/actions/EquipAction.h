/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_EQUIPACTION_H
#define _SHADOW_EQUIPACTION_H

#include "ChatHelper.h"
#include "InventoryAction.h"

class FindItemVisitor;
class Item;
class ShadowAI;

class EquipAction : public InventoryAction
{
public:
    EquipAction(ShadowAI* botAI, std::string const name = "equip") : InventoryAction(botAI, name) {}

    bool Execute(Event event) override;
    void EquipItems(ItemIds ids);

private:
    void EquipItem(FindItemVisitor* visitor);
    uint8 GetSmallestBagSlot();
    void EquipItem(Item* item);
};

class EquipUpgradesAction : public EquipAction
{
public:
    EquipUpgradesAction(ShadowAI* botAI, std::string const name = "equip upgrades") : EquipAction(botAI, name) {}

    bool Execute(Event event) override;
};

class EquipUpgradeAction : public EquipAction
{
public:
    EquipUpgradeAction(ShadowAI* botAI, std::string const name = "equip upgrade") : EquipAction(botAI, name) {}

    bool Execute(Event event) override;
};

#endif
