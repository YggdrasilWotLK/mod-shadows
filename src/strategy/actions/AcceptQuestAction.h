/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_ACCEPTQUESTACTION_H
#define _SHADOW_ACCEPTQUESTACTION_H

#include "QuestAction.h"

class Quest;
class ShadowAI;
class WorldObject;

class AcceptAllQuestsAction : public QuestAction
{
public:
    AcceptAllQuestsAction(ShadowAI* botAI, std::string const name = "accept all quests") : QuestAction(botAI, name)
    {
    }

protected:
    bool ProcessQuest(Quest const* quest, Object* questGiver) override;
};

class AcceptQuestAction : public AcceptAllQuestsAction
{
public:
    AcceptQuestAction(ShadowAI* botAI) : AcceptAllQuestsAction(botAI, "accept quest") {}
    bool Execute(Event event) override;
};

class AcceptQuestShareAction : public Action
{
public:
    AcceptQuestShareAction(ShadowAI* botAI) : Action(botAI, "accept quest share") {}
    bool Execute(Event event) override;
};

class ConfirmQuestAction : public Action {
public:
    ConfirmQuestAction(ShadowAI* ai) : Action(ai, "confirm quest") {}
    bool Execute(Event event);
};

#endif
