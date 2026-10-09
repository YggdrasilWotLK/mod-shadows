/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_GENERICSPELLACTIONS_H
#define _SHADOW_GENERICSPELLACTIONS_H

#include "Action.h"
#include "ShadowAI.h"
#include "ShadowAIConfig.h"
#include "UseItemAction.h"
#include "Value.h"

class ShadowAI;
class Unit;
class WorldObject;

class CastSpellAction : public Action
{
public:
    CastSpellAction(ShadowAI* botAI, std::string const spell);

    std::string const GetTargetName() override { return "current target"; };
    bool Execute(Event event) override;
    bool isPossible() override;
    bool isUseful() override;
    ActionThreatType getThreatType() override { return ActionThreatType::Single; }

    NextAction** getPrerequisites() override;
    std::string const getSpell() { return spell; }

protected:
    std::string spell;
    float range;
};

class CastAuraSpellAction : public CastSpellAction
{
public:
    CastAuraSpellAction(ShadowAI* botAI, std::string const spell, bool isOwner = false, bool checkDuration = false, uint32 beforeDuration = 0)
        : CastSpellAction(botAI, spell)
    {
        this->isOwner = isOwner;
        this->beforeDuration = beforeDuration;
        this->checkDuration = checkDuration;
    }

    bool isUseful() override;

protected:
    bool isOwner;
    bool checkDuration;
    uint32 beforeDuration;
};

class CastMeleeSpellAction : public CastSpellAction
{
public:
    CastMeleeSpellAction(ShadowAI* botAI, std::string const spell);
    bool isUseful() override;
};

class CastDebuffSpellAction : public CastAuraSpellAction
{
public:
    CastDebuffSpellAction(ShadowAI* botAI, std::string const spell, bool isOwner = false, float needLifeTime = 8.0f)
        : CastAuraSpellAction(botAI, spell, isOwner), needLifeTime(needLifeTime)
    {
    }
    bool isUseful() override;

private:
    float needLifeTime;
};

class CastMeleeDebuffSpellAction : public CastDebuffSpellAction
{
public:
    CastMeleeDebuffSpellAction(ShadowAI* botAI, std::string const spell, bool isOwner = false, float needLifeTime = 8.0f);
    bool isUseful() override;
};

class CastDebuffSpellOnAttackerAction : public CastDebuffSpellAction
{
public:
    CastDebuffSpellOnAttackerAction(ShadowAI* botAI, std::string const spell, bool isOwner = true,
                                    float needLifeTime = 8.0f)
        : CastDebuffSpellAction(botAI, spell, isOwner, needLifeTime)
    {
    }

    Value<Unit*>* GetTargetValue() override;
    std::string const getName() override { return spell + " on attacker"; }
    // ActionThreatType getThreatType() override { return ActionThreatType::Aoe; }
};

class CastDebuffSpellOnMeleeAttackerAction : public CastDebuffSpellAction
{
public:
    CastDebuffSpellOnMeleeAttackerAction(ShadowAI* botAI, std::string const spell, bool isOwner = true,
                                         float needLifeTime = 8.0f)
        : CastDebuffSpellAction(botAI, spell, isOwner, needLifeTime)
    {
    }

    Value<Unit*>* GetTargetValue() override;
    std::string const getName() override { return spell + " on attacker"; }
    // ActionThreatType getThreatType() override { return ActionThreatType::Aoe; }
};

class CastBuffSpellAction : public CastAuraSpellAction
{
public:
    CastBuffSpellAction(ShadowAI* botAI, std::string const spell, bool checkIsOwner = false, uint32 beforeDuration = 0);

    std::string const GetTargetName() override { return "self target"; }
};

class CastEnchantItemAction : public CastSpellAction
{
public:
    CastEnchantItemAction(ShadowAI* botAI, std::string const spell);

    bool isPossible() override;
    std::string const GetTargetName() override { return "self target"; }
};

class CastHealingSpellAction : public CastAuraSpellAction
{
public:
    CastHealingSpellAction(ShadowAI* botAI, std::string const spell, uint8 estAmount = 15.0f,
                           HealingManaEfficiency manaEfficiency = HealingManaEfficiency::MEDIUM, bool isOwner = true);

    std::string const GetTargetName() override { return "self target"; }
    bool isUseful() override;
    ActionThreatType getThreatType() override { return ActionThreatType::Aoe; }
    // Yunfan: Mana efficiency tell the bot how to save mana. The higher the better.
    HealingManaEfficiency manaEfficiency;
    uint8 estAmount;

    // protected:
};

