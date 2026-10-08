/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#include "WarriorAiObjectContext.h"

#include "ArmsWarriorStrategy.h"
#include "FuryWarriorStrategy.h"
#include "GenericWarriorNonCombatStrategy.h"
#include "NamedObjectContext.h"
#include "Shadows.h"
#include "PullStrategy.h"
#include "TankWarriorStrategy.h"
#include "WarriorActions.h"
#include "WarriorTriggers.h"

class WarriorStrategyFactoryInternal : public NamedObjectContext<Strategy>
{
public:
    WarriorStrategyFactoryInternal()
    {
        creators["nc"] = &WarriorStrategyFactoryInternal::nc;
        creators["pull"] = &WarriorStrategyFactoryInternal::pull;
        creators["aoe"] = &WarriorStrategyFactoryInternal::warrior_aoe;
    }

private:
    static Strategy* nc(ShadowAI* botAI) { return new GenericWarriorNonCombatStrategy(botAI); }
    static Strategy* warrior_aoe(ShadowAI* botAI) { return new WarrirorAoeStrategy(botAI); }
    static Strategy* pull(ShadowAI* botAI) { return new PullStrategy(botAI, "shoot"); }
};

class WarriorCombatStrategyFactoryInternal : public NamedObjectContext<Strategy>
{
public:
    WarriorCombatStrategyFactoryInternal() : NamedObjectContext<Strategy>(false, true)
    {
        creators["tank"] = &WarriorCombatStrategyFactoryInternal::tank;
        creators["arms"] = &WarriorCombatStrategyFactoryInternal::arms;
        creators["fury"] = &WarriorCombatStrategyFactoryInternal::fury;
    }

private:
    static Strategy* tank(ShadowAI* botAI) { return new TankWarriorStrategy(botAI); }
    static Strategy* arms(ShadowAI* botAI) { return new ArmsWarriorStrategy(botAI); }
    static Strategy* fury(ShadowAI* botAI) { return new FuryWarriorStrategy(botAI); }
};

