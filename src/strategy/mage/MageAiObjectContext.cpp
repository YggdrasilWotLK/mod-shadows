/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#include "MageAiObjectContext.h"
#include "ArcaneMageStrategy.h"
#include "FireMageStrategy.h"
#include "FrostFireMageStrategy.h"
#include "FrostMageStrategy.h"
#include "GenericMageNonCombatStrategy.h"
#include "MageActions.h"
#include "MageTriggers.h"
#include "NamedObjectContext.h"
#include "Shadows.h"
#include "PullStrategy.h"

class MageStrategyFactoryInternal : public NamedObjectContext<Strategy>
{
public:
    MageStrategyFactoryInternal()
    {
        creators["nc"] = &MageStrategyFactoryInternal::nc;
        creators["pull"] = &MageStrategyFactoryInternal::pull;
        creators["aoe"] = &MageStrategyFactoryInternal::aoe;
        creators["cure"] = &MageStrategyFactoryInternal::cure;
        creators["buff"] = &MageStrategyFactoryInternal::buff;
        creators["boost"] = &MageStrategyFactoryInternal::boost;
        creators["cc"] = &MageStrategyFactoryInternal::cc;
        creators["firestarter"] = &MageStrategyFactoryInternal::firestarter;
    }

private:
    static Strategy* nc(ShadowAI* botAI) { return new GenericMageNonCombatStrategy(botAI); }
    static Strategy* pull(ShadowAI* botAI) { return new PullStrategy(botAI, "shoot"); }
    static Strategy* aoe(ShadowAI* botAI) { return new MageAoeStrategy(botAI); }
    static Strategy* cure(ShadowAI* botAI) { return new MageCureStrategy(botAI); }
    static Strategy* buff(ShadowAI* botAI) { return new MageBuffStrategy(botAI); }
    static Strategy* boost(ShadowAI* botAI) { return new MageBoostStrategy(botAI); }
    static Strategy* cc(ShadowAI* botAI) { return new MageCcStrategy(botAI); }
    static Strategy* firestarter(ShadowAI* botAI) { return new FirestarterStrategy(botAI); }
};

class MageCombatStrategyFactoryInternal : public NamedObjectContext<Strategy>
{
public:
    MageCombatStrategyFactoryInternal() : NamedObjectContext<Strategy>(false, true)
    {
        creators["frost"] = &MageCombatStrategyFactoryInternal::frost;
        creators["fire"] = &MageCombatStrategyFactoryInternal::fire;
        creators["frostfire"] = &MageCombatStrategyFactoryInternal::frostfire;
        creators["arcane"] = &MageCombatStrategyFactoryInternal::arcane;
    }

private:
    static Strategy* frost(ShadowAI* botAI) { return new FrostMageStrategy(botAI); }
    static Strategy* fire(ShadowAI* botAI) { return new FireMageStrategy(botAI); }
    static Strategy* frostfire(ShadowAI* botAI) { return new FrostFireMageStrategy(botAI); }
    static Strategy* arcane(ShadowAI* botAI) { return new ArcaneMageStrategy(botAI); }
};

class MageBuffStrategyFactoryInternal : public NamedObjectContext<Strategy>
{
public:
    MageBuffStrategyFactoryInternal() : NamedObjectContext<Strategy>(false, true)
    {
        creators["bmana"] = &MageBuffStrategyFactoryInternal::bmana;
        creators["bdps"] = &MageBuffStrategyFactoryInternal::bdps;
    }

private:
    static Strategy* bmana(ShadowAI* botAI) { return new MageBuffManaStrategy(botAI); }
    static Strategy* bdps(ShadowAI* botAI) { return new MageBuffDpsStrategy(botAI); }
};

