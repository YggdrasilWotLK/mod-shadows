/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_SHAMANACTIONS_H
#define _SHADOW_SHAMANACTIONS_H

#include "GenericSpellActions.h"
#include "Shadows.h"
#include "SharedDefines.h"
#include "TotemsShamanStrategy.h"

class ShadowAI;

// Buff and Out of Combat Actions

class CastWaterShieldAction : public CastBuffSpellAction
{
public:
    CastWaterShieldAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "water shield") {}
};

class CastLightningShieldAction : public CastBuffSpellAction
{
public:
    CastLightningShieldAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "lightning shield") {}
};

class CastEarthlivingWeaponAction : public CastEnchantItemAction
{
public:
    CastEarthlivingWeaponAction(ShadowAI* botAI) : CastEnchantItemAction(botAI, "earthliving weapon") {}
};

class CastRockbiterWeaponAction : public CastEnchantItemAction
{
public:
    CastRockbiterWeaponAction(ShadowAI* botAI) : CastEnchantItemAction(botAI, "rockbiter weapon") {}
};

class CastFlametongueWeaponAction : public CastEnchantItemAction
{
public:
    CastFlametongueWeaponAction(ShadowAI* botAI) : CastEnchantItemAction(botAI, "flametongue weapon") {}
};

class CastFrostbrandWeaponAction : public CastEnchantItemAction
{
public:
    CastFrostbrandWeaponAction(ShadowAI* botAI) : CastEnchantItemAction(botAI, "frostbrand weapon") {}
};

class CastWindfuryWeaponAction : public CastEnchantItemAction
{
public:
    CastWindfuryWeaponAction(ShadowAI* botAI) : CastEnchantItemAction(botAI, "windfury weapon") {}
};

class CastAncestralSpiritAction : public ResurrectPartyMemberAction
{
public:
    CastAncestralSpiritAction(ShadowAI* botAI) : ResurrectPartyMemberAction(botAI, "ancestral spirit") {}
};

class CastWaterBreathingAction : public CastBuffSpellAction
{
public:
    CastWaterBreathingAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "water breathing") {}
};

class CastWaterWalkingAction : public CastBuffSpellAction
{
public:
    CastWaterWalkingAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "water walking") {}
};

class CastWaterBreathingOnPartyAction : public BuffOnPartyAction
{
public:
    CastWaterBreathingOnPartyAction(ShadowAI* botAI) : BuffOnPartyAction(botAI, "water breathing") {}
};

class CastWaterWalkingOnPartyAction : public BuffOnPartyAction
{
public:
    CastWaterWalkingOnPartyAction(ShadowAI* botAI) : BuffOnPartyAction(botAI, "water walking") {}
};

// Boost Actions

class CastHeroismAction : public CastBuffSpellAction
{
public:
    CastHeroismAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "heroism") {}
};

class CastBloodlustAction : public CastBuffSpellAction
{
public:
    CastBloodlustAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "bloodlust") {}
};

class CastElementalMasteryAction : public CastBuffSpellAction
{
public:
    CastElementalMasteryAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "elemental mastery") {}
};

class CastShamanisticRageAction : public CastBuffSpellAction
{
public:
    CastShamanisticRageAction(ShadowAI* ai) : CastBuffSpellAction(ai, "shamanistic rage") {}
};

class CastFeralSpiritAction : public CastSpellAction
{
public:
    CastFeralSpiritAction(ShadowAI* ai) : CastSpellAction(ai, "feral spirit") {}
};

class CastSpiritWalkAction : public Action
{
public:
    CastSpiritWalkAction(ShadowAI* botAI) : Action(botAI, "spirit walk") {}

    bool Execute(Event event) override;
};

// CC, Interrupt, and Dispel Actions

class CastWindShearAction : public CastSpellAction
{
public:
    CastWindShearAction(ShadowAI* botAI) : CastSpellAction(botAI, "wind shear") {}
};

class CastWindShearOnEnemyHealerAction : public CastSpellOnEnemyHealerAction
{
public:
    CastWindShearOnEnemyHealerAction(ShadowAI* botAI) : CastSpellOnEnemyHealerAction(botAI, "wind shear") {}
};

class CastPurgeAction : public CastSpellAction
{
public:
    CastPurgeAction(ShadowAI* botAI) : CastSpellAction(botAI, "purge") {}
};

class CastCleanseSpiritAction : public CastCureSpellAction
{
public:
    CastCleanseSpiritAction(ShadowAI* botAI) : CastCureSpellAction(botAI, "cleanse spirit") {}
};

