#ifndef _SHADOW_WOTLKDUNGEONOKACTIONCONTEXT_H
#define _SHADOW_WOTLKDUNGEONOKACTIONCONTEXT_H

#include "Action.h"
#include "NamedObjectContext.h"
#include "OldKingdomActions.h"

class WotlkDungeonOKActionContext : public NamedObjectContext<Action>
{
    public:
        WotlkDungeonOKActionContext() {
            creators["attack nadox guardian"] = &WotlkDungeonOKActionContext::attack_nadox_guardian;
            creators["attack jedoga volunteer"] = &WotlkDungeonOKActionContext::attack_jedoga_volunteer;
            creators["avoid shadow crash"] = &WotlkDungeonOKActionContext::avoid_shadow_crash;
        }
    private:
        static Action* attack_nadox_guardian(ShadowAI* ai) { return new AttackNadoxGuardianAction(ai); }
        static Action* attack_jedoga_volunteer(ShadowAI* ai) { return new AttackJedogaVolunteerAction(ai); }
        static Action* avoid_shadow_crash(ShadowAI* ai) { return new AvoidShadowCrashAction(ai); }
};

#endif