class MageTriggerFactoryInternal : public NamedObjectContext<Trigger>
{
public:
    MageTriggerFactoryInternal()
    {
        creators["fireball"] = &MageTriggerFactoryInternal::fireball;
        creators["pyroblast"] = &MageTriggerFactoryInternal::pyroblast;
        creators["combustion"] = &MageTriggerFactoryInternal::combustion;
        creators["fingers of frost"] = &MageTriggerFactoryInternal::fingers_of_frost;
        creators["brain freeze"] = &MageTriggerFactoryInternal::brain_freeze;
        creators["icy veins"] = &MageTriggerFactoryInternal::icy_veins;
        creators["cold snap"] = &MageTriggerFactoryInternal::cold_snap;
        creators["ice barrier"] = &MageTriggerFactoryInternal::ice_barrier;
        creators["arcane intellect"] = &MageTriggerFactoryInternal::arcane_intellect;
        creators["arcane intellect on party"] = &MageTriggerFactoryInternal::arcane_intellect_on_party;
        creators["mage armor"] = &MageTriggerFactoryInternal::mage_armor;
        creators["remove curse"] = &MageTriggerFactoryInternal::remove_curse;
        creators["remove curse on party"] = &MageTriggerFactoryInternal::remove_curse_on_party;
        creators["counterspell"] = &MageTriggerFactoryInternal::counterspell;
        creators["polymorph"] = &MageTriggerFactoryInternal::polymorph;
        creators["spellsteal"] = &MageTriggerFactoryInternal::spellsteal;
        creators["hot streak"] = &MageTriggerFactoryInternal::hot_streak;
        creators["living bomb"] = &MageTriggerFactoryInternal::living_bomb;
        creators["living bomb on attackers"] = &MageTriggerFactoryInternal::living_bomb_on_attackers;
        creators["missile barrage"] = &MageTriggerFactoryInternal::missile_barrage;
        creators["arcane blast"] = &MageTriggerFactoryInternal::arcane_blast;
        creators["counterspell on enemy healer"] = &MageTriggerFactoryInternal::counterspell_enemy_healer;
        creators["arcane power"] = &MageTriggerFactoryInternal::arcane_power;
        creators["presence of mind"] = &MageTriggerFactoryInternal::presence_of_mind;
        creators["fire ward"] = &MageTriggerFactoryInternal::fire_ward;
        creators["frost ward"] = &MageTriggerFactoryInternal::frost_ward;
        creators["arcane blast stack"] = &MageTriggerFactoryInternal::arcane_blast_stack;
        creators["mirror image"] = &MageTriggerFactoryInternal::mirror_image;
        creators["frost nova on target"] = &MageTriggerFactoryInternal::frost_nova_on_target;
        creators["frostbite on target"] = &MageTriggerFactoryInternal::frostbite_on_target;
        creators["no focus magic"] = &MageTriggerFactoryInternal::no_focus_magic;
        creators["frostfire bolt"] = &MageTriggerFactoryInternal::frostfire_bolt;
        creators["firestarter"] = &MageTriggerFactoryInternal::firestarter;
        creators["improved scorch"] = &MageTriggerFactoryInternal::improved_scorch;
        creators["flamestrike nearby"] = &MageTriggerFactoryInternal::flamestrike_nearby;
        creators["flamestrike active and medium aoe"] = &MageTriggerFactoryInternal::flamestrike_blizzard;
        creators["arcane blast 4 stacks and missile barrage"] = &MageTriggerFactoryInternal::arcane_blast_4_stacks_and_missile_barrage;
        creators["icy veins on cd"] = &MageTriggerFactoryInternal::icy_veins_on_cd;
        creators["deep freeze on cd"] = &MageTriggerFactoryInternal::deep_freeze_on_cd;
        creators["no mana gem"] = &MageTriggerFactoryInternal::NoManaGem;
        creators["blizzard channel check"] = &MageTriggerFactoryInternal::blizzard_channel_check;
        creators["blast wave off cd"] = &MageTriggerFactoryInternal::blast_wave_off_cd;
        creators["blast wave off cd and medium aoe"] = &MageTriggerFactoryInternal::blast_wave_off_cd_and_medium_aoe;
        creators["no firestarter strategy"] = &MageTriggerFactoryInternal::no_firestarter_strategy;
        creators["enemy is close and no firestarter strategy"] = &MageTriggerFactoryInternal::enemy_is_close_and_no_firestarter_strategy;
        creators["enemy too close for spell and no firestarter strategy"] = &MageTriggerFactoryInternal::enemy_too_close_for_spell_and_no_firestarter_strategy;
    }

private:
    static Trigger* presence_of_mind(ShadowAI* botAI) { return new PresenceOfMindTrigger(botAI); }
    static Trigger* frost_ward(ShadowAI* botAI) { return new FrostWardTrigger(botAI); }
    static Trigger* fire_ward(ShadowAI* botAI) { return new FireWardTrigger(botAI); }
    static Trigger* arcane_power(ShadowAI* botAI) { return new ArcanePowerTrigger(botAI); }
    static Trigger* hot_streak(ShadowAI* botAI) { return new HotStreakTrigger(botAI); }
    static Trigger* fireball(ShadowAI* botAI) { return new FireballTrigger(botAI); }
    static Trigger* pyroblast(ShadowAI* botAI) { return new PyroblastTrigger(botAI); }
    static Trigger* combustion(ShadowAI* botAI) { return new CombustionTrigger(botAI); }
    static Trigger* fingers_of_frost(ShadowAI* botAI) { return new FingersOfFrostTrigger(botAI); }
    static Trigger* brain_freeze(ShadowAI* botAI) { return new BrainFreezeTrigger(botAI); }
    static Trigger* icy_veins(ShadowAI* botAI) { return new IcyVeinsTrigger(botAI); }
    static Trigger* cold_snap(ShadowAI* botAI) { return new ColdSnapTrigger(botAI); }
    static Trigger* ice_barrier(ShadowAI* botAI) { return new IceBarrierTrigger(botAI); }
    static Trigger* arcane_intellect(ShadowAI* botAI) { return new ArcaneIntellectTrigger(botAI); }
    static Trigger* arcane_intellect_on_party(ShadowAI* botAI) { return new ArcaneIntellectOnPartyTrigger(botAI); }
    static Trigger* mage_armor(ShadowAI* botAI) { return new MageArmorTrigger(botAI); }
    static Trigger* remove_curse(ShadowAI* botAI) { return new RemoveCurseTrigger(botAI); }
    static Trigger* remove_curse_on_party(ShadowAI* botAI) { return new PartyMemberRemoveCurseTrigger(botAI); }
    static Trigger* counterspell(ShadowAI* botAI) { return new CounterspellInterruptSpellTrigger(botAI); }
    static Trigger* polymorph(ShadowAI* botAI) { return new PolymorphTrigger(botAI); }
    static Trigger* spellsteal(ShadowAI* botAI) { return new SpellstealTrigger(botAI); }
    static Trigger* living_bomb(ShadowAI* botAI) { return new LivingBombTrigger(botAI); }
    static Trigger* living_bomb_on_attackers(ShadowAI* botAI) { return new LivingBombOnAttackersTrigger(botAI); }
    static Trigger* missile_barrage(ShadowAI* botAI) { return new MissileBarrageTrigger(botAI); }
    static Trigger* arcane_blast(ShadowAI* botAI) { return new ArcaneBlastTrigger(botAI); }
    static Trigger* counterspell_enemy_healer(ShadowAI* botAI) { return new CounterspellEnemyHealerTrigger(botAI); }
    static Trigger* arcane_blast_stack(ShadowAI* botAI) { return new ArcaneBlastStackTrigger(botAI); }
    static Trigger* mirror_image(ShadowAI* botAI) { return new MirrorImageTrigger(botAI); }
    static Trigger* frost_nova_on_target(ShadowAI* botAI) { return new FrostNovaOnTargetTrigger(botAI); }
    static Trigger* frostbite_on_target(ShadowAI* botAI) { return new FrostbiteOnTargetTrigger(botAI); }
    static Trigger* no_focus_magic(ShadowAI* botAI) { return new NoFocusMagicTrigger(botAI); }
    static Trigger* frostfire_bolt(ShadowAI* botAI) { return new FrostfireBoltTrigger(botAI); }
    static Trigger* improved_scorch(ShadowAI* botAI) { return new ImprovedScorchTrigger(botAI); }
    static Trigger* firestarter(ShadowAI* botAI) { return new FirestarterTrigger(botAI); }
    static Trigger* flamestrike_nearby(ShadowAI* botAI) { return new FlamestrikeNearbyTrigger(botAI); }
    static Trigger* flamestrike_blizzard(ShadowAI* botAI) { return new FlamestrikeBlizzardTrigger(botAI); }
    static Trigger* arcane_blast_4_stacks_and_missile_barrage(ShadowAI* botAI) { return new ArcaneBlast4StacksAndMissileBarrageTrigger(botAI); }
    static Trigger* icy_veins_on_cd(ShadowAI* botAI) { return new IcyVeinsCooldownTrigger(botAI); }
    static Trigger* deep_freeze_on_cd(ShadowAI* botAI) { return new DeepFreezeCooldownTrigger(botAI); }
    static Trigger* NoManaGem(ShadowAI* botAI) { return new NoManaGemTrigger(botAI); }
    static Trigger* blizzard_channel_check(ShadowAI* botAI) { return new BlizzardChannelCheckTrigger(botAI); }
    static Trigger* blast_wave_off_cd(ShadowAI* botAI) { return new BlastWaveOffCdTrigger(botAI); }
    static Trigger* blast_wave_off_cd_and_medium_aoe(ShadowAI* botAI) { return new BlastWaveOffCdTriggerAndMediumAoeTrigger(botAI); }
    static Trigger* no_firestarter_strategy(ShadowAI* botAI) { return new NoFirestarterStrategyTrigger(botAI); }
    static Trigger* enemy_is_close_and_no_firestarter_strategy(ShadowAI* botAI) { return new EnemyIsCloseAndNoFirestarterStrategyTrigger(botAI); }
    static Trigger* enemy_too_close_for_spell_and_no_firestarter_strategy(ShadowAI* botAI) { return new EnemyTooCloseForSpellAndNoFirestarterStrategyTrigger(botAI); }
};