class WarriorTriggerFactoryInternal : public NamedObjectContext<Trigger>
{
public:
    WarriorTriggerFactoryInternal()
    {
        creators["hamstring"] = &WarriorTriggerFactoryInternal::hamstring;
        creators["victory rush"] = &WarriorTriggerFactoryInternal::victory_rush;
        creators["death wish"] = &WarriorTriggerFactoryInternal::death_wish;
        creators["recklessness"] = &WarriorTriggerFactoryInternal::recklessness;
        creators["battle shout"] = &WarriorTriggerFactoryInternal::battle_shout;
        creators["commanding shout"] = &WarriorTriggerFactoryInternal::commanding_shout;
        creators["rend"] = &WarriorTriggerFactoryInternal::rend;
        creators["rend on attacker"] = &WarriorTriggerFactoryInternal::rend_on_attacker;
        creators["bloodrage"] = &WarriorTriggerFactoryInternal::bloodrage;
        creators["shield bash"] = &WarriorTriggerFactoryInternal::shield_bash;
        creators["disarm"] = &WarriorTriggerFactoryInternal::disarm;
        creators["concussion blow"] = &WarriorTriggerFactoryInternal::concussion_blow;
        creators["sword and board"] = &WarriorTriggerFactoryInternal::SwordAndBoard;
        creators["shield bash on enemy healer"] = &WarriorTriggerFactoryInternal::shield_bash_on_enemy_healer;
        creators["battle stance"] = &WarriorTriggerFactoryInternal::battle_stance;
        creators["defensive stance"] = &WarriorTriggerFactoryInternal::defensive_stance;
        creators["berserker stance"] = &WarriorTriggerFactoryInternal::berserker_stance;
        creators["shield block"] = &WarriorTriggerFactoryInternal::shield_block;
        creators["sunder armor"] = &WarriorTriggerFactoryInternal::sunder_armor;
        creators["revenge"] = &WarriorTriggerFactoryInternal::revenge;
        creators["overpower"] = &WarriorTriggerFactoryInternal::overpower;
        creators["mocking blow"] = &WarriorTriggerFactoryInternal::mocking_blow;
        creators["rampage"] = &WarriorTriggerFactoryInternal::rampage;
        creators["mortal strike"] = &WarriorTriggerFactoryInternal::mortal_strike;
        creators["thunder clap on snare target"] = &WarriorTriggerFactoryInternal::thunder_clap_on_snare_target;
        creators["thunder clap"] = &WarriorTriggerFactoryInternal::thunder_clap;
        creators["bloodthirst"] = &WarriorTriggerFactoryInternal::bloodthirst;
        creators["whirlwind"] = &WarriorTriggerFactoryInternal::whirlwind;
        creators["berserker rage"] = &WarriorTriggerFactoryInternal::berserker_rage;
        creators["pummel on enemy healer"] = &WarriorTriggerFactoryInternal::pummel_on_enemy_healer;
        creators["pummel"] = &WarriorTriggerFactoryInternal::pummel;
        creators["intercept on enemy healer"] = &WarriorTriggerFactoryInternal::intercept_on_enemy_healer;
        creators["intercept"] = &WarriorTriggerFactoryInternal::intercept;
        creators["taunt on snare target"] = &WarriorTriggerFactoryInternal::taunt_on_snare_target;
        creators["intercept on snare target"] = &WarriorTriggerFactoryInternal::intercept_on_snare_target;
        creators["spell reflection"] = &WarriorTriggerFactoryInternal::spell_reflection;
        creators["sudden death"] = &WarriorTriggerFactoryInternal::sudden_death;
        creators["instant slam"] = &WarriorTriggerFactoryInternal::instant_slam;
        creators["shockwave"] = &WarriorTriggerFactoryInternal::shockwave;
        creators["shockwave on snare target"] = &WarriorTriggerFactoryInternal::shockwave_on_snare_target;
        creators["taste for blood"] = &WarriorTriggerFactoryInternal::taste_for_blood;

        creators["thunder clap and rage"] = &WarriorTriggerFactoryInternal::thunderclap_and_rage;
        creators["intercept can cast"] = &WarriorTriggerFactoryInternal::intercept_can_cast;
        creators["intercept and far enemy"] = &WarriorTriggerFactoryInternal::intercept_and_far_enemy;
        creators["intercept and rage"] = &WarriorTriggerFactoryInternal::intercept_and_rage;
        // creators["slam"] = &WarriorTriggerFactoryInternal::slam;

        creators["vigilance"] = &WarriorTriggerFactoryInternal::vigilance;
        creators["shattering throw trigger"] = &WarriorTriggerFactoryInternal::shattering_throw_trigger;
    }

private:
    static Trigger* shield_block(ShadowAI* botAI) { return new ShieldBlockTrigger(botAI); }
    static Trigger* defensive_stance(ShadowAI* botAI) { return new DefensiveStanceTrigger(botAI); }
    static Trigger* berserker_stance(ShadowAI* botAI) { return new BerserkerStanceTrigger(botAI); }
    static Trigger* battle_stance(ShadowAI* botAI) { return new BattleStanceTrigger(botAI); }
    static Trigger* hamstring(ShadowAI* botAI) { return new HamstringTrigger(botAI); }
    static Trigger* victory_rush(ShadowAI* botAI) { return new VictoryRushTrigger(botAI); }
    static Trigger* death_wish(ShadowAI* botAI) { return new DeathWishTrigger(botAI); }
    static Trigger* recklessness(ShadowAI* botAI) { return new RecklessnessTrigger(botAI); }
    static Trigger* battle_shout(ShadowAI* botAI) { return new BattleShoutTrigger(botAI); }
    static Trigger* commanding_shout(ShadowAI* botAI) { return new CommandingShoutTrigger(botAI); }
    static Trigger* rend(ShadowAI* botAI) { return new RendDebuffTrigger(botAI); }
    static Trigger* rend_on_attacker(ShadowAI* botAI) { return new RendDebuffOnAttackerTrigger(botAI); }
    static Trigger* bloodrage(ShadowAI* botAI) { return new BloodrageBuffTrigger(botAI); }
    static Trigger* shield_bash(ShadowAI* botAI) { return new ShieldBashInterruptSpellTrigger(botAI); }
    static Trigger* disarm(ShadowAI* botAI) { return new DisarmDebuffTrigger(botAI); }
    static Trigger* concussion_blow(ShadowAI* botAI) { return new ConcussionBlowTrigger(botAI); }
    static Trigger* SwordAndBoard(ShadowAI* botAI) { return new SwordAndBoardTrigger(botAI); }
    static Trigger* shield_bash_on_enemy_healer(ShadowAI* botAI)
    {
        return new ShieldBashInterruptEnemyHealerSpellTrigger(botAI);
    }

