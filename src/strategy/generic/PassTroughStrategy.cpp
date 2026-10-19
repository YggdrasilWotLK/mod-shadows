/*
 * Copyright (C) 2016+ YggdrasilCore <yggdrasilcore.github.io>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#include "PassTroughStrategy.h"

#include "Shadows.h"

void PassTroughStrategy::InitTriggers(std::vector<TriggerNode*>& triggers)
{
    for (std::vector<std::string>::iterator i = supported.begin(); i != supported.end(); i++)
        triggers.push_back(
            new TriggerNode(i->c_str(), NextAction::array(0, new NextAction(i->c_str(), relevance), nullptr)));
}
