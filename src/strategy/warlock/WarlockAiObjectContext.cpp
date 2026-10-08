/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#include "WarlockAiObjectContext.h"

#include "AfflictionWarlockStrategy.h"
#include "DemonologyWarlockStrategy.h"
#include "DestructionWarlockStrategy.h"
#include "GenericTriggers.h"
#include "GenericWarlockNonCombatStrategy.h"
#include "NamedObjectContext.h"
#include "Shadows.h"
#include "PullStrategy.h"
#include "Strategy.h"
#include "TankWarlockStrategy.h"
#include "UseItemAction.h"
#include "WarlockActions.h"
#include "WarlockTriggers.h"

class WarlockStrategyFactoryInternal : public NamedObjectContext<Strategy>
{
public:
    WarlockStrategyFactoryInternal()
    {
        creators["nc"] = &WarlockStrategyFactoryInternal::nc;
        creators["pull"] = &WarlockStrategyFactoryInternal::pull;
        creators["boost"] = &WarlockStrategyFactoryInternal::boost;
        creators["cc"] = &WarlockStrategyFactoryInternal::cc;
        creators["pet"] = &WarlockStrategyFactoryInternal::pet;
        creators["meta melee"] = &WarlockStrategyFactoryInternal::meta_melee_aoe;
        creators["tank"] = &WarlockStrategyFactoryInternal::tank;
        creators["aoe"] = &WarlockStrategyFactoryInternal::aoe;
    }

private:
    static Strategy* nc(ShadowAI* botAI) { return new GenericWarlockNonCombatStrategy(botAI); }
    static Strategy* pull(ShadowAI* botAI) { return new PullStrategy(botAI, "shoot"); }
    static Strategy* boost(ShadowAI* botAI) { return new WarlockBoostStrategy(botAI); }
    static Strategy* cc(ShadowAI* botAI) { return new WarlockCcStrategy(botAI); }
    static Strategy* pet(ShadowAI* botAI) { return new WarlockPetStrategy(botAI); }
    static Strategy* meta_melee_aoe(ShadowAI* botAI) { return new MetaMeleeAoeStrategy(botAI); }
    static Strategy* tank(ShadowAI* botAI) { return new TankWarlockStrategy(botAI); }
    static Strategy* aoe(ShadowAI* botAI) { return new AoEWarlockStrategy(botAI); }
};

class WarlockCombatStrategyFactoryInternal : public NamedObjectContext<Strategy>
{
public:
    WarlockCombatStrategyFactoryInternal() : NamedObjectContext<Strategy>(false, true)
    {
        creators["affli"] = &WarlockCombatStrategyFactoryInternal::affliction;
        creators["demo"] = &WarlockCombatStrategyFactoryInternal::demonology;
        creators["destro"] = &WarlockCombatStrategyFactoryInternal::destruction;
    }

private:
    static Strategy* affliction(ShadowAI* botAI) { return new AfflictionWarlockStrategy(botAI); }
    static Strategy* demonology(ShadowAI* botAI) { return new DemonologyWarlockStrategy(botAI); }
    static Strategy* destruction(ShadowAI* botAI) { return new DestructionWarlockStrategy(botAI); }
};

class WarlockPetStrategyFactoryInternal : public NamedObjectContext<Strategy>
{
public:
    WarlockPetStrategyFactoryInternal() : NamedObjectContext<Strategy>(false, true)
    {
        creators["imp"] = &WarlockPetStrategyFactoryInternal::imp;
        creators["voidwalker"] = &WarlockPetStrategyFactoryInternal::voidwalker;
        creators["succubus"] = &WarlockPetStrategyFactoryInternal::succubus;
        creators["felhunter"] = &WarlockPetStrategyFactoryInternal::felhunter;
        creators["felguard"] = &WarlockPetStrategyFactoryInternal::felguard;
    }

private:
    static Strategy* imp(ShadowAI* ai) { return new SummonImpStrategy(ai); }
    static Strategy* voidwalker(ShadowAI* ai) { return new SummonVoidwalkerStrategy(ai); }
    static Strategy* succubus(ShadowAI* ai) { return new SummonSuccubusStrategy(ai); }
    static Strategy* felhunter(ShadowAI* ai) { return new SummonFelhunterStrategy(ai); }
    static Strategy* felguard(ShadowAI* ai) { return new SummonFelguardStrategy(ai); }
};

