/*
 * Copyright (C) 2016+ YggdrasilCore <yggdrasilcore.github.io>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#include "RogueOpeningActions.h"

#include "Shadows.h"

Value<Unit*>* CastSapAction::GetTargetValue() { return context->GetValue<Unit*>("cc target", getName()); }
