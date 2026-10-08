#ifndef _SHADOW_WOTLKDUNGEONOKACTIONS_H
#define _SHADOW_WOTLKDUNGEONOKACTIONS_H

#include "Action.h"
#include "AttackAction.h"
#include "ShadowAI.h"
#include "Shadows.h"
#include "OldKingdomTriggers.h"

class AttackNadoxGuardianAction : public AttackAction
{
public:
    AttackNadoxGuardianAction(ShadowAI* ai) : AttackAction(ai, "attack nadox guardian") {}
    bool Execute(Event event) override;
};

class AttackJedogaVolunteerAction : public AttackAction
{
public:
    AttackJedogaVolunteerAction(ShadowAI* ai) : AttackAction(ai, "attack jedoga volunteer") {}
    bool Execute(Event event) override;
};

class AvoidShadowCrashAction : public MovementAction
{
public:
    AvoidShadowCrashAction(ShadowAI* ai) : MovementAction(ai, "avoid shadow crash") {}
    bool Execute(Event event) override;
};

#endif
