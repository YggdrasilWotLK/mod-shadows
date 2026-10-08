/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_CHATACTIONCONTEXTACTION_H
#define _SHADOW_CHATACTIONCONTEXTACTION_H

#include "AddLootAction.h"
#include "AttackAction.h"
#include "BankAction.h"
#include "BuffAction.h"
#include "BuyAction.h"
#include "CastCustomSpellAction.h"
#include "ChangeChatAction.h"
#include "ChangeStrategyAction.h"
#include "ChangeTalentsAction.h"
#include "ChatShortcutActions.h"
#include "CheatAction.h"
#include "CustomStrategyEditAction.h"
#include "DebugAction.h"
#include "DestroyItemAction.h"
#include "DropQuestAction.h"
#include "EquipAction.h"
#include "FlagAction.h"
#include "Formations.h"
#include "GoAction.h"
#include "GossipHelloAction.h"
#include "GuildBankAction.h"
#include "GuildManagementActions.h"
#include "HelpAction.h"
#include "HireAction.h"
#include "InviteToGroupAction.h"
#include "LeaveGroupAction.h"
#include "ListQuestsActions.h"
#include "ListSpellsAction.h"
#include "LogLevelAction.h"
#include "LootStrategyAction.h"
#include "LootRollAction.h"
#include "MailAction.h"
#include "NamedObjectContext.h"
#include "NewRpgAction.h"
#include "PassLeadershipToMasterAction.h"
#include "PositionAction.h"
#include "QueryItemUsageAction.h"
#include "QueryQuestAction.h"
#include "RangeAction.h"
#include "ReleaseSpiritAction.h"
#include "RepairAllAction.h"
#include "ResetAiAction.h"
#include "ReviveFromCorpseAction.h"
#include "RewardAction.h"
#include "RtiAction.h"
#include "RtscAction.h"
#include "SaveManaAction.h"
#include "SellAction.h"
#include "SendMailAction.h"
#include "SetCraftAction.h"
#include "SetHomeAction.h"
#include "ShareQuestAction.h"
#include "SkipSpellsListAction.h"
#include "Stances.h"
#include "StatsAction.h"
#include "TaxiAction.h"
#include "TeleportAction.h"
#include "TellCastFailedAction.h"
#include "TellItemCountAction.h"
#include "TellLosAction.h"
#include "TellReputationAction.h"
#include "TellTargetAction.h"
#include "TradeAction.h"
#include "TrainerAction.h"
#include "UnequipAction.h"
#include "UseItemAction.h"
#include "UseMeetingStoneAction.h"
#include "WhoAction.h"
#include "WipeAction.h"
#include "WtsAction.h"
#include "OpenItemAction.h"
#include "UnlockItemAction.h"
#include "UnlockTradedItemAction.h"
#include "TameAction.h"
#include "TellGlyphsAction.h"
#include "EquipGlyphsAction.h"
#include "PetsAction.h"

