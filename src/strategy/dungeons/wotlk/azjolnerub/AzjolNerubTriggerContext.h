#ifndef _SHADOW_WOTLKDUNGEONANTRIGGERCONTEXT_H
#define _SHADOW_WOTLKDUNGEONANTRIGGERCONTEXT_H

#include "NamedObjectContext.h"
#include "AiObjectContext.h"
#include "AzjolNerubTriggers.h"

class WotlkDungeonANTriggerContext : public NamedObjectContext<Trigger>
{
    public:
        WotlkDungeonANTriggerContext()
        {
            creators["krik'thir web wrap"] = &WotlkDungeonANTriggerContext::krikthir_web_wrap;
            creators["krik'thir watchers"] = &WotlkDungeonANTriggerContext::krikthir_watchers;
            // creators["anub'arak impale"] = &WotlkDungeonANTriggerContext::anubarak_impale;
            creators["anub'arak pound"] = &WotlkDungeonANTriggerContext::anubarak_pound;
        }
    private:
        static Trigger* krikthir_web_wrap(ShadowAI* ai) { return new KrikthirWebWrapTrigger(ai); }
        static Trigger* krikthir_watchers(ShadowAI* ai) { return new KrikthirWatchersTrigger(ai); }
        // static Trigger* anubarak_impale(ShadowAI* ai) { return new AnubarakImpaleTrigger(ai); }
        static Trigger* anubarak_pound(ShadowAI* ai) { return new AnubarakPoundTrigger(ai); }
};

#endif
