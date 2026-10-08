#ifndef _SHADOW_WOTLKDUNGEONANACTIONCONTEXT_H
#define _SHADOW_WOTLKDUNGEONANACTIONCONTEXT_H

#include "Action.h"
#include "NamedObjectContext.h"
#include "AzjolNerubActions.h"

class WotlkDungeonANActionContext : public NamedObjectContext<Action>
{
    public:
        WotlkDungeonANActionContext() {
            creators["attack web wrap"] = &WotlkDungeonANActionContext::attack_web_wrap;
            creators["krik'thir priority"] = &WotlkDungeonANActionContext::krikthir_priority;
            creators["dodge pound"] = &WotlkDungeonANActionContext::dodge_pound;
        }
    private:
        static Action* attack_web_wrap(ShadowAI* ai) { return new AttackWebWrapAction(ai); }
        static Action* krikthir_priority(ShadowAI* ai) { return new WatchersTargetAction(ai); }
        static Action* dodge_pound(ShadowAI* ai) { return new AnubarakDodgePoundAction(ai); }
};

#endif
