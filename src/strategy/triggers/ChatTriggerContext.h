/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_CHATTRIGGERCONTEXT_H
#define _SHADOW_CHATTRIGGERCONTEXT_H

#include "ChatCommandTrigger.h"
#include "NamedObjectContext.h"

class ShadowAI;

class ChatTriggerContext : public NamedObjectContext<Trigger>
{
public:
    ChatTriggerContext()
    {
        creators["open items"] = &ChatTriggerContext::open_items;
        creators["unlock items"] = &ChatTriggerContext::unlock_items;
        creators["unlock traded item"] = &ChatTriggerContext::unlock_traded_item;
        creators["quests"] = &ChatTriggerContext::quests;
        creators["stats"] = &ChatTriggerContext::stats;
        creators["leave"] = &ChatTriggerContext::leave;
        creators["rep"] = &ChatTriggerContext::reputation;
        creators["reputation"] = &ChatTriggerContext::reputation;
        creators["log"] = &ChatTriggerContext::log;
        creators["los"] = &ChatTriggerContext::los;
        creators["rpg status"] = &ChatTriggerContext::rpg_status;
        creators["rpg do quest"] = &ChatTriggerContext::rpg_do_quest;
        creators["aura"] = &ChatTriggerContext::aura;
        creators["drop"] = &ChatTriggerContext::drop;
        creators["share"] = &ChatTriggerContext::share;
        creators["q"] = &ChatTriggerContext::q;
        creators["ll"] = &ChatTriggerContext::ll;
        creators["ss"] = &ChatTriggerContext::ss;
        creators["loot all"] = &ChatTriggerContext::loot_all;
        creators["add all loot"] = &ChatTriggerContext::loot_all;
        creators["release"] = &ChatTriggerContext::release;
        creators["teleport"] = &ChatTriggerContext::teleport;
        creators["taxi"] = &ChatTriggerContext::taxi;
        creators["repair"] = &ChatTriggerContext::repair;
        creators["u"] = &ChatTriggerContext::use;
        creators["use"] = &ChatTriggerContext::use;
        creators["c"] = &ChatTriggerContext::item_count;
        creators["items"] = &ChatTriggerContext::item_count;
        creators["inventory"] = &ChatTriggerContext::item_count;
        creators["inv"] = &ChatTriggerContext::item_count;
        creators["e"] = &ChatTriggerContext::equip;
        creators["equip"] = &ChatTriggerContext::equip;
        creators["ue"] = &ChatTriggerContext::uneqip;
        creators["s"] = &ChatTriggerContext::sell;
        creators["b"] = &ChatTriggerContext::buy;
        creators["r"] = &ChatTriggerContext::reward;
        creators["t"] = &ChatTriggerContext::trade;
        creators["nt"] = &ChatTriggerContext::nontrade;
        creators["talents"] = &ChatTriggerContext::talents;
        creators["spells"] = &ChatTriggerContext::spells;
        creators["co"] = &ChatTriggerContext::co;
        creators["nc"] = &ChatTriggerContext::nc;
        creators["de"] = &ChatTriggerContext::dead;
        creators["trainer"] = &ChatTriggerContext::trainer;
        creators["maintenance"] = &ChatTriggerContext::maintenance;
        creators["remove glyph"] = &ChatTriggerContext::remove_glyph;
        creators["autogear"] = &ChatTriggerContext::autogear;
        creators["equip upgrade"] = &ChatTriggerContext::equip_upgrade;
        creators["attack"] = &ChatTriggerContext::attack;
        creators["chat"] = &ChatTriggerContext::chat;
        creators["accept"] = &ChatTriggerContext::accept;
        creators["home"] = &ChatTriggerContext::home;
        creators["reset botAI"] = &ChatTriggerContext::reset_ai;
        creators["destroy"] = &ChatTriggerContext::destroy;
        creators["emote"] = &ChatTriggerContext::emote;
        creators["buff"] = &ChatTriggerContext::buff;
        creators["help"] = &ChatTriggerContext::help;
        creators["gb"] = &ChatTriggerContext::gb;
        creators["gbank"] = &ChatTriggerContext::gb;
        creators["bank"] = &ChatTriggerContext::bank;
        creators["follow"] = &ChatTriggerContext::follow;
        creators["move from group"] = &ChatTriggerContext::move_from_group;
        creators["stay"] = &ChatTriggerContext::stay;
        creators["flee"] = &ChatTriggerContext::flee;
        creators["grind"] = &ChatTriggerContext::grind;
        creators["tank attack"] = &ChatTriggerContext::tank_attack;
        creators["talk"] = &ChatTriggerContext::talk;
        creators["enter vehicle"] = &ChatTriggerContext::enter_vehicle;
        creators["leave vehicle"] = &ChatTriggerContext::leave_vehicle;
        creators["cast"] = &ChatTriggerContext::cast;
        creators["castnc"] = &ChatTriggerContext::castnc;
        creators["invite"] = &ChatTriggerContext::invite;
        creators["lfg"] = &ChatTriggerContext::lfg;
        creators["spell"] = &ChatTriggerContext::spell;
        creators["rti"] = &ChatTriggerContext::rti;
        creators["revive"] = &ChatTriggerContext::revive;
        creators["runaway"] = &ChatTriggerContext::runaway;
        creators["warning"] = &ChatTriggerContext::warning;
        creators["position"] = &ChatTriggerContext::position;
        creators["summon"] = &ChatTriggerContext::summon;
        creators["who"] = &ChatTriggerContext::who;
        creators["save mana"] = &ChatTriggerContext::save_mana;
        creators["max dps"] = &ChatTriggerContext::max_dps;
        creators["attackers"] = &ChatTriggerContext::attackers;
        creators["target"] = &ChatTriggerContext::target;
        creators["formation"] = &ChatTriggerContext::formation;
        creators["stance"] = &ChatTriggerContext::stance;
        creators["sendmail"] = &ChatTriggerContext::sendmail;
        creators["mail"] = &ChatTriggerContext::mail;
        creators["outfit"] = &ChatTriggerContext::outfit;
        creators["go"] = &ChatTriggerContext::go;
        creators["ready"] = &ChatTriggerContext::ready_check;
        creators["debug"] = &ChatTriggerContext::debug;
        creators["cdebug"] = &ChatTriggerContext::cdebug;
        creators["cs"] = &ChatTriggerContext::cs;
        creators["wts"] = &ChatTriggerContext::wts;
        // creators["hire"] = &ChatTriggerContext::hire;  // Not correctly implemented at this time, would cause crash and other issues.
        creators["craft"] = &ChatTriggerContext::craft;
        creators["flag"] = &ChatTriggerContext::craft;
        creators["range"] = &ChatTriggerContext::range;
        creators["ra"] = &ChatTriggerContext::ra;
        creators["give leader"] = &ChatTriggerContext::give_leader;
        creators["cheat"] = &ChatTriggerContext::cheat;
        creators["ginvite"] = &ChatTriggerContext::ginvite;
        creators["guild promote"] = &ChatTriggerContext::guild_promote;
        creators["guild demote"] = &ChatTriggerContext::guild_demote;
        creators["guild remove"] = &ChatTriggerContext::guild_remove;
        creators["guild leave"] = &ChatTriggerContext::guild_leave;
        creators["rtsc"] = &ChatTriggerContext::rtsc;
        creators["drink"] = &ChatTriggerContext::drink;
        // creators["naxx"] = &ChatTriggerContext::naxx;
        // creators["bwl"] = &ChatTriggerContext::bwl;
        creators["dps"] = &ChatTriggerContext::dps;
        creators["disperse"] = &ChatTriggerContext::disperse;
        creators["calc"] = &ChatTriggerContext::calc;
        creators["qi"] = &ChatTriggerContext::qi;
        creators["wipe"] = &ChatTriggerContext::wipe;
        creators["tame"] = &ChatTriggerContext::tame;
        creators["glyphs"] = &ChatTriggerContext::glyphs; // Added for custom Glyphs
        creators["glyph equip"] = &ChatTriggerContext::glyph_equip; // Added for custom Glyphs
        creators["pet"] = &ChatTriggerContext::pet;
        creators["pet attack"] = &ChatTriggerContext::pet_attack;
        creators["roll"] = &ChatTriggerContext::roll_action;
    }

private:
    static Trigger* open_items(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "open items"); }
    static Trigger* unlock_items(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "unlock items"); }
    static Trigger* unlock_traded_item(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "unlock traded item"); }
    static Trigger* ra(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "ra"); }
    static Trigger* range(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "range"); }
    static Trigger* flag(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "flag"); }
    static Trigger* craft(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "craft"); }
    static Trigger* hire(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "hire"); }
    static Trigger* wts(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "wts"); }
    static Trigger* cs(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "cs"); }
    static Trigger* debug(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "debug"); }
    static Trigger* cdebug(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "cdebug"); }
    static Trigger* go(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "go"); }
    static Trigger* outfit(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "outfit"); }
    static Trigger* mail(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "mail"); }
    static Trigger* sendmail(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "sendmail"); }
    static Trigger* formation(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "formation"); }
    static Trigger* stance(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "stance"); }
    static Trigger* attackers(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "attackers"); }
    static Trigger* target(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "target"); }
    static Trigger* max_dps(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "max dps"); }
    static Trigger* save_mana(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "save mana"); }
    static Trigger* who(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "who"); }
    static Trigger* summon(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "summon"); }
    static Trigger* position(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "position"); }
    static Trigger* runaway(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "runaway"); }
    static Trigger* warning(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "warning"); }
    static Trigger* revive(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "revive"); }
    static Trigger* rti(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "rti"); }
    static Trigger* invite(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "invite"); }
    static Trigger* lfg(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "lfg"); }
    static Trigger* cast(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "cast"); }
    static Trigger* castnc(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "castnc"); }
    static Trigger* talk(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "talk"); }
    static Trigger* enter_vehicle(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "enter vehicle"); }
    static Trigger* leave_vehicle(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "leave vehicle"); }
    static Trigger* flee(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "flee"); }
    static Trigger* grind(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "grind"); }
    static Trigger* tank_attack(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "tank attack"); }
    static Trigger* stay(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "stay"); }
    static Trigger* follow(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "follow"); }
    static Trigger* move_from_group(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "move from group"); }
    static Trigger* gb(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "gb"); }
    static Trigger* bank(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "bank"); }
    static Trigger* help(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "help"); }
    static Trigger* buff(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "buff"); }
    static Trigger* emote(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "emote"); }
    static Trigger* destroy(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "destroy"); }
    static Trigger* home(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "home"); }
    static Trigger* accept(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "accept"); }
    static Trigger* chat(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "chat"); }
    static Trigger* attack(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "attack"); }
    static Trigger* trainer(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "trainer"); }
    static Trigger* maintenance(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "maintenance"); }
    static Trigger* remove_glyph(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "remove glyph"); }
    static Trigger* autogear(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "autogear"); }
    static Trigger* equip_upgrade(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "equip upgrade"); }
    static Trigger* co(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "co"); }
    static Trigger* nc(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "nc"); }
    static Trigger* dead(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "de"); }
    static Trigger* spells(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "spells"); }
    static Trigger* talents(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "talents"); }
    static Trigger* equip(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "e"); }
    static Trigger* uneqip(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "ue"); }
    static Trigger* sell(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "s"); }
    static Trigger* buy(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "b"); }
    static Trigger* reward(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "r"); }
    static Trigger* trade(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "t"); }
    static Trigger* nontrade(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "nt"); }
    static Trigger* item_count(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "c"); }
    static Trigger* use(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "use"); }
    static Trigger* repair(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "repair"); }
    static Trigger* taxi(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "taxi"); }
    static Trigger* teleport(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "teleport"); }
    static Trigger* q(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "q"); }
    static Trigger* ll(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "ll"); }
    static Trigger* ss(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "ss"); }
    static Trigger* drop(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "drop"); }
    static Trigger* share(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "share"); }
    static Trigger* quests(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "quests"); }
    static Trigger* stats(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "stats"); }
    static Trigger* leave(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "leave"); }
    static Trigger* reputation(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "reputation"); }
    static Trigger* log(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "log"); }
    static Trigger* los(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "los"); }
    static Trigger* rpg_status(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "rpg status"); }
    static Trigger* rpg_do_quest(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "rpg do quest"); }
    static Trigger* aura(ShadowAI* ai) { return new ChatCommandTrigger(ai, "aura"); }
    static Trigger* loot_all(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "add all loot"); }
    static Trigger* release(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "release"); }
    static Trigger* reset_ai(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "reset botAI"); }
    static Trigger* spell(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "spell"); }
    static Trigger* ready_check(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "ready check"); }
    static Trigger* give_leader(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "give leader"); }
    static Trigger* cheat(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "cheat"); }
    static Trigger* ginvite(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "ginvite"); }
    static Trigger* guild_promote(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "guild promote"); }
    static Trigger* guild_demote(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "guild demote"); }
    static Trigger* guild_remove(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "guild remove"); }
    static Trigger* guild_leave(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "guild leave"); }
    static Trigger* rtsc(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "rtsc"); }
    static Trigger* drink(ShadowAI* ai) { return new ChatCommandTrigger(ai, "drink"); }
    // static Trigger* naxx(ShadowAI* ai) { return new ChatCommandTrigger(ai, "naxx"); }
    // static Trigger* bwl(ShadowAI* ai) { return new ChatCommandTrigger(ai, "bwl"); }
    static Trigger* dps(ShadowAI* ai) { return new ChatCommandTrigger(ai, "dps"); }
    static Trigger* disperse(ShadowAI* ai) { return new ChatCommandTrigger(ai, "disperse"); }
    static Trigger* calc(ShadowAI* ai) { return new ChatCommandTrigger(ai, "calc"); }
    static Trigger* qi(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "qi"); }
    static Trigger* wipe(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "wipe"); }
    static Trigger* tame(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "tame"); }
    static Trigger* glyphs(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "glyphs"); } // Added for custom Glyphs
    static Trigger* glyph_equip(ShadowAI* ai) { return new ChatCommandTrigger(ai, "glyph equip"); } // Added for custom Glyphs
    static Trigger* pet(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "pet"); }
    static Trigger* pet_attack(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "pet attack"); }
    static Trigger* roll_action(ShadowAI* botAI) { return new ChatCommandTrigger(botAI, "roll"); }
};

#endif
