#ifndef _SHADOW_RAIDONYXIATRIGGERCONTEXT_H
#define _SHADOW_RAIDONYXIATRIGGERCONTEXT_H

#include "AiObjectContext.h"
#include "NamedObjectContext.h"
#include "RaidOnyxiaTriggers.h"

class RaidOnyxiaTriggerContext : public NamedObjectContext<Trigger>
{
public:
    RaidOnyxiaTriggerContext()
    {
        creators["ony near tail"] = &RaidOnyxiaTriggerContext::near_tail;
        creators["ony deep breath warning"] = &RaidOnyxiaTriggerContext::deep_breath;
        creators["ony fireball splash incoming"] = &RaidOnyxiaTriggerContext::fireball_splash;
        creators["ony whelps spawn"] = &RaidOnyxiaTriggerContext::whelps_spawn;
        creators["ony avoid eggs"] = &RaidOnyxiaTriggerContext::avoid_eggs;
    }

private:
    static Trigger* near_tail(ShadowAI* ai) { return new OnyxiaNearTailTrigger(ai); }
    static Trigger* deep_breath(ShadowAI* ai) { return new OnyxiaDeepBreathTrigger(ai); }
    static Trigger* fireball_splash(ShadowAI* ai) { return new RaidOnyxiaFireballSplashTrigger(ai); }
    static Trigger* whelps_spawn(ShadowAI* ai) { return new RaidOnyxiaWhelpsSpawnTrigger(ai); }
    static Trigger* avoid_eggs(ShadowAI* ai) { return new OnyxiaAvoidEggsTrigger(ai); }
};

#endif
