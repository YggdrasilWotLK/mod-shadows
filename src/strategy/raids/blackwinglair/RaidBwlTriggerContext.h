#ifndef _SHADOW_RAIDBWLTRIGGERCONTEXT_H
#define _SHADOW_RAIDBWLTRIGGERCONTEXT_H

#include "AiObjectContext.h"
#include "NamedObjectContext.h"
#include "RaidBwlTriggers.h"

class RaidBwlTriggerContext : public NamedObjectContext<Trigger>
{
public:
    RaidBwlTriggerContext()
    {
        creators["bwl suppression device"] = &RaidBwlTriggerContext::bwl_suppression_device;
        creators["bwl affliction bronze"] = &RaidBwlTriggerContext::bwl_affliction_bronze;
    }

private:
    static Trigger* bwl_suppression_device(ShadowAI* ai) { return new BwlSuppressionDeviceTrigger(ai); }
    static Trigger* bwl_affliction_bronze(ShadowAI* ai) { return new BwlAfflictionBronzeTrigger(ai); }
};

#endif
