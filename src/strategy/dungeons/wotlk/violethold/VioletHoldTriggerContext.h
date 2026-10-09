#ifndef _SHADOW_WOTLKDUNGEONVHTRIGGERCONTEXT_H
#define _SHADOW_WOTLKDUNGEONVHTRIGGERCONTEXT_H

#include "NamedObjectContext.h"
#include "AiObjectContext.h"
#include "VioletHoldTriggers.h"

class WotlkDungeonVHTriggerContext : public NamedObjectContext<Trigger>
{
    public:
        WotlkDungeonVHTriggerContext()
        {
            creators["erekem target"] = &WotlkDungeonVHTriggerContext::erekem_target;
            creators["ichoron target"] = &WotlkDungeonVHTriggerContext::ichoron_target;
            creators["void shift"] = &WotlkDungeonVHTriggerContext::void_shift;
            creators["shroud of darkness"] = &WotlkDungeonVHTriggerContext::shroud_of_darkness;
            creators["cyanigosa positioning"] = &WotlkDungeonVHTriggerContext::cyanigosa_positioning;
        }
    private:
        static Trigger* erekem_target(ShadowAI* ai) { return new ErekemTargetTrigger(ai); }
        static Trigger* ichoron_target(ShadowAI* ai) { return new IchoronTargetTrigger(ai); }
        static Trigger* void_shift(ShadowAI* ai) { return new VoidShiftTrigger(ai); }
        static Trigger* shroud_of_darkness(ShadowAI* ai) { return new ShroudOfDarknessTrigger(ai); }
        static Trigger* cyanigosa_positioning(ShadowAI* ai) { return new CyanigosaPositioningTrigger(ai); }
};

#endif
