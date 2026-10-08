/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_WARLOCKACTIONS_H
#define _SHADOW_WARLOCKACTIONS_H

#include "GenericSpellActions.h"
#include "UseItemAction.h"
#include "InventoryAction.h"
#include "Action.h"

class ShadowAI;
class Unit;

// Buff and Out of Combat Spells

class CastDemonSkinAction : public CastBuffSpellAction
{
public:
    CastDemonSkinAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "demon skin") {}
};

class CastDemonArmorAction : public CastBuffSpellAction
{
public:
    CastDemonArmorAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "demon armor") {}
};

class CastFelArmorAction : public CastBuffSpellAction
{
public:
    CastFelArmorAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "fel armor") {}
};

class CastSoulLinkAction : public CastBuffSpellAction
{
public:
    CastSoulLinkAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "soul link", false, 5000) {}
    std::string const GetTargetName() override { return "pet target"; }
};

class CreateSoulShardAction : public Action
{
public:
    CreateSoulShardAction(ShadowAI* botAI) : Action(botAI, "create soul shard") {}
    bool Execute(Event event) override;
    bool isUseful() override;
};

class DestroySoulShardAction : public InventoryAction
{
public:
    DestroySoulShardAction(ShadowAI* botAI) : InventoryAction(botAI, "destroy soul shard") {}

    bool Execute(Event event) override;
};

class CastCreateHealthstoneAction : public CastBuffSpellAction
{
public:
    CastCreateHealthstoneAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "create healthstone") {}
};

class CastCreateFirestoneAction : public CastBuffSpellAction
{
public:
    CastCreateFirestoneAction(ShadowAI* botAI);
    bool Execute(Event event) override;
    bool isUseful() override;

private:
    static const std::vector<uint32> firestoneSpellIds;
};

class CastCreateSpellstoneAction : public CastBuffSpellAction
{
public:
    CastCreateSpellstoneAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "create spellstone") {}
};

class CastCreateSoulstoneAction : public CastBuffSpellAction
{
public:
    CastCreateSoulstoneAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "create soulstone") {}
    bool isUseful() override;
};

class UseSoulstoneSelfAction : public UseSpellItemAction
{
public:
    UseSoulstoneSelfAction(ShadowAI* botAI) : UseSpellItemAction(botAI, "soulstone") {}
    bool Execute(Event event) override;
};

class UseSoulstoneMasterAction : public UseSpellItemAction
{
public:
    UseSoulstoneMasterAction(ShadowAI* botAI) : UseSpellItemAction(botAI, "soulstone") {}
    bool Execute(Event event) override;
};

class UseSoulstoneTankAction : public UseSpellItemAction
{
public:
    UseSoulstoneTankAction(ShadowAI* botAI) : UseSpellItemAction(botAI, "soulstone") {}
    bool Execute(Event event) override;
};

class UseSoulstoneHealerAction : public UseSpellItemAction
{
public:
    UseSoulstoneHealerAction(ShadowAI* botAI) : UseSpellItemAction(botAI, "soulstone") {}
    bool Execute(Event event) override;
};

// Summoning Spells

class CastSummonVoidwalkerAction : public CastBuffSpellAction
{
public:
    CastSummonVoidwalkerAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "summon voidwalker") {}
};

class CastSummonFelguardAction : public CastBuffSpellAction
{
public:
    CastSummonFelguardAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "summon felguard") {}
};

class CastSummonFelhunterAction : public CastBuffSpellAction
{
public:
    CastSummonFelhunterAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "summon felhunter") {}
};

class CastSummonImpAction : public CastBuffSpellAction
{
public:
    CastSummonImpAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "summon imp") {}
};

class CastSummonSuccubusAction : public CastBuffSpellAction
{
public:
    CastSummonSuccubusAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "summon succubus") {}
};
class CastFelDominationAction : public CastBuffSpellAction
{
public:
    CastFelDominationAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "fel domination") {}
};

// CC and Pet Spells

