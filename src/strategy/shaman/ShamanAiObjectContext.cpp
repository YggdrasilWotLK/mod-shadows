/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#include "ShamanAiObjectContext.h"

#include "ElementalShamanStrategy.h"
#include "GenericShamanStrategy.h"
#include "RestoShamanStrategy.h"
#include "EnhancementShamanStrategy.h"
#include "NamedObjectContext.h"
#include "Shadows.h"
#include "ShamanActions.h"
#include "ShamanNonCombatStrategy.h"
#include "ShamanTriggers.h"
#include "TotemsShamanStrategy.h"

class ShamanStrategyFactoryInternal : public NamedObjectContext<Strategy>
{
public:
    ShamanStrategyFactoryInternal()
    {
        creators["nc"] = &ShamanStrategyFactoryInternal::nc;
        creators["aoe"] = &ShamanStrategyFactoryInternal::aoe;
        creators["cure"] = &ShamanStrategyFactoryInternal::cure;
        creators["healer dps"] = &ShamanStrategyFactoryInternal::healer_dps;
        creators["boost"] = &ShamanStrategyFactoryInternal::boost;
    }

private:
    static Strategy* nc(ShadowAI* botAI) { return new ShamanNonCombatStrategy(botAI); }
    static Strategy* aoe(ShadowAI* botAI) { return new ShamanAoeStrategy(botAI); }
    static Strategy* cure(ShadowAI* botAI) { return new ShamanCureStrategy(botAI); }
    static Strategy* healer_dps(ShadowAI* botAI) { return new ShamanHealerDpsStrategy(botAI); }
    static Strategy* boost(ShadowAI* botAI) { return new ShamanBoostStrategy(botAI); }
};

class ShamanCombatStrategyFactoryInternal : public NamedObjectContext<Strategy>
{
public:
    ShamanCombatStrategyFactoryInternal() : NamedObjectContext<Strategy>(false, true)
    {
        creators["heal"] = &ShamanCombatStrategyFactoryInternal::resto;
        creators["melee"] = &ShamanCombatStrategyFactoryInternal::enh;
        creators["dps"] = &ShamanCombatStrategyFactoryInternal::enh;
        creators["caster"] = &ShamanCombatStrategyFactoryInternal::ele;
        //creators["offheal"] = &ShamanCombatStrategyFactoryInternal::offheal;
        creators["resto"] = &ShamanCombatStrategyFactoryInternal::resto;
        creators["enh"] = &ShamanCombatStrategyFactoryInternal::enh;
        creators["ele"] = &ShamanCombatStrategyFactoryInternal::ele;
    }

private:
    static Strategy* resto(ShadowAI* botAI) { return new RestoShamanStrategy(botAI); }
    static Strategy* enh(ShadowAI* botAI) { return new EnhancementShamanStrategy(botAI); }
    static Strategy* ele(ShadowAI* botAI) { return new ElementalShamanStrategy(botAI); }
};

class ShamanEarthTotemStrategyFactoryInternal : public NamedObjectContext<Strategy>
{
public:
    ShamanEarthTotemStrategyFactoryInternal() : NamedObjectContext<Strategy>(false, true)
    {
        creators["strength of earth"] = &ShamanEarthTotemStrategyFactoryInternal::strength_of_earth_totem;
        creators["stoneskin"] = &ShamanEarthTotemStrategyFactoryInternal::stoneclaw_totem;
        creators["tremor"] = &ShamanEarthTotemStrategyFactoryInternal::earth_totem;
        creators["earthbind"] = &ShamanEarthTotemStrategyFactoryInternal::earthbind_totem;
    }

private:
    static Strategy* strength_of_earth_totem(ShadowAI* botAI) { return new StrengthOfEarthTotemStrategy(botAI); }
    static Strategy* stoneclaw_totem(ShadowAI* botAI) { return new StoneclawTotemStrategy(botAI); }
    static Strategy* earth_totem(ShadowAI* botAI) { return new EarthTotemStrategy(botAI); }
    static Strategy* earthbind_totem(ShadowAI* botAI) { return new EarthbindTotemStrategy(botAI); }
};

class ShamanFireTotemStrategyFactoryInternal : public NamedObjectContext<Strategy>
{
public:
    ShamanFireTotemStrategyFactoryInternal() : NamedObjectContext<Strategy>(false, true)
    {
        creators["searing"] = &ShamanFireTotemStrategyFactoryInternal::searing_totem;
        creators["magma"] = &ShamanFireTotemStrategyFactoryInternal::magma_totem;
        creators["flametongue"] = &ShamanFireTotemStrategyFactoryInternal::flametongue_totem;
        creators["wrath"] = &ShamanFireTotemStrategyFactoryInternal::totem_of_wrath;
        creators["frost resistance"] = &ShamanFireTotemStrategyFactoryInternal::frost_resistance_totem;
    }

private:
    static Strategy* searing_totem(ShadowAI* botAI) { return new SearingTotemStrategy(botAI); }
    static Strategy* magma_totem(ShadowAI* botAI) { return new MagmaTotemStrategy(botAI); }
    static Strategy* flametongue_totem(ShadowAI* botAI) { return new FlametongueTotemStrategy(botAI); }
    static Strategy* totem_of_wrath(ShadowAI* botAI) { return new TotemOfWrathStrategy(botAI); }
    static Strategy* frost_resistance_totem(ShadowAI* botAI) { return new FrostResistanceTotemStrategy(botAI); }
};

