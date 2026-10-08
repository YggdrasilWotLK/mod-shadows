// /*
//  * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
//  and/or modify it under version 2 of the License, or (at your option), any later version.
//  */

#ifndef _SHADOW_RAIDNAXXACTIONCONTEXT_H
#define _SHADOW_RAIDNAXXACTIONCONTEXT_H

#include "Action.h"
#include "NamedObjectContext.h"
#include "RaidNaxxActions.h"

class RaidNaxxActionContext : public NamedObjectContext<Action>
{
public:
    RaidNaxxActionContext()
    {
        creators["grobbulus go behind the boss"] = &RaidNaxxActionContext::go_behind_the_boss;
        creators["rotate grobbulus"] = &RaidNaxxActionContext::rotate_grobbulus;
        creators["grobbulus move center"] = &RaidNaxxActionContext::grobbulus_move_center;

        creators["heigan dance melee"] = &RaidNaxxActionContext::heigan_dance_melee;
        creators["heigan dance ranged"] = &RaidNaxxActionContext::heigan_dance_ranged;
        creators["thaddius attack nearest pet"] = &RaidNaxxActionContext::thaddius_attack_nearest_pet;
        // creators["thaddius melee to place"] = &RaidNaxxActionContext::thaddius_tank_to_place;
        // creators["thaddius ranged to place"] = &RaidNaxxActionContext::thaddius_ranged_to_place;
        creators["thaddius move to platform"] = &RaidNaxxActionContext::thaddius_move_to_platform;
        creators["thaddius move polarity"] = &RaidNaxxActionContext::thaddius_move_polarity;

        creators["razuvious use obedience crystal"] = &RaidNaxxActionContext::razuvious_use_obedience_crystal;
        creators["razuvious target"] = &RaidNaxxActionContext::razuvious_target;

        creators["horseman attract alternatively"] = &RaidNaxxActionContext::horseman_attract_alternatively;
        creators["horseman attack in order"] = &RaidNaxxActionContext::horseman_attack_in_order;

        creators["sapphiron ground position"] = &RaidNaxxActionContext::sapphiron_ground_position;
        creators["sapphiron flight position"] = &RaidNaxxActionContext::sapphiron_flight_position;

        creators["kel'thuzad choose target"] = &RaidNaxxActionContext::kelthuzad_choose_target;
        creators["kel'thuzad position"] = &RaidNaxxActionContext::kelthuzad_position;

        creators["anub'rekhan choose target"] = &RaidNaxxActionContext::anubrekhan_choose_target;
        creators["anub'rekhan position"] = &RaidNaxxActionContext::anubrekhan_position;

        creators["gluth choose target"] = &RaidNaxxActionContext::gluth_choose_target;
        creators["gluth position"] = &RaidNaxxActionContext::gluth_position;
        creators["gluth slowdown"] = &RaidNaxxActionContext::gluth_slowdown;

        creators["loatheb position"] = &RaidNaxxActionContext::loatheb_position;
        creators["loatheb choose target"] = &RaidNaxxActionContext::loatheb_choose_target;
    }

private:
    static Action* go_behind_the_boss(ShadowAI* ai) { return new GrobbulusGoBehindAction(ai); }
    static Action* rotate_grobbulus(ShadowAI* ai) { return new GrobbulusRotateAction(ai); }
    static Action* grobbulus_move_center(ShadowAI* ai) { return new GrobblulusMoveCenterAction(ai); }
    static Action* heigan_dance_melee(ShadowAI* ai) { return new HeiganDanceMeleeAction(ai); }
    static Action* heigan_dance_ranged(ShadowAI* ai) { return new HeiganDanceRangedAction(ai); }
    static Action* thaddius_attack_nearest_pet(ShadowAI* ai) { return new ThaddiusAttackNearestPetAction(ai); }
    // static Action* thaddius_tank_to_place(ShadowAI* ai) { return new ThaddiusMeleeToPlaceAction(ai); }
    // static Action* thaddius_ranged_to_place(ShadowAI* ai) { return new ThaddiusRangedToPlaceAction(ai); }
    static Action* thaddius_move_to_platform(ShadowAI* ai) { return new ThaddiusMoveToPlatformAction(ai); }
    static Action* thaddius_move_polarity(ShadowAI* ai) { return new ThaddiusMovePolarityAction(ai); }
    static Action* razuvious_target(ShadowAI* ai) { return new RazuviousTargetAction(ai); }
    static Action* razuvious_use_obedience_crystal(ShadowAI* ai)
    {
        return new RazuviousUseObedienceCrystalAction(ai);
    }
    static Action* horseman_attract_alternatively(ShadowAI* ai)
    {
        return new HorsemanAttractAlternativelyAction(ai);
    }
    static Action* horseman_attack_in_order(ShadowAI* ai) { return new HorsemanAttactInOrderAction(ai); }
    // static Action* sapphiron_ground_main_tank_position(ShadowAI* ai) { return new
    // SapphironGroundMainTankPositionAction(ai); }
    static Action* sapphiron_ground_position(ShadowAI* ai) { return new SapphironGroundPositionAction(ai); }
    static Action* sapphiron_flight_position(ShadowAI* ai) { return new SapphironFlightPositionAction(ai); }
    // static Action* sapphiron_avoid_chill(ShadowAI* ai) { return new SapphironAvoidChillAction(ai); }
    static Action* kelthuzad_choose_target(ShadowAI* ai) { return new KelthuzadChooseTargetAction(ai); }
    static Action* kelthuzad_position(ShadowAI* ai) { return new KelthuzadPositionAction(ai); }
    static Action* anubrekhan_choose_target(ShadowAI* ai) { return new AnubrekhanChooseTargetAction(ai); }
    static Action* anubrekhan_position(ShadowAI* ai) { return new AnubrekhanPositionAction(ai); }
    static Action* gluth_choose_target(ShadowAI* ai) { return new GluthChooseTargetAction(ai); }
    static Action* gluth_position(ShadowAI* ai) { return new GluthPositionAction(ai); }
    static Action* gluth_slowdown(ShadowAI* ai) { return new GluthSlowdownAction(ai); }
    static Action* loatheb_position(ShadowAI* ai) { return new LoathebPositionAction(ai); }
    static Action* loatheb_choose_target(ShadowAI* ai) { return new LoathebChooseTargetAction(ai); }
};

#endif