    static Trigger* thunderclap_and_rage(ShadowAI* botAI)
    {
        return new TwoTriggers(botAI, "thunder clap", "light rage available");
    }
    static Trigger* intercept_can_cast(ShadowAI* botAI) { return new InterceptCanCastTrigger(botAI); }
    static Trigger* intercept_and_far_enemy(ShadowAI* botAI)
    {
        return new TwoTriggers(botAI, "enemy is out of melee", "intercept can cast");
    }
    static Trigger* intercept_and_rage(ShadowAI* botAI)
    {
        return new TwoTriggers(botAI, "intercept and far enemy", "light rage available");
    }

    static Trigger* intercept_on_snare_target(ShadowAI* botAI) { return new InterceptSnareTrigger(botAI); }
    static Trigger* spell_reflection(ShadowAI* botAI) { return new SpellReflectionTrigger(botAI); }
    static Trigger* taste_for_blood(ShadowAI* botAI) { return new TasteForBloodTrigger(botAI); }
    static Trigger* shockwave_on_snare_target(ShadowAI* botAI) { return new ShockwaveSnareTrigger(botAI); }
    static Trigger* shockwave(ShadowAI* botAI) { return new ShockwaveTrigger(botAI); }
    static Trigger* instant_slam(ShadowAI* botAI) { return new SlamInstantTrigger(botAI); }
    static Trigger* sudden_death(ShadowAI* botAI) { return new SuddenDeathTrigger(botAI); }
    static Trigger* taunt_on_snare_target(ShadowAI* botAI) { return new TauntSnareTrigger(botAI); }
    static Trigger* intercept(ShadowAI* botAI) { return new InterceptInterruptSpellTrigger(botAI); }
    static Trigger* intercept_on_enemy_healer(ShadowAI* botAI)
    {
        return new InterceptInterruptEnemyHealerSpellTrigger(botAI);
    }
    static Trigger* pummel(ShadowAI* botAI) { return new PummelInterruptSpellTrigger(botAI); }
    static Trigger* pummel_on_enemy_healer(ShadowAI* botAI)
    {
        return new PummelInterruptEnemyHealerSpellTrigger(botAI);
    }
    static Trigger* berserker_rage(ShadowAI* botAI) { return new BerserkerRageBuffTrigger(botAI); }
    static Trigger* bloodthirst(ShadowAI* botAI) { return new BloodthirstBuffTrigger(botAI); }
    static Trigger* whirlwind(ShadowAI* botAI) { return new WhirlwindTrigger(botAI); }
    static Trigger* thunder_clap_on_snare_target(ShadowAI* botAI) { return new ThunderClapSnareTrigger(botAI); }
    static Trigger* thunder_clap(ShadowAI* botAI) { return new ThunderClapTrigger(botAI); }
    static Trigger* mortal_strike(ShadowAI* botAI) { return new MortalStrikeDebuffTrigger(botAI); }
    static Trigger* rampage(ShadowAI* botAI) { return new RampageAvailableTrigger(botAI); }
    static Trigger* mocking_blow(ShadowAI* botAI) { return new MockingBlowTrigger(botAI); }
    static Trigger* overpower(ShadowAI* botAI) { return new OverpowerAvailableTrigger(botAI); }
    static Trigger* revenge(ShadowAI* botAI) { return new RevengeAvailableTrigger(botAI); }
    static Trigger* sunder_armor(ShadowAI* botAI) { return new SunderArmorDebuffTrigger(botAI); }
    // static Trigger* slam(ShadowAI* ai) { return new SlamTrigger(ai); }