class WarlockSoulstoneStrategyFactoryInternal : public NamedObjectContext<Strategy>
{
public:
    WarlockSoulstoneStrategyFactoryInternal() : NamedObjectContext<Strategy>(false, true)
    {
        creators["ss self"] = &WarlockSoulstoneStrategyFactoryInternal::soulstone_self;
        creators["ss master"] = &WarlockSoulstoneStrategyFactoryInternal::soulstone_master;
        creators["ss tank"] = &WarlockSoulstoneStrategyFactoryInternal::soulstone_tank;
        creators["ss healer"] = &WarlockSoulstoneStrategyFactoryInternal::soulstone_healer;
    }

private:
    static Strategy* soulstone_self(ShadowAI* ai) { return new SoulstoneSelfStrategy(ai); }
    static Strategy* soulstone_master(ShadowAI* ai) { return new SoulstoneMasterStrategy(ai); }
    static Strategy* soulstone_tank(ShadowAI* ai) { return new SoulstoneTankStrategy(ai); }
    static Strategy* soulstone_healer(ShadowAI* ai) { return new SoulstoneHealerStrategy(ai); }
};

class WarlockCurseStrategyFactoryInternal : public NamedObjectContext<Strategy>
{
public:
    WarlockCurseStrategyFactoryInternal() : NamedObjectContext<Strategy>(false, true)
    {
        creators["curse of agony"] = &WarlockCurseStrategyFactoryInternal::curse_of_agony;
        creators["curse of elements"] = &WarlockCurseStrategyFactoryInternal::curse_of_elements;
        creators["curse of doom"] = &WarlockCurseStrategyFactoryInternal::curse_of_doom;
        creators["curse of exhaustion"] = &WarlockCurseStrategyFactoryInternal::curse_of_exhaustion;
        creators["curse of tongues"] = &WarlockCurseStrategyFactoryInternal::curse_of_tongues;
        creators["curse of weakness"] = &WarlockCurseStrategyFactoryInternal::curse_of_weakness;
    }

private:
    static Strategy* curse_of_agony(ShadowAI* botAI) { return new WarlockCurseOfAgonyStrategy(botAI); }
    static Strategy* curse_of_elements(ShadowAI* botAI) { return new WarlockCurseOfTheElementsStrategy(botAI); }
    static Strategy* curse_of_doom(ShadowAI* botAI) { return new WarlockCurseOfDoomStrategy(botAI); }
    static Strategy* curse_of_exhaustion(ShadowAI* botAI) { return new WarlockCurseOfExhaustionStrategy(botAI); }
    static Strategy* curse_of_tongues(ShadowAI* botAI) { return new WarlockCurseOfTonguesStrategy(botAI); }
    static Strategy* curse_of_weakness(ShadowAI* botAI) { return new WarlockCurseOfWeaknessStrategy(botAI); }
};

class WarlockWeaponStoneStrategyFactoryInternal : public NamedObjectContext<Strategy>
{
public:
    WarlockWeaponStoneStrategyFactoryInternal() : NamedObjectContext<Strategy>(false, true)
    {
        creators["firestone"] = &WarlockWeaponStoneStrategyFactoryInternal::firestone;
        creators["spellstone"] = &WarlockWeaponStoneStrategyFactoryInternal::spellstone;
    }

private:
    static Strategy* firestone(ShadowAI* ai) { return new UseFirestoneStrategy(ai); }
    static Strategy* spellstone(ShadowAI* ai) { return new UseSpellstoneStrategy(ai); }
};

