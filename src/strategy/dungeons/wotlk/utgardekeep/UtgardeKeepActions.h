#ifndef _SHADOW_WOTLKDUNGEONUKACTIONS_H
#define _SHADOW_WOTLKDUNGEONUKACTIONS_H

#include "Action.h"
#include "AttackAction.h"
#include "ShadowAI.h"
#include "Shadows.h"
#include "UtgardeKeepTriggers.h"

class AttackFrostTombAction : public AttackAction
{
public:
    AttackFrostTombAction(ShadowAI* ai) : AttackAction(ai, "attack frost tomb") {}
    bool Execute(Event event) override;
    bool isUseful() override;
};

class AttackDalronnAction : public AttackAction
{
public:
    AttackDalronnAction(ShadowAI* ai) : AttackAction(ai, "attack dalronn") {}
    bool Execute(Event event) override;
};

#endif