class MageAiObjectContextInternal : public NamedObjectContext<Action>
{
public:
    MageAiObjectContextInternal()
    {
        creators["arcane power"] = &MageAiObjectContextInternal::arcane_power;
        creators["presence of mind"] = &MageAiObjectContextInternal::presence_of_mind;
        creators["frostbolt"] = &MageAiObjectContextInternal::frostbolt;
        creators["frostfire bolt"] = &MageAiObjectContextInternal::frostfire_bolt;
        creators["ice lance"] = &MageAiObjectContextInternal::ice_lance;
        creators["deep freeze"] = &MageAiObjectContextInternal::deep_freeze;
        creators["blizzard"] = &MageAiObjectContextInternal::blizzard;
        creators["cone of cold"] = &MageAiObjectContextInternal::cone_of_cold;
        creators["frost nova"] = &MageAiObjectContextInternal::frost_nova;
        creators["arcane intellect"] = &MageAiObjectContextInternal::arcane_intellect;
        creators["arcane intellect on party"] = &MageAiObjectContextInternal::arcane_intellect_on_party;
        creators["conjure water"] = &MageAiObjectContextInternal::conjure_water;
        creators["conjure food"] = &MageAiObjectContextInternal::conjure_food;
        creators["conjure mana gem"] = &MageAiObjectContextInternal::conjure_mana_gem;
        creators["molten armor"] = &MageAiObjectContextInternal::molten_armor;
        creators["mage armor"] = &MageAiObjectContextInternal::mage_armor;
        creators["ice armor"] = &MageAiObjectContextInternal::ice_armor;
        creators["frost armor"] = &MageAiObjectContextInternal::frost_armor;
        creators["fireball"] = &MageAiObjectContextInternal::fireball;
        creators["pyroblast"] = &MageAiObjectContextInternal::pyroblast;
        creators["flamestrike"] = &MageAiObjectContextInternal::flamestrike;
        creators["fire blast"] = &MageAiObjectContextInternal::fire_blast;
        creators["scorch"] = &MageAiObjectContextInternal::scorch;
        creators["counterspell"] = &MageAiObjectContextInternal::counterspell;
        creators["remove curse"] = &MageAiObjectContextInternal::remove_curse;
        creators["remove curse on party"] = &MageAiObjectContextInternal::remove_curse_on_party;
        creators["remove lesser curse"] = &MageAiObjectContextInternal::remove_lesser_curse;
        creators["remove lesser curse on party"] = &MageAiObjectContextInternal::remove_lesser_curse_on_party;
        creators["icy veins"] = &MageAiObjectContextInternal::icy_veins;
        creators["cold snap"] = &MageAiObjectContextInternal::cold_snap;
        creators["ice barrier"] = &MageAiObjectContextInternal::ice_barrier;
        creators["summon water elemental"] = &MageAiObjectContextInternal::summon_water_elemental;
        creators["combustion"] = &MageAiObjectContextInternal::combustion;
        creators["ice block"] = &MageAiObjectContextInternal::ice_block;
        creators["polymorph"] = &MageAiObjectContextInternal::polymorph;
        creators["spellsteal"] = &MageAiObjectContextInternal::spellsteal;
        creators["living bomb"] = &MageAiObjectContextInternal::living_bomb;
        creators["living bomb on attackers"] = &MageAiObjectContextInternal::living_bomb_on_attackers;
        creators["dragon's breath"] = &MageAiObjectContextInternal::dragons_breath;
        creators["blast wave"] = &MageAiObjectContextInternal::blast_wave;
        creators["invisibility"] = &MageAiObjectContextInternal::invisibility;
        creators["evocation"] = &MageAiObjectContextInternal::evocation;
        creators["arcane blast"] = &MageAiObjectContextInternal::arcane_blast;
        creators["arcane barrage"] = &MageAiObjectContextInternal::arcane_barrage;
        creators["arcane missiles"] = &MageAiObjectContextInternal::arcane_missiles;
        creators["counterspell on enemy healer"] = &MageAiObjectContextInternal::counterspell_on_enemy_healer;
        creators["fire ward"] = &MageAiObjectContextInternal::fire_ward;
        creators["frost ward"] = &MageAiObjectContextInternal::frost_ward;
        creators["mirror image"] = &MageAiObjectContextInternal::mirror_image;
        creators["focus magic on party"] = &MageAiObjectContextInternal::focus_magic_on_party;
        creators["blink back"] = &MageAiObjectContextInternal::blink_back;
        creators["use mana sapphire"] = &MageAiObjectContextInternal::use_mana_sapphire;
        creators["use mana emerald"] = &MageAiObjectContextInternal::use_mana_emerald;
        creators["use mana ruby"] = &MageAiObjectContextInternal::use_mana_ruby;
        creators["use mana citrine"] = &MageAiObjectContextInternal::use_mana_citrine;
        creators["use mana jade"] = &MageAiObjectContextInternal::use_mana_jade;
        creators["use mana agate"] = &MageAiObjectContextInternal::use_mana_agate;
        creators["mana shield"] = &MageAiObjectContextInternal::mana_shield;
    }

private:
    static Action* presence_of_mind(ShadowAI* botAI) { return new CastPresenceOfMindAction(botAI); }
    static Action* frost_ward(ShadowAI* botAI) { return new CastFrostWardAction(botAI); }
    static Action* fire_ward(ShadowAI* botAI) { return new CastFireWardAction(botAI); }
    static Action* arcane_power(ShadowAI* botAI) { return new CastArcanePowerAction(botAI); }
    static Action* arcane_missiles(ShadowAI* botAI) { return new CastArcaneMissilesAction(botAI); }
    static Action* arcane_barrage(ShadowAI* botAI) { return new CastArcaneBarrageAction(botAI); }
    static Action* arcane_blast(ShadowAI* botAI) { return new CastArcaneBlastAction(botAI); }
    static Action* frostbolt(ShadowAI* botAI) { return new CastFrostboltAction(botAI); }
    static Action* frostfire_bolt(ShadowAI* botAI) { return new CastFrostfireBoltAction(botAI); }
    static Action* ice_lance(ShadowAI* botAI) { return new CastIceLanceAction(botAI); }
    static Action* deep_freeze(ShadowAI* botAI) { return new CastDeepFreezeAction(botAI); }
    static Action* blizzard(ShadowAI* botAI) { return new CastBlizzardAction(botAI); }
    static Action* cone_of_cold(ShadowAI* botAI) { return new CastConeOfColdAction(botAI); }
    static Action* frost_nova(ShadowAI* botAI) { return new CastFrostNovaAction(botAI); }
    static Action* arcane_intellect(ShadowAI* botAI) { return new CastArcaneIntellectAction(botAI); }
    static Action* arcane_intellect_on_party(ShadowAI* botAI) { return new CastArcaneIntellectOnPartyAction(botAI); }
    static Action* conjure_water(ShadowAI* botAI) { return new CastConjureWaterAction(botAI); }
    static Action* conjure_food(ShadowAI* botAI) { return new CastConjureFoodAction(botAI); }
    static Action* conjure_mana_gem(ShadowAI* botAI) { return new CastConjureManaGemAction(botAI); }
    static Action* molten_armor(ShadowAI* botAI) { return new CastMoltenArmorAction(botAI); }
    static Action* mage_armor(ShadowAI* botAI) { return new CastMageArmorAction(botAI); }
    static Action* ice_armor(ShadowAI* botAI) { return new CastIceArmorAction(botAI); }
    static Action* frost_armor(ShadowAI* botAI) { return new CastFrostArmorAction(botAI); }
    static Action* fireball(ShadowAI* botAI) { return new CastFireballAction(botAI); }
    static Action* pyroblast(ShadowAI* botAI) { return new CastPyroblastAction(botAI); }
    static Action* flamestrike(ShadowAI* botAI) { return new CastFlamestrikeAction(botAI); }
    static Action* fire_blast(ShadowAI* botAI) { return new CastFireBlastAction(botAI); }
    static Action* scorch(ShadowAI* botAI) { return new CastScorchAction(botAI); }
    static Action* counterspell(ShadowAI* botAI) { return new CastCounterspellAction(botAI); }
    static Action* remove_curse(ShadowAI* botAI) { return new CastRemoveCurseAction(botAI); }
    static Action* remove_curse_on_party(ShadowAI* botAI) { return new CastRemoveCurseOnPartyAction(botAI); }
    static Action* remove_lesser_curse(ShadowAI* botAI) { return new CastRemoveLesserCurseAction(botAI); }
    static Action* remove_lesser_curse_on_party(ShadowAI* botAI) { return new CastRemoveLesserCurseOnPartyAction(botAI); }
    static Action* icy_veins(ShadowAI* botAI) { return new CastIcyVeinsAction(botAI); }
    static Action* cold_snap(ShadowAI* botAI) { return new CastColdSnapAction(botAI); }
    static Action* ice_barrier(ShadowAI* botAI) { return new CastIceBarrierAction(botAI); }
    static Action* summon_water_elemental(ShadowAI* botAI) { return new CastSummonWaterElementalAction(botAI); }
    static Action* combustion(ShadowAI* botAI) { return new CastCombustionAction(botAI); }
    static Action* ice_block(ShadowAI* botAI) { return new CastIceBlockAction(botAI); }
    static Action* polymorph(ShadowAI* botAI) { return new CastPolymorphAction(botAI); }
    static Action* spellsteal(ShadowAI* botAI) { return new CastSpellstealAction(botAI); }
    static Action* living_bomb(ShadowAI* botAI) { return new CastLivingBombAction(botAI); }
    static Action* living_bomb_on_attackers(ShadowAI* botAI) { return new CastLivingBombOnAttackersAction(botAI); }
    static Action* dragons_breath(ShadowAI* botAI) { return new CastDragonsBreathAction(botAI); }
    static Action* blast_wave(ShadowAI* botAI) { return new CastBlastWaveAction(botAI); }
    static Action* invisibility(ShadowAI* botAI) { return new CastInvisibilityAction(botAI); }
    static Action* evocation(ShadowAI* botAI) { return new CastEvocationAction(botAI); }
    static Action* counterspell_on_enemy_healer(ShadowAI* botAI) { return new CastCounterspellOnEnemyHealerAction(botAI); }
    static Action* mirror_image(ShadowAI* botAI) { return new CastMirrorImageAction(botAI); }
    static Action* focus_magic_on_party(ShadowAI* botAI) { return new CastFocusMagicOnPartyAction(botAI); }
    static Action* blink_back(ShadowAI* botAI) { return new CastBlinkBackAction(botAI); }
    static Action* use_mana_sapphire(ShadowAI* botAI) { return new UseManaSapphireAction(botAI); }
    static Action* use_mana_emerald(ShadowAI* botAI) { return new UseManaEmeraldAction(botAI); }
    static Action* use_mana_ruby(ShadowAI* botAI) { return new UseManaRubyAction(botAI); }
    static Action* use_mana_citrine(ShadowAI* botAI) { return new UseManaCitrineAction(botAI); }
    static Action* use_mana_jade(ShadowAI* botAI) { return new UseManaJadeAction(botAI); }
    static Action* use_mana_agate(ShadowAI* botAI) { return new UseManaAgateAction(botAI); }
    static Action* mana_shield(ShadowAI* botAI) { return new CastManaShieldAction(botAI); }
};

