/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#include "DKAiObjectContext.h"

#include "BloodDKStrategy.h"
#include "DKActions.h"
#include "DKTriggers.h"
#include "FrostDKStrategy.h"
#include "GenericDKNonCombatStrategy.h"
#include "GenericTriggers.h"
#include "Shadows.h"
#include "PullStrategy.h"
#include "UnholyDKStrategy.h"

class DeathKnightStrategyFactoryInternal : public NamedObjectContext<Strategy>
{
public:
    DeathKnightStrategyFactoryInternal()
    {
        creators["nc"] = &DeathKnightStrategyFactoryInternal::nc;
        creators["pull"] = &DeathKnightStrategyFactoryInternal::pull;
        creators["frost aoe"] = &DeathKnightStrategyFactoryInternal::frost_aoe;
        creators["unholy aoe"] = &DeathKnightStrategyFactoryInternal::unholy_aoe;
    }

private:
    static Strategy* nc(ShadowAI* botAI) { return new GenericDKNonCombatStrategy(botAI); }
    static Strategy* pull(ShadowAI* botAI) { return new PullStrategy(botAI, "icy touch"); }
    static Strategy* frost_aoe(ShadowAI* botAI) { return new FrostDKAoeStrategy(botAI); }
    static Strategy* unholy_aoe(ShadowAI* botAI) { return new UnholyDKAoeStrategy(botAI); }
};

class DeathKnightCombatStrategyFactoryInternal : public NamedObjectContext<Strategy>
{
public:
    DeathKnightCombatStrategyFactoryInternal() : NamedObjectContext<Strategy>(false, true)
    {
        creators["tank"] = &DeathKnightCombatStrategyFactoryInternal::blood;
        creators["blood"] = &DeathKnightCombatStrategyFactoryInternal::blood;
        creators["frost"] = &DeathKnightCombatStrategyFactoryInternal::frost_dps;
        creators["unholy"] = &DeathKnightCombatStrategyFactoryInternal::unholy_dps;
    }

private:
    static Strategy* frost_dps(ShadowAI* botAI) { return new FrostDKStrategy(botAI); }
    static Strategy* unholy_dps(ShadowAI* botAI) { return new UnholyDKStrategy(botAI); }
    static Strategy* tank(ShadowAI* botAI) { return new BloodDKStrategy(botAI); }
    static Strategy* blood(ShadowAI* botAI) { return new BloodDKStrategy(botAI); }
};

class DeathKnightDKBuffStrategyFactoryInternal : public NamedObjectContext<Strategy>
{
public:
    DeathKnightDKBuffStrategyFactoryInternal() : NamedObjectContext<Strategy>(false, true)
    {
        creators["bdps"] = &DeathKnightDKBuffStrategyFactoryInternal::bdps;
    }

private:
    static Strategy* bdps(ShadowAI* botAI) { return new DKBuffDpsStrategy(botAI); }
};