class WarlockTriggerFactoryInternal : public NamedObjectContext<Trigger>
{
public:
    WarlockTriggerFactoryInternal()
    {
        creators["shadow trance"] = &WarlockTriggerFactoryInternal::shadow_trance;
        creators["demon armor"] = &WarlockTriggerFactoryInternal::demon_armor;
        creators["soul link"] = &WarlockTriggerFactoryInternal::soul_link;
        creators["no soul shard"] = &WarlockTriggerFactoryInternal::no_soul_shard;
        creators["too many soul shards"] = &WarlockTriggerFactoryInternal::too_many_soul_shards;
        creators["no healthstone"] = &WarlockTriggerFactoryInternal::HasHealthstone;
        creators["no firestone"] = &WarlockTriggerFactoryInternal::HasFirestone;
        creators["no spellstone"] = &WarlockTriggerFactoryInternal::HasSpellstone;
        creators["no soulstone"] = &WarlockTriggerFactoryInternal::OutOfSoulstone;
        creators["firestone"] = &WarlockTriggerFactoryInternal::firestone;
        creators["spellstone"] = &WarlockTriggerFactoryInternal::spellstone;
        creators["soulstone"] = &WarlockTriggerFactoryInternal::soulstone;
        creators["banish"] = &WarlockTriggerFactoryInternal::banish;
        creators["fear"] = &WarlockTriggerFactoryInternal::fear;
        creators["spell lock"] = &WarlockTriggerFactoryInternal::spell_lock;
        creators["devour magic purge"] = &WarlockTriggerFactoryInternal::devour_magic_purge;
        creators["devour magic cleanse"] = &WarlockTriggerFactoryInternal::devour_magic_cleanse;
        creators["backlash"] = &WarlockTriggerFactoryInternal::backlash;
        creators["corruption"] = &WarlockTriggerFactoryInternal::corruption;
        creators["corruption on attacker"] = &WarlockTriggerFactoryInternal::corruption_on_attacker;
        creators["immolate"] = &WarlockTriggerFactoryInternal::immolate;
        creators["immolate on attacker"] = &WarlockTriggerFactoryInternal::immolate_on_attacker;
        creators["unstable affliction"] = &WarlockTriggerFactoryInternal::unstable_affliction;
        creators["unstable affliction on attacker"] = &WarlockTriggerFactoryInternal::unstable_affliction_on_attacker;
        creators["haunt"] = &WarlockTriggerFactoryInternal::haunt;
        creators["decimation"] = &WarlockTriggerFactoryInternal::decimation;
        creators["life tap"] = &WarlockTriggerFactoryInternal::life_tap;
        creators["life tap glyph buff"] = &WarlockTriggerFactoryInternal::life_tap_glyph_buff;
        creators["molten core"] = &WarlockTriggerFactoryInternal::molten_core;
        creators["metamorphosis"] = &WarlockTriggerFactoryInternal::metamorphosis;
        creators["demonic empowerment"] = &WarlockTriggerFactoryInternal::demonic_empowerment;
        creators["immolation aura active"] = &WarlockTriggerFactoryInternal::immolation_aura_active;
        creators["metamorphosis not active"] = &WarlockTriggerFactoryInternal::metamorphosis_not_active;
        creators["meta melee flee check"] = &WarlockTriggerFactoryInternal::meta_melee_flee_check;
        creators["curse of agony"] = &WarlockTriggerFactoryInternal::curse_of_agony;
        creators["curse of agony on attacker"] = &WarlockTriggerFactoryInternal::curse_of_agony_on_attacker;
        creators["curse of the elements"] = &WarlockTriggerFactoryInternal::curse_of_the_elements;
        creators["curse of doom"] = &WarlockTriggerFactoryInternal::curse_of_doom;
        creators["curse of exhaustion"] = &WarlockTriggerFactoryInternal::curse_of_exhaustion;
        creators["curse of tongues"] = &WarlockTriggerFactoryInternal::curse_of_tongues;
        creators["curse of weakness"] = &WarlockTriggerFactoryInternal::curse_of_weakness;
        creators["wrong pet"] = &WarlockTriggerFactoryInternal::wrong_pet;
        creators["rain of fire channel check"] = &WarlockTriggerFactoryInternal::rain_of_fire_channel_check;
    }

private:
    static Trigger* shadow_trance(ShadowAI* botAI) { return new ShadowTranceTrigger(botAI); }
    static Trigger* demon_armor(ShadowAI* botAI) { return new DemonArmorTrigger(botAI); }
    static Trigger* soul_link(ShadowAI* botAI) { return new SoulLinkTrigger(botAI); }
    static Trigger* no_soul_shard(ShadowAI* botAI) { return new OutOfSoulShardsTrigger(botAI); }
    static Trigger* too_many_soul_shards(ShadowAI* botAI) { return new TooManySoulShardsTrigger(botAI); }
    static Trigger* HasHealthstone(ShadowAI* botAI) { return new HasHealthstoneTrigger(botAI); }
    static Trigger* HasFirestone(ShadowAI* botAI) { return new HasFirestoneTrigger(botAI); }
    static Trigger* HasSpellstone(ShadowAI* botAI) { return new HasSpellstoneTrigger(botAI); }
    static Trigger* OutOfSoulstone(ShadowAI* botAI) { return new OutOfSoulstoneTrigger(botAI); }
    static Trigger* firestone(ShadowAI* botAI) { return new FirestoneTrigger(botAI); }
    static Trigger* spellstone(ShadowAI* botAI) { return new SpellstoneTrigger(botAI); }
    static Trigger* soulstone(ShadowAI* botAI) { return new SoulstoneTrigger(botAI); }
    static Trigger* corruption(ShadowAI* botAI) { return new CorruptionTrigger(botAI); }
    static Trigger* corruption_on_attacker(ShadowAI* botAI) { return new CorruptionOnAttackerTrigger(botAI); }
    static Trigger* banish(ShadowAI* botAI) { return new BanishTrigger(botAI); }
    static Trigger* fear(ShadowAI* botAI) { return new FearTrigger(botAI); }
    static Trigger* spell_lock(ShadowAI* botAI) { return new SpellLockInterruptSpellTrigger(botAI); }
    static Trigger* devour_magic_purge(ShadowAI* botAI) { return new DevourMagicPurgeTrigger(botAI); }
    static Trigger* devour_magic_cleanse(ShadowAI* botAI) { return new DevourMagicCleanseTrigger(botAI); }
    static Trigger* backlash(ShadowAI* botAI) { return new BacklashTrigger(botAI); }
    static Trigger* immolate(ShadowAI* botAI) { return new ImmolateTrigger(botAI); }
    static Trigger* immolate_on_attacker(ShadowAI* ai) { return new ImmolateOnAttackerTrigger(ai); }
    static Trigger* unstable_affliction(ShadowAI* ai) { return new UnstableAfflictionTrigger(ai); }
    static Trigger* unstable_affliction_on_attacker(ShadowAI* ai) { return new UnstableAfflictionOnAttackerTrigger(ai); }
    static Trigger* haunt(ShadowAI* ai) { return new HauntTrigger(ai); }
    static Trigger* decimation(ShadowAI* ai) { return new DecimationTrigger(ai); }
    static Trigger* life_tap(ShadowAI* ai) { return new LifeTapTrigger(ai); }
    static Trigger* life_tap_glyph_buff(ShadowAI* ai) { return new LifeTapGlyphBuffTrigger(ai); }
    static Trigger* molten_core(ShadowAI* ai) { return new MoltenCoreTrigger(ai); }
    static Trigger* metamorphosis(ShadowAI* ai) { return new MetamorphosisTrigger(ai); }
    static Trigger* demonic_empowerment(ShadowAI* ai) { return new DemonicEmpowermentTrigger(ai); }
    static Trigger* immolation_aura_active(ShadowAI* ai) { return new ImmolationAuraActiveTrigger(ai); }
    static Trigger* metamorphosis_not_active(ShadowAI* ai) { return new MetamorphosisNotActiveTrigger(ai); }
    static Trigger* meta_melee_flee_check(ShadowAI* ai) { return new MetaMeleeEnemyTooCloseForSpellTrigger(ai); }
    static Trigger* curse_of_agony(ShadowAI* botAI) { return new CurseOfAgonyTrigger(botAI); }
    static Trigger* curse_of_agony_on_attacker(ShadowAI* botAI) { return new CurseOfAgonyOnAttackerTrigger(botAI); }
    static Trigger* curse_of_the_elements(ShadowAI* ai) { return new CurseOfTheElementsTrigger(ai); }
    static Trigger* curse_of_doom(ShadowAI* ai) { return new CurseOfDoomTrigger(ai); }
    static Trigger* curse_of_exhaustion(ShadowAI* ai) { return new CurseOfExhaustionTrigger(ai); }
    static Trigger* curse_of_tongues(ShadowAI* ai) { return new CurseOfTonguesTrigger(ai); }
    static Trigger* curse_of_weakness(ShadowAI* ai) { return new CurseOfWeaknessTrigger(ai); }
    static Trigger* wrong_pet(ShadowAI* ai) { return new WrongPetTrigger(ai); }
    static Trigger* rain_of_fire_channel_check(ShadowAI* ai) { return new RainOfFireChannelCheckTrigger(ai); }
};

