#ifndef _PLAYERBOT_WOTLKDUNGEONANACTIONS_H
#define _PLAYERBOT_WOTLKDUNGEONANACTIONS_H

#include "Action.h"
#include "AttackAction.h"
#include "PlayerbotAI.h"
#include "Playerbots.h"
#include "AzjolNerubTriggers.h"
#include "MovementActions.h"

const Position AN_WATCHER_STACK_POSITION = Position(570.0f, 682.3f, 769.3f);

class AttackWebWrapAction : public AttackAction
{
public:
    AttackWebWrapAction(PlayerbotAI* ai) : AttackAction(ai, "attack web wrap") {}
    bool Execute(Event event) override;
    bool isUseful() override;
};

class WatchersTargetAction : public AttackAction
{
public:
    WatchersTargetAction(PlayerbotAI* ai) : AttackAction(ai, "krik'thir priority") {}
    bool Execute(Event event) override;
    bool isUseful() override;
};

#endif
class WatchersTankPositionAction : public AttackAction
{
public:
    WatchersTankPositionAction(PlayerbotAI* ai) : AttackAction(ai, "watchers tank position") {}
    bool Execute(Event event) override;
};

class WatchersGroupStackAction : public MovementAction
{
public:
    WatchersGroupStackAction(PlayerbotAI* ai) : MovementAction(ai, "watchers group stack") {}
    bool Execute(Event event) override;
};

class AnubarakDodgePoundAction : public AttackAction
{
public:
    AnubarakDodgePoundAction(PlayerbotAI* ai) : AttackAction(ai, "anub'arak dodge pound") {}
    bool Execute(Event event) override;
    bool isUseful() override;
};