class DeathKnightTriggerFactoryInternal : public NamedObjectContext<Trigger>
{
public:
    DeathKnightTriggerFactoryInternal()
    {
        creators["bone shield"] = &DeathKnightTriggerFactoryInternal::bone_shield;
        creators["pestilence glyph"] = &DeathKnightTriggerFactoryInternal::pestilence_glyph;
        creators["blood strike"] = &DeathKnightTriggerFactoryInternal::blood_strike;
        creators["plague strike"] = &DeathKnightTriggerFactoryInternal::plague_strike;
        creators["plague strike on attacker"] = &DeathKnightTriggerFactoryInternal::plague_strike_on_attacker;
        creators["icy touch"] = &DeathKnightTriggerFactoryInternal::icy_touch;
        creators["icy touch 3s"] = &DeathKnightTriggerFactoryInternal::icy_touch_3s;
        creators["dd cd and icy touch 3s"] = &DeathKnightTriggerFactoryInternal::dd_cd_and_icy_touch_3s;
        creators["death coil"] = &DeathKnightTriggerFactoryInternal::death_coil;
        creators["icy touch on attacker"] = &DeathKnightTriggerFactoryInternal::icy_touch_on_attacker;
        creators["improved icy talons"] = &DeathKnightTriggerFactoryInternal::improved_icy_talons;
        creators["plague strike"] = &DeathKnightTriggerFactoryInternal::plague_strike;
        creators["plague strike 3s"] = &DeathKnightTriggerFactoryInternal::plague_strike_3s;
        creators["dd cd and plague strike 3s"] = &DeathKnightTriggerFactoryInternal::dd_cd_and_plague_strike_3s;
        creators["horn of winter"] = &DeathKnightTriggerFactoryInternal::horn_of_winter;
        creators["mind freeze"] = &DeathKnightTriggerFactoryInternal::mind_freeze;
        creators["mind freeze on enemy healer"] = &DeathKnightTriggerFactoryInternal::mind_freeze_on_enemy_healer;
        creators["strangulate"] = &DeathKnightTriggerFactoryInternal::strangulate;
        creators["strangulate on enemy healer"] = &DeathKnightTriggerFactoryInternal::strangulate_on_enemy_healer;
        creators["blood tap"] = &DeathKnightTriggerFactoryInternal::blood_tap;
        creators["raise dead"] = &DeathKnightTriggerFactoryInternal::raise_dead;
        creators["chains of ice"] = &DeathKnightTriggerFactoryInternal::chains_of_ice;
        creators["unbreakable armor"] = &DeathKnightTriggerFactoryInternal::unbreakable_armor;
        creators["high blood rune"] = &DeathKnightTriggerFactoryInternal::high_blood_rune;
        creators["high frost rune"] = &DeathKnightTriggerFactoryInternal::high_frost_rune;
        creators["high unholy rune"] = &DeathKnightTriggerFactoryInternal::high_unholy_rune;
        creators["no rune"] = &DeathKnightTriggerFactoryInternal::no_rune;
        creators["freezing fog"] = &DeathKnightTriggerFactoryInternal::freezing_fog;
        creators["no desolation"] = &DeathKnightTriggerFactoryInternal::no_desolation;
        creators["dd cd and no desolation"] = &DeathKnightTriggerFactoryInternal::dd_cd_and_no_desolation;
        creators["death and decay cooldown"] = &DeathKnightTriggerFactoryInternal::death_and_decay_cooldown;
        creators["army of the dead"] = &DeathKnightTriggerFactoryInternal::army_of_the_dead;
    }

private:
    static Trigger* bone_shield(ShadowAI* botAI) { return new BoneShieldTrigger(botAI); }
    static Trigger* pestilence_glyph(ShadowAI* botAI) { return new PestilenceGlyphTrigger(botAI); }
    static Trigger* blood_strike(ShadowAI* botAI) { return new BloodStrikeTrigger(botAI); }
    static Trigger* plague_strike(ShadowAI* botAI) { return new PlagueStrikeDebuffTrigger(botAI); }
    static Trigger* plague_strike_3s(ShadowAI* botAI) { return new PlagueStrike3sDebuffTrigger(botAI); }
    static Trigger* dd_cd_and_plague_strike_3s(ShadowAI* botAI)
    {
        return new TwoTriggers(botAI, "death and decay cooldown", "plague strike 3s");
    }
    static Trigger* plague_strike_on_attacker(ShadowAI* botAI)
    {
        return new PlagueStrikeDebuffOnAttackerTrigger(botAI);
    }
    static Trigger* icy_touch(ShadowAI* botAI) { return new IcyTouchDebuffTrigger(botAI); }
    static Trigger* icy_touch_3s(ShadowAI* botAI) { return new IcyTouch3sDebuffTrigger(botAI); }
    static Trigger* dd_cd_and_icy_touch_3s(ShadowAI* botAI)
    {
        return new TwoTriggers(botAI, "death and decay cooldown", "icy touch 3s");
    }
    static Trigger* death_coil(ShadowAI* botAI) { return new DeathCoilTrigger(botAI); }
    static Trigger* icy_touch_on_attacker(ShadowAI* botAI) { return new IcyTouchDebuffOnAttackerTrigger(botAI); }
    static Trigger* improved_icy_talons(ShadowAI* botAI) { return new ImprovedIcyTalonsTrigger(botAI); }
    static Trigger* horn_of_winter(ShadowAI* botAI) { return new HornOfWinterTrigger(botAI); }
    static Trigger* mind_freeze(ShadowAI* botAI) { return new MindFreezeInterruptSpellTrigger(botAI); }
    static Trigger* mind_freeze_on_enemy_healer(ShadowAI* botAI)
    {
        return new MindFreezeOnEnemyHealerTrigger(botAI);
    }
    static Trigger* strangulate(ShadowAI* botAI) { return new StrangulateInterruptSpellTrigger(botAI); }
    static Trigger* strangulate_on_enemy_healer(ShadowAI* botAI)
    {
        return new StrangulateOnEnemyHealerTrigger(botAI);
    }
    static Trigger* blood_tap(ShadowAI* botAI) { return new BloodTapTrigger(botAI); }
    static Trigger* raise_dead(ShadowAI* botAI) { return new RaiseDeadTrigger(botAI); }
    static Trigger* chains_of_ice(ShadowAI* botAI) { return new ChainsOfIceSnareTrigger(botAI); }
    static Trigger* unbreakable_armor(ShadowAI* botAI) { return new UnbreakableArmorTrigger(botAI); }
    static Trigger* high_blood_rune(ShadowAI* botAI) { return new HighBloodRuneTrigger(botAI); }
    static Trigger* high_frost_rune(ShadowAI* botAI) { return new HighFrostRuneTrigger(botAI); }
    static Trigger* high_unholy_rune(ShadowAI* botAI) { return new HighUnholyRuneTrigger(botAI); }
    static Trigger* no_rune(ShadowAI* botAI) { return new NoRuneTrigger(botAI); }
    static Trigger* freezing_fog(ShadowAI* botAI) { return new FreezingFogTrigger(botAI); }
    static Trigger* no_desolation(ShadowAI* botAI) { return new DesolationTrigger(botAI); }
    static Trigger* dd_cd_and_no_desolation(ShadowAI* botAI)
    {
        return new TwoTriggers(botAI, "death and decay cooldown", "no desolation");
    }
    static Trigger* death_and_decay_cooldown(ShadowAI* botAI) { return new DeathAndDecayCooldownTrigger(botAI); }
    static Trigger* army_of_the_dead(ShadowAI* botAI) { return new ArmyOfTheDeadTrigger(botAI); }
};

