#ifndef _SHADOW_WOTLKDUNGEONNEXTRIGGERCONTEXT_H
#define _SHADOW_WOTLKDUNGEONNEXTRIGGERCONTEXT_H

#include "NamedObjectContext.h"
#include "AiObjectContext.h"
#include "NexusTriggers.h"

class WotlkDungeonNexTriggerContext : public NamedObjectContext<Trigger>
{
    public:
        WotlkDungeonNexTriggerContext()
        {
            creators["faction commander whirlwind"] = &WotlkDungeonNexTriggerContext::faction_commander_whirlwind;
            creators["telestra firebomb"] = &WotlkDungeonNexTriggerContext::telestra_firebomb;
            creators["telestra split phase"] = &WotlkDungeonNexTriggerContext::telestra_split_phase;
            creators["chaotic rift"] = &WotlkDungeonNexTriggerContext::chaotic_rift;
            creators["ormorok spikes"] = &WotlkDungeonNexTriggerContext::ormorok_spikes;
            creators["ormorok stack"] = &WotlkDungeonNexTriggerContext::ormorok_stack;
            creators["intense cold"] = &WotlkDungeonNexTriggerContext::intense_cold;
            creators["keristrasza positioning"] = &WotlkDungeonNexTriggerContext::keristrasza_positioning;
        }
    private:
        static Trigger* faction_commander_whirlwind(ShadowAI* ai) { return new FactionCommanderWhirlwindTrigger(ai); }
        static Trigger* telestra_firebomb(ShadowAI* ai) { return new TelestraFirebombTrigger(ai); }
        static Trigger* telestra_split_phase(ShadowAI* ai) { return new TelestraSplitPhaseTrigger(ai); }
        static Trigger* chaotic_rift(ShadowAI* ai) { return new ChaoticRiftTrigger(ai); }
        static Trigger* ormorok_spikes(ShadowAI* ai) { return new OrmorokSpikesTrigger(ai); }
        static Trigger* ormorok_stack(ShadowAI* ai) { return new OrmorokStackTrigger(ai); }
        static Trigger* intense_cold(ShadowAI* ai) { return new IntenseColdTrigger(ai); }
        static Trigger* keristrasza_positioning(ShadowAI* ai) { return new KeristraszaPositioningTrigger(ai); }
};

#endif