class ChatActionContext : public NamedObjectContext<Action>
{
public:
    ChatActionContext()
    {
        creators["open items"] = &ChatActionContext::open_items;
        creators["unlock items"] = &ChatActionContext::unlock_items;
        creators["unlock traded item"] = &ChatActionContext::unlock_traded_item;
        creators["range"] = &ChatActionContext::range;
        creators["stats"] = &ChatActionContext::stats;
        creators["quests"] = &ChatActionContext::quests;
        //creators["leave"] = &ChatActionContext::leave;
        creators["reputation"] = &ChatActionContext::reputation;
        creators["log"] = &ChatActionContext::log;
        creators["los"] = &ChatActionContext::los;
        creators["rpg status"] = &ChatActionContext::rpg_status;
        creators["rpg do quest"] = &ChatActionContext::rpg_do_quest;
        creators["aura"] = &ChatActionContext::aura;
        creators["drop"] = &ChatActionContext::drop;
        creators["clean quest log"] = &ChatActionContext::clean_quest_log;
        creators["share"] = &ChatActionContext::share;
        creators["query quest"] = &ChatActionContext::query_quest;
        creators["query item usage"] = &ChatActionContext::query_item_usage;
        creators["ll"] = &ChatActionContext::ll;
        creators["ss"] = &ChatActionContext::ss;
        creators["add all loot"] = &ChatActionContext::add_all_loot;
        creators["release"] = &ChatActionContext::release;
        creators["repop"] = &ChatActionContext::repop;
        creators["teleport"] = &ChatActionContext::teleport;
        creators["taxi"] = &ChatActionContext::taxi;
        creators["repair"] = &ChatActionContext::repair;
        creators["use"] = &ChatActionContext::use;
        creators["item count"] = &ChatActionContext::item_count;
        creators["equip"] = &ChatActionContext::equip;
        creators["equip upgrades"] = &ChatActionContext::equip_upgrades;
        creators["unequip"] = &ChatActionContext::unequip;
        creators["sell"] = &ChatActionContext::sell;
        creators["buy"] = &ChatActionContext::buy;
        creators["reward"] = &ChatActionContext::reward;
        creators["trade"] = &ChatActionContext::trade;
        creators["talents"] = &ChatActionContext::talents;
        creators["spells"] = &ChatActionContext::spells;
        creators["co"] = &ChatActionContext::co;
        creators["nc"] = &ChatActionContext::nc;
        creators["de"] = &ChatActionContext::dead;
        creators["trainer"] = &ChatActionContext::trainer;
        creators["maintenance"] = &ChatActionContext::maintenance;
        creators["remove glyph"] = &ChatActionContext::remove_glyph;
        creators["autogear"] = &ChatActionContext::autogear;
        creators["equip upgrade"] = &ChatActionContext::equip_upgrade;
        creators["attack my target"] = &ChatActionContext::attack_my_target;
        creators["chat"] = &ChatActionContext::chat;
        creators["home"] = &ChatActionContext::home;
        creators["destroy"] = &ChatActionContext::destroy;
        creators["reset botAI"] = &ChatActionContext::reset_ai;
        creators["reset shadows"] = &ChatActionContext::reset_ai;
        creators["buff"] = &ChatActionContext::buff;
        creators["help"] = &ChatActionContext::help;
        creators["gb"] = &ChatActionContext::gb;
        creators["bank"] = &ChatActionContext::bank;
        creators["follow chat shortcut"] = &ChatActionContext::follow_chat_shortcut;
        creators["stay chat shortcut"] = &ChatActionContext::stay_chat_shortcut;
        creators["flee chat shortcut"] = &ChatActionContext::flee_chat_shortcut;
        creators["runaway chat shortcut"] = &ChatActionContext::runaway_chat_shortcut;
        creators["move from group chat shortcut"] = &ChatActionContext::move_from_group_chat_shortcut;
        creators["grind chat shortcut"] = &ChatActionContext::grind_chat_shortcut;
        creators["tank attack chat shortcut"] = &ChatActionContext::tank_attack_chat_shortcut;
        creators["gossip hello"] = &ChatActionContext::gossip_hello;
        creators["cast custom spell"] = &ChatActionContext::cast_custom_spell;
        creators["cast custom nc spell"] = &ChatActionContext::cast_custom_nc_spell;
        creators["invite"] = &ChatActionContext::invite;
        creators["spell"] = &ChatActionContext::spell;
        creators["rti"] = &ChatActionContext::rti;
        creators["spirit healer"] = &ChatActionContext::spirit_healer;
        creators["position"] = &ChatActionContext::position;
        creators["tell target"] = &ChatActionContext::tell_target;
        creators["summon"] = &ChatActionContext::summon;
        creators["who"] = &ChatActionContext::who;
        creators["save mana"] = &ChatActionContext::save_mana;
        creators["max dps chat shortcut"] = &ChatActionContext::max_dps_chat_shortcut;
        creators["tell attackers"] = &ChatActionContext::tell_attackers;
        creators["tell target"] = &ChatActionContext::tell_target;
        creators["formation"] = &ChatActionContext::formation;
        creators["stance"] = &ChatActionContext::stance;
        creators["sendmail"] = &ChatActionContext::sendmail;
        creators["mail"] = &ChatActionContext::mail;
        creators["go"] = &ChatActionContext::go;
        creators["debug"] = &ChatActionContext::debug;
        creators["cdebug"] = &ChatActionContext::debug;
        creators["cs"] = &ChatActionContext::cs;
        creators["wts"] = &ChatActionContext::wts;
        creators["hire"] = &ChatActionContext::hire;
        creators["craft"] = &ChatActionContext::craft;
        creators["flag"] = &ChatActionContext::flag;
        creators["give leader"] = &ChatActionContext::give_leader;
        creators["cheat"] = &ChatActionContext::cheat;
        creators["ginvite"] = &ChatActionContext::ginvite;
        creators["guild promote"] = &ChatActionContext::guild_promote;
        creators["guild demote"] = &ChatActionContext::guild_demote;
        creators["guild remove"] = &ChatActionContext::guild_remove;
        creators["guild leave"] = &ChatActionContext::guild_leave;
        creators["rtsc"] = &ChatActionContext::rtsc;
        creators["naxx chat shortcut"] = &ChatActionContext::naxx_chat_shortcut;
        creators["bwl chat shortcut"] = &ChatActionContext::bwl_chat_shortcut;
        creators["tell estimated dps"] = &ChatActionContext::tell_estimated_dps;
        creators["join"] = &ChatActionContext::join;
        creators["lfg"] = &ChatActionContext::lfg;
        creators["calc"] = &ChatActionContext::calc;
        creators["wipe"] = &ChatActionContext::wipe;
        creators["tame"] = &ChatActionContext::tame;
        creators["glyphs"] = &ChatActionContext::glyphs; // Added for custom Glyphs
        creators["glyph equip"] = &ChatActionContext::glyph_equip; // Added for custom Glyphs
        creators["pet"] = &ChatActionContext::pet;
        creators["pet attack"] = &ChatActionContext::pet_attack;
        creators["roll"] = &ChatActionContext::roll_action;
    }

private:
    static Action* open_items(ShadowAI* botAI) { return new OpenItemAction(botAI); }
    static Action* unlock_items(ShadowAI* botAI) { return new UnlockItemAction(botAI); }
    static Action* unlock_traded_item(ShadowAI* botAI) { return new UnlockTradedItemAction(botAI); }
    static Action* range(ShadowAI* botAI) { return new RangeAction(botAI); }
    static Action* flag(ShadowAI* botAI) { return new FlagAction(botAI); }
    static Action* craft(ShadowAI* botAI) { return new SetCraftAction(botAI); }
    static Action* hire(ShadowAI* botAI) { return new HireAction(botAI); }
    static Action* wts(ShadowAI* botAI) { return new WtsAction(botAI); }
    static Action* cs(ShadowAI* botAI) { return new CustomStrategyEditAction(botAI); }
    static Action* debug(ShadowAI* botAI) { return new DebugAction(botAI); }
    static Action* mail(ShadowAI* botAI) { return new MailAction(botAI); }
    static Action* go(ShadowAI* botAI) { return new GoAction(botAI); }
    static Action* sendmail(ShadowAI* botAI) { return new SendMailAction(botAI); }
    static Action* formation(ShadowAI* botAI) { return new SetFormationAction(botAI); }
    static Action* stance(ShadowAI* botAI) { return new SetStanceAction(botAI); }
    static Action* tell_attackers(ShadowAI* botAI) { return new TellAttackersAction(botAI); }
    static Action* max_dps_chat_shortcut(ShadowAI* botAI) { return new MaxDpsChatShortcutAction(botAI); }
    static Action* save_mana(ShadowAI* botAI) { return new SaveManaAction(botAI); }
    static Action* who(ShadowAI* botAI) { return new WhoAction(botAI); }
    static Action* summon(ShadowAI* botAI) { return new SummonAction(botAI); }
    static Action* tell_target(ShadowAI* botAI) { return new TellTargetAction(botAI); }
    static Action* position(ShadowAI* botAI) { return new PositionAction(botAI); }
    static Action* spirit_healer(ShadowAI* botAI) { return new SpiritHealerAction(botAI); }
    static Action* rti(ShadowAI* botAI) { return new RtiAction(botAI); }
    static Action* invite(ShadowAI* botAI) { return new InviteToGroupAction(botAI); }
    static Action* lfg(ShadowAI* botAI) { return new LfgAction(botAI); }
    static Action* spell(ShadowAI* botAI) { return new TellSpellAction(botAI); }
    static Action* cast_custom_spell(ShadowAI* botAI) { return new CastCustomSpellAction(botAI); }
    static Action* cast_custom_nc_spell(ShadowAI* botAI) { return new CastCustomNcSpellAction(botAI); }
    static Action* tank_attack_chat_shortcut(ShadowAI* botAI) { return new TankAttackChatShortcutAction(botAI); }
    static Action* grind_chat_shortcut(ShadowAI* botAI) { return new GrindChatShortcutAction(botAI); }
    static Action* flee_chat_shortcut(ShadowAI* botAI) { return new FleeChatShortcutAction(botAI); }
    static Action* runaway_chat_shortcut(ShadowAI* botAI) { return new GoawayChatShortcutAction(botAI); }
    static Action* stay_chat_shortcut(ShadowAI* botAI) { return new StayChatShortcutAction(botAI); }
    static Action* follow_chat_shortcut(ShadowAI* botAI) { return new FollowChatShortcutAction(botAI); }
    static Action* move_from_group_chat_shortcut(ShadowAI* botAI) { return new MoveFromGroupChatShortcutAction(botAI); }
    static Action* gb(ShadowAI* botAI) { return new GuildBankAction(botAI); }
    static Action* bank(ShadowAI* botAI) { return new BankAction(botAI); }
    static Action* help(ShadowAI* botAI) { return new HelpAction(botAI); }
    static Action* buff(ShadowAI* botAI) { return new BuffAction(botAI); }
    static Action* destroy(ShadowAI* botAI) { return new DestroyItemAction(botAI); }
    static Action* home(ShadowAI* botAI) { return new SetHomeAction(botAI); }
    static Action* chat(ShadowAI* botAI) { return new ChangeChatAction(botAI); }
    static Action* attack_my_target(ShadowAI* botAI) { return new AttackMyTargetAction(botAI); }
    static Action* trainer(ShadowAI* botAI) { return new TrainerAction(botAI); }
    static Action* maintenance(ShadowAI* botAI) { return new MaintenanceAction(botAI); }
    static Action* remove_glyph(ShadowAI* botAI) { return new RemoveGlyphAction(botAI); }
    static Action* autogear(ShadowAI* botAI) { return new AutoGearAction(botAI); }
    static Action* equip_upgrade(ShadowAI* botAI) { return new EquipUpgradeAction(botAI); }
    static Action* co(ShadowAI* botAI) { return new ChangeCombatStrategyAction(botAI); }
    static Action* nc(ShadowAI* botAI) { return new ChangeNonCombatStrategyAction(botAI); }
    static Action* dead(ShadowAI* botAI) { return new ChangeDeadStrategyAction(botAI); }
    static Action* spells(ShadowAI* botAI) { return new ListSpellsAction(botAI); }
    static Action* talents(ShadowAI* botAI) { return new ChangeTalentsAction(botAI); }

