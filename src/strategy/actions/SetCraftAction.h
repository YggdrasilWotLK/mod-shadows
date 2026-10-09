/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_SETCRAFTACTION_H
#define _SHADOW_SETCRAFTACTION_H

#include "Action.h"
#include "CraftValue.h"

class ShadowAI;

struct SkillLineAbilityEntry;

class SetCraftAction : public Action
{
public:
    SetCraftAction(ShadowAI* botAI) : Action(botAI, "craft") {}

    bool Execute(Event event) override;

    static uint32 GetCraftFee(CraftData& craftData);

private:
    void TellCraft();

    static std::map<uint32, SkillLineAbilityEntry const*> skillSpells;
};

#endif
