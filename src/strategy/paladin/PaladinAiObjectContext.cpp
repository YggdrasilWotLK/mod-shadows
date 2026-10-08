/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#include "PaladinAiObjectContext.h"

#include "DpsPaladinStrategy.h"
#include "GenericPaladinNonCombatStrategy.h"
#include "HealPaladinStrategy.h"
#include "NamedObjectContext.h"
#include "OffhealRetPaladinStrategy.h"
#include "PaladinActions.h"
#include "PaladinBuffStrategies.h"
#include "PaladinTriggers.h"
#include "Shadows.h"
#include "TankPaladinStrategy.h"

class PaladinStrategyFactoryInternal : public NamedObjectContext<Strategy>
{
public:
    PaladinStrategyFactoryInternal()
    {
        creators["nc"] = &PaladinStrategyFactoryInternal::nc;
        creators["cure"] = &PaladinStrategyFactoryInternal::cure;
        creators["boost"] = &PaladinStrategyFactoryInternal::boost;
        creators["cc"] = &PaladinStrategyFactoryInternal::cc;
        creators["bthreat"] = &PaladinStrategyFactoryInternal::bthreat;
        creators["healer dps"] = &PaladinStrategyFactoryInternal::healer_dps;
    }

private:
    static Strategy* nc(ShadowAI* botAI) { return new GenericPaladinNonCombatStrategy(botAI); }
    static Strategy* cure(ShadowAI* botAI) { return new PaladinCureStrategy(botAI); }
    static Strategy* boost(ShadowAI* botAI) { return new PaladinBoostStrategy(botAI); }
    static Strategy* cc(ShadowAI* botAI) { return new PaladinCcStrategy(botAI); }
    static Strategy* bthreat(ShadowAI* botAI) { return new PaladinBuffThreatStrategy(botAI); }
    static Strategy* healer_dps(ShadowAI* botAI) { return new PaladinHealerDpsStrategy(botAI); }
};

class PaladinResistanceStrategyFactoryInternal : public NamedObjectContext<Strategy>
{
public:
    PaladinResistanceStrategyFactoryInternal() : NamedObjectContext<Strategy>(false, true)
    {
        creators["rshadow"] = &PaladinResistanceStrategyFactoryInternal::rshadow;
        creators["rfrost"] = &PaladinResistanceStrategyFactoryInternal::rfrost;
        creators["rfire"] = &PaladinResistanceStrategyFactoryInternal::rfire;
        creators["baoe"] = &PaladinResistanceStrategyFactoryInternal::baoe;
        creators["barmor"] = &PaladinResistanceStrategyFactoryInternal::barmor;
        creators["bcast"] = &PaladinResistanceStrategyFactoryInternal::bcast;
        creators["bspeed"] = &PaladinResistanceStrategyFactoryInternal::bspeed;
    }

private:
    static Strategy* rshadow(ShadowAI* botAI) { return new PaladinShadowResistanceStrategy(botAI); }
    static Strategy* rfrost(ShadowAI* botAI) { return new PaladinFrostResistanceStrategy(botAI); }
    static Strategy* rfire(ShadowAI* botAI) { return new PaladinFireResistanceStrategy(botAI); }
    static Strategy* baoe(ShadowAI* botAI) { return new PaladinBuffAoeStrategy(botAI); }
    static Strategy* barmor(ShadowAI* botAI) { return new PaladinBuffArmorStrategy(botAI); }
    static Strategy* bcast(ShadowAI* botAI) { return new PaladinBuffCastStrategy(botAI); }
    static Strategy* bspeed(ShadowAI* botAI) { return new PaladinBuffSpeedStrategy(botAI); }
};

class PaladinBuffStrategyFactoryInternal : public NamedObjectContext<Strategy>
{
public:
    PaladinBuffStrategyFactoryInternal() : NamedObjectContext<Strategy>(false, true)
    {
        creators["bhealth"] = &PaladinBuffStrategyFactoryInternal::bhealth;
        creators["bmana"] = &PaladinBuffStrategyFactoryInternal::bmana;
        creators["bdps"] = &PaladinBuffStrategyFactoryInternal::bdps;
        creators["bstats"] = &PaladinBuffStrategyFactoryInternal::bstats;
    }

private:
    static Strategy* bhealth(ShadowAI* botAI) { return new PaladinBuffHealthStrategy(botAI); }
    static Strategy* bmana(ShadowAI* botAI) { return new PaladinBuffManaStrategy(botAI); }
    static Strategy* bdps(ShadowAI* botAI) { return new PaladinBuffDpsStrategy(botAI); }
    static Strategy* bstats(ShadowAI* botAI) { return new PaladinBuffStatsStrategy(botAI); }
};

