/*
 * Copyright (C) 2016+ YggdrasilCore <yggdrasilcore.github.io>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#include "TellMasterAction.h"

#include "Event.h"
#include "Shadows.h"

bool TellMasterAction::Execute(Event event [[maybe_unused]])
{
    botAI->TellMaster(text);
    return true;
}

bool OutOfReactRangeAction::Execute(Event event [[maybe_unused]])
{
    botAI->TellMaster("Wait for me!");
    return true;
}

bool OutOfReactRangeAction::isUseful()
{
    bool canFollow = Follow(AI_VALUE(Unit*, "master target"));
    if (!canFollow)
    {
        return false;
    }

    return true;
}
