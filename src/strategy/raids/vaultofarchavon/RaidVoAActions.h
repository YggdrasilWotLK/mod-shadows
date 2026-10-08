#ifndef _SHADOW_RAIDVOAACTIONS_H
#define _SHADOW_RAIDVOAACTIONS_H

#include "Action.h"
#include "MovementActions.h"
#include "ShadowAI.h"
#include "Event.h"

//
//  Emalon the Storm Watcher
//

class EmalonMarkBossAction : public MovementAction
{
public:
    EmalonMarkBossAction(ShadowAI* botAI) : MovementAction(botAI, "emalon mark boss action") {}
    bool Execute(Event event) override;
    bool isUseful() override;
};

class EmalonLightingNovaAction : public MovementAction
{
public:
    EmalonLightingNovaAction(ShadowAI* botAI) : MovementAction(botAI, "emalon lighting nova action") {}
    bool Execute(Event event) override;
    bool isUseful() override;
};

class EmalonOverchargeAction : public Action
{
public:
    EmalonOverchargeAction(ShadowAI* botAI) : Action(botAI, "emalon overcharge action") {}
    bool Execute(Event event) override;
    bool isUseful() override;
};

class EmalonFallFromFloorAction : public Action
{
public:
    EmalonFallFromFloorAction(ShadowAI* botAI) : Action(botAI, "emalon fall from floor action") {}
    bool Execute(Event event) override;
    bool isUseful() override;
};

#endif