SharedNamedObjectContextList<Strategy> MageAiObjectContext::sharedStrategyContexts;
SharedNamedObjectContextList<Action> MageAiObjectContext::sharedActionContexts;
SharedNamedObjectContextList<Trigger> MageAiObjectContext::sharedTriggerContexts;
SharedNamedObjectContextList<UntypedValue> MageAiObjectContext::sharedValueContexts;

MageAiObjectContext::MageAiObjectContext(ShadowAI* botAI)
    : AiObjectContext(botAI, sharedStrategyContexts, sharedActionContexts, sharedTriggerContexts, sharedValueContexts)
{
}

void MageAiObjectContext::BuildSharedContexts()
{
    BuildSharedStrategyContexts(sharedStrategyContexts);
    BuildSharedActionContexts(sharedActionContexts);
    BuildSharedTriggerContexts(sharedTriggerContexts);
    BuildSharedValueContexts(sharedValueContexts);
}

void MageAiObjectContext::BuildSharedStrategyContexts(SharedNamedObjectContextList<Strategy>& strategyContexts)
{
    AiObjectContext::BuildSharedStrategyContexts(strategyContexts);
    strategyContexts.Add(new MageStrategyFactoryInternal());
    strategyContexts.Add(new MageCombatStrategyFactoryInternal());
    strategyContexts.Add(new MageBuffStrategyFactoryInternal());
}

void MageAiObjectContext::BuildSharedActionContexts(SharedNamedObjectContextList<Action>& actionContexts)
{
    AiObjectContext::BuildSharedActionContexts(actionContexts);
    actionContexts.Add(new MageAiObjectContextInternal());
}

void MageAiObjectContext::BuildSharedTriggerContexts(SharedNamedObjectContextList<Trigger>& triggerContexts)
{
    AiObjectContext::BuildSharedTriggerContexts(triggerContexts);
    triggerContexts.Add(new MageTriggerFactoryInternal());
}

void MageAiObjectContext::BuildSharedValueContexts(SharedNamedObjectContextList<UntypedValue>& valueContexts)
{
    AiObjectContext::BuildSharedValueContexts(valueContexts);
}
