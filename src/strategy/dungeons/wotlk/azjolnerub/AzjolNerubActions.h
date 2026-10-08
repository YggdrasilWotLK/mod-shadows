#ifndef _SHADOW_WOTLKDUNGEONANACTIONS_H
#define _SHADOW_WOTLKDUNGEONANACTIONS_H

#include "Action.h"
#include "AttackAction.h"
#include "ShadowAI.h"
#include "Shadows.h"
#include "AzjolNerubTriggers.h"

class AttackWebWrapAction : public AttackAction
{
public:
    AttackWebWrapAction(ShadowAI* ai) : AttackAction(ai, "attack web wrap") {}
    bool Execute(Event event) override;
    bool isUseful() override;
};

class WatchersTargetAction : public AttackAction
{
public:
    WatchersTargetAction(ShadowAI* ai) : AttackAction(ai, "krik'thir priority") {}
    bool Execute(Event event) override;
    bool isUseful() override;
};

class AnubarakDodgePoundAction : public AttackAction
{
public:
    AnubarakDodgePoundAction(ShadowAI* ai) : AttackAction(ai, "anub'arak dodge pound") {}
    bool Execute(Event event) override;
    bool isUseful() override;
};

#endif
