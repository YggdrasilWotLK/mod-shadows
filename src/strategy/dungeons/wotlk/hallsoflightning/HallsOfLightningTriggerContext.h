#ifndef _SHADOW_WOTLKDUNGEONHOLTRIGGERCONTEXT_H
#define _SHADOW_WOTLKDUNGEONHOLTRIGGERCONTEXT_H

#include "NamedObjectContext.h"
#include "AiObjectContext.h"
#include "HallsOfLightningTriggers.h"

class WotlkDungeonHoLTriggerContext : public NamedObjectContext<Trigger>
{
    public:
        WotlkDungeonHoLTriggerContext()
        {
            creators["stormforged lieutenant"] = &WotlkDungeonHoLTriggerContext::stormforged_lieutenant;
            creators["whirlwind"] = &WotlkDungeonHoLTriggerContext::bjarngrim_whirlwind;
            creators["volkhan"] = &WotlkDungeonHoLTriggerContext::volkhan;
            creators["static overload"] = &WotlkDungeonHoLTriggerContext::static_overload;
            creators["ball lightning"] = &WotlkDungeonHoLTriggerContext::ball_lightning;
            creators["ionar tank aggro"] = &WotlkDungeonHoLTriggerContext::ionar_tank_aggro;
            creators["ionar disperse"] = &WotlkDungeonHoLTriggerContext::ionar_disperse;
            creators["loken ranged"] = &WotlkDungeonHoLTriggerContext::loken_ranged;
            creators["lightning nova"] = &WotlkDungeonHoLTriggerContext::lightning_nova;
        }
    private:
        static Trigger* stormforged_lieutenant(ShadowAI* ai) { return new StormforgedLieutenantTrigger(ai); }
        static Trigger* bjarngrim_whirlwind(ShadowAI* ai) { return new BjarngrimWhirlwindTrigger(ai); }
        static Trigger* volkhan(ShadowAI* ai) { return new VolkhanTrigger(ai); }
        static Trigger* static_overload(ShadowAI* ai) { return new IonarStaticOverloadTrigger(ai); }
        static Trigger* ball_lightning(ShadowAI* ai) { return new IonarBallLightningTrigger(ai); }
        static Trigger* ionar_tank_aggro(ShadowAI* ai) { return new IonarTankAggroTrigger(ai); }
        static Trigger* ionar_disperse(ShadowAI* ai) { return new IonarDisperseTrigger(ai); }
        static Trigger* loken_ranged(ShadowAI* ai) { return new LokenRangedTrigger(ai); }
        static Trigger* lightning_nova(ShadowAI* ai) { return new LokenLightningNovaTrigger(ai); }
};

#endif
