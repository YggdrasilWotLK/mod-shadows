#ifndef _SHADOW_WOTLKDUNGEONUPTRIGGERCONTEXT_H
#define _SHADOW_WOTLKDUNGEONUPTRIGGERCONTEXT_H

#include "NamedObjectContext.h"
#include "AiObjectContext.h"
#include "UtgardePinnacleTriggers.h"

class WotlkDungeonUPTriggerContext : public NamedObjectContext<Trigger> 
{
    public:
        WotlkDungeonUPTriggerContext()
        {
            creators["freezing cloud"] = &WotlkDungeonUPTriggerContext::freezing_cloud;
            creators["skadi whirlwind"] = &WotlkDungeonUPTriggerContext::whirlwind;
            creators["ymiron bane"] = &WotlkDungeonUPTriggerContext::bane;
        }
    private:
        static Trigger* freezing_cloud(ShadowAI* ai) { return new SkadiFreezingCloudTrigger(ai); }
        static Trigger* whirlwind(ShadowAI* ai) { return new SkadiWhirlwindTrigger(ai); }
        static Trigger* bane(ShadowAI* ai) { return new YmironBaneTrigger(ai); }
};

#endif
