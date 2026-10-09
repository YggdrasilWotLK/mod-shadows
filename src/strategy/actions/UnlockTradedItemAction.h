#ifndef _SHADOW_UNLOCKTRADEDITEMACTION_H
#define _SHADOW_UNLOCKTRADEDITEMACTION_H

#include "Action.h"

class ShadowAI;

class UnlockTradedItemAction : public Action
{
public:
    UnlockTradedItemAction(ShadowAI* botAI) : Action(botAI, "unlock traded item") {}

    bool Execute(Event event) override;

private:
    bool CanUnlockItem(Item* item);
    void UnlockItem(Item* item);
};

#endif