class DeathKnightAiObjectContextInternal : public NamedObjectContext<Action>
{
public:
    DeathKnightAiObjectContextInternal()
    {
        // Unholy
        creators["bone shield"] = &DeathKnightAiObjectContextInternal::bone_shield;
        creators["plague strike"] = &DeathKnightAiObjectContextInternal::plague_strike;
        creators["plague strike on attacker"] = &DeathKnightAiObjectContextInternal::plague_strike_on_attacker;
        creators["death grip"] = &DeathKnightAiObjectContextInternal::death_grip;
        creators["death coil"] = &DeathKnightAiObjectContextInternal::death_coil;
        creators["death strike"] = &DeathKnightAiObjectContextInternal::death_strike;
        creators["unholy blight"] = &DeathKnightAiObjectContextInternal::unholy_blight;
        creators["scourge strike"] = &DeathKnightAiObjectContextInternal::scourge_strike;
        creators["death and decay"] = &DeathKnightAiObjectContextInternal::death_and_decay;
        creators["unholy presence"] = &DeathKnightAiObjectContextInternal::unholy_presence;
        creators["raise dead"] = &DeathKnightAiObjectContextInternal::raise_dead;
        creators["army of the dead"] = &DeathKnightAiObjectContextInternal::army_of_the_dead;
        creators["summon gargoyle"] = &DeathKnightAiObjectContextInternal::summon_gargoyle;
        creators["anti magic shell"] = &DeathKnightAiObjectContextInternal::anti_magic_shell;
        creators["anti magic zone"] = &DeathKnightAiObjectContextInternal::anti_magic_zone;
        creators["ghoul frenzy"] = &DeathKnightAiObjectContextInternal::ghoul_frenzy;
        creators["corpse explosion"] = &DeathKnightAiObjectContextInternal::corpse_explosion;
        // Frost
        creators["icy touch"] = &DeathKnightAiObjectContextInternal::icy_touch;
        creators["icy touch on attacker"] = &DeathKnightAiObjectContextInternal::icy_touch_on_attacker;
        creators["obliterate"] = &DeathKnightAiObjectContextInternal::obliterate;
        creators["howling blast"] = &DeathKnightAiObjectContextInternal::howling_blast;
        creators["frost strike"] = &DeathKnightAiObjectContextInternal::frost_strike;
        creators["chains of ice"] = &DeathKnightAiObjectContextInternal::chains_of_ice;
        creators["rune strike"] = &DeathKnightAiObjectContextInternal::rune_strike;
        // creators["icy clutch"] = &DeathKnightAiObjectContextInternal::icy_clutch;
        creators["horn of winter"] = &DeathKnightAiObjectContextInternal::horn_of_winter;
        creators["killing machine"] = &DeathKnightAiObjectContextInternal::killing_machine;
        creators["frost presence"] = &DeathKnightAiObjectContextInternal::frost_presence;
        creators["deathchill"] = &DeathKnightAiObjectContextInternal::deathchill;
        creators["icebound fortitude"] = &DeathKnightAiObjectContextInternal::icebound_fortitude;
        creators["mind freeze"] = &DeathKnightAiObjectContextInternal::mind_freeze;
        creators["empower rune weapon"] = &DeathKnightAiObjectContextInternal::empower_rune_weapon;
        creators["hungering cold"] = &DeathKnightAiObjectContextInternal::hungering_cold;
        creators["unbreakable armor"] = &DeathKnightAiObjectContextInternal::unbreakable_armor;
        creators["improved icy talons"] = &DeathKnightAiObjectContextInternal::improved_icy_talons;
        // blood
        creators["blood strike"] = &DeathKnightAiObjectContextInternal::blood_strike;
        creators["blood tap"] = &DeathKnightAiObjectContextInternal::blood_tap;
        creators["pestilence"] = &DeathKnightAiObjectContextInternal::pestilence;
        creators["strangulate"] = &DeathKnightAiObjectContextInternal::strangulate;
        creators["blood boil"] = &DeathKnightAiObjectContextInternal::blood_boil;
        creators["heart strike"] = &DeathKnightAiObjectContextInternal::heart_strike;
        creators["mark of_blood"] = &DeathKnightAiObjectContextInternal::mark_of_blood;
        creators["blood presence"] = &DeathKnightAiObjectContextInternal::blood_presence;
        creators["rune tap"] = &DeathKnightAiObjectContextInternal::rune_tap;
        creators["vampiric blood"] = &DeathKnightAiObjectContextInternal::vampiric_blood;
        creators["death pact"] = &DeathKnightAiObjectContextInternal::death_pact;
        creators["death rune_mastery"] = &DeathKnightAiObjectContextInternal::death_rune_mastery;
        // creators["hysteria"] = &DeathKnightAiObjectContextInternal::hysteria;
        creators["dancing rune weapon"] = &DeathKnightAiObjectContextInternal::dancing_rune_weapon;
        creators["dark command"] = &DeathKnightAiObjectContextInternal::dark_command;
    }

private:
    // Unholy
    static Action* bone_shield(ShadowAI* botAI) { return new CastBoneShieldAction(botAI); }
    static Action* plague_strike(ShadowAI* botAI) { return new CastPlagueStrikeAction(botAI); }
    static Action* plague_strike_on_attacker(ShadowAI* botAI) { return new CastPlagueStrikeOnAttackerAction(botAI); }
    static Action* death_grip(ShadowAI* botAI) { return new CastDeathGripAction(botAI); }
    static Action* death_coil(ShadowAI* botAI) { return new CastDeathCoilAction(botAI); }
    static Action* death_strike(ShadowAI* botAI) { return new CastDeathStrikeAction(botAI); }
    static Action* unholy_blight(ShadowAI* botAI) { return new CastUnholyBlightAction(botAI); }
    static Action* scourge_strike(ShadowAI* botAI) { return new CastScourgeStrikeAction(botAI); }
    static Action* death_and_decay(ShadowAI* botAI) { return new CastDeathAndDecayAction(botAI); }
    static Action* unholy_presence(ShadowAI* botAI) { return new CastUnholyPresenceAction(botAI); }
    static Action* raise_dead(ShadowAI* botAI) { return new CastRaiseDeadAction(botAI); }
    static Action* army_of_the_dead(ShadowAI* botAI) { return new CastArmyOfTheDeadAction(botAI); }
    static Action* summon_gargoyle(ShadowAI* botAI) { return new CastSummonGargoyleAction(botAI); }
    static Action* anti_magic_shell(ShadowAI* botAI) { return new CastAntiMagicShellAction(botAI); }
    static Action* anti_magic_zone(ShadowAI* botAI) { return new CastAntiMagicZoneAction(botAI); }
    static Action* ghoul_frenzy(ShadowAI* botAI) { return new CastGhoulFrenzyAction(botAI); }
    static Action* corpse_explosion(ShadowAI* botAI) { return new CastCorpseExplosionAction(botAI); }
    // Frost
    static Action* icy_touch(ShadowAI* botAI) { return new CastIcyTouchAction(botAI); }
    static Action* icy_touch_on_attacker(ShadowAI* botAI) { return new CastIcyTouchOnAttackerAction(botAI); }
    static Action* obliterate(ShadowAI* botAI) { return new CastObliterateAction(botAI); }
    static Action* howling_blast(ShadowAI* botAI) { return new CastHowlingBlastAction(botAI); }
    static Action* frost_strike(ShadowAI* botAI) { return new CastFrostStrikeAction(botAI); }
    static Action* chains_of_ice(ShadowAI* botAI) { return new CastChainsOfIceAction(botAI); }
    static Action* rune_strike(ShadowAI* botAI) { return new CastRuneStrikeAction(botAI); }
    // static Action* icy_clutch(ShadowAI* botAI) { return new CastIcyClutchAction(botAI); }
    static Action* horn_of_winter(ShadowAI* botAI) { return new CastHornOfWinterAction(botAI); }
    static Action* killing_machine(ShadowAI* botAI) { return new CastKillingMachineAction(botAI); }
    static Action* frost_presence(ShadowAI* botAI) { return new CastFrostPresenceAction(botAI); }
    static Action* deathchill(ShadowAI* botAI) { return new CastDeathchillAction(botAI); }
    static Action* icebound_fortitude(ShadowAI* botAI) { return new CastIceboundFortitudeAction(botAI); }
    static Action* mind_freeze(ShadowAI* botAI) { return new CastMindFreezeAction(botAI); }
    static Action* empower_rune_weapon(ShadowAI* botAI) { return new CastEmpowerRuneWeaponAction(botAI); }
    static Action* hungering_cold(ShadowAI* botAI) { return new CastHungeringColdAction(botAI); }
    static Action* unbreakable_armor(ShadowAI* botAI) { return new CastUnbreakableArmorAction(botAI); }
    static Action* improved_icy_talons(ShadowAI* botAI) { return new CastImprovedIcyTalonsAction(botAI); }
    // blood
    static Action* blood_strike(ShadowAI* botAI) { return new CastBloodStrikeAction(botAI); }
    static Action* blood_tap(ShadowAI* botAI) { return new CastBloodTapAction(botAI); }
    static Action* pestilence(ShadowAI* botAI) { return new CastPestilenceAction(botAI); }
    static Action* strangulate(ShadowAI* botAI) { return new CastStrangulateAction(botAI); }
    static Action* blood_boil(ShadowAI* botAI) { return new CastBloodBoilAction(botAI); }
    static Action* heart_strike(ShadowAI* botAI) { return new CastHeartStrikeAction(botAI); }
    static Action* mark_of_blood(ShadowAI* botAI) { return new CastMarkOfBloodAction(botAI); }
    static Action* blood_presence(ShadowAI* botAI) { return new CastBloodPresenceAction(botAI); }
    static Action* rune_tap(ShadowAI* botAI) { return new CastRuneTapAction(botAI); }
    static Action* vampiric_blood(ShadowAI* botAI) { return new CastVampiricBloodAction(botAI); }
    static Action* death_pact(ShadowAI* botAI) { return new CastDeathPactAction(botAI); }
    static Action* death_rune_mastery(ShadowAI* botAI) { return new CastDeathRuneMasteryAction(botAI); }
    // static Action* hysteria(ShadowAI* botAI) { return new CastHysteriaAction(botAI); }
    static Action* dancing_rune_weapon(ShadowAI* botAI) { return new CastDancingRuneWeaponAction(botAI); }
    static Action* dark_command(ShadowAI* botAI) { return new CastDarkCommandAction(botAI); }
    static Action* mind_freeze_on_enemy_healer(ShadowAI* botAI)
    {
        return new CastMindFreezeOnEnemyHealerAction(botAI);
    }
};

