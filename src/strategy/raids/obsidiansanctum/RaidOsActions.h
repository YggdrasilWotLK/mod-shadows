#ifndef _SHADOW_RAIDOSACTIONS_H
#define _SHADOW_RAIDOSACTIONS_H

#include "MovementActions.h"
#include "AttackAction.h"
#include "ShadowAI.h"
#include "Shadows.h"

const float TSUNAMI_LEFT_SAFE_MELEE = 552.0f;
const float TSUNAMI_LEFT_SAFE_RANGED = 504.0f;
const float TSUNAMI_RIGHT_SAFE_ALL = 529.0f;
const std::pair<float, float> SARTHARION_MAINTANK_POSITION = {3258.5f, 532.5f};
const std::pair<float, float> SARTHARION_OFFTANK_POSITION = {3230.0f, 526.0f};
const std::pair<float, float> SARTHARION_RANGED_POSITION = {3248.0f, 507.0f};

class SartharionTankPositionAction : public AttackAction
{
public:
    SartharionTankPositionAction(ShadowAI* botAI, std::string const name = "sartharion tank position")
        : AttackAction(botAI, name) {}
    bool Execute(Event event) override;
};

class AvoidTwilightFissureAction : public MovementAction
{
public:
    AvoidTwilightFissureAction(ShadowAI* botAI, std::string const name = "avoid twilight fissure")
        : MovementAction(botAI, name) {}
    bool Execute(Event event) override;
};

class AvoidFlameTsunamiAction : public MovementAction
{
public:
    AvoidFlameTsunamiAction(ShadowAI* botAI, std::string const name = "avoid flame tsunami")
        : MovementAction(botAI, name) {}
    bool Execute(Event event) override;
};

class SartharionAttackPriorityAction : public AttackAction
{
public:
    SartharionAttackPriorityAction(ShadowAI* botAI, std::string const name = "sartharion attack priority")
        : AttackAction(botAI, name) {}
    bool Execute(Event event) override;
};

class EnterTwilightPortalAction : public MovementAction
{
public:
    EnterTwilightPortalAction(ShadowAI* botAI, std::string const name = "enter twilight portal")
        : MovementAction(botAI, name) {}
    bool Execute(Event event) override;
};

class ExitTwilightPortalAction : public MovementAction
{
public:
    ExitTwilightPortalAction(ShadowAI* botAI, std::string const name = "exit twilight portal")
        : MovementAction(botAI, name) {}
    bool Execute(Event event) override;
};

#endif
