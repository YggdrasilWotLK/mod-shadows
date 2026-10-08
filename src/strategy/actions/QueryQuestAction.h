/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_QUERYQUESTACTION_H
#define _SHADOW_QUERYQUESTACTION_H

#include "Action.h"

class ShadowAI;

class QueryQuestAction : public Action
{
public:
    QueryQuestAction(ShadowAI* botAI) : Action(botAI, "query quest") {}

    bool Execute(Event event) override;

private:
    void TellObjectives(uint32 questId);
    void TellObjective(std::string const name, uint32 available, uint32 required);
};

#endif