    static Action* equip(ShadowAI* botAI) { return new EquipAction(botAI); }
    static Action* equip_upgrades(ShadowAI* botAI) { return new EquipUpgradesAction(botAI); }
    static Action* unequip(ShadowAI* botAI) { return new UnequipAction(botAI); }
    static Action* sell(ShadowAI* botAI) { return new SellAction(botAI); }
    static Action* buy(ShadowAI* botAI) { return new BuyAction(botAI); }
    static Action* reward(ShadowAI* botAI) { return new RewardAction(botAI); }
    static Action* trade(ShadowAI* botAI) { return new TradeAction(botAI); }

    static Action* item_count(ShadowAI* botAI) { return new TellItemCountAction(botAI); }
    static Action* use(ShadowAI* botAI) { return new UseItemAction(botAI); }
    static Action* repair(ShadowAI* botAI) { return new RepairAllAction(botAI); }
    static Action* taxi(ShadowAI* botAI) { return new TaxiAction(botAI); }
    static Action* teleport(ShadowAI* botAI) { return new TeleportAction(botAI); }
    static Action* release(ShadowAI* botAI) { return new ReleaseSpiritAction(botAI); }
    static Action* repop(ShadowAI* botAI) { return new RepopAction(botAI); }
    static Action* query_item_usage(ShadowAI* botAI) { return new QueryItemUsageAction(botAI); }
    static Action* query_quest(ShadowAI* botAI) { return new QueryQuestAction(botAI); }
    static Action* drop(ShadowAI* botAI) { return new DropQuestAction(botAI); }
    static Action* clean_quest_log(ShadowAI* botAI) { return new CleanQuestLogAction(botAI); }
    static Action* share(ShadowAI* botAI) { return new ShareQuestAction(botAI); }
    static Action* stats(ShadowAI* botAI) { return new StatsAction(botAI); }
    static Action* quests(ShadowAI* botAI) { return new ListQuestsAction(botAI); }
    static Action* leave(ShadowAI* botAI) { return new LeaveGroupAction(botAI); }
    static Action* reputation(ShadowAI* botAI) { return new TellReputationAction(botAI); }
    static Action* log(ShadowAI* botAI) { return new LogLevelAction(botAI); }
    static Action* los(ShadowAI* botAI) { return new TellLosAction(botAI); }
    static Action* rpg_status(ShadowAI* botAI) { return new TellRpgStatusAction(botAI); }
    static Action* rpg_do_quest(ShadowAI* botAI) { return new StartRpgDoQuestAction(botAI); }
    static Action* aura(ShadowAI* ai) { return new TellAuraAction(ai); }
    static Action* ll(ShadowAI* botAI) { return new LootStrategyAction(botAI); }
    static Action* ss(ShadowAI* botAI) { return new SkipSpellsListAction(botAI); }
    static Action* add_all_loot(ShadowAI* botAI) { return new AddAllLootAction(botAI); }
    static Action* reset_ai(ShadowAI* botAI) { return new ResetAiAction(botAI); }
    static Action* gossip_hello(ShadowAI* botAI) { return new GossipHelloAction(botAI); }
    static Action* give_leader(ShadowAI* botAI) { return new GiveLeaderAction(botAI); }
    static Action* cheat(ShadowAI* botAI) { return new CheatAction(botAI); }
    static Action* ginvite(ShadowAI* botAI) { return new GuildInviteAction(botAI); }
    static Action* guild_promote(ShadowAI* botAI) { return new GuildPromoteAction(botAI); }
    static Action* guild_demote(ShadowAI* botAI) { return new GuildDemoteAction(botAI); }
    static Action* guild_remove(ShadowAI* botAI) { return new GuildRemoveAction(botAI); }
    static Action* guild_leave(ShadowAI* botAI) { return new GuildLeaveAction(botAI); }
    static Action* rtsc(ShadowAI* botAI) { return new RTSCAction(botAI); }
    static Action* naxx_chat_shortcut(ShadowAI* ai) { return new NaxxChatShortcutAction(ai); }
    static Action* bwl_chat_shortcut(ShadowAI* ai) { return new BwlChatShortcutAction(ai); }
    static Action* tell_estimated_dps(ShadowAI* ai) { return new TellEstimatedDpsAction(ai); }
    static Action* join(ShadowAI* ai) { return new JoinGroupAction(ai); }
    static Action* calc(ShadowAI* ai) { return new TellCalculateItemAction(ai); }
    static Action* wipe(ShadowAI* ai) { return new WipeAction(ai); }
    static Action* tame(ShadowAI* botAI) { return new TameAction(botAI); }
    static Action* glyphs(ShadowAI* botAI) { return new TellGlyphsAction(botAI); } // Added for custom Glyphs
    static Action* glyph_equip(ShadowAI* ai) { return new EquipGlyphsAction(ai); } // Added for custom Glyphs
    static Action* pet(ShadowAI* botAI) { return new PetsAction(botAI); }
    static Action* pet_attack(ShadowAI* botAI) { return new PetsAction(botAI, "attack"); }
    static Action* roll_action(ShadowAI* botAI) { return new RollAction(botAI); }
};

#endif
