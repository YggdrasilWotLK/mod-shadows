#ifndef _SHADOW_WOTLKDUNGEONUPACTIONCONTEXT_H
#define _SHADOW_WOTLKDUNGEONUPACTIONCONTEXT_H

#include "Action.h"
#include "NamedObjectContext.h"
#include "UtgardePinnacleActions.h"

class WotlkDungeonUPActionContext : public NamedObjectContext<Action>
{
    public:
        WotlkDungeonUPActionContext() {
            creators["avoid freezing cloud"] = &WotlkDungeonUPActionContext::avoid_freezing_cloud;
            creators["avoid skadi whirlwind"] = &WotlkDungeonUPActionContext::avoid_whirlwind;
            creators["avoid ymiron bane"] = &WotlkDungeonUPActionContext::avoid_ymiron_bane;
        }
    private:
        static Action* avoid_freezing_cloud(ShadowAI* ai) { return new AvoidFreezingCloudAction(ai); }
        static Action* avoid_whirlwind(ShadowAI* ai) { return new AvoidSkadiWhirlwindAction(ai); }
        static Action* avoid_ymiron_bane(ShadowAI* ai) { return new AvoidYmironBaneAction(ai); }
};

#endif
