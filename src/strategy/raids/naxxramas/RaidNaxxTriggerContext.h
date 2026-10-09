// /*
//  * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
//  and/or modify it under version 2 of the License, or (at your option), any later version.
//  */

#ifndef _SHADOW_RAIDNAXXTRIGGERCONTEXT_H
#define _SHADOW_RAIDNAXXTRIGGERCONTEXT_H

#include "AiObjectContext.h"
#include "NamedObjectContext.h"
#include "RaidNaxxTriggers.h"

class RaidNaxxTriggerContext : public NamedObjectContext<Trigger>
{
public:
    RaidNaxxTriggerContext()
    {
        creators["mutating injection"] = &RaidNaxxTriggerContext::mutating_injection;
        creators["mutating injection removed"] = &RaidNaxxTriggerContext::mutating_injection_removed;
        creators["grobbulus cloud"] = &RaidNaxxTriggerContext::grobbulus_cloud;
        creators["heigan melee"] = &RaidNaxxTriggerContext::heigan_melee;
        creators["heigan ranged"] = &RaidNaxxTriggerContext::heigan_ranged;

        creators["thaddius phase pet"] = &RaidNaxxTriggerContext::thaddius_phase_pet;
        creators["thaddius phase pet lose aggro"] = &RaidNaxxTriggerContext::thaddius_phase_pet_lose_aggro;
        creators["thaddius phase transition"] = &RaidNaxxTriggerContext::thaddius_phase_transition;
        creators["thaddius phase thaddius"] = &RaidNaxxTriggerContext::thaddius_phase_thaddius;

        creators["razuvious tank"] = &RaidNaxxTriggerContext::razuvious_tank;
        creators["razuvious nontank"] = &RaidNaxxTriggerContext::razuvious_nontank;

        creators["horseman attractors"] = &RaidNaxxTriggerContext::horseman_attractors;
        creators["horseman except attractors"] = &RaidNaxxTriggerContext::horseman_except_attractors;

        creators["sapphiron ground"] = &RaidNaxxTriggerContext::sapphiron_ground;
        creators["sapphiron flight"] = &RaidNaxxTriggerContext::sapphiron_flight;

        creators["kel'thuzad"] = &RaidNaxxTriggerContext::kelthuzad;

        creators["anub'rekhan"] = &RaidNaxxTriggerContext::anubrekhan;

        creators["gluth"] = &RaidNaxxTriggerContext::gluth;
        creators["gluth main tank mortal wound"] = &RaidNaxxTriggerContext::gluth_main_tank_mortal_wound;

        creators["loatheb"] = &RaidNaxxTriggerContext::loatheb;
    }

private:
    static Trigger* mutating_injection(ShadowAI* ai) { return new MutatingInjectionTrigger(ai); }
    static Trigger* mutating_injection_removed(ShadowAI* ai) { return new MutatingInjectionRemovedTrigger(ai); }
    static Trigger* grobbulus_cloud(ShadowAI* ai) { return new GrobbulusCloudTrigger(ai); }
    static Trigger* heigan_melee(ShadowAI* ai) { return new HeiganMeleeTrigger(ai); }
    static Trigger* heigan_ranged(ShadowAI* ai) { return new HeiganRangedTrigger(ai); }

    static Trigger* thaddius_phase_pet(ShadowAI* ai) { return new ThaddiusPhasePetTrigger(ai); }
    static Trigger* thaddius_phase_pet_lose_aggro(ShadowAI* ai) { return new ThaddiusPhasePetLoseAggroTrigger(ai); }
    static Trigger* thaddius_phase_transition(ShadowAI* ai) { return new ThaddiusPhaseTransitionTrigger(ai); }
    static Trigger* thaddius_phase_thaddius(ShadowAI* ai) { return new ThaddiusPhaseThaddiusTrigger(ai); }
    static Trigger* razuvious_tank(ShadowAI* ai) { return new RazuviousTankTrigger(ai); }
    static Trigger* razuvious_nontank(ShadowAI* ai) { return new RazuviousNontankTrigger(ai); }

    static Trigger* horseman_attractors(ShadowAI* ai) { return new HorsemanAttractorsTrigger(ai); }
    static Trigger* horseman_except_attractors(ShadowAI* ai) { return new HorsemanExceptAttractorsTrigger(ai); }

    static Trigger* sapphiron_ground(ShadowAI* ai) { return new SapphironGroundTrigger(ai); }
    static Trigger* sapphiron_flight(ShadowAI* ai) { return new SapphironFlightTrigger(ai); }
    static Trigger* kelthuzad(ShadowAI* ai) { return new KelthuzadTrigger(ai); }
    static Trigger* anubrekhan(ShadowAI* ai) { return new AnubrekhanTrigger(ai); }
    static Trigger* gluth(ShadowAI* ai) { return new GluthTrigger(ai); }
    static Trigger* gluth_main_tank_mortal_wound(ShadowAI* ai) { return new GluthMainTankMortalWoundTrigger(ai); }
    static Trigger* loatheb(ShadowAI* ai) { return new LoathebTrigger(ai); }
};

#endif