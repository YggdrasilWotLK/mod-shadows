#ifndef _SHADOW_WOTLKDUNGEONNEXACTIONCONTEXT_H
#define _SHADOW_WOTLKDUNGEONNEXACTIONCONTEXT_H

#include "Action.h"
#include "NamedObjectContext.h"
#include "NexusActions.h"

class WotlkDungeonNexActionContext : public NamedObjectContext<Action>
{
    public:
        WotlkDungeonNexActionContext() {
            creators["move from whirlwind"] = &WotlkDungeonNexActionContext::move_from_whirlwind;
            creators["firebomb spread"] = &WotlkDungeonNexActionContext::firebomb_spread;
            creators["telestra split target"] = &WotlkDungeonNexActionContext::telestra_split_target;
            creators["chaotic rift target"] = &WotlkDungeonNexActionContext::chaotic_rift_target;
            creators["dodge spikes"] = &WotlkDungeonNexActionContext::dodge_spikes;
            creators["intense cold jump"] = &WotlkDungeonNexActionContext::intense_cold_jump;
        }
    private:
        static Action* move_from_whirlwind(ShadowAI* ai) { return new MoveFromWhirlwindAction(ai); }
        static Action* firebomb_spread(ShadowAI* ai) { return new FirebombSpreadAction(ai); }
        static Action* telestra_split_target(ShadowAI* ai) { return new TelestraSplitTargetAction(ai); }
        static Action* chaotic_rift_target(ShadowAI* ai) { return new ChaoticRiftTargetAction(ai); }
        static Action* dodge_spikes(ShadowAI* ai) { return new DodgeSpikesAction(ai); }
        static Action* intense_cold_jump(ShadowAI* ai) { return new IntenseColdJumpAction(ai); }
};

#endif
