#ifndef _SHADOW_UNLOCKITEMACTION_H
#define _SHADOW_UNLOCKITEMACTION_H

#include "Action.h"

class ShadowAI;

class UnlockItemAction : public Action
{
public:
    UnlockItemAction(ShadowAI* botAI) : Action(botAI, "unlock item") { }

    bool Execute(Event event) override;

private:
    void UnlockItem(Item* item);
};

#endif
