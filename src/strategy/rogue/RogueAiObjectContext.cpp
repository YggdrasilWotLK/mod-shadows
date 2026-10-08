/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#include "RogueAiObjectContext.h"

#include "AiObjectContext.h"
#include "AssassinationRogueStrategy.h"
#include "DpsRogueStrategy.h"
#include "GenericRogueNonCombatStrategy.h"
#include "NamedObjectContext.h"
#include "Shadows.h"
#include "PullStrategy.h"
#include "RogueActions.h"
#include "RogueComboActions.h"
#include "RogueFinishingActions.h"
#include "RogueOpeningActions.h"
#include "RogueTriggers.h"

class RogueStrategyFactoryInternal : public NamedObjectContext<Strategy>
{
public:
    RogueStrategyFactoryInternal()
    {
        creators["nc"] = &RogueStrategyFactoryInternal::nc;
        creators["pull"] = &RogueStrategyFactoryInternal::pull;
        creators["aoe"] = &RogueStrategyFactoryInternal::aoe;
        creators["boost"] = &RogueStrategyFactoryInternal::boost;
        creators["stealthed"] = &RogueStrategyFactoryInternal::stealthed;
        creators["stealth"] = &RogueStrategyFactoryInternal::stealth;
        creators["cc"] = &RogueStrategyFactoryInternal::cc;
    }

private:
    static Strategy* boost(ShadowAI* botAI) { return new RogueBoostStrategy(botAI); }
    static Strategy* aoe(ShadowAI* botAI) { return new RogueAoeStrategy(botAI); }
    static Strategy* nc(ShadowAI* botAI) { return new GenericRogueNonCombatStrategy(botAI); }
    static Strategy* pull(ShadowAI* botAI) { return new PullStrategy(botAI, "shoot"); }
    static Strategy* stealthed(ShadowAI* botAI) { return new StealthedRogueStrategy(botAI); }
    static Strategy* stealth(ShadowAI* botAI) { return new StealthStrategy(botAI); }
    static Strategy* cc(ShadowAI* botAI) { return new RogueCcStrategy(botAI); }
};

class RogueCombatStrategyFactoryInternal : public NamedObjectContext<Strategy>
{
public:
    RogueCombatStrategyFactoryInternal() : NamedObjectContext<Strategy>(false, true)
    {
        creators["dps"] = &RogueCombatStrategyFactoryInternal::dps;
        creators["melee"] = &RogueCombatStrategyFactoryInternal::melee;
    }

private:
    static Strategy* dps(ShadowAI* botAI) { return new DpsRogueStrategy(botAI); }
    static Strategy* melee(ShadowAI* botAI) { return new AssassinationRogueStrategy(botAI); }
};

class RogueTriggerFactoryInternal : public NamedObjectContext<Trigger>
{
public:
    RogueTriggerFactoryInternal()
    {
        creators["kick"] = &RogueTriggerFactoryInternal::kick;
        creators["rupture"] = &RogueTriggerFactoryInternal::rupture;
        creators["slice and dice"] = &RogueTriggerFactoryInternal::slice_and_dice;
        creators["hunger for blood"] = &RogueTriggerFactoryInternal::hunger_for_blood;
        creators["expose armor"] = &RogueTriggerFactoryInternal::expose_armor;
        creators["kick on enemy healer"] = &RogueTriggerFactoryInternal::kick_on_enemy_healer;
        creators["unstealth"] = &RogueTriggerFactoryInternal::unstealth;
        creators["sap"] = &RogueTriggerFactoryInternal::sap;
        creators["in stealth"] = &RogueTriggerFactoryInternal::in_stealth;
        creators["no stealth"] = &RogueTriggerFactoryInternal::no_stealth;
        creators["stealth"] = &RogueTriggerFactoryInternal::stealth;
        creators["sprint"] = &RogueTriggerFactoryInternal::sprint;
        creators["main hand weapon no enchant"] = &RogueTriggerFactoryInternal::main_hand_weapon_no_enchant;
        creators["off hand weapon no enchant"] = &RogueTriggerFactoryInternal::off_hand_weapon_no_enchant;
        creators["tricks of the trade on main tank"] = &RogueTriggerFactoryInternal::tricks_of_the_trade_on_main_tank;
        creators["adrenaline rush"] = &RogueTriggerFactoryInternal::adrenaline_rush;
        creators["blade fury"] = &RogueTriggerFactoryInternal::blade_fury;
    }

private:
    static Trigger* adrenaline_rush(ShadowAI* botAI) { return new AdrenalineRushTrigger(botAI); }
    static Trigger* blade_fury(ShadowAI* botAI) { return new BladeFuryTrigger(botAI); }
    static Trigger* kick(ShadowAI* botAI) { return new KickInterruptSpellTrigger(botAI); }
    static Trigger* rupture(ShadowAI* botAI) { return new RuptureTrigger(botAI); }
    static Trigger* slice_and_dice(ShadowAI* botAI) { return new SliceAndDiceTrigger(botAI); }
    static Trigger* hunger_for_blood(ShadowAI* botAI) { return new HungerForBloodTrigger(botAI); }
    static Trigger* expose_armor(ShadowAI* botAI) { return new ExposeArmorTrigger(botAI); }
    static Trigger* kick_on_enemy_healer(ShadowAI* botAI) { return new KickInterruptEnemyHealerSpellTrigger(botAI); }
    static Trigger* unstealth(ShadowAI* botAI) { return new UnstealthTrigger(botAI); }
    static Trigger* sap(ShadowAI* botAI) { return new SapTrigger(botAI); }
    static Trigger* in_stealth(ShadowAI* botAI) { return new InStealthTrigger(botAI); }
    static Trigger* no_stealth(ShadowAI* botAI) { return new NoStealthTrigger(botAI); }
    static Trigger* stealth(ShadowAI* botAI) { return new StealthTrigger(botAI); }
    static Trigger* sprint(ShadowAI* botAI) { return new SprintTrigger(botAI); }
    static Trigger* main_hand_weapon_no_enchant(ShadowAI* ai) { return new MainHandWeaponNoEnchantTrigger(ai); }
    static Trigger* off_hand_weapon_no_enchant(ShadowAI* ai) { return new OffHandWeaponNoEnchantTrigger(ai); }
    static Trigger* tricks_of_the_trade_on_main_tank(ShadowAI* ai)
    {
        return new TricksOfTheTradeOnMainTankTrigger(ai);
    }
};

