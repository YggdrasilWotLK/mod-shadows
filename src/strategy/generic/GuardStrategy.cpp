/*
 * Copyright (C) 2016+ YggdrasilCore <yggdrasilcore.github.io>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#include "GuardStrategy.h"

#include "Shadows.h"

NextAction** GuardStrategy::getDefaultActions() { return NextAction::array(0, new NextAction("guard", 4.0f), nullptr); }

void GuardStrategy::InitTriggers(std::vector<TriggerNode*>& triggers [[maybe_unused]]) {}