    static Trigger* vigilance(ShadowAI* botAI) { return new VigilanceTrigger(botAI); }
    static Trigger* shattering_throw_trigger(ShadowAI* botAI) { return new ShatteringThrowTrigger(botAI); }
};

class WarriorAiObjectContextInternal : public NamedObjectContext<Action>
{
public:
    WarriorAiObjectContextInternal()
    {
        creators["devastate"] = &WarriorAiObjectContextInternal::devastate;
        creators["overpower"] = &WarriorAiObjectContextInternal::overpower;
        creators["charge"] = &WarriorAiObjectContextInternal::charge;
        creators["bloodthirst"] = &WarriorAiObjectContextInternal::bloodthirst;
        creators["rend"] = &WarriorAiObjectContextInternal::rend;
        creators["rend on attacker"] = &WarriorAiObjectContextInternal::rend_on_attacker;
        creators["mocking blow"] = &WarriorAiObjectContextInternal::mocking_blow;
        creators["death wish"] = &WarriorAiObjectContextInternal::death_wish;
        creators["recklessness"] = &WarriorAiObjectContextInternal::recklessness;
        creators["berserker rage"] = &WarriorAiObjectContextInternal::berserker_rage;
        creators["victory rush"] = &WarriorAiObjectContextInternal::victory_rush;
        creators["execute"] = &WarriorAiObjectContextInternal::execute;
        creators["defensive stance"] = &WarriorAiObjectContextInternal::defensive_stance;
        creators["hamstring"] = &WarriorAiObjectContextInternal::hamstring;
        creators["shield bash"] = &WarriorAiObjectContextInternal::shield_bash;
        creators["shield block"] = &WarriorAiObjectContextInternal::shield_block;
        creators["bloodrage"] = &WarriorAiObjectContextInternal::bloodrage;
        creators["battle stance"] = &WarriorAiObjectContextInternal::battle_stance;
        creators["heroic strike"] = &WarriorAiObjectContextInternal::heroic_strike;
        creators["intimidating shout"] = &WarriorAiObjectContextInternal::intimidating_shout;
        creators["demoralizing shout"] = &WarriorAiObjectContextInternal::demoralizing_shout;
        creators["demoralizing shout without life time check"] =
            &WarriorAiObjectContextInternal::demoralizing_shout_without_life_time_check;
        creators["challenging shout"] = &WarriorAiObjectContextInternal::challenging_shout;
        creators["shield wall"] = &WarriorAiObjectContextInternal::shield_wall;
        creators["battle shout"] = &WarriorAiObjectContextInternal::battle_shout;
        creators["commanding shout"] = &WarriorAiObjectContextInternal::commanding_shout;
        creators["battle shout taunt"] = &WarriorAiObjectContextInternal::battle_shout_taunt;
        creators["thunder clap"] = &WarriorAiObjectContextInternal::thunder_clap;
        creators["taunt"] = &WarriorAiObjectContextInternal::taunt;
        creators["revenge"] = &WarriorAiObjectContextInternal::revenge;
        creators["slam"] = &WarriorAiObjectContextInternal::slam;
        creators["shield slam"] = &WarriorAiObjectContextInternal::shield_slam;
        creators["disarm"] = &WarriorAiObjectContextInternal::disarm;
        creators["sunder armor"] = &WarriorAiObjectContextInternal::sunder_armor;
        creators["last stand"] = &WarriorAiObjectContextInternal::last_stand;
        creators["shockwave on snare target"] = &WarriorAiObjectContextInternal::shockwave_on_snare_target;
        creators["shockwave"] = &WarriorAiObjectContextInternal::shockwave;
        creators["cleave"] = &WarriorAiObjectContextInternal::cleave;
        creators["concussion blow"] = &WarriorAiObjectContextInternal::concussion_blow;
        creators["shield bash on enemy healer"] = &WarriorAiObjectContextInternal::shield_bash_on_enemy_healer;
        creators["berserker stance"] = &WarriorAiObjectContextInternal::berserker_stance;
        creators["retaliation"] = &WarriorAiObjectContextInternal::retaliation;
        creators["mortal strike"] = &WarriorAiObjectContextInternal::mortal_strike;
        creators["sweeping strikes"] = &WarriorAiObjectContextInternal::sweeping_strikes;
        creators["intercept"] = &WarriorAiObjectContextInternal::intercept;
        creators["whirlwind"] = &WarriorAiObjectContextInternal::whirlwind;
        creators["pummel"] = &WarriorAiObjectContextInternal::pummel;
        creators["pummel on enemy healer"] = &WarriorAiObjectContextInternal::pummel_on_enemy_healer;
        creators["recklessness"] = &WarriorAiObjectContextInternal::recklessness;
        creators["piercing howl"] = &WarriorAiObjectContextInternal::piercing_howl;
        creators["rampage"] = &WarriorAiObjectContextInternal::rampage;
        creators["intervene"] = &WarriorAiObjectContextInternal::intervene;
        creators["spell reflection"] = &WarriorAiObjectContextInternal::spell_reflection;
        creators["thunder clap on snare target"] = &WarriorAiObjectContextInternal::thunder_clap_on_snare_target;
        creators["taunt on snare target"] = &WarriorAiObjectContextInternal::taunt_on_snare_target;
        creators["intercept on enemy healer"] = &WarriorAiObjectContextInternal::intercept_on_enemy_healer;
        creators["intercept on snare target"] = &WarriorAiObjectContextInternal::intercept_on_snare_target;
        creators["bladestorm"] = &WarriorAiObjectContextInternal::bladestorm;
        creators["heroic throw"] = &WarriorAiObjectContextInternal::heroic_throw;
        creators["heroic throw on snare target"] = &WarriorAiObjectContextInternal::heroic_throw_on_snare_target;
        creators["shattering throw"] = &WarriorAiObjectContextInternal::shattering_throw;
        creators["vigilance"] = &WarriorAiObjectContextInternal::vigilance;
        creators["enraged regeneration"] = &WarriorAiObjectContextInternal::enraged_regeneration;
    }

private:
    static Action* devastate(ShadowAI* botAI) { return new CastDevastateAction(botAI); }
    static Action* last_stand(ShadowAI* botAI) { return new CastLastStandAction(botAI); }
    static Action* shockwave(ShadowAI* botAI) { return new CastShockwaveAction(botAI); }
    static Action* shockwave_on_snare_target(ShadowAI* botAI) { return new CastShockwaveSnareAction(botAI); }
    static Action* cleave(ShadowAI* botAI) { return new CastCleaveAction(botAI); }
    static Action* concussion_blow(ShadowAI* botAI) { return new CastConcussionBlowAction(botAI); }
    static Action* taunt(ShadowAI* botAI) { return new CastTauntAction(botAI); }
    static Action* revenge(ShadowAI* botAI) { return new CastRevengeAction(botAI); }
    static Action* slam(ShadowAI* botAI) { return new CastSlamAction(botAI); }
    static Action* shield_slam(ShadowAI* botAI) { return new CastShieldSlamAction(botAI); }
    static Action* disarm(ShadowAI* botAI) { return new CastDisarmAction(botAI); }
    static Action* sunder_armor(ShadowAI* botAI) { return new CastSunderArmorAction(botAI); }
    static Action* overpower(ShadowAI* botAI) { return new CastOverpowerAction(botAI); }
    static Action* charge(ShadowAI* botAI) { return new CastChargeAction(botAI); }
    static Action* bloodthirst(ShadowAI* botAI) { return new CastBloodthirstAction(botAI); }
    static Action* rend(ShadowAI* botAI) { return new CastRendAction(botAI); }
    static Action* rend_on_attacker(ShadowAI* botAI) { return new CastRendOnAttackerAction(botAI); }
    static Action* mocking_blow(ShadowAI* botAI) { return new CastMockingBlowAction(botAI); }
    static Action* death_wish(ShadowAI* botAI) { return new CastDeathWishAction(botAI); }
    static Action* recklessness(ShadowAI* botAI) { return new CastRecklessnessAction(botAI); }
    static Action* berserker_rage(ShadowAI* botAI) { return new CastBerserkerRageAction(botAI); }
    static Action* victory_rush(ShadowAI* botAI) { return new CastVictoryRushAction(botAI); }
    static Action* execute(ShadowAI* botAI) { return new CastExecuteAction(botAI); }
    static Action* defensive_stance(ShadowAI* botAI) { return new CastDefensiveStanceAction(botAI); }
    static Action* hamstring(ShadowAI* botAI) { return new CastHamstringAction(botAI); }
    static Action* shield_bash(ShadowAI* botAI) { return new CastShieldBashAction(botAI); }
    static Action* shield_block(ShadowAI* botAI) { return new CastShieldBlockAction(botAI); }
    static Action* bloodrage(ShadowAI* botAI) { return new CastBloodrageAction(botAI); }
    static Action* battle_stance(ShadowAI* botAI) { return new CastBattleStanceAction(botAI); }
    static Action* heroic_strike(ShadowAI* botAI) { return new CastHeroicStrikeAction(botAI); }
    static Action* intimidating_shout(ShadowAI* botAI) { return new CastIntimidatingShoutAction(botAI); }
    static Action* demoralizing_shout(ShadowAI* botAI) { return new CastDemoralizingShoutAction(botAI); }
    static Action* demoralizing_shout_without_life_time_check(ShadowAI* botAI)
    {
        return new CastDemoralizingShoutWithoutLifeTimeCheckAction(botAI);
    }
    static Action* challenging_shout(ShadowAI* botAI) { return new CastChallengingShoutAction(botAI); }
    static Action* shield_wall(ShadowAI* botAI) { return new CastShieldWallAction(botAI); }
    static Action* battle_shout(ShadowAI* botAI) { return new CastBattleShoutAction(botAI); }
    static Action* commanding_shout(ShadowAI* botAI) { return new CastCommandingShoutAction(botAI); }
    static Action* battle_shout_taunt(ShadowAI* botAI) { return new CastBattleShoutTauntAction(botAI); }
    static Action* thunder_clap(ShadowAI* botAI) { return new CastThunderClapAction(botAI); }
    static Action* shield_bash_on_enemy_healer(ShadowAI* botAI)
    {
        return new CastShieldBashOnEnemyHealerAction(botAI);
    }
    static Action* intercept_on_snare_target(ShadowAI* botAI) { return new CastInterceptOnSnareTargetAction(botAI); }
    static Action* intercept_on_enemy_healer(ShadowAI* botAI) { return new CastInterceptOnEnemyHealerAction(botAI); }
    static Action* taunt_on_snare_target(ShadowAI* botAI) { return new CastTauntOnSnareTargetAction(botAI); }
    static Action* thunder_clap_on_snare_target(ShadowAI* botAI) { return new CastThunderClapSnareAction(botAI); }
    static Action* berserker_stance(ShadowAI* botAI) { return new CastBerserkerStanceAction(botAI); }
    static Action* retaliation(ShadowAI* botAI) { return new CastRetaliationAction(botAI); }
    static Action* mortal_strike(ShadowAI* botAI) { return new CastMortalStrikeAction(botAI); }
    static Action* sweeping_strikes(ShadowAI* botAI) { return new CastSweepingStrikesAction(botAI); }
    static Action* intercept(ShadowAI* botAI) { return new CastInterceptAction(botAI); }
    static Action* whirlwind(ShadowAI* botAI) { return new CastWhirlwindAction(botAI); }
    static Action* pummel(ShadowAI* botAI) { return new CastPummelAction(botAI); }
    static Action* pummel_on_enemy_healer(ShadowAI* botAI) { return new CastPummelOnEnemyHealerAction(botAI); }
    static Action* piercing_howl(ShadowAI* botAI) { return new CastPiercingHowlAction(botAI); }
    static Action* rampage(ShadowAI* botAI) { return new CastRampageAction(botAI); }
    static Action* intervene(ShadowAI* botAI) { return new CastInterveneAction(botAI); }
    static Action* spell_reflection(ShadowAI* botAI) { return new CastSpellReflectionAction(botAI); }
    static Action* shattering_throw(ShadowAI* botAI) { return new CastShatteringThrowAction(botAI); }
    static Action* heroic_throw_on_snare_target(ShadowAI* botAI) { return new CastHeroicThrowSnareAction(botAI); }
    static Action* heroic_throw(ShadowAI* botAI) { return new CastHeroicThrowAction(botAI); }
    static Action* bladestorm(ShadowAI* botAI) { return new CastBladestormAction(botAI); }
    static Action* vigilance(ShadowAI* botAI) { return new CastVigilanceAction(botAI); }
    static Action* enraged_regeneration(ShadowAI* botAI) { return new CastEnragedRegenerationAction(botAI); }
};

