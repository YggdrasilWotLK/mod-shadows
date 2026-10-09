#ifndef _SHADOW_RAIDAQ20TRIGGERCONTEXT_H
#define _SHADOW_RAIDAQ20TRIGGERCONTEXT_H

#include "AiObjectContext.h"
#include "NamedObjectContext.h"
#include "RaidAq20Triggers.h"

class RaidAq20TriggerContext : public NamedObjectContext<Trigger>
{
public:
    RaidAq20TriggerContext()
    {
        creators["aq20 move to crystal"] = &RaidAq20TriggerContext::move_to_crystal;
    }

private:
    static Trigger* move_to_crystal(ShadowAI* ai) { return new Aq20MoveToCrystalTrigger(ai); }
};

#endif