class CastCleanseSpiritPoisonOnPartyAction : public CurePartyMemberAction
{
public:
    CastCleanseSpiritPoisonOnPartyAction(ShadowAI* botAI)
        : CurePartyMemberAction(botAI, "cleanse spirit", DISPEL_POISON)
    {
    }

    std::string const getName() override { return "cleanse spirit poison on party"; }
};

class CastCleanseSpiritCurseOnPartyAction : public CurePartyMemberAction
{
public:
    CastCleanseSpiritCurseOnPartyAction(ShadowAI* botAI)
        : CurePartyMemberAction(botAI, "cleanse spirit", DISPEL_CURSE)
    {
    }

    std::string const getName() override { return "cleanse spirit curse on party"; }
};

class CastCleanseSpiritDiseaseOnPartyAction : public CurePartyMemberAction
{
public:
    CastCleanseSpiritDiseaseOnPartyAction(ShadowAI* botAI)
        : CurePartyMemberAction(botAI, "cleanse spirit", DISPEL_DISEASE)
    {
    }

    std::string const getName() override { return "cleanse spirit disease on party"; }
};

class CastCurePoisonActionSham : public CastCureSpellAction
{
public:
    CastCurePoisonActionSham(ShadowAI* botAI) : CastCureSpellAction(botAI, "cure poison") {}
};

class CastCurePoisonOnPartyActionSham : public CurePartyMemberAction
{
public:
    CastCurePoisonOnPartyActionSham(ShadowAI* botAI) : CurePartyMemberAction(botAI, "cure poison", DISPEL_POISON) {}

    std::string const getName() override { return "cure poison on party"; }
};

class CastCureDiseaseActionSham : public CastCureSpellAction
{
public:
    CastCureDiseaseActionSham(ShadowAI* botAI) : CastCureSpellAction(botAI, "cure disease") {}
};

class CastCureDiseaseOnPartyActionSham : public CurePartyMemberAction
{
public:
    CastCureDiseaseOnPartyActionSham(ShadowAI* botAI) : CurePartyMemberAction(botAI, "cure disease", DISPEL_DISEASE)
    {
    }

    std::string const getName() override { return "cure disease on party"; }
};

// Damage and Debuff Actions

class CastFireNovaAction : public CastMeleeSpellAction
{
public:
    CastFireNovaAction(ShadowAI* botAI) : CastMeleeSpellAction(botAI, "fire nova") {}
    bool isUseful() override;
};

class CastStormstrikeAction : public CastMeleeSpellAction
{
public:
    CastStormstrikeAction(ShadowAI* botAI) : CastMeleeSpellAction(botAI, "stormstrike") {}
};

class CastLavaLashAction : public CastMeleeSpellAction
{
public:
    CastLavaLashAction(ShadowAI* botAI) : CastMeleeSpellAction(botAI, "lava lash") {}
};

class CastFlameShockAction : public CastDebuffSpellAction
{
public:
    CastFlameShockAction(ShadowAI* botAI) : CastDebuffSpellAction(botAI, "flame shock", true, 6.0f) {}
    bool isUseful() override
    {
        // Bypass TTL check
        return CastAuraSpellAction::isUseful();
    }
};

class CastEarthShockAction : public CastSpellAction
{
public:
    CastEarthShockAction(ShadowAI* botAI) : CastSpellAction(botAI, "earth shock") {}
};

class CastFrostShockAction : public CastSnareSpellAction
{
public:
    CastFrostShockAction(ShadowAI* botAI) : CastSnareSpellAction(botAI, "frost shock") {}
};

class CastChainLightningAction : public CastSpellAction
{
public:
    CastChainLightningAction(ShadowAI* botAI) : CastSpellAction(botAI, "chain lightning") {}
    ActionThreatType getThreatType() override { return ActionThreatType::Aoe; }
};

class CastLightningBoltAction : public CastSpellAction
{
public:
    CastLightningBoltAction(ShadowAI* botAI) : CastSpellAction(botAI, "lightning bolt") {}
};

class CastThunderstormAction : public CastSpellAction
{
public:
    CastThunderstormAction(ShadowAI* botAI) : CastSpellAction(botAI, "thunderstorm") {}
};

class CastLavaBurstAction : public CastSpellAction
{
public:
    CastLavaBurstAction(ShadowAI* ai) : CastSpellAction(ai, "lava burst") {}
    bool isUseful() override;
};


// Healing Actions

