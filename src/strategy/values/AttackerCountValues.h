/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_ATTACKERCOUNTVALUES_H
#define _SHADOW_ATTACKERCOUNTVALUES_H

#include "NamedObjectContext.h"
#include "Value.h"

class ShadowAI;
class Unit;

class AttackerCountValue : public Uint8CalculatedValue, public Qualified
{
public:
    AttackerCountValue(ShadowAI* botAI, std::string const name = "attackers count")
        : Uint8CalculatedValue(botAI, name)
    {
    }

    Unit* GetTarget();
    uint8 Calculate() override;
};

class MyAttackerCountValue : public Uint8CalculatedValue, public Qualified
{
public:
    MyAttackerCountValue(ShadowAI* botAI, std::string const name = "my attackers count")
        : Uint8CalculatedValue(botAI, name)
    {
    }

    Unit* GetTarget();
    uint8 Calculate() override;
};

class HasAggroValue : public BoolCalculatedValue, public Qualified
{
public:
    HasAggroValue(ShadowAI* botAI, std::string const name = "has aggro") : BoolCalculatedValue(botAI, name) {}

    Unit* GetTarget();
    bool Calculate() override;
};

class BalancePercentValue : public Uint8CalculatedValue, public Qualified
{
public:
    BalancePercentValue(ShadowAI* botAI, std::string const name = "balance percentage")
        : Uint8CalculatedValue(botAI, name)
    {
    }

    Unit* GetTarget();
    uint8 Calculate() override;
};

#endif
