/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_DROPQUESTACTION_H
#define _SHADOW_DROPQUESTACTION_H

#include "Action.h"

class Player;
class ShadowAI;
class Quest;

class DropQuestAction : public Action
{
public:
    DropQuestAction(ShadowAI* botAI) : Action(botAI, "drop quest") {}

    bool Execute(Event event) override;
};

class CleanQuestLogAction : public Action
{
public:
    CleanQuestLogAction(ShadowAI* botAI) : Action(botAI, "clean quest log") {}

    bool Execute(Event event) override;
    void DropQuestType(uint8& numQuest, uint8 wantNum = 100, bool isGreen = false, bool hasProgress = false,
                       bool isComplete = false);

    static bool HasProgress(Player* bot, Quest const* quest);
};

#endif
