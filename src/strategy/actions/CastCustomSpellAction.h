/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_CASTCUSTOMSPELLACTION_H
#define _SHADOW_CASTCUSTOMSPELLACTION_H

#include "ListSpellsAction.h"

class ShadowAI;
class SpellInfo;
class WorldObject;

class CastCustomSpellAction : public InventoryAction
{
public:
    CastCustomSpellAction(ShadowAI* botAI, std::string const name = "cast custom spell")
        : InventoryAction(botAI, name)
    {
    }

    bool Execute(Event event) override;
    virtual std::string const castString(WorldObject* target) { return "cast"; }

protected:
    bool ncCast = false;
};

class CastCustomNcSpellAction : public CastCustomSpellAction
{
public:
    CastCustomNcSpellAction(ShadowAI* botAI, std::string const name = "cast custom nc spell")
        : CastCustomSpellAction(botAI, name)
    {
    }

    bool isUseful() override;
    std::string const castString(WorldObject* target) override;
};

class CastRandomSpellAction : public ListSpellsAction
{
public:
    CastRandomSpellAction(ShadowAI* botAI, std::string const name = "cast random spell")
        : ListSpellsAction(botAI, name)
    {
    }

    bool isUseful() override { return false; }
    virtual bool AcceptSpell(SpellInfo const* spellInfo);
    virtual uint32 GetSpellPriority(SpellInfo const* spellInfo) { return 1; }
    virtual bool castSpell(uint32 spellId, WorldObject* wo);
    bool Execute(Event event) override;

protected:
    bool MultiCast = false;
};

class CraftRandomItemAction : public CastRandomSpellAction
{
public:
    CraftRandomItemAction(ShadowAI* botAI) : CastRandomSpellAction(botAI, "craft random item") { MultiCast = true; }

    bool AcceptSpell(SpellInfo const* spellInfo) override;
    uint32 GetSpellPriority(SpellInfo const* spellInfo) override;
};

class DisEnchantRandomItemAction : public CastCustomSpellAction
{
public:
    DisEnchantRandomItemAction(ShadowAI* botAI) : CastCustomSpellAction(botAI, "disenchant random item") {}

    bool isUseful() override;
    bool Execute(Event event) override;
};

class EnchantRandomItemAction : public CastRandomSpellAction
{
public:
    EnchantRandomItemAction(ShadowAI* botAI) : CastRandomSpellAction(botAI, "enchant random item") {}

    bool isUseful() override;
    bool AcceptSpell(SpellInfo const* spellInfo) override;
    uint32 GetSpellPriority(SpellInfo const* spellInfo) override;
};

#endif
