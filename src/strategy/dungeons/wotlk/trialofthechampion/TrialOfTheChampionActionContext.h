#ifndef _SHADOW_WOTLKDUNGEONTOCACTIONCONTEXT_H
#define _SHADOW_WOTLKDUNGEONTOCACTIONCONTEXT_H

#include "Action.h"
#include "NamedObjectContext.h"
#include "TrialOfTheChampionActions.h"

class WotlkDungeonToCActionContext : public NamedObjectContext<Action>
{
    public:
        WotlkDungeonToCActionContext() {
            creators["toc lance"] = &WotlkDungeonToCActionContext::toc_lance;
            creators["toc ue lance"] = &WotlkDungeonToCActionContext::toc_ue_lance;
            creators["toc mount"] = &WotlkDungeonToCActionContext::toc_mount;
            creators["toc mounted"] = &WotlkDungeonToCActionContext::toc_mounted;
            creators["toc eadric"] = &WotlkDungeonToCActionContext::toc_eadric;
        }
    private:
        static Action* toc_lance(ShadowAI* ai) { return new ToCLanceAction(ai); }
        static Action* toc_ue_lance(ShadowAI* ai) { return new ToCUELanceAction(ai); }
        static Action* toc_mount(ShadowAI* ai) { return new ToCMountAction(ai); }
        static Action* toc_mounted(ShadowAI* ai) { return new ToCMountedAction(ai); }
        static Action* toc_eadric(ShadowAI* ai) { return new ToCEadricAction(ai); }
};

#endif