class CastBanishOnCcAction : public CastCrowdControlSpellAction
{
public:
    CastBanishOnCcAction(ShadowAI* botAI) : CastCrowdControlSpellAction(botAI, "banish") {}
    bool isPossible() override;
};

class CastFearOnCcAction : public CastCrowdControlSpellAction
{
public:
    CastFearOnCcAction(ShadowAI* botAI) : CastCrowdControlSpellAction(botAI, "fear") {}
    bool isPossible() override;
};

class CastSpellLockAction : public CastSpellAction
{
public:
    CastSpellLockAction(ShadowAI* botAI) : CastSpellAction(botAI, "spell lock") {}
};

class CastDevourMagicPurgeAction : public CastSpellAction
{
public:
    CastDevourMagicPurgeAction(ShadowAI* botAI) : CastSpellAction(botAI, "devour magic") {}

    std::string const GetTargetName() override { return "current target"; }
};

class CastDevourMagicCleanseAction : public CastSpellAction
{
public:
    CastDevourMagicCleanseAction(ShadowAI* botAI) : CastSpellAction(botAI, "devour magic cleanse") {}
    std::string const getName() override { return "cleanse magic on party"; }
};

// Utility Spells

class CastShadowWardAction : public CastBuffSpellAction
{
public:
    CastShadowWardAction(ShadowAI* ai) : CastBuffSpellAction(ai, "shadow ward") {}
};

class CastSoulshatterAction : public CastSpellAction
{
public:
    CastSoulshatterAction(ShadowAI* ai) : CastSpellAction(ai, "soulshatter") {}
    bool isUseful() override;
};

class CastLifeTapAction : public CastSpellAction
{
public:
    CastLifeTapAction(ShadowAI* botAI) : CastSpellAction(botAI, "life tap") {}

    std::string const GetTargetName() override { return "self target"; }
    bool isUseful() override;
};

class DemonChargeAction : public CastSpellAction
{
public:
    DemonChargeAction(ShadowAI* ai) : CastSpellAction(ai, "demon charge") {}
};

// Cooldown Spells

class CastMetamorphosisAction : public CastBuffSpellAction
{
public:
    CastMetamorphosisAction(ShadowAI* ai) : CastBuffSpellAction(ai, "metamorphosis") {}
};

class CastDemonicEmpowermentAction : public CastBuffSpellAction
{
public:
    CastDemonicEmpowermentAction(ShadowAI* ai) : CastBuffSpellAction(ai, "demonic empowerment") {}
    std::string const GetTargetName() override { return "pet target"; }
};

// DoT/Curse Spells

class CastCorruptionAction : public CastDebuffSpellAction
{
public:
    CastCorruptionAction(ShadowAI* botAI) : CastDebuffSpellAction(botAI, "corruption", true) {}
    bool isUseful() override
    {
        // Bypass TTL check and prevent casting if Seed of Corruption is present
        return CastAuraSpellAction::isUseful() && !botAI->HasAura("seed of corruption", GetTarget(), false, true);
    }
};

class CastCorruptionOnAttackerAction : public CastDebuffSpellOnAttackerAction
{
public:
    CastCorruptionOnAttackerAction(ShadowAI* botAI) : CastDebuffSpellOnAttackerAction(botAI, "corruption", true) {}
    bool isUseful() override
    {
        // Bypass TTL check and prevent casting if Seed of Corruption is present
        return CastAuraSpellAction::isUseful() && !botAI->HasAura("seed of corruption", GetTarget(), false, true);
    }
};

class CastImmolateAction : public CastDebuffSpellAction
{
public:
    CastImmolateAction(ShadowAI* botAI) : CastDebuffSpellAction(botAI, "immolate", true) {}
    bool isUseful() override
    {
        // Bypass TTL check
        return CastAuraSpellAction::isUseful();
    }
};

