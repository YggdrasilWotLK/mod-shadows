#ifndef _SHADOW_WOTLKDUNGEONUKACTIONCONTEXT_H
#define _SHADOW_WOTLKDUNGEONUKACTIONCONTEXT_H

#include "Action.h"
#include "NamedObjectContext.h"
#include "UtgardeKeepActions.h"

class WotlkDungeonUKActionContext : public NamedObjectContext<Action>
{
    public:
        WotlkDungeonUKActionContext() {
            creators["attack frost tomb"] = &WotlkDungeonUKActionContext::attack_frost_tomb;
            creators["attack dalronn"] = &WotlkDungeonUKActionContext::attack_dalronn;
        }
    private:
        static Action* attack_frost_tomb(ShadowAI* ai) { return new AttackFrostTombAction(ai); }
        static Action* attack_dalronn(ShadowAI* ai) { return new AttackDalronnAction(ai); }
};

#endif