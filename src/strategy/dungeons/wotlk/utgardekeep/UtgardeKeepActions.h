#ifndef _PLAYERBOT_WOTLKDUNGEONUKACTIONS_H
#define _PLAYERBOT_WOTLKDUNGEONUKACTIONS_H

#include "Action.h"
#include "AttackAction.h"
#include "PlayerbotAI.h"
#include "Playerbots.h"
#include "UtgardeKeepTriggers.h"

class AttackFrostTombAction : public AttackAction
{
public:
    AttackFrostTombAction(PlayerbotAI* ai) : AttackAction(ai, "attack frost tomb") {}
    bool Execute(Event event) override;
    bool isUseful() override;
};

class AttackDalronnAction : public AttackAction
{
public:
    AttackDalronnAction(PlayerbotAI* ai) : AttackAction(ai, "attack dalronn") {}
    bool Execute(Event event) override;
};

#endif