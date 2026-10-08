/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_STRATEGYCONTEXT_H
#define _SHADOW_STRATEGYCONTEXT_H

#include "AttackEnemyPlayersStrategy.h"
#include "BattlegroundStrategy.h"
#include "CastTimeStrategy.h"
#include "ChatCommandHandlerStrategy.h"
#include "ConserveManaStrategy.h"
#include "CustomStrategy.h"
#include "DeadStrategy.h"
#include "DebugStrategy.h"
#include "DpsAssistStrategy.h"
#include "DuelStrategy.h"
#include "EmoteStrategy.h"
#include "FleeStrategy.h"
#include "FollowMasterStrategy.h"
#include "GrindingStrategy.h"
#include "GroupStrategy.h"
#include "GuardStrategy.h"
#include "GuildStrategy.h"
#include "KiteStrategy.h"
#include "LfgStrategy.h"
#include "LootNonCombatStrategy.h"
#include "MaintenanceStrategy.h"
#include "MarkRtiStrategy.h"
#include "MeleeCombatStrategy.h"
#include "MoveFromGroupStrategy.h"
#include "NamedObjectContext.h"
#include "NewRpgStrategy.h"
#include "NonCombatStrategy.h"
#include "PassiveStrategy.h"
#include "PullStrategy.h"
#include "QuestStrategies.h"
#include "RTSCStrategy.h"
#include "RacialsStrategy.h"
#include "RangedCombatStrategy.h"
#include "ReturnStrategy.h"
#include "RpgStrategy.h"
#include "RunawayStrategy.h"
#include "StayStrategy.h"
#include "TankAssistStrategy.h"
#include "TellTargetStrategy.h"
#include "ThreatStrategy.h"
#include "TravelStrategy.h"
#include "UseFoodStrategy.h"
#include "UsePotionsStrategy.h"
#include "WorldPacketHandlerStrategy.h"

