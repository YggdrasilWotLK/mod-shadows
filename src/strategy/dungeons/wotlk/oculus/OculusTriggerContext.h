#ifndef _SHADOW_WOTLKDUNGEONOCCTRIGGERCONTEXT_H
#define _SHADOW_WOTLKDUNGEONOCCTRIGGERCONTEXT_H

#include "NamedObjectContext.h"
#include "AiObjectContext.h"
#include "OculusTriggers.h"

class WotlkDungeonOccTriggerContext : public NamedObjectContext<Trigger>
{
    public:
        WotlkDungeonOccTriggerContext()
        {
            creators["unstable sphere"] = &WotlkDungeonOccTriggerContext::unstable_sphere;
            creators["drake mount"] = &WotlkDungeonOccTriggerContext::drake_mount;
            creators["drake dismount"] = &WotlkDungeonOccTriggerContext::drake_dismount;
            creators["group flying"] = &WotlkDungeonOccTriggerContext::group_flying;
            creators["drake combat"] = &WotlkDungeonOccTriggerContext::drake_combat;
            creators["varos cloudstrider"] = &WotlkDungeonOccTriggerContext::varos_cloudstrider;
            creators["arcane explosion"] = &WotlkDungeonOccTriggerContext::arcane_explosion;
            creators["time bomb"] = &WotlkDungeonOccTriggerContext::time_bomb;
        }
    private:
        static Trigger* unstable_sphere(ShadowAI* ai) { return new DrakosUnstableSphereTrigger(ai); }
        static Trigger* drake_mount(ShadowAI* ai) { return new DrakeMountTrigger(ai); }
        static Trigger* drake_dismount(ShadowAI* ai) { return new DrakeDismountTrigger(ai); }
        static Trigger* group_flying(ShadowAI* ai) { return new GroupFlyingTrigger(ai); }
        static Trigger* drake_combat(ShadowAI* ai) { return new DrakeCombatTrigger(ai); }
        static Trigger* varos_cloudstrider(ShadowAI* ai) { return new VarosCloudstriderTrigger(ai); }
        static Trigger* arcane_explosion(ShadowAI* ai) { return new UromArcaneExplosionTrigger(ai); }
        static Trigger* time_bomb(ShadowAI* ai) { return new UromTimeBombTrigger(ai); }
};

#endif
