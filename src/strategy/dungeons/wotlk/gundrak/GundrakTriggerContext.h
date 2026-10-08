#ifndef _SHADOW_WOTLKDUNGEONGDTRIGGERCONTEXT_H
#define _SHADOW_WOTLKDUNGEONGDTRIGGERCONTEXT_H

#include "NamedObjectContext.h"
#include "AiObjectContext.h"
#include "GundrakTriggers.h"

class WotlkDungeonGDTriggerContext : public NamedObjectContext<Trigger>
{
    public:
        WotlkDungeonGDTriggerContext()
        {
            creators["poison nova"] = &WotlkDungeonGDTriggerContext::poison_nova;
            creators["snake wrap"] = &WotlkDungeonGDTriggerContext::snake_wrap;
            creators["whirling slash"] = &WotlkDungeonGDTriggerContext::whirling_slash;
        }
    private:
        static Trigger* poison_nova(ShadowAI* ai) { return new SladranPoisonNovaTrigger(ai); }
        static Trigger* snake_wrap(ShadowAI* ai) { return new SladranSnakeWrapTrigger(ai); }
        static Trigger* whirling_slash(ShadowAI* ai) { return new GaldarahWhirlingSlashTrigger(ai); }
};

#endif