class ShamanWaterTotemStrategyFactoryInternal : public NamedObjectContext<Strategy>
{
public:
    ShamanWaterTotemStrategyFactoryInternal() : NamedObjectContext<Strategy>(false, true)
    {
        creators["healing stream"] = &ShamanWaterTotemStrategyFactoryInternal::healing_stream_totem;
        creators["mana spring"] = &ShamanWaterTotemStrategyFactoryInternal::mana_spring_totem;
        creators["cleansing"] = &ShamanWaterTotemStrategyFactoryInternal::cleansing_totem;
        creators["fire resistance"] = &ShamanWaterTotemStrategyFactoryInternal::fire_resistance_totem;
    }

private:
    static Strategy* healing_stream_totem(ShadowAI* botAI) { return new HealingStreamTotemStrategy(botAI); }
    static Strategy* mana_spring_totem(ShadowAI* botAI) { return new ManaSpringTotemStrategy(botAI); }
    static Strategy* cleansing_totem(ShadowAI* botAI) { return new CleansingTotemStrategy(botAI); }
    static Strategy* fire_resistance_totem(ShadowAI* botAI) { return new FireResistanceTotemStrategy(botAI); }
};

class ShamanAirTotemStrategyFactoryInternal : public NamedObjectContext<Strategy>
{
public:
    ShamanAirTotemStrategyFactoryInternal() : NamedObjectContext<Strategy>(false, true)
    {
        creators["wrath of air"] = &ShamanAirTotemStrategyFactoryInternal::wrath_of_air_totem;
        creators["windfury"] = &ShamanAirTotemStrategyFactoryInternal::windfury_totem;
        creators["nature resistance"] = &ShamanAirTotemStrategyFactoryInternal::nature_resistance_totem;
        creators["grounding"] = &ShamanAirTotemStrategyFactoryInternal::grounding_totem;
    }

private:
    static Strategy* wrath_of_air_totem(ShadowAI* botAI) { return new WrathOfAirTotemStrategy(botAI); }
    static Strategy* windfury_totem(ShadowAI* botAI) { return new WindfuryTotemStrategy(botAI); }
    static Strategy* nature_resistance_totem(ShadowAI* botAI) { return new NatureResistanceTotemStrategy(botAI); }
    static Strategy* grounding_totem(ShadowAI* botAI) { return new GroundingTotemStrategy(botAI); }
};