class StrategyContext : public NamedObjectContext<Strategy>
{
public:
    StrategyContext()
    {
        creators["racials"] = &StrategyContext::racials;
        creators["loot"] = &StrategyContext::loot;
        creators["gather"] = &StrategyContext::gather;
        creators["emote"] = &StrategyContext::emote;
        creators["passive"] = &StrategyContext::passive;
        creators["save mana"] = &StrategyContext::auto_save_mana;
        creators["food"] = &StrategyContext::food;
        creators["chat"] = &StrategyContext::chat;
        creators["default"] = &StrategyContext::world_packet;
        creators["ready check"] = &StrategyContext::ready_check;
        creators["dead"] = &StrategyContext::dead;
        creators["flee"] = &StrategyContext::flee;
        creators["duel"] = &StrategyContext::duel;
        creators["start duel"] = &StrategyContext::start_duel;
        creators["kite"] = &StrategyContext::kite;
        creators["potions"] = &StrategyContext::potions;
        creators["cast time"] = &StrategyContext::cast_time;
        creators["threat"] = &StrategyContext::threat;
        creators["focus"] = &StrategyContext::focus;
        creators["tell target"] = &StrategyContext::tell_target;
        creators["pvp"] = &StrategyContext::pvp;
        creators["return"] = &StrategyContext::_return;
        creators["lfg"] = &StrategyContext::lfg;
        creators["custom"] = &StrategyContext::custom;
        creators["reveal"] = &StrategyContext::reveal;
        creators["collision"] = &StrategyContext::collision;
        creators["rpg"] = &StrategyContext::rpg;
        creators["new rpg"] = &StrategyContext::new_rpg;
        creators["travel"] = &StrategyContext::travel;
        creators["explore"] = &StrategyContext::explore;
        creators["map"] = &StrategyContext::map;
        creators["map full"] = &StrategyContext::map_full;
        creators["sit"] = &StrategyContext::sit;
        creators["mark rti"] = &StrategyContext::mark_rti;
        creators["adds"] = &StrategyContext::possible_adds;
        creators["close"] = &StrategyContext::close;
        creators["ranged"] = &StrategyContext::ranged;
        creators["behind"] = &StrategyContext::behind;
        creators["bg"] = &StrategyContext::bg;
        creators["battleground"] = &StrategyContext::battleground;
        creators["warsong"] = &StrategyContext::warsong;
        creators["alterac"] = &StrategyContext::alterac;
        creators["arathi"] = &StrategyContext::arathi;
        creators["eye"] = &StrategyContext::eye;
        creators["isle"] = &StrategyContext::isle;
        creators["arena"] = &StrategyContext::arena;
        creators["mount"] = &StrategyContext::mount;
        creators["rtsc"] = &StrategyContext::rtsc;
        creators["attack tagged"] = &StrategyContext::attack_tagged;
        creators["debug"] = &StrategyContext::debug;
        creators["debug move"] = &StrategyContext::debug_move;
        creators["debug rpg"] = &StrategyContext::debug_rpg;
        creators["debug spell"] = &StrategyContext::debug_spell;
        creators["debug quest"] = &StrategyContext::debug_quest;
        creators["maintenance"] = &StrategyContext::maintenance;
        creators["group"] = &StrategyContext::group;
        creators["guild"] = &StrategyContext::guild;
        creators["grind"] = &StrategyContext::grind;
        creators["avoid aoe"] = &StrategyContext::avoid_aoe;
        creators["tank face"] = &StrategyContext::tank_face;
        creators["move random"] = &StrategyContext::move_random;
        creators["formation"] = &StrategyContext::combat_formation;
        creators["move from group"] = &StrategyContext::move_from_group;
        creators["worldbuff"] = &StrategyContext::world_buff;
    }

private:
    static Strategy* behind(ShadowAI* botAI) { return new SetBehindCombatStrategy(botAI); }
    static Strategy* ranged(ShadowAI* botAI) { return new RangedCombatStrategy(botAI); }
    static Strategy* close(ShadowAI* botAI) { return new MeleeCombatStrategy(botAI); }
    static Strategy* mark_rti(ShadowAI* botAI) { return new MarkRtiStrategy(botAI); }
    static Strategy* tell_target(ShadowAI* botAI) { return new TellTargetStrategy(botAI); }
    static Strategy* threat(ShadowAI* botAI) { return new ThreatStrategy(botAI); }
    static Strategy* focus(ShadowAI* botAI) { return new FocusStrategy(botAI); }
    static Strategy* cast_time(ShadowAI* botAI) { return new CastTimeStrategy(botAI); }
    static Strategy* potions(ShadowAI* botAI) { return new UsePotionsStrategy(botAI); }
    static Strategy* kite(ShadowAI* botAI) { return new KiteStrategy(botAI); }
    static Strategy* duel(ShadowAI* botAI) { return new DuelStrategy(botAI); }
    static Strategy* start_duel(ShadowAI* botAI) { return new StartDuelStrategy(botAI); }
    static Strategy* flee(ShadowAI* botAI) { return new FleeStrategy(botAI); }
    static Strategy* dead(ShadowAI* botAI) { return new DeadStrategy(botAI); }
    static Strategy* racials(ShadowAI* botAI) { return new RacialsStrategy(botAI); }
    static Strategy* loot(ShadowAI* botAI) { return new LootNonCombatStrategy(botAI); }
    static Strategy* gather(ShadowAI* botAI) { return new GatherStrategy(botAI); }
    static Strategy* emote(ShadowAI* botAI) { return new EmoteStrategy(botAI); }
    static Strategy* passive(ShadowAI* botAI) { return new PassiveStrategy(botAI); }
    // static Strategy* conserve_mana(ShadowAI* botAI) { return new ConserveManaStrategy(botAI); }
    static Strategy* auto_save_mana(ShadowAI* botAI) { return new HealerAutoSaveManaStrategy(botAI); }
    static Strategy* food(ShadowAI* botAI) { return new UseFoodStrategy(botAI); }
    static Strategy* chat(ShadowAI* botAI) { return new ChatCommandHandlerStrategy(botAI); }
    static Strategy* world_packet(ShadowAI* botAI) { return new WorldPacketHandlerStrategy(botAI); }
    static Strategy* ready_check(ShadowAI* botAI) { return new ReadyCheckStrategy(botAI); }
    static Strategy* pvp(ShadowAI* botAI) { return new AttackEnemyPlayersStrategy(botAI); }
    static Strategy* _return(ShadowAI* botAI) { return new ReturnStrategy(botAI); }
    static Strategy* lfg(ShadowAI* botAI) { return new LfgStrategy(botAI); }
    static Strategy* custom(ShadowAI* botAI) { return new CustomStrategy(botAI); }
    static Strategy* reveal(ShadowAI* botAI) { return new RevealStrategy(botAI); }
    static Strategy* collision(ShadowAI* botAI) { return new CollisionStrategy(botAI); }
    static Strategy* rpg(ShadowAI* botAI) { return new RpgStrategy(botAI); }
    static Strategy* new_rpg(ShadowAI* botAI) { return new NewRpgStrategy(botAI); }
    static Strategy* travel(ShadowAI* botAI) { return new TravelStrategy(botAI); }
    static Strategy* explore(ShadowAI* botAI) { return new ExploreStrategy(botAI); }
    static Strategy* map(ShadowAI* botAI) { return new MapStrategy(botAI); }
    static Strategy* map_full(ShadowAI* botAI) { return new MapFullStrategy(botAI); }
    static Strategy* sit(ShadowAI* botAI) { return new SitStrategy(botAI); }
    static Strategy* possible_adds(ShadowAI* botAI) { return new PossibleAddsStrategy(botAI); }
    static Strategy* mount(ShadowAI* botAI) { return new MountStrategy(botAI); }
    static Strategy* bg(ShadowAI* botAI) { return new BGStrategy(botAI); }
    static Strategy* battleground(ShadowAI* botAI) { return new BattlegroundStrategy(botAI); }
    static Strategy* warsong(ShadowAI* botAI) { return new WarsongStrategy(botAI); }
    static Strategy* alterac(ShadowAI* botAI) { return new AlteracStrategy(botAI); }
    static Strategy* arathi(ShadowAI* botAI) { return new ArathiStrategy(botAI); }
    static Strategy* eye(ShadowAI* botAI) { return new EyeStrategy(botAI); }
    static Strategy* isle(ShadowAI* botAI) { return new IsleStrategy(botAI); }
    static Strategy* arena(ShadowAI* botAI) { return new ArenaStrategy(botAI); }
    static Strategy* rtsc(ShadowAI* botAI) { return new RTSCStrategy(botAI); }
    static Strategy* attack_tagged(ShadowAI* botAI) { return new AttackTaggedStrategy(botAI); }
    static Strategy* debug(ShadowAI* botAI) { return new DebugStrategy(botAI); }
    static Strategy* debug_move(ShadowAI* botAI) { return new DebugMoveStrategy(botAI); }
    static Strategy* debug_rpg(ShadowAI* botAI) { return new DebugRpgStrategy(botAI); }
    static Strategy* debug_spell(ShadowAI* botAI) { return new DebugSpellStrategy(botAI); }
    static Strategy* debug_quest(ShadowAI* botAI) { return new DebugQuestStrategy(botAI); }
    static Strategy* maintenance(ShadowAI* botAI) { return new MaintenanceStrategy(botAI); }
    static Strategy* group(ShadowAI* botAI) { return new GroupStrategy(botAI); }
    static Strategy* guild (ShadowAI* botAI) { return new GuildStrategy(botAI); }
    static Strategy* grind(ShadowAI* botAI) { return new GrindingStrategy(botAI); }
    static Strategy* avoid_aoe(ShadowAI* botAI) { return new AvoidAoeStrategy(botAI); }
    static Strategy* tank_face(ShadowAI* botAI) { return new TankFaceStrategy(botAI); }
    static Strategy* move_random(ShadowAI* botAI) { return new MoveRandomStrategy(botAI); }
    static Strategy* combat_formation(ShadowAI* botAI) { return new CombatFormationStrategy(botAI); }
    static Strategy* move_from_group(ShadowAI* botAI) { return new MoveFromGroupStrategy(botAI); }
    static Strategy* world_buff(ShadowAI* botAI) { return new WorldBuffStrategy(botAI); }
};