class CastLesserHealingWaveAction : public CastHealingSpellAction
{
public:
    CastLesserHealingWaveAction(ShadowAI* botAI) : CastHealingSpellAction(botAI, "lesser healing wave") {}
};

class CastLesserHealingWaveOnPartyAction : public HealPartyMemberAction
{
public:
    CastLesserHealingWaveOnPartyAction(ShadowAI* botAI)
        : HealPartyMemberAction(botAI, "lesser healing wave", 25.0f, HealingManaEfficiency::LOW)
    {
    }
};

class CastHealingWaveAction : public CastHealingSpellAction
{
public:
    CastHealingWaveAction(ShadowAI* botAI) : CastHealingSpellAction(botAI, "healing wave") {}
};

class CastHealingWaveOnPartyAction : public HealPartyMemberAction
{
public:
    CastHealingWaveOnPartyAction(ShadowAI* botAI)
        : HealPartyMemberAction(botAI, "healing wave", 50.0f, HealingManaEfficiency::MEDIUM)
    {
    }
};

class CastChainHealAction : public HealPartyMemberAction
{
public:
    CastChainHealAction(ShadowAI* botAI)
        : HealPartyMemberAction(botAI, "chain heal", 15.0f, HealingManaEfficiency::HIGH)
    {
    }
};

class CastRiptideAction : public CastHealingSpellAction
{
public:
    CastRiptideAction(ShadowAI* botAI) : CastHealingSpellAction(botAI, "riptide") {}
};

class CastRiptideOnPartyAction : public HealPartyMemberAction
{
public:
    CastRiptideOnPartyAction(ShadowAI* botAI)
        : HealPartyMemberAction(botAI, "riptide", 15.0f, HealingManaEfficiency::VERY_HIGH)
    {
    }
};

class CastEarthShieldAction : public CastBuffSpellAction
{
public:
    CastEarthShieldAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "earth shield") {}
};

class CastEarthShieldOnPartyAction : public BuffOnPartyAction
{
public:
    CastEarthShieldOnPartyAction(ShadowAI* botAI) : BuffOnPartyAction(botAI, "earth shield") {}
};

class CastEarthShieldOnMainTankAction : public BuffOnMainTankAction
{
public:
    CastEarthShieldOnMainTankAction(ShadowAI* ai) : BuffOnMainTankAction(ai, "earth shield", false) {}
};

// Totem Spells

class CastTotemAction : public CastBuffSpellAction
{
public:
    CastTotemAction(ShadowAI* botAI, std::string const spell, std::string const buffName = "")
        : CastBuffSpellAction(botAI, spell)
    {
        buff = (buffName == "") ? spell : buffName;
    }

    bool isUseful() override;

protected:
    std::string buff;
};

class CastCallOfTheElementsAction : public CastSpellAction
{
public:
    CastCallOfTheElementsAction(ShadowAI* ai) : CastSpellAction(ai, "call of the elements") {}
};

class CastTotemicRecallAction : public CastSpellAction
{
public:
    CastTotemicRecallAction(ShadowAI* ai) : CastSpellAction(ai, "totemic recall") {}
};

class CastStrengthOfEarthTotemAction : public CastTotemAction
{
public:
    CastStrengthOfEarthTotemAction(ShadowAI* botAI) : CastTotemAction(botAI, "strength of earth totem", "strength of earth") {}
};

class CastStoneskinTotemAction : public CastTotemAction
{
public:
    CastStoneskinTotemAction(ShadowAI* botAI) : CastTotemAction(botAI, "stoneskin totem", "stoneskin") {}
};

class CastTremorTotemAction : public CastTotemAction
{
public:
    CastTremorTotemAction(ShadowAI* botAI) : CastTotemAction(botAI, "tremor totem", "") {}
};

class CastEarthbindTotemAction : public CastTotemAction
{
public:
    CastEarthbindTotemAction(ShadowAI* botAI) : CastTotemAction(botAI, "earthbind totem", "") {}
};

class CastStoneclawTotemAction : public CastTotemAction
{
public:
    CastStoneclawTotemAction(ShadowAI* botAI) : CastTotemAction(botAI, "stoneclaw totem", "") {}
    bool isUseful() override;
};

class CastSearingTotemAction : public CastTotemAction
{
public:
    CastSearingTotemAction(ShadowAI* botAI) : CastTotemAction(botAI, "searing totem", "") {}
};