class RogueAiObjectContextInternal : public NamedObjectContext<Action>
{
public:
    RogueAiObjectContextInternal()
    {
        creators["riposte"] = &RogueAiObjectContextInternal::riposte;
        creators["mutilate"] = &RogueAiObjectContextInternal::mutilate;
        creators["sinister strike"] = &RogueAiObjectContextInternal::sinister_strike;
        creators["gouge"] = &RogueAiObjectContextInternal::gouge;
        creators["kidney shot"] = &RogueAiObjectContextInternal::kidney_shot;
        creators["rupture"] = &RogueAiObjectContextInternal::rupture;
        creators["slice and dice"] = &RogueAiObjectContextInternal::slice_and_dice;
        creators["hunger for blood"] = &RogueAiObjectContextInternal::hunger_for_blood;
        creators["eviscerate"] = &RogueAiObjectContextInternal::eviscerate;
        creators["vanish"] = &RogueAiObjectContextInternal::vanish;
        creators["evasion"] = &RogueAiObjectContextInternal::evasion;
        creators["cloak of shadows"] = &RogueAiObjectContextInternal::cloak_of_shadows;
        creators["kick"] = &RogueAiObjectContextInternal::kick;
        creators["feint"] = &RogueAiObjectContextInternal::feint;
        creators["backstab"] = &RogueAiObjectContextInternal::backstab;
        creators["expose armor"] = &RogueAiObjectContextInternal::expose_armor;
        creators["kick on enemy healer"] = &RogueAiObjectContextInternal::kick_on_enemy_healer;
        creators["blade flurry"] = &RogueAiObjectContextInternal::blade_flurry;
        creators["adrenaline rush"] = &RogueAiObjectContextInternal::adrenaline_rush;
        creators["ambush"] = &RogueAiObjectContextInternal::ambush;
        creators["stealth"] = &RogueAiObjectContextInternal::stealth;
        creators["sprint"] = &RogueAiObjectContextInternal::sprint;
        creators["garrote"] = &RogueAiObjectContextInternal::garrote;
        creators["cheap shot"] = &RogueAiObjectContextInternal::cheap_shot;
        creators["blind"] = &RogueAiObjectContextInternal::blind;
        creators["unstealth"] = &RogueAiObjectContextInternal::unstealth;
        creators["sap"] = &RogueAiObjectContextInternal::sap;
        creators["check stealth"] = &RogueAiObjectContextInternal::check_stealth;
        creators["envenom"] = &RogueAiObjectContextInternal::envenom;
        creators["tricks of the trade on main tank"] = &RogueAiObjectContextInternal::tricks_of_the_trade_on_main_tank;
        creators["use instant poison on main hand"] = &RogueAiObjectContextInternal::use_instant_poison;
        creators["use deadly poison on off hand"] = &RogueAiObjectContextInternal::use_deadly_poison;
        creators["use instant poison on off hand"] = &RogueAiObjectContextInternal::use_instant_poison_off_hand;
        creators["fan of knives"] = &RogueAiObjectContextInternal::fan_of_knives;
        creators["killing spree"] = &RogueAiObjectContextInternal::killing_spree;
    }

private:
    static Action* adrenaline_rush(ShadowAI* botAI) { return new CastAdrenalineRushAction(botAI); }
    static Action* blade_flurry(ShadowAI* botAI) { return new CastBladeFlurryAction(botAI); }
    static Action* riposte(ShadowAI* botAI) { return new CastRiposteAction(botAI); }
    static Action* mutilate(ShadowAI* botAI) { return new CastMutilateAction(botAI); }
    static Action* sinister_strike(ShadowAI* botAI) { return new CastSinisterStrikeAction(botAI); }
    static Action* gouge(ShadowAI* botAI) { return new CastGougeAction(botAI); }
    static Action* kidney_shot(ShadowAI* botAI) { return new CastKidneyShotAction(botAI); }
    static Action* rupture(ShadowAI* botAI) { return new CastRuptureAction(botAI); }
    static Action* slice_and_dice(ShadowAI* botAI) { return new CastSliceAndDiceAction(botAI); }
    static Action* hunger_for_blood(ShadowAI* botAI) { return new CastHungerForBloodAction(botAI); }
    static Action* eviscerate(ShadowAI* botAI) { return new CastEviscerateAction(botAI); }
    static Action* vanish(ShadowAI* botAI) { return new CastVanishAction(botAI); }
    static Action* evasion(ShadowAI* botAI) { return new CastEvasionAction(botAI); }
    static Action* cloak_of_shadows(ShadowAI* botAI) { return new CastCloakOfShadowsAction(botAI); }
    static Action* kick(ShadowAI* botAI) { return new CastKickAction(botAI); }
    static Action* feint(ShadowAI* botAI) { return new CastFeintAction(botAI); }
    static Action* backstab(ShadowAI* botAI) { return new CastBackstabAction(botAI); }
    static Action* expose_armor(ShadowAI* botAI) { return new CastExposeArmorAction(botAI); }
    static Action* kick_on_enemy_healer(ShadowAI* botAI) { return new CastKickOnEnemyHealerAction(botAI); }
    static Action* ambush(ShadowAI* botAI) { return new CastAmbushAction(botAI); }
    static Action* stealth(ShadowAI* botAI) { return new CastStealthAction(botAI); }
    static Action* sprint(ShadowAI* botAI) { return new CastSprintAction(botAI); }
    static Action* garrote(ShadowAI* botAI) { return new CastGarroteAction(botAI); }
    static Action* cheap_shot(ShadowAI* botAI) { return new CastCheapShotAction(botAI); }
    static Action* blind(ShadowAI* botAI) { return new CastBlindAction(botAI); }
    static Action* check_stealth(ShadowAI* botAI) { return new CheckStealthAction(botAI); }
    static Action* sap(ShadowAI* botAI) { return new CastSapAction(botAI); }
    static Action* unstealth(ShadowAI* botAI) { return new UnstealthAction(botAI); }
    static Action* envenom(ShadowAI* ai) { return new CastEnvenomAction(ai); }
    static Action* tricks_of_the_trade_on_main_tank(ShadowAI* ai)
    {
        return new CastTricksOfTheTradeOnMainTankAction(ai);
    }
    static Action* use_instant_poison(ShadowAI* ai) { return new UseInstantPoisonAction(ai); }
    static Action* use_deadly_poison(ShadowAI* ai) { return new UseDeadlyPoisonAction(ai); }
    static Action* use_instant_poison_off_hand(ShadowAI* ai) { return new UseInstantPoisonOffHandAction(ai); }
    static Action* fan_of_knives(ShadowAI* ai) { return new FanOfKnivesAction(ai); }
    static Action* killing_spree(ShadowAI* ai) { return new CastKillingSpreeAction(ai); }
};

