/*
 * Copyright (C) 2016+ YggdrasilCore <yggdrasilcore.github.io>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#include "MasterTargetValue.h"

#include "Shadows.h"

Unit* MasterTargetValue::Calculate() { return botAI->GetGroupMaster(); }