class CastMagmaTotemAction : public CastTotemAction
{
public:
    CastMagmaTotemAction(ShadowAI* botAI) : CastTotemAction(botAI, "magma totem", "") {}
    std::string const GetTargetName() override { return "self target"; }
    bool isUseful() override;
};

class CastFlametongueTotemAction : public CastTotemAction
{
public:
    CastFlametongueTotemAction(ShadowAI* botAI) : CastTotemAction(botAI, "flametongue totem", "flametongue totem") {}
};

class CastTotemOfWrathAction : public CastTotemAction
{
public:
    CastTotemOfWrathAction(ShadowAI* botAI) : CastTotemAction(botAI, "totem of wrath", "totem of wrath") {}
};

class CastFrostResistanceTotemAction : public CastTotemAction
{
public:
    CastFrostResistanceTotemAction(ShadowAI* botAI)
        : CastTotemAction(botAI, "frost resistance totem", "frost resistance") {}
};

class CastFireElementalTotemAction : public CastTotemAction
{
public:
    CastFireElementalTotemAction(ShadowAI* ai) : CastTotemAction(ai, "fire elemental totem", "") {}
    virtual std::string const GetTargetName() override { return "self target"; }
    virtual bool isUseful() override { return CastTotemAction::isUseful(); }
};

class CastFireElementalTotemMeleeAction : public CastTotemAction
{
public:
    CastFireElementalTotemMeleeAction(ShadowAI* ai) : CastTotemAction(ai, "fire elemental totem", "") {}
    virtual std::string const GetTargetName() override { return "self target"; }
    virtual bool isUseful() override
    {
        Unit* target = AI_VALUE(Unit*, "current target");
        if (!target || !bot->IsWithinMeleeRange(target))
            return false;
        return CastTotemAction::isUseful();
    }
};

class CastHealingStreamTotemAction : public CastTotemAction
{
public:
    CastHealingStreamTotemAction(ShadowAI* botAI) : CastTotemAction(botAI, "healing stream totem", "") {}
};

class CastManaSpringTotemAction : public CastTotemAction
{
public:
    CastManaSpringTotemAction(ShadowAI* botAI) : CastTotemAction(botAI, "mana spring totem", "mana spring") {}
};

class CastCleansingTotemAction : public CastTotemAction
{
public:
    CastCleansingTotemAction(ShadowAI* botAI) : CastTotemAction(botAI, "cleansing totem", "") {}
    virtual bool isUseful();
};

class CastManaTideTotemAction : public CastTotemAction
{
public:
    CastManaTideTotemAction(ShadowAI* botAI) : CastTotemAction(botAI, "mana tide totem", "") {}
    std::string const GetTargetName() override { return "self target"; }
};

class CastFireResistanceTotemAction : public CastTotemAction
{
public:
    CastFireResistanceTotemAction(ShadowAI* botAI) : CastTotemAction(botAI, "fire resistance totem", "fire resistance") {}
};

class CastWrathOfAirTotemAction : public CastTotemAction
{
public:
    CastWrathOfAirTotemAction(ShadowAI* ai) : CastTotemAction(ai, "wrath of air totem", "wrath of air totem") {}
};

class CastWindfuryTotemAction : public CastTotemAction
{
public:
    CastWindfuryTotemAction(ShadowAI* botAI) : CastTotemAction(botAI, "windfury totem", "windfury totem") {}
};

class CastNatureResistanceTotemAction : public CastTotemAction
{
public:
    CastNatureResistanceTotemAction(ShadowAI* botAI) : CastTotemAction(botAI, "nature resistance totem", "nature resistance") {}
};

// Set Strategy Assigned Totems

class SetTotemAction : public Action
{
public:
    // Template constructor: infers N (size of the id array) at compile time
    template <size_t N>
    SetTotemAction(ShadowAI* botAI, std::string const& totemName, const uint32 (&ids)[N], int actionButtonId)
        : Action(botAI, "set " + totemName)
        , totemSpellIds(ids)
        , totemSpellIdsCount(N)
        , actionButtonId(actionButtonId)
    {}

    bool Execute(Event event) override;
    uint32 const* totemSpellIds;
    size_t totemSpellIdsCount;
    int actionButtonId;
};

class SetStrengthOfEarthTotemAction : public SetTotemAction
{
public:
    SetStrengthOfEarthTotemAction(ShadowAI* ai)
        : SetTotemAction(ai, "strength of earth totem", STRENGTH_OF_EARTH_TOTEM, TOTEM_BAR_SLOT_EARTH) {}
};