class CastImmolateOnAttackerAction : public CastDebuffSpellOnAttackerAction
{
public:
    CastImmolateOnAttackerAction(ShadowAI* botAI) : CastDebuffSpellOnAttackerAction(botAI, "immolate", true) {}
    bool isUseful() override
    {
        // Bypass TTL check
        return CastAuraSpellAction::isUseful();
    }
};

class CastUnstableAfflictionAction : public CastDebuffSpellAction
{
public:
    CastUnstableAfflictionAction(ShadowAI* ai) : CastDebuffSpellAction(ai, "unstable affliction", true) {}
    bool isUseful() override
    {
        // Bypass TTL check
        return CastAuraSpellAction::isUseful();
    }
};

class CastUnstableAfflictionOnAttackerAction : public CastDebuffSpellOnAttackerAction
{
public:
    CastUnstableAfflictionOnAttackerAction(ShadowAI* ai)
        : CastDebuffSpellOnAttackerAction(ai, "unstable affliction", true)
    {
    }
    bool isUseful() override
    {
        // Bypass TTL check
        return CastAuraSpellAction::isUseful();
    }
};

class CastCurseOfAgonyAction : public CastDebuffSpellAction
{
public:
    CastCurseOfAgonyAction(ShadowAI* botAI) : CastDebuffSpellAction(botAI, "curse of agony", true) {}
    bool isUseful() override
    {
        // Bypass TTL check
        return CastAuraSpellAction::isUseful();
    }
};

class CastCurseOfAgonyOnAttackerAction : public CastDebuffSpellOnAttackerAction
{
public:
    CastCurseOfAgonyOnAttackerAction(ShadowAI* botAI)
        : CastDebuffSpellOnAttackerAction(botAI, "curse of agony", true)
    {
    }
    bool isUseful() override
    {
        // Bypass TTL check
        return CastAuraSpellAction::isUseful();
    }
};

class CastCurseOfTheElementsAction : public CastDebuffSpellAction
{
public:
    CastCurseOfTheElementsAction(ShadowAI* ai) : CastDebuffSpellAction(ai, "curse of the elements", true) {}
    bool isUseful() override
    {
        // Bypass TTL check
        return CastAuraSpellAction::isUseful();
    }
};

class CastCurseOfDoomAction : public CastDebuffSpellAction
{
public:
    CastCurseOfDoomAction(ShadowAI* botAI) : CastDebuffSpellAction(botAI, "curse of doom", true, 0) {}
    bool isUseful() override
    {
        // Bypass TTL check
        return CastAuraSpellAction::isUseful();
    }
};

class CastCurseOfExhaustionAction : public CastDebuffSpellAction
{
public:
    CastCurseOfExhaustionAction(ShadowAI* botAI) : CastDebuffSpellAction(botAI, "curse of exhaustion") {}
    bool isUseful() override
    {
        // Bypass TTL check
        return CastAuraSpellAction::isUseful();
    }
};

class CastCurseOfTonguesAction : public CastDebuffSpellAction
{
public:
    CastCurseOfTonguesAction(ShadowAI* botAI) : CastDebuffSpellAction(botAI, "curse of tongues") {}
    bool isUseful() override
    {
        // Bypass TTL check
        return CastAuraSpellAction::isUseful();
    }
};

class CastCurseOfWeaknessAction : public CastDebuffSpellAction
{
public:
    CastCurseOfWeaknessAction(ShadowAI* botAI) : CastDebuffSpellAction(botAI, "curse of weakness") {}
    bool isUseful() override
    {
        // Bypass TTL check
        return CastAuraSpellAction::isUseful();
    }
};

// Damage Spells

class CastShadowBoltAction : public CastSpellAction
{
public:
    CastShadowBoltAction(ShadowAI* botAI) : CastSpellAction(botAI, "shadow bolt") {}
};

class CastDrainSoulAction : public CastSpellAction
{
public:
    CastDrainSoulAction(ShadowAI* botAI) : CastSpellAction(botAI, "drain soul") {}

    bool isUseful() override;
};

