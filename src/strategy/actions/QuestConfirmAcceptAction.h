/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_QUESTCONFIRMACCEPTACTION_H
#define _SHADOW_QUESTCONFIRMACCEPTACTION_H

#include "AiObjectContext.h"
#include "Player.h"
#include "ShadowAI.h"
#include "QuestAction.h"

class ObjectGuid;
class Quest;
class Player;
class ShadowAI;
class WorldObject;

class QuestConfirmAcceptAction : public Action
{
public:
    QuestConfirmAcceptAction(ShadowAI* botAI) : Action(botAI, "quest confirm accept") {}
    bool Execute(Event event) override;
};

#endif