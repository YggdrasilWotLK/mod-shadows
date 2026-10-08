#ifndef _SHADOW_RAIDEOEACTIONCONTEXT_H
#define _SHADOW_RAIDEOEACTIONCONTEXT_H

#include "Action.h"
#include "NamedObjectContext.h"
#include "RaidEoEActions.h"

class RaidEoEActionContext : public NamedObjectContext<Action>
{
public:
    RaidEoEActionContext()
    {
        creators["malygos position"] = &RaidEoEActionContext::position;
        creators["malygos target"] = &RaidEoEActionContext::target;
        // creators["pull power spark"] = &RaidEoEActionContext::pull_power_spark;
        // creators["kill power spark"] = &RaidEoEActionContext::kill_power_spark;
        creators["eoe fly drake"] = &RaidEoEActionContext::eoe_fly_drake;
        creators["eoe drake attack"] = &RaidEoEActionContext::eoe_drake_attack;
    }

private:
    static Action* position(ShadowAI* ai) { return new MalygosPositionAction(ai); }
    static Action* target(ShadowAI* ai) { return new MalygosTargetAction(ai); }
    // static Action* pull_power_spark(ShadowAI* ai) { return new PullPowerSparkAction(ai); }
    // static Action* kill_power_spark(ShadowAI* ai) { return new KillPowerSparkAction(ai); }
    static Action* eoe_fly_drake(ShadowAI* ai) { return new EoEFlyDrakeAction(ai); }
    static Action* eoe_drake_attack(ShadowAI* ai) { return new EoEDrakeAttackAction(ai); }
};

#endif
