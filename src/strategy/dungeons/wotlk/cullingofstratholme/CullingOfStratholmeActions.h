#ifndef _SHADOW_WOTLKDUNGEONCOSACTIONS_H
#define _SHADOW_WOTLKDUNGEONCOSACTIONS_H

#include "Action.h"
#include "AttackAction.h"
#include "GenericSpellActions.h"
#include "ShadowAI.h"
#include "Shadows.h"
#include "CullingOfStratholmeTriggers.h"

class ExplodeGhoulSpreadAction : public MovementAction
{
public:
    ExplodeGhoulSpreadAction(ShadowAI* ai) : MovementAction(ai, "explode ghoul spread") {}
    bool Execute(Event event) override;
};

class EpochStackAction : public MovementAction
{
public:
    EpochStackAction(ShadowAI* ai) : MovementAction(ai, "epoch stack") {}
    bool Execute(Event event) override;
    bool isUseful() override;
};

#endif