SharedNamedObjectContextList<Strategy> DKAiObjectContext::sharedStrategyContexts;
SharedNamedObjectContextList<Action> DKAiObjectContext::sharedActionContexts;
SharedNamedObjectContextList<Trigger> DKAiObjectContext::sharedTriggerContexts;
SharedNamedObjectContextList<UntypedValue> DKAiObjectContext::sharedValueContexts;

DKAiObjectContext::DKAiObjectContext(ShadowAI* botAI)
    : AiObjectContext(botAI, sharedStrategyContexts, sharedActionContexts, sharedTriggerContexts, sharedValueContexts)
{
}

void DKAiObjectContext::BuildSharedContexts()
{
    BuildSharedStrategyContexts(sharedStrategyContexts);
    BuildSharedActionContexts(sharedActionContexts);
    BuildSharedTriggerContexts(sharedTriggerContexts);
    BuildSharedValueContexts(sharedValueContexts);
}

void DKAiObjectContext::BuildSharedStrategyContexts(SharedNamedObjectContextList<Strategy>& strategyContexts)
{
    AiObjectContext::BuildSharedStrategyContexts(strategyContexts);
    strategyContexts.Add(new DeathKnightStrategyFactoryInternal());
    strategyContexts.Add(new DeathKnightCombatStrategyFactoryInternal());
    strategyContexts.Add(new DeathKnightDKBuffStrategyFactoryInternal());
}

void DKAiObjectContext::BuildSharedActionContexts(SharedNamedObjectContextList<Action>& actionContexts)
{
    AiObjectContext::BuildSharedActionContexts(actionContexts);
    actionContexts.Add(new DeathKnightAiObjectContextInternal());
}

void DKAiObjectContext::BuildSharedTriggerContexts(SharedNamedObjectContextList<Trigger>& triggerContexts)
{
    AiObjectContext::BuildSharedTriggerContexts(triggerContexts);
    triggerContexts.Add(new DeathKnightTriggerFactoryInternal());
}

void DKAiObjectContext::BuildSharedValueContexts(SharedNamedObjectContextList<UntypedValue>& valueContexts)
{
    AiObjectContext::BuildSharedValueContexts(valueContexts);
}
