/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_LFGVALUES_H
#define _SHADOW_LFGVALUES_H

#include "Value.h"

class ShadowAI;

class LfgProposalValue : public ManualSetValue<uint32>
{
public:
    LfgProposalValue(ShadowAI* botAI) : ManualSetValue<uint32>(botAI, 0, "lfg proposal") {}
};

#endif