class MovementStrategyContext : public NamedObjectContext<Strategy>
{
public:
    MovementStrategyContext() : NamedObjectContext<Strategy>(false, true)
    {
        creators["follow"] = &MovementStrategyContext::follow_master;
        creators["stay"] = &MovementStrategyContext::stay;
        creators["runaway"] = &MovementStrategyContext::runaway;
        creators["flee from adds"] = &MovementStrategyContext::flee_from_adds;
        creators["guard"] = &MovementStrategyContext::guard;
    }

private:
    static Strategy* guard(ShadowAI* botAI) { return new GuardStrategy(botAI); }
    static Strategy* follow_master(ShadowAI* botAI) { return new FollowMasterStrategy(botAI); }
    static Strategy* stay(ShadowAI* botAI) { return new StayStrategy(botAI); }
    static Strategy* runaway(ShadowAI* botAI) { return new RunawayStrategy(botAI); }
    static Strategy* flee_from_adds(ShadowAI* botAI) { return new FleeFromAddsStrategy(botAI); }
};

class AssistStrategyContext : public NamedObjectContext<Strategy>
{
public:
    AssistStrategyContext() : NamedObjectContext<Strategy>(false, true)
    {
        creators["dps assist"] = &AssistStrategyContext::dps_assist;
        creators["dps aoe"] = &AssistStrategyContext::dps_aoe;
        creators["tank assist"] = &AssistStrategyContext::tank_assist;
    }

private:
    static Strategy* dps_assist(ShadowAI* botAI) { return new DpsAssistStrategy(botAI); }
    static Strategy* dps_aoe(ShadowAI* botAI) { return new DpsAoeStrategy(botAI); }
    static Strategy* tank_assist(ShadowAI* botAI) { return new TankAssistStrategy(botAI); }
};

class QuestStrategyContext : public NamedObjectContext<Strategy>
{
public:
    QuestStrategyContext() : NamedObjectContext<Strategy>(false, true)
    {
        creators["quest"] = &QuestStrategyContext::quest;
        creators["accept all quests"] = &QuestStrategyContext::accept_all_quests;
    }

private:
    static Strategy* quest(ShadowAI* botAI) { return new DefaultQuestStrategy(botAI); }
    static Strategy* accept_all_quests(ShadowAI* botAI) { return new AcceptAllQuestsStrategy(botAI); }
};

#endif