class ShamanATriggerFactoryInternal : public NamedObjectContext<Trigger>
{
public:
    ShamanATriggerFactoryInternal()
    {
        creators["wind shear"] = &ShamanATriggerFactoryInternal::wind_shear;
        creators["purge"] = &ShamanATriggerFactoryInternal::purge;
        creators["main hand weapon no imbue"] = &ShamanATriggerFactoryInternal::main_hand_weapon_no_imbue;
        creators["off hand weapon no imbue"] = &ShamanATriggerFactoryInternal::off_hand_weapon_no_imbue;
        creators["water shield"] = &ShamanATriggerFactoryInternal::water_shield;
        creators["lightning shield"] = &ShamanATriggerFactoryInternal::lightning_shield;
        creators["water breathing"] = &ShamanATriggerFactoryInternal::water_breathing;
        creators["water walking"] = &ShamanATriggerFactoryInternal::water_walking;
        creators["water breathing on party"] = &ShamanATriggerFactoryInternal::water_breathing_on_party;
        creators["water walking on party"] = &ShamanATriggerFactoryInternal::water_walking_on_party;
        creators["cleanse spirit poison"] = &ShamanATriggerFactoryInternal::cleanse_poison;
        creators["cleanse spirit curse"] = &ShamanATriggerFactoryInternal::cleanse_curse;
        creators["cleanse spirit disease"] = &ShamanATriggerFactoryInternal::cleanse_disease;
        creators["party member cleanse spirit poison"] = &ShamanATriggerFactoryInternal::party_member_cleanse_poison;
        creators["party member cleanse spirit curse"] = &ShamanATriggerFactoryInternal::party_member_cleanse_curse;
        creators["party member cleanse spirit disease"] = &ShamanATriggerFactoryInternal::party_member_cleanse_disease;
        creators["shock"] = &ShamanATriggerFactoryInternal::shock;
        creators["frost shock snare"] = &ShamanATriggerFactoryInternal::frost_shock_snare;
        creators["heroism"] = &ShamanATriggerFactoryInternal::heroism;
        creators["bloodlust"] = &ShamanATriggerFactoryInternal::bloodlust;
        creators["elemental mastery"] = &ShamanATriggerFactoryInternal::elemental_mastery;
        creators["wind shear on enemy healer"] = &ShamanATriggerFactoryInternal::wind_shear_on_enemy_healer;
        creators["cure poison"] = &ShamanATriggerFactoryInternal::cure_poison;
        creators["party member cure poison"] = &ShamanATriggerFactoryInternal::party_member_cure_poison;
        creators["cure disease"] = &ShamanATriggerFactoryInternal::cure_disease;
        creators["party member cure disease"] = &ShamanATriggerFactoryInternal::party_member_cure_disease;
        creators["earth shield on main tank"] = &ShamanATriggerFactoryInternal::earth_shield_on_main_tank;
        creators["maelstrom weapon 3"] = &ShamanATriggerFactoryInternal::maelstrom_weapon_3;
        creators["maelstrom weapon 4"] = &ShamanATriggerFactoryInternal::maelstrom_weapon_4;
        creators["maelstrom weapon 5"] = &ShamanATriggerFactoryInternal::maelstrom_weapon_5;
        creators["flame shock"] = &ShamanATriggerFactoryInternal::flame_shock;
        creators["fire elemental totem"] = &ShamanATriggerFactoryInternal::fire_elemental_totem;
        creators["earth shock execute"] = &ShamanATriggerFactoryInternal::earth_shock_execute;
        creators["spirit walk ready"] = &ShamanATriggerFactoryInternal::spirit_walk_ready;
        creators["chain lightning no cd"] = &ShamanATriggerFactoryInternal::chain_lightning_no_cd;
        creators["call of the elements and enemy within melee"] = &ShamanATriggerFactoryInternal::call_of_the_elements_and_enemy_within_melee;
        creators["maelstrom weapon 5 and medium aoe"] = &ShamanATriggerFactoryInternal::maelstrom_weapon_5_and_medium_aoe;
        creators["maelstrom weapon 4 and medium aoe"] = &ShamanATriggerFactoryInternal::maelstrom_weapon_4_and_medium_aoe;
        creators["call of the elements"] = &ShamanATriggerFactoryInternal::call_of_the_elements;
        creators["totemic recall"] = &ShamanATriggerFactoryInternal::totemic_recall;
        creators["no earth totem"] = &ShamanATriggerFactoryInternal::no_earth_totem;
        creators["no fire totem"] = &ShamanATriggerFactoryInternal::no_fire_totem;
        creators["no water totem"] = &ShamanATriggerFactoryInternal::no_water_totem;
        creators["no air totem"] = &ShamanATriggerFactoryInternal::no_air_totem;
        creators["set strength of earth totem"] = &ShamanATriggerFactoryInternal::set_strength_of_earth_totem;
        creators["set stoneskin totem"] = &ShamanATriggerFactoryInternal::set_stoneskin_totem;
        creators["set tremor totem"] = &ShamanATriggerFactoryInternal::set_tremor_totem;
        creators["set earthbind totem"] = &ShamanATriggerFactoryInternal::set_earthbind_totem;
        creators["set searing totem"] = &ShamanATriggerFactoryInternal::set_searing_totem;
        creators["set magma totem"] = &ShamanATriggerFactoryInternal::set_magma_totem;
        creators["set flametongue totem"] = &ShamanATriggerFactoryInternal::set_flametongue_totem;
        creators["set totem of wrath"] = &ShamanATriggerFactoryInternal::set_totem_of_wrath;
        creators["set frost resistance totem"] = &ShamanATriggerFactoryInternal::set_frost_resistance_totem;
        creators["set healing stream totem"] = &ShamanATriggerFactoryInternal::set_healing_stream_totem;
        creators["set mana spring totem"] = &ShamanATriggerFactoryInternal::set_mana_spring_totem;
        creators["set cleansing totem"] = &ShamanATriggerFactoryInternal::set_cleansing_totem;
        creators["set fire resistance totem"] = &ShamanATriggerFactoryInternal::set_fire_resistance_totem;
        creators["set wrath of air totem"] = &ShamanATriggerFactoryInternal::set_wrath_of_air_totem;
        creators["set windfury totem"] = &ShamanATriggerFactoryInternal::set_windfury_totem;
        creators["set nature resistance totem"] = &ShamanATriggerFactoryInternal::set_nature_resistance_totem;
        creators["set grounding totem"] = &ShamanATriggerFactoryInternal::set_grounding_totem;
    }

private:
    static Trigger* maelstrom_weapon_3(ShadowAI* botAI) { return new MaelstromWeaponTrigger(botAI, 3); }
    static Trigger* maelstrom_weapon_4(ShadowAI* botAI) { return new MaelstromWeaponTrigger(botAI, 4); }
    static Trigger* maelstrom_weapon_5(ShadowAI* botAI) { return new MaelstromWeaponTrigger(botAI, 5); }
    static Trigger* heroism(ShadowAI* botAI) { return new HeroismTrigger(botAI); }
    static Trigger* bloodlust(ShadowAI* botAI) { return new BloodlustTrigger(botAI); }
    static Trigger* elemental_mastery(ShadowAI* botAI) { return new ElementalMasteryTrigger(botAI); }
    static Trigger* party_member_cleanse_disease(ShadowAI* botAI) { return new PartyMemberCleanseSpiritDiseaseTrigger(botAI); }
    static Trigger* party_member_cleanse_curse(ShadowAI* botAI) { return new PartyMemberCleanseSpiritCurseTrigger(botAI); }
    static Trigger* party_member_cleanse_poison(ShadowAI* botAI) { return new PartyMemberCleanseSpiritPoisonTrigger(botAI); }
    static Trigger* cleanse_disease(ShadowAI* botAI) { return new CleanseSpiritDiseaseTrigger(botAI); }
    static Trigger* cleanse_curse(ShadowAI* botAI) { return new CleanseSpiritCurseTrigger(botAI); }
    static Trigger* cleanse_poison(ShadowAI* botAI) { return new CleanseSpiritPoisonTrigger(botAI); }
    static Trigger* water_breathing(ShadowAI* botAI) { return new WaterBreathingTrigger(botAI); }
    static Trigger* water_walking(ShadowAI* botAI) { return new WaterWalkingTrigger(botAI); }
    static Trigger* water_breathing_on_party(ShadowAI* botAI) { return new WaterBreathingOnPartyTrigger(botAI); }
    static Trigger* water_walking_on_party(ShadowAI* botAI) { return new WaterWalkingOnPartyTrigger(botAI); }
    static Trigger* wind_shear(ShadowAI* botAI) { return new WindShearInterruptSpellTrigger(botAI); }
    static Trigger* purge(ShadowAI* botAI) { return new PurgeTrigger(botAI); }
    static Trigger* main_hand_weapon_no_imbue(ShadowAI* botAI) { return new MainHandWeaponNoImbueTrigger(botAI); }
    static Trigger* off_hand_weapon_no_imbue(ShadowAI* botAI) { return new OffHandWeaponNoImbueTrigger(botAI); }
    static Trigger* water_shield(ShadowAI* botAI) { return new WaterShieldTrigger(botAI); }
    static Trigger* lightning_shield(ShadowAI* botAI) { return new LightningShieldTrigger(botAI); }
    static Trigger* shock(ShadowAI* botAI) { return new ShockTrigger(botAI); }
    static Trigger* frost_shock_snare(ShadowAI* botAI) { return new FrostShockSnareTrigger(botAI); }
    static Trigger* wind_shear_on_enemy_healer(ShadowAI* botAI) { return new WindShearInterruptEnemyHealerSpellTrigger(botAI); }
    static Trigger* cure_poison(ShadowAI* botAI) { return new CurePoisonTrigger(botAI); }
    static Trigger* party_member_cure_poison(ShadowAI* botAI) { return new PartyMemberCurePoisonTrigger(botAI); }
    static Trigger* cure_disease(ShadowAI* botAI) { return new CureDiseaseTrigger(botAI); }
    static Trigger* party_member_cure_disease(ShadowAI* botAI) { return new PartyMemberCureDiseaseTrigger(botAI); }
    static Trigger* earth_shield_on_main_tank(ShadowAI* ai) { return new EarthShieldOnMainTankTrigger(ai); }
    static Trigger* flame_shock(ShadowAI* ai) { return new FlameShockTrigger(ai); }
    static Trigger* fire_elemental_totem(ShadowAI* botAI) { return new FireElementalTotemTrigger(botAI); }
    static Trigger* earth_shock_execute(ShadowAI* botAI) { return new EarthShockExecuteTrigger(botAI); }
    static Trigger* spirit_walk_ready(ShadowAI* ai) { return new SpiritWalkTrigger(ai); }
    static Trigger* chain_lightning_no_cd(ShadowAI* ai) { return new ChainLightningNoCdTrigger(ai); }
    static Trigger* call_of_the_elements_and_enemy_within_melee(ShadowAI* ai) { return new CallOfTheElementsAndEnemyWithinMeleeTrigger(ai); }
    static Trigger* maelstrom_weapon_5_and_medium_aoe(ShadowAI* ai) { return new MaelstromWeapon5AndMediumAoeTrigger(ai); }
    static Trigger* maelstrom_weapon_4_and_medium_aoe(ShadowAI* ai) { return new MaelstromWeapon4AndMediumAoeTrigger(ai); }
    static Trigger* call_of_the_elements(ShadowAI* ai) { return new CallOfTheElementsTrigger(ai); }
    static Trigger* totemic_recall(ShadowAI* ai) { return new TotemicRecallTrigger(ai); }
    static Trigger* no_earth_totem(ShadowAI* ai) { return new NoEarthTotemTrigger(ai); }
    static Trigger* no_fire_totem(ShadowAI* ai) { return new NoFireTotemTrigger(ai); }
    static Trigger* no_water_totem(ShadowAI* ai) { return new NoWaterTotemTrigger(ai); }
    static Trigger* no_air_totem(ShadowAI* ai) { return new NoAirTotemTrigger(ai); }
    static Trigger* set_strength_of_earth_totem(ShadowAI* ai) { return new SetStrengthOfEarthTotemTrigger(ai); }
    static Trigger* set_stoneskin_totem(ShadowAI* ai) { return new SetStoneskinTotemTrigger(ai); }
    static Trigger* set_tremor_totem(ShadowAI* ai) { return new SetTremorTotemTrigger(ai); }
    static Trigger* set_earthbind_totem(ShadowAI* ai) { return new SetEarthbindTotemTrigger(ai); }
    static Trigger* set_searing_totem(ShadowAI* ai) { return new SetSearingTotemTrigger(ai); }
    static Trigger* set_magma_totem(ShadowAI* ai) { return new SetMagmaTotemTrigger(ai); }
    static Trigger* set_flametongue_totem(ShadowAI* ai) { return new SetFlametongueTotemTrigger(ai); }
    static Trigger* set_totem_of_wrath(ShadowAI* ai) { return new SetTotemOfWrathTrigger(ai); }
    static Trigger* set_frost_resistance_totem(ShadowAI* ai) { return new SetFrostResistanceTotemTrigger(ai); }
    static Trigger* set_healing_stream_totem(ShadowAI* ai) { return new SetHealingStreamTotemTrigger(ai); }
    static Trigger* set_mana_spring_totem(ShadowAI* ai) { return new SetManaSpringTotemTrigger(ai); }
    static Trigger* set_cleansing_totem(ShadowAI* ai) { return new SetCleansingTotemTrigger(ai); }
    static Trigger* set_fire_resistance_totem(ShadowAI* ai) { return new SetFireResistanceTotemTrigger(ai); }
    static Trigger* set_wrath_of_air_totem(ShadowAI* ai) { return new SetWrathOfAirTotemTrigger(ai); }
    static Trigger* set_windfury_totem(ShadowAI* ai) { return new SetWindfuryTotemTrigger(ai); }
    static Trigger* set_nature_resistance_totem(ShadowAI* ai) { return new SetNatureResistanceTotemTrigger(ai); }
    static Trigger* set_grounding_totem(ShadowAI* ai) { return new SetGroundingTotemTrigger(ai); }
};

