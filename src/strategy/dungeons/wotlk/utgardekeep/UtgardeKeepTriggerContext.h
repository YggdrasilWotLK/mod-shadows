#ifndef _PLAYERBOT_WOTLKDUNGEONUKTRIGGERCONTEXT_H
#define _PLAYERBOT_WOTLKDUNGEONUKTRIGGERCONTEXT_H

#include "NamedObjectContext.h"
#include "AiObjectContext.h"
#include "UtgardeKeepTriggers.h"

class WotlkDungeonUKTriggerContext : public NamedObjectContext<Trigger>
{
    public:
        WotlkDungeonUKTriggerContext()
        {
            creators["keleseth frost tomb"] = &WotlkDungeonUKTriggerContext::keleseth_frost_tomb;
            creators["dalronn priority"] = &WotlkDungeonUKTriggerContext::dalronn_priority_target;
        }
    private:
        static Trigger* keleseth_frost_tomb(PlayerbotAI* ai) { return new KelesethFrostTombTrigger(ai); }
        static Trigger* dalronn_priority_target(PlayerbotAI* ai) { return new DalronnDpsTrigger(ai); }
};

#endif