SharedNamedObjectContextList<Strategy> RogueAiObjectContext::sharedStrategyContexts;
SharedNamedObjectContextList<Action> RogueAiObjectContext::sharedActionContexts;
SharedNamedObjectContextList<Trigger> RogueAiObjectContext::sharedTriggerContexts;
SharedNamedObjectContextList<UntypedValue> RogueAiObjectContext::sharedValueContexts;

RogueAiObjectContext::RogueAiObjectContext(ShadowAI* botAI)
    : AiObjectContext(botAI, sharedStrategyContexts, sharedActionContexts,
                      sharedTriggerContexts, sharedValueContexts)
{
}

void RogueAiObjectContext::BuildSharedContexts()
{
    BuildSharedStrategyContexts(sharedStrategyContexts);
    BuildSharedActionContexts(sharedActionContexts);
    BuildSharedTriggerContexts(sharedTriggerContexts);
    BuildSharedValueContexts(sharedValueContexts);
}

void RogueAiObjectContext::BuildSharedStrategyContexts(SharedNamedObjectContextList<Strategy>& strategyContexts)
{
    AiObjectContext::BuildSharedStrategyContexts(strategyContexts);
    strategyContexts.Add(new RogueStrategyFactoryInternal());
    strategyContexts.Add(new RogueCombatStrategyFactoryInternal());
}

void RogueAiObjectContext::BuildSharedActionContexts(SharedNamedObjectContextList<Action>& actionContexts)
{
    AiObjectContext::BuildSharedActionContexts(actionContexts);
    actionContexts.Add(new RogueAiObjectContextInternal());
}

void RogueAiObjectContext::BuildSharedTriggerContexts(SharedNamedObjectContextList<Trigger>& triggerContexts)
{
    AiObjectContext::BuildSharedTriggerContexts(triggerContexts);
    triggerContexts.Add(new RogueTriggerFactoryInternal());
}

void RogueAiObjectContext::BuildSharedValueContexts(SharedNamedObjectContextList<UntypedValue>& valueContexts)
{
    AiObjectContext::BuildSharedValueContexts(valueContexts);
}