#ifndef _SHADOW_WOTLKDUNGEONPOSTRIGGERCONTEXT_H
#define _SHADOW_WOTLKDUNGEONPOSTRIGGERCONTEXT_H

#include "NamedObjectContext.h"
#include "AiObjectContext.h"
#include "PitOfSaronTriggers.h"

class WotlkDungeonPoSTriggerContext : public NamedObjectContext<Trigger>
{
public:
    WotlkDungeonPoSTriggerContext()
    {
        creators["ick and krick"] = &WotlkDungeonPoSTriggerContext::ick_and_krick;
        creators["tyrannus"] = &WotlkDungeonPoSTriggerContext::tyrannus;
    }

private:
    static Trigger* ick_and_krick(ShadowAI* ai) { return new IckAndKrickTrigger(ai); }
    static Trigger* tyrannus(ShadowAI* ai) { return new TyrannusTrigger(ai); }
};

#endif