class WarlockAiObjectContextInternal : public NamedObjectContext<Action>
{
public:
    WarlockAiObjectContextInternal()
    {
        creators["fel armor"] = &WarlockAiObjectContextInternal::fel_armor;
        creators["demon armor"] = &WarlockAiObjectContextInternal::demon_armor;
        creators["demon skin"] = &WarlockAiObjectContextInternal::demon_skin;
        creators["soul link"] = &WarlockAiObjectContextInternal::soul_link;
        creators["create soul shard"] = &WarlockAiObjectContextInternal::create_soul_shard;
        creators["destroy soul shard"] = &WarlockAiObjectContextInternal::destroy_soul_shard;
        creators["create healthstone"] = &WarlockAiObjectContextInternal::create_healthstone;
        creators["create firestone"] = &WarlockAiObjectContextInternal::create_firestone;
        creators["create spellstone"] = &WarlockAiObjectContextInternal::create_spellstone;
        creators["create soulstone"] = &WarlockAiObjectContextInternal::create_soulstone;
        creators["firestone"] = &WarlockAiObjectContextInternal::firestone;
        creators["spellstone"] = &WarlockAiObjectContextInternal::spellstone;
        creators["soulstone self"] = &WarlockAiObjectContextInternal::soulstone_self;
        creators["soulstone master"] = &WarlockAiObjectContextInternal::soulstone_master;
        creators["soulstone tank"] = &WarlockAiObjectContextInternal::soulstone_tank;
        creators["soulstone healer"] = &WarlockAiObjectContextInternal::soulstone_healer;
        creators["summon voidwalker"] = &WarlockAiObjectContextInternal::summon_voidwalker;
        creators["summon felguard"] = &WarlockAiObjectContextInternal::summon_felguard;
        creators["summon felhunter"] = &WarlockAiObjectContextInternal::summon_felhunter;
        creators["summon succubus"] = &WarlockAiObjectContextInternal::summon_succubus;
        creators["summon imp"] = &WarlockAiObjectContextInternal::summon_imp;
        creators["fel domination"] = &WarlockAiObjectContextInternal::fel_domination;
        creators["immolate"] = &WarlockAiObjectContextInternal::immolate;
        creators["immolate on attacker"] = &WarlockAiObjectContextInternal::immolate_on_attacker;
        creators["corruption"] = &WarlockAiObjectContextInternal::corruption;
        creators["corruption on attacker"] = &WarlockAiObjectContextInternal::corruption_on_attacker;
        creators["shadow bolt"] = &WarlockAiObjectContextInternal::shadow_bolt;
        creators["drain soul"] = &WarlockAiObjectContextInternal::drain_soul;
        creators["drain mana"] = &WarlockAiObjectContextInternal::drain_mana;
        creators["drain life"] = &WarlockAiObjectContextInternal::drain_life;
        creators["banish on cc"] = &WarlockAiObjectContextInternal::banish_on_cc;
        creators["fear on cc"] = &WarlockAiObjectContextInternal::fear_on_cc;
        creators["spell lock"] = &WarlockAiObjectContextInternal::spell_lock;
        creators["devour magic purge"] = &WarlockAiObjectContextInternal::devour_magic_purge;
        creators["devour magic cleanse"] = &WarlockAiObjectContextInternal::devour_magic_cleanse;
        creators["seed of corruption"] = &WarlockAiObjectContextInternal::seed_of_corruption;
        creators["seed of corruption on attacker"] = &WarlockAiObjectContextInternal::seed_of_corruption_on_attacker;
        creators["rain of fire"] = &WarlockAiObjectContextInternal::rain_of_fire;
        creators["hellfire"] = &WarlockAiObjectContextInternal::hellfire;
        creators["shadowfury"] = &WarlockAiObjectContextInternal::shadowfury;
        creators["life tap"] = &WarlockAiObjectContextInternal::life_tap;
        creators["incinerate"] = &WarlockAiObjectContextInternal::incinerate;
        creators["conflagrate"] = &WarlockAiObjectContextInternal::conflagrate;
        creators["unstable affliction"] = &WarlockAiObjectContextInternal::unstable_affliction;
        creators["unstable affliction on attacker"] = &WarlockAiObjectContextInternal::unstable_affliction_on_attacker;
        creators["haunt"] = &WarlockAiObjectContextInternal::haunt;
        creators["demonic empowerment"] = &WarlockAiObjectContextInternal::demonic_empowerment;
        creators["metamorphosis"] = &WarlockAiObjectContextInternal::metamorphosis;
        creators["soul fire"] = &WarlockAiObjectContextInternal::soul_fire;
        creators["incinerate"] = &WarlockAiObjectContextInternal::incinerate;
        creators["demon charge"] = &WarlockAiObjectContextInternal::demon_charge;
        creators["shadow cleave"] = &WarlockAiObjectContextInternal::shadow_cleave;
        creators["shadowburn"] = &WarlockAiObjectContextInternal::shadowburn;
        creators["shadowflame"] = &WarlockAiObjectContextInternal::shadowflame;
        creators["immolation aura"] = &WarlockAiObjectContextInternal::immolation_aura;
        creators["chaos bolt"] = &WarlockAiObjectContextInternal::chaos_bolt;
        creators["soulshatter"] = &WarlockAiObjectContextInternal::soulshatter;
        creators["searing pain"] = WarlockAiObjectContextInternal::searing_pain;
        creators["shadow ward"] = &WarlockAiObjectContextInternal::shadow_ward;
        creators["curse of agony"] = &WarlockAiObjectContextInternal::curse_of_agony;
        creators["curse of agony on attacker"] = &WarlockAiObjectContextInternal::curse_of_agony_on_attacker;
        creators["curse of the elements"] = &WarlockAiObjectContextInternal::curse_of_the_elements;
        creators["curse of doom"] = &WarlockAiObjectContextInternal::curse_of_doom;
        creators["curse of exhaustion"] = &WarlockAiObjectContextInternal::curse_of_exhaustion;
        creators["curse of tongues"] = &WarlockAiObjectContextInternal::curse_of_tongues;
        creators["curse of weakness"] = &WarlockAiObjectContextInternal::curse_of_weakness;
    }

private:
    static Action* conflagrate(ShadowAI* botAI) { return new CastConflagrateAction(botAI); }
    static Action* incinerate(ShadowAI* botAI) { return new CastIncinerateAction(botAI); }
    static Action* immolate(ShadowAI* botAI) { return new CastImmolateAction(botAI); }
    static Action* immolate_on_attacker(ShadowAI* botAI) { return new CastImmolateOnAttackerAction(botAI); }
    static Action* fel_armor(ShadowAI* botAI) { return new CastFelArmorAction(botAI); }
    static Action* demon_armor(ShadowAI* botAI) { return new CastDemonArmorAction(botAI); }
    static Action* demon_skin(ShadowAI* botAI) { return new CastDemonSkinAction(botAI); }
    static Action* soul_link(ShadowAI* botAI) { return new CastSoulLinkAction(botAI); }
    static Action* create_soul_shard(ShadowAI* botAI) { return new CreateSoulShardAction(botAI); }
    static Action* destroy_soul_shard(ShadowAI* botAI) { return new DestroySoulShardAction(botAI); }
    static Action* create_healthstone(ShadowAI* botAI) { return new CastCreateHealthstoneAction(botAI); }
    static Action* create_firestone(ShadowAI* botAI) { return new CastCreateFirestoneAction(botAI); }
    static Action* create_spellstone(ShadowAI* botAI) { return new CastCreateSpellstoneAction(botAI); }
    static Action* create_soulstone(ShadowAI* botAI) { return new CastCreateSoulstoneAction(botAI); }
    static Action* firestone(ShadowAI* botAI) { return new UseSpellItemAction(botAI, "firestone", true); }
    static Action* spellstone(ShadowAI* botAI) { return new UseSpellItemAction(botAI, "spellstone", true); }
    static Action* soulstone_self(ShadowAI* botAI) { return new UseSoulstoneSelfAction(botAI); }
    static Action* soulstone_master(ShadowAI* botAI) { return new UseSoulstoneMasterAction(botAI); }
    static Action* soulstone_tank(ShadowAI* botAI) { return new UseSoulstoneTankAction(botAI); }
    static Action* soulstone_healer(ShadowAI* botAI) { return new UseSoulstoneHealerAction(botAI); }
    static Action* summon_voidwalker(ShadowAI* botAI) { return new CastSummonVoidwalkerAction(botAI); }
    static Action* summon_felguard(ShadowAI* botAI) { return new CastSummonFelguardAction(botAI); }
    static Action* summon_felhunter(ShadowAI* botAI) { return new CastSummonFelhunterAction(botAI); }
    static Action* summon_imp(ShadowAI* botAI) { return new CastSummonImpAction(botAI); }
    static Action* summon_succubus(ShadowAI* botAI) { return new CastSummonSuccubusAction(botAI); }
    static Action* fel_domination(ShadowAI* botAI) { return new CastFelDominationAction(botAI); }
    static Action* corruption(ShadowAI* botAI) { return new CastCorruptionAction(botAI); }
    static Action* corruption_on_attacker(ShadowAI* botAI) { return new CastCorruptionOnAttackerAction(botAI); }
    static Action* shadow_bolt(ShadowAI* botAI) { return new CastShadowBoltAction(botAI); }
    static Action* drain_soul(ShadowAI* botAI) { return new CastDrainSoulAction(botAI); }
    static Action* drain_mana(ShadowAI* botAI) { return new CastDrainManaAction(botAI); }
    static Action* drain_life(ShadowAI* botAI) { return new CastDrainLifeAction(botAI); }
    static Action* banish_on_cc(ShadowAI* botAI) { return new CastBanishOnCcAction(botAI); }
    static Action* fear_on_cc(ShadowAI* botAI) { return new CastFearOnCcAction(botAI); }
    static Action* spell_lock(ShadowAI* botAI) { return new CastSpellLockAction(botAI); }
    static Action* devour_magic_purge(ShadowAI* botAI) { return new CastDevourMagicPurgeAction(botAI); }
    static Action* devour_magic_cleanse(ShadowAI* botAI) { return new CastDevourMagicCleanseAction(botAI); }
    static Action* seed_of_corruption(ShadowAI* botAI) { return new CastSeedOfCorruptionAction(botAI); }
    static Action* seed_of_corruption_on_attacker(ShadowAI* botAI) { return new CastSeedOfCorruptionOnAttackerAction(botAI); }
    static Action* rain_of_fire(ShadowAI* botAI) { return new CastRainOfFireAction(botAI); }
    static Action* hellfire(ShadowAI* botAI) { return new CastHellfireAction(botAI); }
    static Action* shadowfury(ShadowAI* botAI) { return new CastShadowfuryAction(botAI); }
    static Action* life_tap(ShadowAI* botAI) { return new CastLifeTapAction(botAI); }
    static Action* unstable_affliction(ShadowAI* ai) { return new CastUnstableAfflictionAction(ai); }
    static Action* unstable_affliction_on_attacker(ShadowAI* ai) { return new CastUnstableAfflictionOnAttackerAction(ai); }
    static Action* haunt(ShadowAI* ai) { return new CastHauntAction(ai); }
    static Action* demonic_empowerment(ShadowAI* ai) { return new CastDemonicEmpowermentAction(ai); }
    static Action* metamorphosis(ShadowAI* ai) { return new CastMetamorphosisAction(ai); }
    static Action* soul_fire(ShadowAI* ai) { return new CastSoulFireAction(ai); }
    static Action* demon_charge(ShadowAI* ai) { return new DemonChargeAction(ai); }
    static Action* shadow_cleave(ShadowAI* ai) { return new ShadowCleaveAction(ai); }
    static Action* shadowburn(ShadowAI* ai) { return new CastShadowburnAction(ai); }
    static Action* shadowflame(ShadowAI* botAI) { return new CastShadowflameAction(botAI); }
    static Action* immolation_aura(ShadowAI* botAI) { return new CastImmolationAuraAction(botAI); }
    static Action* chaos_bolt(ShadowAI* botAI) { return new CastChaosBoltAction(botAI); }
    static Action* soulshatter(ShadowAI* botAI) { return new CastSoulshatterAction(botAI); }
    static Action* searing_pain(ShadowAI* botAI) { return new CastSearingPainAction(botAI); }
    static Action* shadow_ward(ShadowAI* botAI) { return new CastShadowWardAction(botAI); }
    static Action* curse_of_agony(ShadowAI* botAI) { return new CastCurseOfAgonyAction(botAI); }
    static Action* curse_of_agony_on_attacker(ShadowAI* botAI) { return new CastCurseOfAgonyOnAttackerAction(botAI); }
    static Action* curse_of_the_elements(ShadowAI* ai) { return new CastCurseOfTheElementsAction(ai); }
    static Action* curse_of_doom(ShadowAI* ai) { return new CastCurseOfDoomAction(ai); }
    static Action* curse_of_exhaustion(ShadowAI* ai) { return new CastCurseOfExhaustionAction(ai); }
    static Action* curse_of_tongues(ShadowAI* ai) { return new CastCurseOfTonguesAction(ai); }
    static Action* curse_of_weakness(ShadowAI* ai) { return new CastCurseOfWeaknessAction(ai); }
};

