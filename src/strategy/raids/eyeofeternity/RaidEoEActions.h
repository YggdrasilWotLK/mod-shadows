#ifndef _SHADOW_RAIDEOEACTIONS_H
#define _SHADOW_RAIDEOEACTIONS_H

#include "MovementActions.h"
#include "AttackAction.h"
#include "GenericSpellActions.h"
#include "ShadowAI.h"
#include "Shadows.h"

const std::pair<float, float> MALYGOS_MAINTANK_POSITION = {757.0f, 1337.0f};
const std::pair<float, float> MALYGOS_STACK_POSITION = {755.0f, 1301.0f};

class MalygosPositionAction : public MovementAction
{
public:
    MalygosPositionAction(ShadowAI* botAI, std::string const name = "malygos position")
        : MovementAction(botAI, name) {}
    bool Execute(Event event) override;
};

class MalygosTargetAction : public AttackAction
{
public:
    MalygosTargetAction(ShadowAI* botAI, std::string const name = "malygos target")
        : AttackAction(botAI, name) {}
    bool Execute(Event event) override;
};

class PullPowerSparkAction : public CastSpellAction
{
public:
    PullPowerSparkAction(ShadowAI* botAI, std::string const name = "pull power spark")
        : CastSpellAction(botAI, name) {}
    bool Execute(Event event) override;
    bool isPossible() override;
    bool isUseful() override;
};

class KillPowerSparkAction : public AttackAction
{
public:
    KillPowerSparkAction(ShadowAI* botAI, std::string const name = "kill power spark")
        : AttackAction(botAI, name) {}
    bool Execute(Event event) override;
};

class EoEFlyDrakeAction : public MovementAction
{
public:
    EoEFlyDrakeAction(ShadowAI* ai) : MovementAction(ai, "eoe fly drake") {}
    bool Execute(Event event) override;
    bool isPossible() override;
};

class EoEDrakeAttackAction : public Action
{
public:
    EoEDrakeAttackAction(ShadowAI* botAI) : Action(botAI, "eoe drake attack") {}
    bool Execute(Event event) override;
    bool isPossible() override;

protected:
    Unit* vehicleBase;
    bool CastDrakeSpellAction(Unit* target, uint32 spellId, uint32 cooldown);
    bool DrakeDpsAction(Unit* target);
    bool DrakeHealAction();
};

#endif