class PaladinCombatStrategyFactoryInternal : public NamedObjectContext<Strategy>
{
public:
    PaladinCombatStrategyFactoryInternal() : NamedObjectContext<Strategy>(false, true)
    {
        creators["tank"] = &PaladinCombatStrategyFactoryInternal::tank;
        creators["dps"] = &PaladinCombatStrategyFactoryInternal::dps;
        creators["heal"] = &PaladinCombatStrategyFactoryInternal::heal;
        creators["offheal"] = &PaladinCombatStrategyFactoryInternal::offheal;
    }

private:
    static Strategy* tank(ShadowAI* botAI) { return new TankPaladinStrategy(botAI); }
    static Strategy* dps(ShadowAI* botAI) { return new DpsPaladinStrategy(botAI); }
    static Strategy* heal(ShadowAI* botAI) { return new HealPaladinStrategy(botAI); }
    static Strategy* offheal(ShadowAI* botAI) { return new OffhealRetPaladinStrategy(botAI); }
};

class PaladinTriggerFactoryInternal : public NamedObjectContext<Trigger>
{
public:
    PaladinTriggerFactoryInternal()
    {
        creators["judgement"] = &PaladinTriggerFactoryInternal::judgement;
        creators["judgement of wisdom"] = &PaladinTriggerFactoryInternal::judgement_of_wisdom;
        creators["judgement of light"] = &PaladinTriggerFactoryInternal::judgement_of_light;
        creators["blessing"] = &PaladinTriggerFactoryInternal::blessing;
        creators["seal"] = &PaladinTriggerFactoryInternal::seal;
        creators["art of war"] = &PaladinTriggerFactoryInternal::art_of_war;
        creators["blessing on party"] = &PaladinTriggerFactoryInternal::blessing_on_party;
        creators["crusader aura"] = &PaladinTriggerFactoryInternal::crusader_aura;
        creators["retribution aura"] = &PaladinTriggerFactoryInternal::retribution_aura;
        creators["devotion aura"] = &PaladinTriggerFactoryInternal::devotion_aura;
        creators["sanctity aura"] = &PaladinTriggerFactoryInternal::sanctity_aura;
        creators["concentration aura"] = &PaladinTriggerFactoryInternal::concentration_aura;
        creators["shadow resistance aura"] = &PaladinTriggerFactoryInternal::shadow_resistance_aura;
        creators["frost resistance aura"] = &PaladinTriggerFactoryInternal::frost_resistance_aura;
        creators["fire resistance aura"] = &PaladinTriggerFactoryInternal::fire_resistance_aura;
        creators["hammer of justice snare"] = &PaladinTriggerFactoryInternal::hammer_of_justice_snare;
        creators["hammer of justice interrupt"] = &PaladinTriggerFactoryInternal::hammer_of_justice_interrupt;
        creators["cleanse cure disease"] = &PaladinTriggerFactoryInternal::CleanseCureDisease;
        creators["cleanse party member cure disease"] = &PaladinTriggerFactoryInternal::CleanseCurePartyMemberDisease;
        creators["cleanse cure poison"] = &PaladinTriggerFactoryInternal::CleanseCurePoison;
        creators["cleanse party member cure poison"] = &PaladinTriggerFactoryInternal::CleanseCurePartyMemberPoison;
        creators["cleanse cure magic"] = &PaladinTriggerFactoryInternal::CleanseCureMagic;
        creators["cleanse party member cure magic"] = &PaladinTriggerFactoryInternal::CleanseCurePartyMemberMagic;
        creators["righteous fury"] = &PaladinTriggerFactoryInternal::righteous_fury;
        creators["holy shield"] = &PaladinTriggerFactoryInternal::holy_shield;
        creators["hammer of justice on enemy healer"] =
            &PaladinTriggerFactoryInternal::hammer_of_justice_on_enemy_target;
        creators["hammer of justice on snare target"] =
            &PaladinTriggerFactoryInternal::hammer_of_justice_on_snare_target;
        creators["divine favor"] = &PaladinTriggerFactoryInternal::divine_favor;
        creators["turn undead"] = &PaladinTriggerFactoryInternal::turn_undead;
        creators["avenger's shield"] = &PaladinTriggerFactoryInternal::avenger_shield;
        creators["consecration"] = &PaladinTriggerFactoryInternal::consecration;
        creators["repentance on enemy healer"] = &PaladinTriggerFactoryInternal::repentance_on_enemy_healer;
        creators["repentance on snare target"] = &PaladinTriggerFactoryInternal::repentance_on_snare_target;
        creators["repentance interrupt"] = &PaladinTriggerFactoryInternal::repentance_interrupt;
        creators["beacon of light on main tank"] = &PaladinTriggerFactoryInternal::beacon_of_light_on_main_tank;
        creators["sacred shield on main tank"] = &PaladinTriggerFactoryInternal::sacred_shield_on_main_tank;

        creators["blessing of kings on party"] = &PaladinTriggerFactoryInternal::blessing_of_kings_on_party;
        creators["blessing of wisdom on party"] = &PaladinTriggerFactoryInternal::blessing_of_wisdom_on_party;
        creators["blessing of might on party"] = &PaladinTriggerFactoryInternal::blessing_of_might_on_party;
        creators["blessing of sanctuary on party"] = &PaladinTriggerFactoryInternal::blessing_of_sanctuary_on_party;

        creators["avenging wrath"] = &PaladinTriggerFactoryInternal::avenging_wrath;
        creators["self sanctuary"] = &PaladinTriggerFactoryInternal::self_sanctuary;
    }

private:
    static Trigger* turn_undead(ShadowAI* botAI) { return new TurnUndeadTrigger(botAI); }
    static Trigger* divine_favor(ShadowAI* botAI) { return new DivineFavorTrigger(botAI); }
    static Trigger* holy_shield(ShadowAI* botAI) { return new HolyShieldTrigger(botAI); }
    static Trigger* righteous_fury(ShadowAI* botAI) { return new RighteousFuryTrigger(botAI); }
    static Trigger* judgement(ShadowAI* botAI) { return new JudgementTrigger(botAI); }
    static Trigger* judgement_of_wisdom(ShadowAI* botAI) { return new JudgementOfWisdomTrigger(botAI); }
    static Trigger* judgement_of_light(ShadowAI* botAI) { return new JudgementOfLightTrigger(botAI); }
    static Trigger* blessing(ShadowAI* botAI) { return new BlessingTrigger(botAI); }
    static Trigger* seal(ShadowAI* botAI) { return new SealTrigger(botAI); }
    static Trigger* art_of_war(ShadowAI* botAI) { return new ArtOfWarTrigger(botAI); }
    static Trigger* blessing_on_party(ShadowAI* botAI) { return new BlessingOnPartyTrigger(botAI); }
    static Trigger* crusader_aura(ShadowAI* botAI) { return new CrusaderAuraTrigger(botAI); }
    static Trigger* retribution_aura(ShadowAI* botAI) { return new RetributionAuraTrigger(botAI); }
    static Trigger* devotion_aura(ShadowAI* botAI) { return new DevotionAuraTrigger(botAI); }
    static Trigger* sanctity_aura(ShadowAI* botAI) { return new SanctityAuraTrigger(botAI); }
    static Trigger* concentration_aura(ShadowAI* botAI) { return new ConcentrationAuraTrigger(botAI); }
    static Trigger* shadow_resistance_aura(ShadowAI* botAI) { return new ShadowResistanceAuraTrigger(botAI); }
    static Trigger* frost_resistance_aura(ShadowAI* botAI) { return new FrostResistanceAuraTrigger(botAI); }
    static Trigger* fire_resistance_aura(ShadowAI* botAI) { return new FireResistanceAuraTrigger(botAI); }
    static Trigger* hammer_of_justice_snare(ShadowAI* botAI) { return new HammerOfJusticeSnareTrigger(botAI); }
    static Trigger* hammer_of_justice_interrupt(ShadowAI* botAI)
    {
        return new HammerOfJusticeInterruptSpellTrigger(botAI);
    }
    static Trigger* CleanseCureDisease(ShadowAI* botAI) { return new CleanseCureDiseaseTrigger(botAI); }
    static Trigger* CleanseCurePartyMemberDisease(ShadowAI* botAI)
    {
        return new CleanseCurePartyMemberDiseaseTrigger(botAI);
    }
    static Trigger* CleanseCurePoison(ShadowAI* botAI) { return new CleanseCurePoisonTrigger(botAI); }
    static Trigger* CleanseCurePartyMemberPoison(ShadowAI* botAI)
    {
        return new CleanseCurePartyMemberPoisonTrigger(botAI);
    }
    static Trigger* CleanseCureMagic(ShadowAI* botAI) { return new CleanseCureMagicTrigger(botAI); }
    static Trigger* CleanseCurePartyMemberMagic(ShadowAI* botAI)
    {
        return new CleanseCurePartyMemberMagicTrigger(botAI);
    }
    static Trigger* hammer_of_justice_on_enemy_target(ShadowAI* botAI)
    {
        return new HammerOfJusticeEnemyHealerTrigger(botAI);
    }
    static Trigger* hammer_of_justice_on_snare_target(ShadowAI* botAI)
    {
        return new HammerOfJusticeSnareTrigger(botAI);
    }
    static Trigger* avenger_shield(ShadowAI* botAI) { return new AvengerShieldTrigger(botAI); }
    static Trigger* consecration(ShadowAI* botAI) { return new ConsecrationTrigger(botAI); }
    static Trigger* repentance_on_enemy_healer(ShadowAI* botAI) { return new RepentanceOnHealerTrigger(botAI); }
    static Trigger* repentance_on_snare_target(ShadowAI* botAI) { return new RepentanceSnareTrigger(botAI); }
    static Trigger* repentance_interrupt(ShadowAI* botAI) { return new RepentanceInterruptTrigger(botAI); }
    static Trigger* beacon_of_light_on_main_tank(ShadowAI* ai) { return new BeaconOfLightOnMainTankTrigger(ai); }
    static Trigger* sacred_shield_on_main_tank(ShadowAI* ai) { return new SacredShieldOnMainTankTrigger(ai); }

