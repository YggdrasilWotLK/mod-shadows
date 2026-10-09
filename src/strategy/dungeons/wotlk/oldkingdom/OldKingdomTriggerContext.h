#ifndef _SHADOW_WOTLKDUNGEONOKTRIGGERCONTEXT_H
#define _SHADOW_WOTLKDUNGEONOKTRIGGERCONTEXT_H

#include "NamedObjectContext.h"
#include "AiObjectContext.h"
#include "OldKingdomTriggers.h"

class WotlkDungeonOKTriggerContext : public NamedObjectContext<Trigger>
{
    public:
        WotlkDungeonOKTriggerContext()
        {
            creators["nadox guardian"] = &WotlkDungeonOKTriggerContext::nadox_guardian;
            creators["jedoga volunteer"] = &WotlkDungeonOKTriggerContext::jedoga_volunteer;
            creators["shadow crash"] = &WotlkDungeonOKTriggerContext::shadow_crash;
        }
    private:
        static Trigger* nadox_guardian(ShadowAI* ai) { return new NadoxGuardianTrigger(ai); }
        static Trigger* jedoga_volunteer(ShadowAI* ai) { return new JedogaVolunteerTrigger(ai); }
        static Trigger* shadow_crash(ShadowAI* ai) { return new ShadowCrashTrigger(ai); }
};

#endif
