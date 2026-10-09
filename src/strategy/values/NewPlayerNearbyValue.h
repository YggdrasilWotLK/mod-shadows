/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_NEWPLAYERNEARBYVALUE_H
#define _SHADOW_NEWPLAYERNEARBYVALUE_H

#include "ObjectGuid.h"
#include "Value.h"

class ShadowAI;

class NewPlayerNearbyValue : public CalculatedValue<ObjectGuid>
{
public:
    NewPlayerNearbyValue(ShadowAI* botAI) : CalculatedValue<ObjectGuid>(botAI, "new player nearby") {}

    ObjectGuid Calculate() override;
};

class AlreadySeenPlayersValue : public ManualSetValue<GuidSet&>
{
public:
    AlreadySeenPlayersValue(ShadowAI* botAI) : ManualSetValue<GuidSet&>(botAI, data, "already seen players") {}

    GuidSet data;
};

#endif