    static Trigger* blessing_of_kings_on_party(ShadowAI* botAI) { return new BlessingOfKingsOnPartyTrigger(botAI); }
    static Trigger* blessing_of_wisdom_on_party(ShadowAI* botAI)
    {
        return new BlessingOfWisdomOnPartyTrigger(botAI);
    }
    static Trigger* blessing_of_might_on_party(ShadowAI* botAI) { return new BlessingOfMightOnPartyTrigger(botAI); }
    static Trigger* blessing_of_sanctuary_on_party(ShadowAI* botAI)
    {
        return new BlessingOfSanctuaryOnPartyTrigger(botAI);
    }

    static Trigger* avenging_wrath(ShadowAI* botAI) { return new AvengingWrathTrigger(botAI); }
    static Trigger* self_sanctuary(ShadowAI* botAI) { return new SelfSanctuaryTrigger(botAI); }
};

class PaladinAiObjectContextInternal : public NamedObjectContext<Action>
{
public:
    PaladinAiObjectContextInternal()
    {
        creators["seal of command"] = &PaladinAiObjectContextInternal::seal_of_command;
        creators["seal of vengeance"] = &PaladinAiObjectContextInternal::seal_of_vengeance;
        creators["seal of corruption"] = &PaladinAiObjectContextInternal::seal_of_corruption;
        creators["blessing of might"] = &PaladinAiObjectContextInternal::blessing_of_might;
        creators["blessing of wisdom"] = &PaladinAiObjectContextInternal::blessing_of_wisdom;
        creators["blessing of kings"] = &PaladinAiObjectContextInternal::blessing_of_kings;
        creators["blessing of sanctuary"] = &PaladinAiObjectContextInternal::blessing_of_sanctuary;
        creators["divine storm"] = &PaladinAiObjectContextInternal::divine_storm;
        creators["blessing of kings on party"] = &PaladinAiObjectContextInternal::blessing_of_kings_on_party;
        creators["blessing of might on party"] = &PaladinAiObjectContextInternal::blessing_of_might_on_party;
        creators["blessing of wisdom on party"] = &PaladinAiObjectContextInternal::blessing_of_wisdom_on_party;
        creators["blessing of sanctuary on party"] = &PaladinAiObjectContextInternal::blessing_of_sanctuary_on_party;
        creators["redemption"] = &PaladinAiObjectContextInternal::redemption;
        creators["crusader strike"] = &PaladinAiObjectContextInternal::crusader_strike;
        creators["crusader aura"] = &PaladinAiObjectContextInternal::crusader_aura;
        creators["seal of light"] = &PaladinAiObjectContextInternal::seal_of_light;
        creators["devotion aura"] = &PaladinAiObjectContextInternal::devotion_aura;
        creators["concentration aura"] = &PaladinAiObjectContextInternal::concentration_aura;
        creators["holy wrath"] = &PaladinAiObjectContextInternal::holy_wrath;
        creators["consecration"] = &PaladinAiObjectContextInternal::consecration;
        creators["cleanse disease"] = &PaladinAiObjectContextInternal::cleanse_disease;
        creators["cleanse poison"] = &PaladinAiObjectContextInternal::cleanse_poison;
        creators["cleanse magic"] = &PaladinAiObjectContextInternal::cleanse_magic;
        creators["purify disease"] = &PaladinAiObjectContextInternal::purify_disease;
        creators["purify poison"] = &PaladinAiObjectContextInternal::purify_poison;
        creators["cleanse poison on party"] = &PaladinAiObjectContextInternal::cleanse_poison_on_party;
        creators["cleanse disease on party"] = &PaladinAiObjectContextInternal::cleanse_disease_on_party;
        creators["cleanse magic on party"] = &PaladinAiObjectContextInternal::cleanse_magic_on_party;
        creators["purify poison on party"] = &PaladinAiObjectContextInternal::purify_poison_on_party;
        creators["purify disease on party"] = &PaladinAiObjectContextInternal::purify_disease_on_party;
        creators["seal of wisdom"] = &PaladinAiObjectContextInternal::seal_of_wisdom;
        creators["seal of justice"] = &PaladinAiObjectContextInternal::seal_of_justice;
        creators["seal of righteousness"] = &PaladinAiObjectContextInternal::seal_of_righteousness;
        creators["flash of light"] = &PaladinAiObjectContextInternal::flash_of_light;
        creators["hand of reckoning"] = &PaladinAiObjectContextInternal::hand_of_reckoning;
        creators["avenger's shield"] = &PaladinAiObjectContextInternal::avengers_shield;
        creators["exorcism"] = &PaladinAiObjectContextInternal::exorcism;
        creators["judgement"] = &PaladinAiObjectContextInternal::judgement;
        creators["judgement of light"] = &PaladinAiObjectContextInternal::judgement_of_light;
        creators["judgement of wisdom"] = &PaladinAiObjectContextInternal::judgement_of_wisdom;
        creators["divine shield"] = &PaladinAiObjectContextInternal::divine_shield;
        creators["divine protection"] = &PaladinAiObjectContextInternal::divine_protection;
        creators["divine protection on party"] = &PaladinAiObjectContextInternal::divine_protection_on_party;
        creators["hammer of justice"] = &PaladinAiObjectContextInternal::hammer_of_justice;
        creators["flash of light on party"] = &PaladinAiObjectContextInternal::flash_of_light_on_party;
        creators["holy light"] = &PaladinAiObjectContextInternal::holy_light;
        creators["holy light on party"] = &PaladinAiObjectContextInternal::holy_light_on_party;
        creators["lay on hands"] = &PaladinAiObjectContextInternal::lay_on_hands;
        creators["lay on hands on party"] = &PaladinAiObjectContextInternal::lay_on_hands_on_party;
        creators["judgement of justice"] = &PaladinAiObjectContextInternal::judgement_of_justice;
        creators["hammer of wrath"] = &PaladinAiObjectContextInternal::hammer_of_wrath;
        creators["holy shield"] = &PaladinAiObjectContextInternal::holy_shield;
        creators["hammer of the righteous"] = &PaladinAiObjectContextInternal::hammer_of_the_righteous;
        creators["retribution aura"] = &PaladinAiObjectContextInternal::retribution_aura;
        creators["shadow resistance aura"] = &PaladinAiObjectContextInternal::shadow_resistance_aura;
        creators["frost resistance aura"] = &PaladinAiObjectContextInternal::frost_resistance_aura;
        creators["fire resistance aura"] = &PaladinAiObjectContextInternal::fire_resistance_aura;
        creators["righteous fury"] = &PaladinAiObjectContextInternal::righteous_fury;
        creators["hammer of justice on enemy healer"] =
            &PaladinAiObjectContextInternal::hammer_of_justice_on_enemy_healer;
        creators["hammer of justice on snare target"] =
            &PaladinAiObjectContextInternal::hammer_of_justice_on_snare_target;
        creators["divine favor"] = &PaladinAiObjectContextInternal::divine_favor;
        creators["turn undead"] = &PaladinAiObjectContextInternal::turn_undead;
        creators["blessing of protection on party"] = &PaladinAiObjectContextInternal::blessing_of_protection_on_party;
        creators["righteous defense"] = &PaladinAiObjectContextInternal::righteous_defense;
        creators["repentance"] = &PaladinAiObjectContextInternal::repentance;
        creators["repentance on snare target"] = &PaladinAiObjectContextInternal::repentance_on_snare_target;
        creators["repentance on enemy healer"] = &PaladinAiObjectContextInternal::repentance_on_enemy_healer;
        creators["sanctity aura"] = &PaladinAiObjectContextInternal::sanctity_aura;
        creators["holy shock"] = &PaladinAiObjectContextInternal::holy_shock;
        creators["holy shock on party"] = &PaladinAiObjectContextInternal::holy_shock_on_party;
        creators["divine plea"] = &PaladinAiObjectContextInternal::divine_plea;
        creators["shield of righteousness"] = &PaladinAiObjectContextInternal::shield_of_righteousness;
        creators["beacon of light on main tank"] = &PaladinAiObjectContextInternal::beacon_of_light_on_main_tank;
        creators["sacred shield on main tank"] = &PaladinAiObjectContextInternal::sacred_shield_on_main_tank;
        creators["avenging wrath"] = &PaladinAiObjectContextInternal::avenging_wrath;
        creators["divine illumination"] = &PaladinAiObjectContextInternal::divine_illumination;
        creators["divine sacrifice"] = &PaladinAiObjectContextInternal::divine_sacrifice;
        creators["cancel divine sacrifice"] = &PaladinAiObjectContextInternal::cancel_divine_sacrifice;
    }

private:
    static Action* blessing_of_protection_on_party(ShadowAI* botAI)
    {
        return new CastBlessingOfProtectionProtectAction(botAI);
    }
    static Action* turn_undead(ShadowAI* botAI) { return new CastTurnUndeadAction(botAI); }
    static Action* divine_favor(ShadowAI* botAI) { return new CastDivineFavorAction(botAI); }
    static Action* righteous_fury(ShadowAI* botAI) { return new CastRighteousFuryAction(botAI); }
    static Action* seal_of_command(ShadowAI* botAI) { return new CastSealOfCommandAction(botAI); }
    static Action* seal_of_vengeance(ShadowAI* botAI) { return new CastSealOfVengeanceAction(botAI); }
    static Action* seal_of_corruption(ShadowAI* botAI) { return new CastSealOfCorruptionAction(botAI); }
    static Action* blessing_of_sanctuary(ShadowAI* botAI) { return new CastBlessingOfSanctuaryAction(botAI); }
    static Action* blessing_of_might(ShadowAI* botAI) { return new CastBlessingOfMightAction(botAI); }
    static Action* blessing_of_wisdom(ShadowAI* botAI) { return new CastBlessingOfWisdomAction(botAI); }
    static Action* blessing_of_kings(ShadowAI* botAI) { return new CastBlessingOfKingsAction(botAI); }
    static Action* divine_storm(ShadowAI* botAI) { return new CastDivineStormAction(botAI); }
    static Action* blessing_of_kings_on_party(ShadowAI* botAI)
    {
        return new CastBlessingOfKingsOnPartyAction(botAI);
    }
    static Action* blessing_of_might_on_party(ShadowAI* botAI)
    {
        return new CastBlessingOfMightOnPartyAction(botAI);
    }
    static Action* blessing_of_wisdom_on_party(ShadowAI* botAI)
    {
        return new CastBlessingOfWisdomOnPartyAction(botAI);
    }
    static Action* blessing_of_sanctuary_on_party(ShadowAI* botAI)
    {
        return new CastBlessingOfSanctuaryOnPartyAction(botAI);
    }
    static Action* redemption(ShadowAI* botAI) { return new CastRedemptionAction(botAI); }
    static Action* crusader_strike(ShadowAI* botAI) { return new CastCrusaderStrikeAction(botAI); }
    static Action* crusader_aura(ShadowAI* botAI) { return new CastCrusaderAuraAction(botAI); }
    static Action* seal_of_light(ShadowAI* botAI) { return new CastSealOfLightAction(botAI); }
    static Action* devotion_aura(ShadowAI* botAI) { return new CastDevotionAuraAction(botAI); }
    static Action* concentration_aura(ShadowAI* botAI) { return new CastConcentrationAuraAction(botAI); }
    static Action* holy_wrath(ShadowAI* botAI) { return new CastHolyWrathAction(botAI); }
    static Action* consecration(ShadowAI* botAI) { return new CastConsecrationAction(botAI); }
    static Action* cleanse_poison(ShadowAI* botAI) { return new CastCleansePoisonAction(botAI); }
    static Action* cleanse_disease(ShadowAI* botAI) { return new CastCleanseDiseaseAction(botAI); }
    static Action* cleanse_magic(ShadowAI* botAI) { return new CastCleanseMagicAction(botAI); }
    static Action* purify_poison(ShadowAI* botAI) { return new CastPurifyPoisonAction(botAI); }
    static Action* purify_disease(ShadowAI* botAI) { return new CastPurifyDiseaseAction(botAI); }
    static Action* cleanse_poison_on_party(ShadowAI* botAI) { return new CastCleansePoisonOnPartyAction(botAI); }
    static Action* cleanse_disease_on_party(ShadowAI* botAI) { return new CastCleanseDiseaseOnPartyAction(botAI); }
    static Action* cleanse_magic_on_party(ShadowAI* botAI) { return new CastCleanseMagicOnPartyAction(botAI); }
    static Action* purify_poison_on_party(ShadowAI* botAI) { return new CastPurifyPoisonOnPartyAction(botAI); }
    static Action* purify_disease_on_party(ShadowAI* botAI) { return new CastPurifyDiseaseOnPartyAction(botAI); }
    static Action* seal_of_wisdom(ShadowAI* botAI) { return new CastSealOfWisdomAction(botAI); }
    static Action* seal_of_justice(ShadowAI* botAI) { return new CastSealOfJusticeAction(botAI); }
    static Action* seal_of_righteousness(ShadowAI* botAI) { return new CastSealOfRighteousnessAction(botAI); }
    static Action* flash_of_light(ShadowAI* botAI) { return new CastFlashOfLightAction(botAI); }
    static Action* hand_of_reckoning(ShadowAI* botAI) { return new CastHandOfReckoningAction(botAI); }
    static Action* avengers_shield(ShadowAI* botAI) { return new CastAvengersShieldAction(botAI); }
    static Action* exorcism(ShadowAI* botAI) { return new CastExorcismAction(botAI); }
    static Action* judgement(ShadowAI* botAI) { return new CastJudgementAction(botAI); }
    static Action* judgement_of_light(ShadowAI* botAI) { return new CastJudgementOfLightAction(botAI); }
    static Action* judgement_of_wisdom(ShadowAI* botAI) { return new CastJudgementOfWisdomAction(botAI); }
    static Action* divine_shield(ShadowAI* botAI) { return new CastDivineShieldAction(botAI); }
    static Action* divine_protection(ShadowAI* botAI) { return new CastDivineProtectionAction(botAI); }
    static Action* divine_protection_on_party(ShadowAI* botAI)
    {
        return new CastDivineProtectionOnPartyAction(botAI);
    }
    static Action* hammer_of_justice(ShadowAI* botAI) { return new CastHammerOfJusticeAction(botAI); }
    static Action* flash_of_light_on_party(ShadowAI* botAI) { return new CastFlashOfLightOnPartyAction(botAI); }
    static Action* holy_light(ShadowAI* botAI) { return new CastHolyLightAction(botAI); }
    static Action* holy_light_on_party(ShadowAI* botAI) { return new CastHolyLightOnPartyAction(botAI); }
    static Action* lay_on_hands(ShadowAI* botAI) { return new CastLayOnHandsAction(botAI); }
    static Action* lay_on_hands_on_party(ShadowAI* botAI) { return new CastLayOnHandsOnPartyAction(botAI); }
    static Action* judgement_of_justice(ShadowAI* botAI) { return new CastJudgementOfJusticeAction(botAI); }
    static Action* hammer_of_wrath(ShadowAI* botAI) { return new CastHammerOfWrathAction(botAI); }
    static Action* holy_shield(ShadowAI* botAI) { return new CastHolyShieldAction(botAI); }
    static Action* hammer_of_the_righteous(ShadowAI* botAI) { return new CastHammerOfTheRighteousAction(botAI); }
    static Action* retribution_aura(ShadowAI* botAI) { return new CastRetributionAuraAction(botAI); }
    static Action* shadow_resistance_aura(ShadowAI* botAI) { return new CastShadowResistanceAuraAction(botAI); }
    static Action* frost_resistance_aura(ShadowAI* botAI) { return new CastFrostResistanceAuraAction(botAI); }
    static Action* fire_resistance_aura(ShadowAI* botAI) { return new CastFireResistanceAuraAction(botAI); }
    static Action* hammer_of_justice_on_enemy_healer(ShadowAI* botAI)
    {
        return new CastHammerOfJusticeOnEnemyHealerAction(botAI);
    }
    static Action* hammer_of_justice_on_snare_target(ShadowAI* botAI)
    {
        return new CastHammerOfJusticeSnareAction(botAI);
    }
    static Action* righteous_defense(ShadowAI* botAI) { return new CastRighteousDefenseAction(botAI); }
    static Action* repentance(ShadowAI* botAI) { return new CastRepentanceAction(botAI); }
    static Action* repentance_on_snare_target(ShadowAI* botAI) { return new CastRepentanceSnareAction(botAI); }
    static Action* repentance_on_enemy_healer(ShadowAI* botAI) { return new CastRepentanceOnHealerAction(botAI); }
    static Action* sanctity_aura(ShadowAI* botAI) { return new CastSanctityAuraAction(botAI); }
    static Action* holy_shock(ShadowAI* botAI) { return new CastHolyShockAction(botAI); }
    static Action* holy_shock_on_party(ShadowAI* botAI) { return new CastHolyShockOnPartyAction(botAI); }
    static Action* divine_plea(ShadowAI* ai) { return new CastDivinePleaAction(ai); }
    static Action* shield_of_righteousness(ShadowAI* ai) { return new ShieldOfRighteousnessAction(ai); }
    static Action* beacon_of_light_on_main_tank(ShadowAI* ai) { return new CastBeaconOfLightOnMainTankAction(ai); }
    static Action* sacred_shield_on_main_tank(ShadowAI* ai) { return new CastSacredShieldOnMainTankAction(ai); }
    static Action* avenging_wrath(ShadowAI* ai) { return new CastAvengingWrathAction(ai); }
    static Action* divine_illumination(ShadowAI* ai) { return new CastDivineIlluminationAction(ai); }
    static Action* divine_sacrifice(ShadowAI* ai) { return new CastDivineSacrificeAction(ai); }
    static Action* cancel_divine_sacrifice(ShadowAI* ai) { return new CastCancelDivineSacrificeAction(ai); }
};

