#ifndef _SHADOW_RAIDOSTRIGGERCONTEXT_H
#define _SHADOW_RAIDOSTRIGGERCONTEXT_H

#include "AiObjectContext.h"
#include "NamedObjectContext.h"
#include "RaidOsTriggers.h"

class RaidOsTriggerContext : public NamedObjectContext<Trigger>
{
public:
    RaidOsTriggerContext()
    {
        creators["sartharion tank"] = &RaidOsTriggerContext::sartharion_tank;
        creators["flame tsunami"] = &RaidOsTriggerContext::flame_tsunami;
        creators["twilight fissure"] = &RaidOsTriggerContext::twilight_fissure;
        creators["sartharion dps"] = &RaidOsTriggerContext::sartharion_dps;
        creators["sartharion melee positioning"] = &RaidOsTriggerContext::sartharion_melee;
        creators["twilight portal enter"] = &RaidOsTriggerContext::twilight_portal_enter;
        creators["twilight portal exit"] = &RaidOsTriggerContext::twilight_portal_exit;
    }

private:
    static Trigger* sartharion_tank(ShadowAI* ai) { return new SartharionTankTrigger(ai); }
    static Trigger* flame_tsunami(ShadowAI* ai) { return new FlameTsunamiTrigger(ai); }
    static Trigger* twilight_fissure(ShadowAI* ai) { return new TwilightFissureTrigger(ai); }
    static Trigger* sartharion_dps(ShadowAI* ai) { return new SartharionDpsTrigger(ai); }
    static Trigger* sartharion_melee(ShadowAI* ai) { return new SartharionMeleePositioningTrigger(ai); }
    static Trigger* twilight_portal_enter(ShadowAI* ai) { return new TwilightPortalEnterTrigger(ai); }
    static Trigger* twilight_portal_exit(ShadowAI* ai) { return new TwilightPortalExitTrigger(ai); }
};

#endif