class CastDrainManaAction : public CastSpellAction
{
public:
    CastDrainManaAction(ShadowAI* botAI) : CastSpellAction(botAI, "drain mana") {}
};

class CastDrainLifeAction : public CastSpellAction
{
public:
    CastDrainLifeAction(ShadowAI* botAI) : CastSpellAction(botAI, "drain life") {}
};

class CastConflagrateAction : public CastSpellAction
{
public:
    CastConflagrateAction(ShadowAI* botAI) : CastSpellAction(botAI, "conflagrate") {}
};

class CastIncinerateAction : public CastSpellAction
{
public:
    CastIncinerateAction(ShadowAI* ai) : CastSpellAction(ai, "incinerate") {}
};

class CastHauntAction : public CastSpellAction
{
public:
    CastHauntAction(ShadowAI* ai) : CastSpellAction(ai, "haunt") {}
};

class CastSoulFireAction : public CastSpellAction
{
public:
    CastSoulFireAction(ShadowAI* ai) : CastSpellAction(ai, "soul fire") {}
};

class CastShadowburnAction : public CastSpellAction
{
public:
    CastShadowburnAction(ShadowAI* ai) : CastSpellAction(ai, "shadowburn") {}
};

class CastChaosBoltAction : public CastSpellAction
{
public:
    CastChaosBoltAction(ShadowAI* ai) : CastSpellAction(ai, "chaos bolt") {}
};

class CastSearingPainAction : public CastSpellAction
{
public:
    CastSearingPainAction(ShadowAI* botAI) : CastSpellAction(botAI, "searing pain") {}
};

// AoE Spells

class CastSeedOfCorruptionAction : public CastDebuffSpellAction
{
public:
    CastSeedOfCorruptionAction(ShadowAI* botAI) : CastDebuffSpellAction(botAI, "seed of corruption", true, 0) {}
    bool isUseful() override
    {
        // Bypass TTL check
        return CastAuraSpellAction::isUseful();
    }
    ActionThreatType getThreatType() override { return ActionThreatType::Aoe; }
};

class CastSeedOfCorruptionOnAttackerAction : public CastDebuffSpellOnAttackerAction
{
public:
    CastSeedOfCorruptionOnAttackerAction(ShadowAI* botAI)
        : CastDebuffSpellOnAttackerAction(botAI, "seed of corruption", true, 0)
    {
    }
    bool isUseful() override
    {
        // Bypass TTL check
        return CastAuraSpellAction::isUseful();
    }
    ActionThreatType getThreatType() override { return ActionThreatType::Aoe; }
};

class CastRainOfFireAction : public CastSpellAction
{
public:
    CastRainOfFireAction(ShadowAI* botAI) : CastSpellAction(botAI, "rain of fire") {}
    ActionThreatType getThreatType() override { return ActionThreatType::Aoe; }
    bool isUseful() override;
};

class CastHellfireAction : public CastSpellAction
{
public:
    CastHellfireAction(ShadowAI* botAI) : CastSpellAction(botAI, "hellfire") {}
    ActionThreatType getThreatType() override { return ActionThreatType::Aoe; }
    bool isUseful() override;
};

class CastShadowflameAction : public CastSpellAction
{
public:
    CastShadowflameAction(ShadowAI* botAI) : CastSpellAction(botAI, "shadowflame") {}
    bool isUseful() override;
};

class CastShadowfuryAction : public CastSpellAction
{
public:
    CastShadowfuryAction(ShadowAI* botAI) : CastSpellAction(botAI, "shadowfury") {}
};

class CastImmolationAuraAction : public CastSpellAction
{
public:
    CastImmolationAuraAction(ShadowAI* botAI) : CastSpellAction(botAI, "immolation aura") {}
    ActionThreatType getThreatType() override { return ActionThreatType::Aoe; }
    bool isUseful() override;
};

class ShadowCleaveAction : public CastMeleeSpellAction
{
public:
    ShadowCleaveAction(ShadowAI* ai) : CastMeleeSpellAction(ai, "shadow cleave") {}
};
#endif
