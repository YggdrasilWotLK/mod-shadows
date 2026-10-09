/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_LISTSPELLSACTION_H
#define _SHADOW_LISTSPELLSACTION_H

#include "InventoryAction.h"

class ShadowAI;

class ListSpellsAction : public InventoryAction
{
public:
    ListSpellsAction(ShadowAI* botAI, std::string const name = "spells") : InventoryAction(botAI, name) {}

    bool Execute(Event event) override;
    virtual std::vector<std::pair<uint32, std::string>> GetSpellList(std::string filter = "");

private:
    static std::map<uint32, SkillLineAbilityEntry const*> skillSpells;
    static std::set<uint32> vendorItems;
};

#endif
