#ifndef _SHADOW_RAIDEOETRIGGERCONTEXT_H
#define _SHADOW_RAIDEOETRIGGERCONTEXT_H

#include "AiObjectContext.h"
#include "NamedObjectContext.h"
#include "RaidEoETriggers.h"

class RaidEoETriggerContext : public NamedObjectContext<Trigger>
{
public:
    RaidEoETriggerContext()
    {
        creators["malygos"] = &RaidEoETriggerContext::malygos;
        creators["power spark"] = &RaidEoETriggerContext::power_spark;
    }

private:
    static Trigger* power_spark(ShadowAI* ai) { return new PowerSparkTrigger(ai); }
    static Trigger* malygos(ShadowAI* ai) { return new MalygosTrigger(ai); }
};

#endif