SharedNamedObjectContextList<Strategy> PaladinAiObjectContext::sharedStrategyContexts;
SharedNamedObjectContextList<Action> PaladinAiObjectContext::sharedActionContexts;
SharedNamedObjectContextList<Trigger> PaladinAiObjectContext::sharedTriggerContexts;
SharedNamedObjectContextList<UntypedValue> PaladinAiObjectContext::sharedValueContexts;

PaladinAiObjectContext::PaladinAiObjectContext(ShadowAI* botAI)
    : AiObjectContext(botAI, sharedStrategyContexts, sharedActionContexts, sharedTriggerContexts, sharedValueContexts)
{
}

void PaladinAiObjectContext::BuildSharedContexts()
{
    BuildSharedStrategyContexts(sharedStrategyContexts);
    BuildSharedActionContexts(sharedActionContexts);
    BuildSharedTriggerContexts(sharedTriggerContexts);
    BuildSharedValueContexts(sharedValueContexts);
}

void PaladinAiObjectContext::BuildSharedStrategyContexts(SharedNamedObjectContextList<Strategy>& strategyContexts)
{
    AiObjectContext::BuildSharedStrategyContexts(strategyContexts);
    strategyContexts.Add(new PaladinStrategyFactoryInternal());
    strategyContexts.Add(new PaladinCombatStrategyFactoryInternal());
    strategyContexts.Add(new PaladinBuffStrategyFactoryInternal());
    strategyContexts.Add(new PaladinResistanceStrategyFactoryInternal());
}

void PaladinAiObjectContext::BuildSharedActionContexts(SharedNamedObjectContextList<Action>& actionContexts)
{
    AiObjectContext::BuildSharedActionContexts(actionContexts);
    actionContexts.Add(new PaladinAiObjectContextInternal());
}

void PaladinAiObjectContext::BuildSharedTriggerContexts(SharedNamedObjectContextList<Trigger>& triggerContexts)
{
    AiObjectContext::BuildSharedTriggerContexts(triggerContexts);
    triggerContexts.Add(new PaladinTriggerFactoryInternal());
}

void PaladinAiObjectContext::BuildSharedValueContexts(SharedNamedObjectContextList<UntypedValue>& valueContexts)
{
    AiObjectContext::BuildSharedValueContexts(valueContexts);
}