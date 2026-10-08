#ifndef _SHADOW_WOTLKDUNGEONDTKACTIONCONTEXT_H
#define _SHADOW_WOTLKDUNGEONDTKACTIONCONTEXT_H

#include "Action.h"
#include "NamedObjectContext.h"
#include "DrakTharonKeepActions.h"

class WotlkDungeonDTKActionContext : public NamedObjectContext<Action>
{
    public:
        WotlkDungeonDTKActionContext() {
            creators["corpse explode spread"] = &WotlkDungeonDTKActionContext::corpse_explode_spread;
            creators["avoid arcane field"] = &WotlkDungeonDTKActionContext::avoid_arcane_field;
            creators["novos positioning"] = &WotlkDungeonDTKActionContext::novos_positioning;
            creators["novos target priority"] = &WotlkDungeonDTKActionContext::novos_target_priority;
            creators["slaying strike"] = &WotlkDungeonDTKActionContext::slaying_strike;
            creators["tharonja taunt"] = &WotlkDungeonDTKActionContext::taunt;
            creators["bone armor"] = &WotlkDungeonDTKActionContext::bone_armor;
            creators["touch of life"] = &WotlkDungeonDTKActionContext::touch_of_life;
        }
    private:
        static Action* corpse_explode_spread(ShadowAI* ai) { return new CorpseExplodeSpreadAction(ai); }
        static Action* avoid_arcane_field(ShadowAI* ai) { return new AvoidArcaneFieldAction(ai); }
        static Action* novos_positioning(ShadowAI* ai) { return new NovosDefaultPositionAction(ai); }
        static Action* novos_target_priority(ShadowAI* ai) { return new NovosTargetPriorityAction(ai); }
        static Action* slaying_strike(ShadowAI* ai) { return new CastSlayingStrikeAction(ai); }
        static Action* taunt(ShadowAI* ai) { return new CastTauntAction(ai); }
        static Action* bone_armor(ShadowAI* ai) { return new CastBoneArmorAction(ai); }
        static Action* touch_of_life(ShadowAI* ai) { return new CastTouchOfLifeAction(ai); }
};

#endif
