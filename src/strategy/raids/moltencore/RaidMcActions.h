#ifndef _SHADOW_RAIDMCACTIONS_H
#define _SHADOW_RAIDMCACTIONS_H

#include "MovementActions.h"
#include "ShadowAI.h"
#include "Shadows.h"

class McCheckShouldMoveFromGroupAction : public Action
{
public:
    McCheckShouldMoveFromGroupAction(ShadowAI* botAI, std::string const name = "mc check should move from group")
        : Action(botAI, name) {}
    bool Execute(Event event) override;
};

class McMoveFromBaronGeddonAction : public MovementAction
{
public:
    McMoveFromBaronGeddonAction(ShadowAI* botAI, std::string const name = "mc move from baron geddon")
        : MovementAction(botAI, name) {}
    bool Execute(Event event) override;
};

#endif