class SetStoneskinTotemAction : public SetTotemAction
{
public:
    SetStoneskinTotemAction(ShadowAI* ai)
        : SetTotemAction(ai, "stoneskin totem", STONESKIN_TOTEM, TOTEM_BAR_SLOT_EARTH) {}
};

class SetTremorTotemAction : public SetTotemAction
{
public:
    SetTremorTotemAction(ShadowAI* ai)
        : SetTotemAction(ai, "tremor totem", TREMOR_TOTEM, TOTEM_BAR_SLOT_EARTH) {}
};

class SetEarthbindTotemAction : public SetTotemAction
{
public:
    SetEarthbindTotemAction(ShadowAI* ai)
        : SetTotemAction(ai, "earthbind totem", EARTHBIND_TOTEM, TOTEM_BAR_SLOT_EARTH) {}
};

class SetSearingTotemAction : public SetTotemAction
{
public:
    SetSearingTotemAction(ShadowAI* ai)
        : SetTotemAction(ai, "searing totem", SEARING_TOTEM, TOTEM_BAR_SLOT_FIRE) {}
};

class SetMagmaTotemAction : public SetTotemAction
{
public:
    SetMagmaTotemAction(ShadowAI* ai)
        : SetTotemAction(ai, "magma totem", MAGMA_TOTEM, TOTEM_BAR_SLOT_FIRE) {}
};

class SetFlametongueTotemAction : public SetTotemAction
{
public:
    SetFlametongueTotemAction(ShadowAI* ai)
        : SetTotemAction(ai, "flametongue totem", FLAMETONGUE_TOTEM, TOTEM_BAR_SLOT_FIRE) {}
};

class SetTotemOfWrathAction : public SetTotemAction
{
public:
    SetTotemOfWrathAction(ShadowAI* ai)
        : SetTotemAction(ai, "totem of wrath", TOTEM_OF_WRATH, TOTEM_BAR_SLOT_FIRE) {}
};

class SetFrostResistanceTotemAction : public SetTotemAction
{
public:
    SetFrostResistanceTotemAction(ShadowAI* ai)
        : SetTotemAction(ai, "frost resistance totem", FROST_RESISTANCE_TOTEM, TOTEM_BAR_SLOT_FIRE) {}
};

class SetHealingStreamTotemAction : public SetTotemAction
{
public:
    SetHealingStreamTotemAction(ShadowAI* ai)
        : SetTotemAction(ai, "healing stream totem", HEALING_STREAM_TOTEM, TOTEM_BAR_SLOT_WATER) {}
};

class SetManaSpringTotemAction : public SetTotemAction
{
public:
    SetManaSpringTotemAction(ShadowAI* ai)
        : SetTotemAction(ai, "mana spring totem", MANA_SPRING_TOTEM, TOTEM_BAR_SLOT_WATER) {}
};

class SetCleansingTotemAction : public SetTotemAction
{
public:
    SetCleansingTotemAction(ShadowAI* ai)
        : SetTotemAction(ai, "cleansing totem", CLEANSING_TOTEM, TOTEM_BAR_SLOT_WATER) {}
};

class SetFireResistanceTotemAction : public SetTotemAction
{
public:
    SetFireResistanceTotemAction(ShadowAI* ai)
        : SetTotemAction(ai, "fire resistance totem", FIRE_RESISTANCE_TOTEM, TOTEM_BAR_SLOT_WATER) {}
};

class SetWrathOfAirTotemAction : public SetTotemAction
{
public:
    SetWrathOfAirTotemAction(ShadowAI* ai)
        : SetTotemAction(ai, "wrath of air totem", WRATH_OF_AIR_TOTEM, TOTEM_BAR_SLOT_AIR) {}
};

class SetWindfuryTotemAction : public SetTotemAction
{
public:
    SetWindfuryTotemAction(ShadowAI* ai)
        : SetTotemAction(ai, "windfury totem", WINDFURY_TOTEM, TOTEM_BAR_SLOT_AIR) {}
};

class SetNatureResistanceTotemAction : public SetTotemAction
{
public:
    SetNatureResistanceTotemAction(ShadowAI* ai)
        : SetTotemAction(ai, "nature resistance totem", NATURE_RESISTANCE_TOTEM, TOTEM_BAR_SLOT_AIR) {}
};

class SetGroundingTotemAction : public SetTotemAction
{
public:
    SetGroundingTotemAction(ShadowAI* ai)
        : SetTotemAction(ai, "grounding totem", GROUNDING_TOTEM, TOTEM_BAR_SLOT_AIR) {}
};

#endif
