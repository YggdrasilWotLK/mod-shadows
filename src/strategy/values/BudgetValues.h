/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_BUDGETVALUES_H
#define _SHADOW_BUDGETVALUES_H

#include "NamedObjectContext.h"
#include "Value.h"

class ShadowAI;

enum class NeedMoneyFor : uint32
{
    none = 0,
    repair = 1,
    ammo = 2,
    spells = 3,
    travel = 4,
    consumables = 5,
    gear = 6,
    guild = 7,
    tradeskill = 8,
    anything = 9
};

class MaxGearRepairCostValue : public Uint32CalculatedValue
{
public:
    MaxGearRepairCostValue(ShadowAI* botAI) : Uint32CalculatedValue(botAI, "max repair cost", 60) {}

    uint32 Calculate() override;
};

class RepairCostValue : public Uint32CalculatedValue
{
public:
    RepairCostValue(ShadowAI* botAI) : Uint32CalculatedValue(botAI, "repair cost", 60) {}

    uint32 Calculate() override;
};

class TrainCostValue : public Uint32CalculatedValue
{
public:
    TrainCostValue(ShadowAI* botAI) : Uint32CalculatedValue(botAI, "train cost", 60) {}

    uint32 Calculate() override;
};

class MoneyNeededForValue : public Uint32CalculatedValue, public Qualified
{
public:
    MoneyNeededForValue(ShadowAI* botAI) : Uint32CalculatedValue(botAI, "money needed for", 60) {}

    uint32 Calculate() override;
};

class TotalMoneyNeededForValue : public Uint32CalculatedValue, public Qualified
{
public:
    TotalMoneyNeededForValue(ShadowAI* botAI) : Uint32CalculatedValue(botAI, "total money needed for", 60) {}

    uint32 Calculate() override;

private:
    std::vector<NeedMoneyFor> saveMoneyFor = {NeedMoneyFor::guild, NeedMoneyFor::repair, NeedMoneyFor::ammo,
                                              NeedMoneyFor::spells, NeedMoneyFor::travel};
};

class FreeMoneyForValue : public Uint32CalculatedValue, public Qualified
{
public:
    FreeMoneyForValue(ShadowAI* botAI) : Uint32CalculatedValue(botAI, "free money for") {}

    uint32 Calculate() override;
};

class ShouldGetMoneyValue : public BoolCalculatedValue
{
public:
    ShouldGetMoneyValue(ShadowAI* botAI) : BoolCalculatedValue(botAI, "should get money", 2) {}

    bool Calculate() override;
};

#endif
