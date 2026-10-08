/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_PARTYMEMBERTOHEAL_H
#define _SHADOW_PARTYMEMBERTOHEAL_H

#include "PartyMemberValue.h"

class Pet;
class ShadowAI;
class Unit;

class PartyMemberToHeal : public PartyMemberValue
{
public:
    PartyMemberToHeal(ShadowAI* botAI, std::string const name = "party member to heal")
        : PartyMemberValue(botAI, name)
    {
    }

protected:
    Unit* Calculate() override;
    bool Check(Unit* player) override;
};

class PartyMemberToProtect : public PartyMemberValue
{
public:
    PartyMemberToProtect(ShadowAI* botAI, std::string const name = "party member to protect")
        : PartyMemberValue(botAI, name)
    {
    }

protected:
    Unit* Calculate() override;
};

#endif
