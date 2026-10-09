#ifndef _SHADOW_WOTLKDUNGEONHOLACTIONCONTEXT_H
#define _SHADOW_WOTLKDUNGEONHOLACTIONCONTEXT_H

#include "Action.h"
#include "NamedObjectContext.h"
#include "HallsOfLightningActions.h"

class WotlkDungeonHoLActionContext : public NamedObjectContext<Action>
{
    public:
        WotlkDungeonHoLActionContext() {
            creators["bjarngrim target"] = &WotlkDungeonHoLActionContext::bjarngrim_target;
            creators["avoid whirlwind"] = &WotlkDungeonHoLActionContext::avoid_whirlwind;
            creators["volkhan target"] = &WotlkDungeonHoLActionContext::volkhan_target;
            creators["static overload spread"] = &WotlkDungeonHoLActionContext::static_overload_spread;
            creators["ball lightning spread"] = &WotlkDungeonHoLActionContext::ball_lightning_spread;
            creators["ionar tank position"] = &WotlkDungeonHoLActionContext::ionar_tank_position;
            creators["disperse position"] = &WotlkDungeonHoLActionContext::disperse_position;
            creators["loken stack"] = &WotlkDungeonHoLActionContext::loken_stack;
            creators["avoid lightning nova"] = &WotlkDungeonHoLActionContext::avoid_lightning_nova;
        }
    private:
        static Action* bjarngrim_target(ShadowAI* ai) { return new BjarngrimTargetAction(ai); }
        static Action* avoid_whirlwind(ShadowAI* ai) { return new AvoidWhirlwindAction(ai); }
        static Action* volkhan_target(ShadowAI* ai) { return new VolkhanTargetAction(ai); }
        static Action* static_overload_spread(ShadowAI* ai) { return new StaticOverloadSpreadAction(ai); }
        static Action* ball_lightning_spread(ShadowAI* ai) { return new BallLightningSpreadAction(ai); }
        static Action* ionar_tank_position(ShadowAI* ai) { return new IonarTankPositionAction(ai); }
        static Action* disperse_position(ShadowAI* ai) { return new DispersePositionAction(ai); }
        static Action* loken_stack(ShadowAI* ai) { return new LokenStackAction(ai); }
        static Action* avoid_lightning_nova(ShadowAI* ai) { return new AvoidLightningNovaAction(ai); }
};

#endif
