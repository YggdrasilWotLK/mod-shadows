/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#include "NamedObjectContext.h"
#include "Value.h"

class ShadowAI;

class GroupMembersValue : public ObjectGuidListCalculatedValue
{
public:
    GroupMembersValue(ShadowAI* botAI) : ObjectGuidListCalculatedValue(botAI, "group members", 2 * 1000) {}

    GuidVector Calculate() override;
};

class IsFollowingPartyValue : public BoolCalculatedValue
{
public:
    IsFollowingPartyValue(ShadowAI* botAI) : BoolCalculatedValue(botAI, "following party") {}

    bool Calculate() override;
};

class IsNearLeaderValue : public BoolCalculatedValue
{
public:
    IsNearLeaderValue(ShadowAI* botAI) : BoolCalculatedValue(botAI, "near leader") {}

    bool Calculate() override;
};

class BoolANDValue : public BoolCalculatedValue, public Qualified
{
public:
    BoolANDValue(ShadowAI* botAI) : BoolCalculatedValue(botAI, "bool and") {}

    bool Calculate() override;
};

class GroupBoolCountValue : public Uint32CalculatedValue, public Qualified
{
public:
    GroupBoolCountValue(ShadowAI* botAI) : Uint32CalculatedValue(botAI, "group count") {}

    uint32 Calculate() override;
};

class GroupBoolANDValue : public BoolCalculatedValue, public Qualified
{
public:
    GroupBoolANDValue(ShadowAI* botAI) : BoolCalculatedValue(botAI, "group bool and") {}

    bool Calculate() override;
};

class GroupBoolORValue : public BoolCalculatedValue, public Qualified
{
public:
    GroupBoolORValue(ShadowAI* botAI) : BoolCalculatedValue(botAI, "group bool or") {}

    bool Calculate() override;
};

class GroupReadyValue : public BoolCalculatedValue, public Qualified
{
public:
    GroupReadyValue(ShadowAI* botAI) : BoolCalculatedValue(botAI, "group ready", 2 * 2000) {}

    bool Calculate() override;
};
