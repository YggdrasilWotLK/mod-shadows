#ifndef _SHADOW_WOTLKDUNGEONHOSACTIONS_H
#define _SHADOW_WOTLKDUNGEONHOSACTIONS_H

#include "Action.h"
#include "AttackAction.h"
#include "ShadowAI.h"
#include "Shadows.h"
#include "HallsOfStoneTriggers.h"

class ShatterSpreadAction : public MovementAction
{
public:
    ShatterSpreadAction(ShadowAI* ai) : MovementAction(ai, "shatter spread") {}
    bool Execute(Event event) override;
};

class AvoidLightningRingAction : public MovementAction
{
public:
    AvoidLightningRingAction(ShadowAI* ai) : MovementAction(ai, "avoid lightning ring") {}
    bool Execute(Event event) override;
};

#endif