class CastAoeHealSpellAction : public CastHealingSpellAction
{
public:
    CastAoeHealSpellAction(ShadowAI* botAI, std::string const spell, uint8 estAmount = 15.0f,
                           HealingManaEfficiency manaEfficiency = HealingManaEfficiency::MEDIUM)
        : CastHealingSpellAction(botAI, spell, estAmount, manaEfficiency)
    {
    }

    std::string const GetTargetName() override { return "party member to heal"; }
    bool isUseful() override;
};

class CastCureSpellAction : public CastSpellAction
{
public:
    CastCureSpellAction(ShadowAI* botAI, std::string const spell);

    std::string const GetTargetName() override { return "self target"; }
};

class PartyMemberActionNameSupport
{
public:
    PartyMemberActionNameSupport(std::string const spell) { name = std::string(spell + " on party"); }

    std::string const getName() { return name; }

private:
    std::string name;
};

class HealPartyMemberAction : public CastHealingSpellAction, public PartyMemberActionNameSupport
{
public:
    HealPartyMemberAction(ShadowAI* botAI, std::string const spell, uint8 estAmount = 15.0f,
                          HealingManaEfficiency manaEfficiency = HealingManaEfficiency::MEDIUM, bool isOwner = true)
        : CastHealingSpellAction(botAI, spell, estAmount, manaEfficiency, isOwner), PartyMemberActionNameSupport(spell)
    {
    }

    std::string const GetTargetName() override { return "party member to heal"; }
    std::string const getName() override { return PartyMemberActionNameSupport::getName(); }
};

class ResurrectPartyMemberAction : public CastSpellAction
{
public:
    ResurrectPartyMemberAction(ShadowAI* botAI, std::string const spell) : CastSpellAction(botAI, spell) {}

    std::string const GetTargetName() override { return "party member to resurrect"; }
    NextAction** getPrerequisites() override
    {
        return NextAction::merge(NextAction::array(0, new NextAction("reach party member to resurrect"), NULL),
                                 Action::getPrerequisites());
    }
};

class CurePartyMemberAction : public CastSpellAction, public PartyMemberActionNameSupport
{
public:
    CurePartyMemberAction(ShadowAI* botAI, std::string const spell, uint32 dispelType)
        : CastSpellAction(botAI, spell), PartyMemberActionNameSupport(spell), dispelType(dispelType)
    {
    }

    Value<Unit*>* GetTargetValue() override;
    std::string const getName() override { return PartyMemberActionNameSupport::getName(); }

protected:
    uint32 dispelType;
};

// Make Bots Paladin, druid, mage use the greater buff rank spell
class BuffOnPartyAction : public CastBuffSpellAction, public PartyMemberActionNameSupport
{
public:
    BuffOnPartyAction(ShadowAI* botAI, std::string const spell)
        : CastBuffSpellAction(botAI, spell), PartyMemberActionNameSupport(spell) { }

    Value<Unit*>* GetTargetValue() override;
    bool Execute(Event event) override;
    std::string const getName() override { return PartyMemberActionNameSupport::getName(); }
};
// End Fix

class CastShootAction : public CastSpellAction
{
public:
    CastShootAction(ShadowAI* botAI);

    ActionThreatType getThreatType() override { return ActionThreatType::None; }
};

class CastLifeBloodAction : public CastHealingSpellAction
{
public:
    CastLifeBloodAction(ShadowAI* botAI) : CastHealingSpellAction(botAI, "lifeblood") {}
};

class CastGiftOfTheNaaruAction : public CastHealingSpellAction
{
public:
    CastGiftOfTheNaaruAction(ShadowAI* botAI) : CastHealingSpellAction(botAI, "gift of the naaru") {}
};

class CastArcaneTorrentAction : public CastBuffSpellAction
{
public:
    CastArcaneTorrentAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "arcane torrent") {}
};

class CastManaTapAction : public CastBuffSpellAction
{
public:
    CastManaTapAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "mana tap") {}
};

class CastWarStompAction : public CastMeleeSpellAction
{
public:
    CastWarStompAction(ShadowAI* botAI) : CastMeleeSpellAction(botAI, "war stomp") {}
};

class CastBloodFuryAction : public CastBuffSpellAction
{
public:
    CastBloodFuryAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "blood fury") {}
};

class CastBerserkingAction : public CastBuffSpellAction
{
public:
    CastBerserkingAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "berserking") {}
};

class UseTrinketAction : public Action
{
public:
    UseTrinketAction(ShadowAI* botAI) : Action(botAI, "use trinket") {}
    bool Execute(Event event) override;
protected:
    bool UseTrinket(Item* trinket);
};

class CastSpellOnEnemyHealerAction : public CastSpellAction
{
public:
    CastSpellOnEnemyHealerAction(ShadowAI* botAI, std::string const spell) : CastSpellAction(botAI, spell) {}

