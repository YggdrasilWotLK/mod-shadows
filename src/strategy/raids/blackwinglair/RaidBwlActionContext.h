#ifndef _SHADOW_RAIDBWLACTIONCONTEXT_H
#define _SHADOW_RAIDBWLACTIONCONTEXT_H

#include "Action.h"
#include "NamedObjectContext.h"
#include "RaidBwlActions.h"

class RaidBwlActionContext : public NamedObjectContext<Action>
{
public:
    RaidBwlActionContext()
    {
        creators["bwl check onyxia scale cloak"] = &RaidBwlActionContext::bwl_check_onyxia_scale_cloak;
        creators["bwl turn off suppression device"] = &RaidBwlActionContext::bwl_turn_off_suppression_device;
        creators["bwl use hourglass sand"] = &RaidBwlActionContext::bwl_use_hourglass_sand;
    }

private:
    static Action* bwl_check_onyxia_scale_cloak(ShadowAI* botAI) { return new BwlOnyxiaScaleCloakAuraCheckAction(botAI); }
    static Action* bwl_turn_off_suppression_device(ShadowAI* botAI) { return new BwlTurnOffSuppressionDeviceAction(botAI); }
    static Action* bwl_use_hourglass_sand(ShadowAI* botAI) { return new BwlUseHourglassSandAction(botAI); }
};

#endif
