#ifndef _SHADOW_RAIDONYXIAACTIONS_CONTEXT_H
#define _SHADOW_RAIDONYXIAACTIONS_CONTEXT_H

#include "Action.h"
#include "NamedObjectContext.h"
#include "RaidOnyxiaActions.h"

class RaidOnyxiaActionContext : public NamedObjectContext<Action>
{
public:
    RaidOnyxiaActionContext()
    {
        creators["ony move to side"] = &RaidOnyxiaActionContext::move_to_side;
        creators["ony spread out"] = &RaidOnyxiaActionContext::spread_out;
        creators["ony move to safe zone"] = &RaidOnyxiaActionContext::move_to_safe_zone;
        creators["ony kill whelps"] = &RaidOnyxiaActionContext::kill_whelps;
        creators["ony avoid eggs move"] = &RaidOnyxiaActionContext::avoid_eggs;
    }

private:
    static Action* move_to_side(ShadowAI* ai) { return new RaidOnyxiaMoveToSideAction(ai); }
    static Action* spread_out(ShadowAI* ai) { return new RaidOnyxiaSpreadOutAction(ai); }
    static Action* move_to_safe_zone(ShadowAI* ai) { return new RaidOnyxiaMoveToSafeZoneAction(ai); }
    static Action* kill_whelps(ShadowAI* ai) { return new RaidOnyxiaKillWhelpsAction(ai); }
    static Action* avoid_eggs(ShadowAI* ai) { return new OnyxiaAvoidEggsAction(ai); }
};

#endif