SharedNamedObjectContextList<Strategy> WarriorAiObjectContext::sharedStrategyContexts;
SharedNamedObjectContextList<Action> WarriorAiObjectContext::sharedActionContexts;
SharedNamedObjectContextList<Trigger> WarriorAiObjectContext::sharedTriggerContexts;
SharedNamedObjectContextList<UntypedValue> WarriorAiObjectContext::sharedValueContexts;

WarriorAiObjectContext::WarriorAiObjectContext(ShadowAI* botAI)
    : AiObjectContext(botAI, sharedStrategyContexts, sharedActionContexts, sharedTriggerContexts, sharedValueContexts)
{
}

void WarriorAiObjectContext::BuildSharedContexts()
{
    BuildSharedStrategyContexts(sharedStrategyContexts);
    BuildSharedActionContexts(sharedActionContexts);
    BuildSharedTriggerContexts(sharedTriggerContexts);
    BuildSharedValueContexts(sharedValueContexts);
}

void WarriorAiObjectContext::BuildSharedStrategyContexts(SharedNamedObjectContextList<Strategy>& strategyContexts)
{
    AiObjectContext::BuildSharedStrategyContexts(strategyContexts);
    strategyContexts.Add(new WarriorStrategyFactoryInternal());
    strategyContexts.Add(new WarriorCombatStrategyFactoryInternal());
}

void WarriorAiObjectContext::BuildSharedActionContexts(SharedNamedObjectContextList<Action>& actionContexts)
{
    AiObjectContext::BuildSharedActionContexts(actionContexts);
    actionContexts.Add(new WarriorAiObjectContextInternal());
}

void WarriorAiObjectContext::BuildSharedTriggerContexts(SharedNamedObjectContextList<Trigger>& triggerContexts)
{
    AiObjectContext::BuildSharedTriggerContexts(triggerContexts);
    triggerContexts.Add(new WarriorTriggerFactoryInternal());
}

void WarriorAiObjectContext::BuildSharedValueContexts(SharedNamedObjectContextList<UntypedValue>& valueContexts)
{
    AiObjectContext::BuildSharedValueContexts(valueContexts);
}