SharedNamedObjectContextList<Strategy> WarlockAiObjectContext::sharedStrategyContexts;
SharedNamedObjectContextList<Action> WarlockAiObjectContext::sharedActionContexts;
SharedNamedObjectContextList<Trigger> WarlockAiObjectContext::sharedTriggerContexts;
SharedNamedObjectContextList<UntypedValue> WarlockAiObjectContext::sharedValueContexts;

WarlockAiObjectContext::WarlockAiObjectContext(ShadowAI* botAI)
    : AiObjectContext(botAI, sharedStrategyContexts, sharedActionContexts, sharedTriggerContexts, sharedValueContexts)
{
}

void WarlockAiObjectContext::BuildSharedContexts()
{
    BuildSharedStrategyContexts(sharedStrategyContexts);
    BuildSharedActionContexts(sharedActionContexts);
    BuildSharedTriggerContexts(sharedTriggerContexts);
    BuildSharedValueContexts(sharedValueContexts);
}

void WarlockAiObjectContext::BuildSharedStrategyContexts(SharedNamedObjectContextList<Strategy>& strategyContexts)
{
    AiObjectContext::BuildSharedStrategyContexts(strategyContexts);
    strategyContexts.Add(new WarlockStrategyFactoryInternal());
    strategyContexts.Add(new WarlockCombatStrategyFactoryInternal());
    strategyContexts.Add(new WarlockPetStrategyFactoryInternal());
    strategyContexts.Add(new WarlockSoulstoneStrategyFactoryInternal());
    strategyContexts.Add(new WarlockCurseStrategyFactoryInternal());
    strategyContexts.Add(new WarlockWeaponStoneStrategyFactoryInternal());
}

void WarlockAiObjectContext::BuildSharedActionContexts(SharedNamedObjectContextList<Action>& actionContexts)
{
    AiObjectContext::BuildSharedActionContexts(actionContexts);
    actionContexts.Add(new WarlockAiObjectContextInternal());
}

void WarlockAiObjectContext::BuildSharedTriggerContexts(SharedNamedObjectContextList<Trigger>& triggerContexts)
{
    AiObjectContext::BuildSharedTriggerContexts(triggerContexts);
    triggerContexts.Add(new WarlockTriggerFactoryInternal());
}

void WarlockAiObjectContext::BuildSharedValueContexts(SharedNamedObjectContextList<UntypedValue>& valueContexts)
{
    AiObjectContext::BuildSharedValueContexts(valueContexts);
}