class ShamanAiObjectContextInternal : public NamedObjectContext<Action>
{
public:
    ShamanAiObjectContextInternal()
    {
        creators["water shield"] = &ShamanAiObjectContextInternal::water_shield;
        creators["lightning shield"] = &ShamanAiObjectContextInternal::lightning_shield;
        creators["wind shear"] = &ShamanAiObjectContextInternal::wind_shear;
        creators["wind shear on enemy healer"] = &ShamanAiObjectContextInternal::wind_shear_on_enemy_healer;
        creators["rockbiter weapon"] = &ShamanAiObjectContextInternal::rockbiter_weapon;
        creators["flametongue weapon"] = &ShamanAiObjectContextInternal::flametongue_weapon;
        creators["frostbrand weapon"] = &ShamanAiObjectContextInternal::frostbrand_weapon;
        creators["windfury weapon"] = &ShamanAiObjectContextInternal::windfury_weapon;
        creators["earthliving weapon"] = &ShamanAiObjectContextInternal::earthliving_weapon;
        creators["purge"] = &ShamanAiObjectContextInternal::purge;
        creators["healing wave"] = &ShamanAiObjectContextInternal::healing_wave;
        creators["lesser healing wave"] = &ShamanAiObjectContextInternal::lesser_healing_wave;
        creators["healing wave on party"] = &ShamanAiObjectContextInternal::healing_wave_on_party;
        creators["lesser healing wave on party"] = &ShamanAiObjectContextInternal::lesser_healing_wave_on_party;
        creators["earth shield"] = &ShamanAiObjectContextInternal::earth_shield;
        creators["earth shield on party"] = &ShamanAiObjectContextInternal::earth_shield_on_party;
        creators["chain heal on party"] = &ShamanAiObjectContextInternal::chain_heal;
        creators["riptide"] = &ShamanAiObjectContextInternal::riptide;
        creators["riptide on party"] = &ShamanAiObjectContextInternal::riptide_on_party;
        creators["stormstrike"] = &ShamanAiObjectContextInternal::stormstrike;
        creators["lava lash"] = &ShamanAiObjectContextInternal::lava_lash;
        creators["fire nova"] = &ShamanAiObjectContextInternal::fire_nova;
        creators["ancestral spirit"] = &ShamanAiObjectContextInternal::ancestral_spirit;
        creators["water walking"] = &ShamanAiObjectContextInternal::water_walking;
        creators["water breathing"] = &ShamanAiObjectContextInternal::water_breathing;
        creators["water walking on party"] = &ShamanAiObjectContextInternal::water_walking_on_party;
        creators["water breathing on party"] = &ShamanAiObjectContextInternal::water_breathing_on_party;
        creators["cleanse spirit"] = &ShamanAiObjectContextInternal::cleanse_spirit;
        creators["cleanse spirit poison on party"] = &ShamanAiObjectContextInternal::cleanse_spirit_poison_on_party;
        creators["cleanse spirit disease on party"] = &ShamanAiObjectContextInternal::cleanse_spirit_disease_on_party;
        creators["cleanse spirit curse on party"] = &ShamanAiObjectContextInternal::cleanse_spirit_curse_on_party;
        creators["flame shock"] = &ShamanAiObjectContextInternal::flame_shock;
        creators["earth shock"] = &ShamanAiObjectContextInternal::earth_shock;
        creators["frost shock"] = &ShamanAiObjectContextInternal::frost_shock;
        creators["chain lightning"] = &ShamanAiObjectContextInternal::chain_lightning;
        creators["lightning bolt"] = &ShamanAiObjectContextInternal::lightning_bolt;
        creators["thunderstorm"] = &ShamanAiObjectContextInternal::thunderstorm;
        creators["heroism"] = &ShamanAiObjectContextInternal::heroism;
        creators["bloodlust"] = &ShamanAiObjectContextInternal::bloodlust;
        creators["elemental mastery"] = &ShamanAiObjectContextInternal::elemental_mastery;
        creators["cure disease"] = &ShamanAiObjectContextInternal::cure_disease;
        creators["cure disease on party"] = &ShamanAiObjectContextInternal::cure_disease_on_party;
        creators["cure poison"] = &ShamanAiObjectContextInternal::cure_poison;
        creators["cure poison on party"] = &ShamanAiObjectContextInternal::cure_poison_on_party;
        creators["lava burst"] = &ShamanAiObjectContextInternal::lava_burst;
        creators["earth shield on main tank"] = &ShamanAiObjectContextInternal::earth_shield_on_main_tank;
        creators["shamanistic rage"] = &ShamanAiObjectContextInternal::shamanistic_rage;
        creators["feral spirit"] = &ShamanAiObjectContextInternal::feral_spirit;
        creators["spirit walk"] = &ShamanAiObjectContextInternal::spirit_walk;
        creators["call of the elements"] = &ShamanAiObjectContextInternal::call_of_the_elements;
        creators["totemic recall"] = &ShamanAiObjectContextInternal::totemic_recall;
        creators["strength of earth totem"] = &ShamanAiObjectContextInternal::strength_of_earth_totem;
        creators["stoneskin totem"] = &ShamanAiObjectContextInternal::stoneskin_totem;
        creators["tremor totem"] = &ShamanAiObjectContextInternal::tremor_totem;
        creators["earthbind totem"] = &ShamanAiObjectContextInternal::earthbind_totem;
        creators["stoneclaw totem"] = &ShamanAiObjectContextInternal::stoneclaw_totem;
        creators["searing totem"] = &ShamanAiObjectContextInternal::searing_totem;
        creators["magma totem"] = &ShamanAiObjectContextInternal::magma_totem;
        creators["flametongue totem"] = &ShamanAiObjectContextInternal::flametongue_totem;
        creators["totem of wrath"] = &ShamanAiObjectContextInternal::totem_of_wrath;
        creators["frost resistance totem"] = &ShamanAiObjectContextInternal::frost_resistance_totem;
        creators["fire elemental totem"] = &ShamanAiObjectContextInternal::fire_elemental_totem;
        creators["fire elemental totem melee"] = &ShamanAiObjectContextInternal::fire_elemental_totem_melee;
        creators["healing stream totem"] = &ShamanAiObjectContextInternal::healing_stream_totem;
        creators["mana spring totem"] = &ShamanAiObjectContextInternal::mana_spring_totem;
        creators["cleansing totem"] = &ShamanAiObjectContextInternal::cleansing_totem;
        creators["mana tide totem"] = &ShamanAiObjectContextInternal::mana_tide_totem;
        creators["fire resistance totem"] = &ShamanAiObjectContextInternal::fire_resistance_totem;
        creators["wrath of air totem"] = &ShamanAiObjectContextInternal::wrath_of_air_totem;
        creators["windfury totem"] = &ShamanAiObjectContextInternal::windfury_totem;
        creators["nature resistance totem"] = &ShamanAiObjectContextInternal::nature_resistance_totem;
        creators["set strength of earth totem"] = &ShamanAiObjectContextInternal::set_strength_of_earth_totem;
        creators["set stoneskin totem"] = &ShamanAiObjectContextInternal::set_stoneskin_totem;
        creators["set tremor totem"] = &ShamanAiObjectContextInternal::set_tremor_totem;
        creators["set earthbind totem"] = &ShamanAiObjectContextInternal::set_earthbind_totem;
        creators["set searing totem"] = &ShamanAiObjectContextInternal::set_searing_totem;
        creators["set magma totem"] = &ShamanAiObjectContextInternal::set_magma_totem;
        creators["set flametongue totem"] = &ShamanAiObjectContextInternal::set_flametongue_totem;
        creators["set totem of wrath"] = &ShamanAiObjectContextInternal::set_totem_of_wrath;
        creators["set frost resistance totem"] = &ShamanAiObjectContextInternal::set_frost_resistance_totem;
        creators["set healing stream totem"] = &ShamanAiObjectContextInternal::set_healing_stream_totem;
        creators["set mana spring totem"] = &ShamanAiObjectContextInternal::set_mana_spring_totem;
        creators["set cleansing totem"] = &ShamanAiObjectContextInternal::set_cleansing_totem;
        creators["set fire resistance totem"] = &ShamanAiObjectContextInternal::set_fire_resistance_totem;
        creators["set wrath of air totem"] = &ShamanAiObjectContextInternal::set_wrath_of_air_totem;
        creators["set windfury totem"] = &ShamanAiObjectContextInternal::set_windfury_totem;
        creators["set nature resistance totem"] = &ShamanAiObjectContextInternal::set_nature_resistance_totem;
        creators["set grounding totem"] = &ShamanAiObjectContextInternal::set_grounding_totem;
    }

private:
    static Action* heroism(ShadowAI* botAI) { return new CastHeroismAction(botAI); }
    static Action* bloodlust(ShadowAI* botAI) { return new CastBloodlustAction(botAI); }
    static Action* elemental_mastery(ShadowAI* botAI) { return new CastElementalMasteryAction(botAI); }
    static Action* thunderstorm(ShadowAI* botAI) { return new CastThunderstormAction(botAI); }
    static Action* lightning_bolt(ShadowAI* botAI) { return new CastLightningBoltAction(botAI); }
    static Action* chain_lightning(ShadowAI* botAI) { return new CastChainLightningAction(botAI); }
    static Action* frost_shock(ShadowAI* botAI) { return new CastFrostShockAction(botAI); }
    static Action* earth_shock(ShadowAI* botAI) { return new CastEarthShockAction(botAI); }
    static Action* flame_shock(ShadowAI* botAI) { return new CastFlameShockAction(botAI); }
    static Action* cleanse_spirit_poison_on_party(ShadowAI* botAI) { return new CastCleanseSpiritPoisonOnPartyAction(botAI); }
    static Action* cleanse_spirit_disease_on_party(ShadowAI* botAI) { return new CastCleanseSpiritDiseaseOnPartyAction(botAI); }
    static Action* cleanse_spirit_curse_on_party(ShadowAI* botAI) { return new CastCleanseSpiritCurseOnPartyAction(botAI); }
    static Action* cleanse_spirit(ShadowAI* botAI) { return new CastCleanseSpiritAction(botAI); }
    static Action* water_walking(ShadowAI* botAI) { return new CastWaterWalkingAction(botAI); }
    static Action* water_breathing(ShadowAI* botAI) { return new CastWaterBreathingAction(botAI); }
    static Action* water_walking_on_party(ShadowAI* botAI) { return new CastWaterWalkingOnPartyAction(botAI); }
    static Action* water_breathing_on_party(ShadowAI* botAI) { return new CastWaterBreathingOnPartyAction(botAI); }
    static Action* water_shield(ShadowAI* botAI) { return new CastWaterShieldAction(botAI); }
    static Action* lightning_shield(ShadowAI* botAI) { return new CastLightningShieldAction(botAI); }
    static Action* fire_nova(ShadowAI* botAI) { return new CastFireNovaAction(botAI); }
    static Action* wind_shear(ShadowAI* botAI) { return new CastWindShearAction(botAI); }
    static Action* rockbiter_weapon(ShadowAI* botAI) { return new CastRockbiterWeaponAction(botAI); }
    static Action* flametongue_weapon(ShadowAI* botAI) { return new CastFlametongueWeaponAction(botAI); }
    static Action* frostbrand_weapon(ShadowAI* botAI) { return new CastFrostbrandWeaponAction(botAI); }
    static Action* windfury_weapon(ShadowAI* botAI) { return new CastWindfuryWeaponAction(botAI); }
    static Action* earthliving_weapon(ShadowAI* botAI) { return new CastEarthlivingWeaponAction(botAI); }
    static Action* purge(ShadowAI* botAI) { return new CastPurgeAction(botAI); }
    static Action* healing_wave(ShadowAI* botAI) { return new CastHealingWaveAction(botAI); }
    static Action* lesser_healing_wave(ShadowAI* botAI) { return new CastLesserHealingWaveAction(botAI); }
    static Action* healing_wave_on_party(ShadowAI* botAI) { return new CastHealingWaveOnPartyAction(botAI); }
    static Action* lesser_healing_wave_on_party(ShadowAI* botAI) { return new CastLesserHealingWaveOnPartyAction(botAI); }
    static Action* earth_shield(ShadowAI* botAI) { return new CastEarthShieldAction(botAI); }
    static Action* earth_shield_on_party(ShadowAI* botAI) { return new CastEarthShieldOnPartyAction(botAI); }
    static Action* chain_heal(ShadowAI* botAI) { return new CastChainHealAction(botAI); }
    static Action* riptide(ShadowAI* botAI) { return new CastRiptideAction(botAI); }
    static Action* riptide_on_party(ShadowAI* botAI) { return new CastRiptideOnPartyAction(botAI); }
    static Action* stormstrike(ShadowAI* botAI) { return new CastStormstrikeAction(botAI); }
    static Action* lava_lash(ShadowAI* botAI) { return new CastLavaLashAction(botAI); }
    static Action* ancestral_spirit(ShadowAI* botAI) { return new CastAncestralSpiritAction(botAI); }
    static Action* wind_shear_on_enemy_healer(ShadowAI* botAI) { return new CastWindShearOnEnemyHealerAction(botAI); }
    static Action* cure_poison(ShadowAI* botAI) { return new CastCurePoisonActionSham(botAI); }
    static Action* cure_poison_on_party(ShadowAI* botAI) { return new CastCurePoisonOnPartyActionSham(botAI); }
    static Action* cure_disease(ShadowAI* botAI) { return new CastCureDiseaseActionSham(botAI); }
    static Action* cure_disease_on_party(ShadowAI* botAI) { return new CastCureDiseaseOnPartyActionSham(botAI); }
    static Action* lava_burst(ShadowAI* ai) { return new CastLavaBurstAction(ai); }
    static Action* earth_shield_on_main_tank(ShadowAI* ai) { return new CastEarthShieldOnMainTankAction(ai); }
    static Action* shamanistic_rage(ShadowAI* ai) { return new CastShamanisticRageAction(ai); }
    static Action* feral_spirit(ShadowAI* ai) { return new CastFeralSpiritAction(ai); }
    static Action* spirit_walk(ShadowAI* ai) { return new CastSpiritWalkAction(ai); }
    static Action* call_of_the_elements(ShadowAI* ai) { return new CastCallOfTheElementsAction(ai); }
    static Action* totemic_recall(ShadowAI* ai) { return new CastTotemicRecallAction(ai); }
    static Action* strength_of_earth_totem(ShadowAI* ai) { return new CastStrengthOfEarthTotemAction(ai); }
    static Action* stoneskin_totem(ShadowAI* ai) { return new CastStoneskinTotemAction(ai); }
    static Action* tremor_totem(ShadowAI* ai) { return new CastTremorTotemAction(ai); }
    static Action* earthbind_totem(ShadowAI* ai) { return new CastEarthbindTotemAction(ai); }
    static Action* stoneclaw_totem(ShadowAI* ai) { return new CastStoneclawTotemAction(ai); }
    static Action* searing_totem(ShadowAI* ai) { return new CastSearingTotemAction(ai); }
    static Action* magma_totem(ShadowAI* ai) { return new CastMagmaTotemAction(ai); }
    static Action* flametongue_totem(ShadowAI* ai) { return new CastFlametongueTotemAction(ai); }
    static Action* totem_of_wrath(ShadowAI* ai) { return new CastTotemOfWrathAction(ai); }
    static Action* frost_resistance_totem(ShadowAI* ai) { return new CastFrostResistanceTotemAction(ai); }
    static Action* fire_elemental_totem(ShadowAI* ai) { return new CastFireElementalTotemAction(ai); }
    static Action* fire_elemental_totem_melee(ShadowAI* ai) { return new CastFireElementalTotemMeleeAction(ai); }
    static Action* healing_stream_totem(ShadowAI* ai) { return new CastHealingStreamTotemAction(ai); }
    static Action* mana_spring_totem(ShadowAI* ai) { return new CastManaSpringTotemAction(ai); }
    static Action* cleansing_totem(ShadowAI* ai) { return new CastCleansingTotemAction(ai); }
    static Action* mana_tide_totem(ShadowAI* ai) { return new CastManaTideTotemAction(ai); }
    static Action* fire_resistance_totem(ShadowAI* ai) { return new CastFireResistanceTotemAction(ai); }
    static Action* wrath_of_air_totem(ShadowAI* ai) { return new CastWrathOfAirTotemAction(ai); }
    static Action* windfury_totem(ShadowAI* ai) { return new CastWindfuryTotemAction(ai); }
    static Action* nature_resistance_totem(ShadowAI* ai) { return new CastNatureResistanceTotemAction(ai); }
    static Action* set_strength_of_earth_totem(ShadowAI* ai) { return new SetStrengthOfEarthTotemAction(ai); }
    static Action* set_stoneskin_totem(ShadowAI* ai) { return new SetStoneskinTotemAction(ai); }
    static Action* set_tremor_totem(ShadowAI* ai) { return new SetTremorTotemAction(ai); }
    static Action* set_earthbind_totem(ShadowAI* ai) { return new SetEarthbindTotemAction(ai); }
    static Action* set_searing_totem(ShadowAI* ai) { return new SetSearingTotemAction(ai); }
    static Action* set_magma_totem(ShadowAI* ai) { return new SetMagmaTotemAction(ai); }
    static Action* set_flametongue_totem(ShadowAI* ai) { return new SetFlametongueTotemAction(ai); }
    static Action* set_totem_of_wrath(ShadowAI* ai) { return new SetTotemOfWrathAction(ai); }
    static Action* set_frost_resistance_totem(ShadowAI* ai) { return new SetFrostResistanceTotemAction(ai); }
    static Action* set_healing_stream_totem(ShadowAI* ai) { return new SetHealingStreamTotemAction(ai); }
    static Action* set_mana_spring_totem(ShadowAI* ai) { return new SetManaSpringTotemAction(ai); }
    static Action* set_cleansing_totem(ShadowAI* ai) { return new SetCleansingTotemAction(ai); }
    static Action* set_fire_resistance_totem(ShadowAI* ai) { return new SetFireResistanceTotemAction(ai); }
    static Action* set_wrath_of_air_totem(ShadowAI* ai) { return new SetWrathOfAirTotemAction(ai); }
    static Action* set_windfury_totem(ShadowAI* ai) { return new SetWindfuryTotemAction(ai); }
    static Action* set_nature_resistance_totem(ShadowAI* ai) { return new SetNatureResistanceTotemAction(ai); }
    static Action* set_grounding_totem(ShadowAI* ai) { return new SetGroundingTotemAction(ai); }
};