    Value<Unit*>* GetTargetValue() override;
    std::string const getName() override { return spell + " on enemy healer"; }
};

class CastSnareSpellAction : public CastDebuffSpellAction
{
public:
    CastSnareSpellAction(ShadowAI* botAI, std::string const spell) : CastDebuffSpellAction(botAI, spell) {}

    Value<Unit*>* GetTargetValue() override;
    std::string const getName() override { return spell + " on snare target"; }
    ActionThreatType getThreatType() override { return ActionThreatType::None; }
};

class CastCrowdControlSpellAction : public CastBuffSpellAction
{
public:
    CastCrowdControlSpellAction(ShadowAI* botAI, std::string const spell) : CastBuffSpellAction(botAI, spell) {}

    Value<Unit*>* GetTargetValue() override;
    bool Execute(Event event) override;
    bool isPossible() override;
    bool isUseful() override;
    ActionThreatType getThreatType() override { return ActionThreatType::None; }
};

class CastProtectSpellAction : public CastSpellAction
{
public:
    CastProtectSpellAction(ShadowAI* botAI, std::string const spell) : CastSpellAction(botAI, spell) {}

    std::string const GetTargetName() override;
    bool isUseful() override;
    ActionThreatType getThreatType() override { return ActionThreatType::None; }
};

class CastVehicleSpellAction : public CastSpellAction
{
public:
    CastVehicleSpellAction(ShadowAI* botAI, std::string const& spell) : CastSpellAction(botAI, spell)
    {
        range = 120.0f;
    }

    std::string const GetTargetName() override { return "current target"; }
    bool Execute(Event event) override;
    bool isUseful() override;
    bool isPossible() override;
    ActionThreatType getThreatType() override { return ActionThreatType::None; }

protected:
    WorldObject* spellTarget;
};

class CastHurlBoulderAction : public CastVehicleSpellAction
{
public:
    CastHurlBoulderAction(ShadowAI* botAI) : CastVehicleSpellAction(botAI, "hurl boulder") {}
};

class CastSteamRushAction : public CastVehicleSpellAction
{
public:
    CastSteamRushAction(ShadowAI* botAI) : CastVehicleSpellAction(botAI, "steam rush") {}
};

class CastRamAction : public CastVehicleSpellAction
{
public:
    CastRamAction(ShadowAI* botAI) : CastVehicleSpellAction(botAI, "ram") {}
};

class CastNapalmAction : public CastVehicleSpellAction
{
public:
    CastNapalmAction(ShadowAI* botAI) : CastVehicleSpellAction(botAI, "napalm") {}
};

class CastFireCannonAction : public CastVehicleSpellAction
{
public:
    CastFireCannonAction(ShadowAI* botAI) : CastVehicleSpellAction(botAI, "fire cannon") {}
};

class CastSteamBlastAction : public CastVehicleSpellAction
{
public:
    CastSteamBlastAction(ShadowAI* botAI) : CastVehicleSpellAction(botAI, "steam blast") {}
};

class CastIncendiaryRocketAction : public CastVehicleSpellAction
{
public:
    CastIncendiaryRocketAction(ShadowAI* botAI) : CastVehicleSpellAction(botAI, "incendiary rocket") {}
};

class CastRocketBlastAction : public CastVehicleSpellAction
{
public:
    CastRocketBlastAction(ShadowAI* botAI) : CastVehicleSpellAction(botAI, "rocket blast") {}
};

class CastGlaiveThrowAction : public CastVehicleSpellAction
{
public:
    CastGlaiveThrowAction(ShadowAI* botAI) : CastVehicleSpellAction(botAI, "glaive throw") {}
};

class CastBladeSalvoAction : public CastVehicleSpellAction
{
public:
    CastBladeSalvoAction(ShadowAI* botAI) : CastVehicleSpellAction(botAI, "blade salvo") {}
};

class MainTankActionNameSupport
{
public:
    MainTankActionNameSupport(std::string spell) { name = std::string(spell) + " on main tank"; }

    virtual std::string const getName() { return name; }

private:
    std::string name;
};

class BuffOnMainTankAction : public CastBuffSpellAction, public MainTankActionNameSupport
{
public:
    BuffOnMainTankAction(ShadowAI* ai, std::string spell, bool checkIsOwner = false)
        : CastBuffSpellAction(ai, spell, checkIsOwner), MainTankActionNameSupport(spell)
    {
    }

public:
    virtual Value<Unit*>* GetTargetValue();
    virtual std::string const getName() { return MainTankActionNameSupport::getName(); }
};
#endif
