#ifndef _SHADOW_WOTLKDUNGEONUPACTIONS_H
#define _SHADOW_WOTLKDUNGEONUPACTIONS_H

#include "Action.h"
#include "AttackAction.h"
#include "ShadowAI.h"
#include "Shadows.h"
#include "UtgardePinnacleTriggers.h"

class AvoidFreezingCloudAction : public MovementAction
{
public:
    AvoidFreezingCloudAction(ShadowAI* ai) : MovementAction(ai, "avoid freezing cloud") {}
    bool Execute(Event event) override;
};

class AvoidSkadiWhirlwindAction : public MovementAction
{
public:
    AvoidSkadiWhirlwindAction(ShadowAI* ai) : MovementAction(ai, "avoid skadi whirlwind") {}
    bool Execute(Event event) override;
};

class AvoidYmironBaneAction : public MovementAction
{
public:
    AvoidYmironBaneAction(ShadowAI* ai) : MovementAction(ai, "avoid ymiron bane") {}
    bool Execute(Event event) override;
};

#endif