SharedNamedObjectContextList<Strategy> ShamanAiObjectContext::sharedStrategyContexts;
SharedNamedObjectContextList<Action> ShamanAiObjectContext::sharedActionContexts;
SharedNamedObjectContextList<Trigger> ShamanAiObjectContext::sharedTriggerContexts;
SharedNamedObjectContextList<UntypedValue> ShamanAiObjectContext::sharedValueContexts;

ShamanAiObjectContext::ShamanAiObjectContext(ShadowAI* botAI)
    : AiObjectContext(botAI, sharedStrategyContexts, sharedActionContexts, sharedTriggerContexts, sharedValueContexts)
{
}

void ShamanAiObjectContext::BuildSharedContexts()
{
    BuildSharedStrategyContexts(sharedStrategyContexts);
    BuildSharedActionContexts(sharedActionContexts);
    BuildSharedTriggerContexts(sharedTriggerContexts);
    BuildSharedValueContexts(sharedValueContexts);
}

void ShamanAiObjectContext::BuildSharedStrategyContexts(SharedNamedObjectContextList<Strategy>& strategyContexts)
{
    AiObjectContext::BuildSharedStrategyContexts(strategyContexts);
    strategyContexts.Add(new ShamanStrategyFactoryInternal());
    strategyContexts.Add(new ShamanCombatStrategyFactoryInternal());
    strategyContexts.Add(new ShamanEarthTotemStrategyFactoryInternal());
    strategyContexts.Add(new ShamanFireTotemStrategyFactoryInternal());
    strategyContexts.Add(new ShamanWaterTotemStrategyFactoryInternal());
    strategyContexts.Add(new ShamanAirTotemStrategyFactoryInternal());
}

void ShamanAiObjectContext::BuildSharedActionContexts(SharedNamedObjectContextList<Action>& actionContexts)
{
    AiObjectContext::BuildSharedActionContexts(actionContexts);
    actionContexts.Add(new ShamanAiObjectContextInternal());
}

void ShamanAiObjectContext::BuildSharedTriggerContexts(SharedNamedObjectContextList<Trigger>& triggerContexts)
{
    AiObjectContext::BuildSharedTriggerContexts(triggerContexts);
    triggerContexts.Add(new ShamanATriggerFactoryInternal());
}

void ShamanAiObjectContext::BuildSharedValueContexts(SharedNamedObjectContextList<UntypedValue>& valueContexts)
{
    AiObjectContext::BuildSharedValueContexts(valueContexts);
}
