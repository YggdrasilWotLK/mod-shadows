#ifndef _PLAYERBOT_WOTLKDUNGEONANACTIONCONTEXT_H
#define _PLAYERBOT_WOTLKDUNGEONANACTIONCONTEXT_H

#include "Action.h"
#include "NamedObjectContext.h"
#include "AzjolNerubActions.h"

class WotlkDungeonANActionContext : public NamedObjectContext<Action>
{
    public:
        WotlkDungeonANActionContext() {
            creators["attack web wrap"] = &WotlkDungeonANActionContext::attack_web_wrap;
            creators["krik'thir priority"] = &WotlkDungeonANActionContext::krikthir_priority;
            creators["watchers tank position"] = &WotlkDungeonANActionContext::watchers_tank_position;
            creators["watchers group stack"] = &WotlkDungeonANActionContext::watchers_group_stack;
            creators["dodge pound"] = &WotlkDungeonANActionContext::dodge_pound;
        }
    private:
        static Action* attack_web_wrap(PlayerbotAI* ai) { return new AttackWebWrapAction(ai); }
        static Action* krikthir_priority(PlayerbotAI* ai) { return new WatchersTargetAction(ai); }
        static Action* watchers_tank_position(PlayerbotAI* ai) { return new WatchersTankPositionAction(ai); }
        static Action* watchers_group_stack(PlayerbotAI* ai) { return new WatchersGroupStackAction(ai); }
        static Action* dodge_pound(PlayerbotAI* ai) { return new AnubarakDodgePoundAction(ai); }
};

#endif
