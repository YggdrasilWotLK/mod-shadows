/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_STATSVALUE_H
#define _SHADOW_STATSVALUE_H

#include "NamedObjectContext.h"
#include "Value.h"

class ShadowAI;
class Unit;

class HealthValue : public Uint8CalculatedValue, public Qualified
{
public:
    HealthValue(ShadowAI* botAI, std::string const name = "health") : Uint8CalculatedValue(botAI, name) {}

    Unit* GetTarget();
    uint8 Calculate() override;
};

class IsDeadValue : public BoolCalculatedValue, public Qualified
{
public:
    IsDeadValue(ShadowAI* botAI, std::string const name = "dead") : BoolCalculatedValue(botAI, name) {}

    Unit* GetTarget();
    bool Calculate() override;
};

class PetIsDeadValue : public BoolCalculatedValue
{
public:
    PetIsDeadValue(ShadowAI* botAI, std::string const name = "pet dead") : BoolCalculatedValue(botAI, name) {}

    bool Calculate() override;
};

class PetIsHappyValue : public BoolCalculatedValue
{
public:
    PetIsHappyValue(ShadowAI* botAI, std::string const name = "pet happy") : BoolCalculatedValue(botAI, name) {}

    bool Calculate() override;
};

class RageValue : public Uint8CalculatedValue, public Qualified
{
public:
    RageValue(ShadowAI* botAI, std::string const name = "rage") : Uint8CalculatedValue(botAI, name) {}

    Unit* GetTarget();
    uint8 Calculate() override;
};

class EnergyValue : public Uint8CalculatedValue, public Qualified
{
public:
    EnergyValue(ShadowAI* botAI, std::string const name = "energy") : Uint8CalculatedValue(botAI, name) {}

    Unit* GetTarget();
    uint8 Calculate() override;
};

class ManaValue : public Uint8CalculatedValue, public Qualified
{
public:
    ManaValue(ShadowAI* botAI, std::string const name = "mana") : Uint8CalculatedValue(botAI, name) {}

    Unit* GetTarget();
    uint8 Calculate() override;
};

class HasManaValue : public BoolCalculatedValue, public Qualified
{
public:
    HasManaValue(ShadowAI* botAI, std::string const name = "has mana") : BoolCalculatedValue(botAI, name, 2 * 1000)
    {
    }

    Unit* GetTarget();
    bool Calculate() override;
};

class ComboPointsValue : public Uint8CalculatedValue, public Qualified
{
public:
    ComboPointsValue(ShadowAI* botAI, std::string const name = "combo points") : Uint8CalculatedValue(botAI, name) {}

    Unit* GetTarget();
    uint8 Calculate() override;
};

class IsMountedValue : public BoolCalculatedValue, public Qualified
{
public:
    IsMountedValue(ShadowAI* botAI, std::string const name = "mounted") : BoolCalculatedValue(botAI, name) {}

    Unit* GetTarget();
    bool Calculate() override;
};

class IsInCombatValue : public MemoryCalculatedValue<bool>, public Qualified
{
public:
    IsInCombatValue(ShadowAI* botAI, std::string const name = "combat") : MemoryCalculatedValue(botAI, name) {}

    Unit* GetTarget();
    bool Calculate() override;
    bool EqualToLast(bool value) override;
};

class BagSpaceValue : public Uint8CalculatedValue
{
public:
    BagSpaceValue(ShadowAI* botAI, std::string const name = "bag space") : Uint8CalculatedValue(botAI, name) {}

    uint8 Calculate() override;
};

class DurabilityValue : public Uint8CalculatedValue
{
public:
    DurabilityValue(ShadowAI* botAI, std::string const name = "durability") : Uint8CalculatedValue(botAI, name) {}

    uint8 Calculate() override;
};

class SpeedValue : public Uint8CalculatedValue, public Qualified
{
public:
    SpeedValue(ShadowAI* botAI, std::string const name = "speed") : Uint8CalculatedValue(botAI, name) {}

    Unit* GetTarget();
    uint8 Calculate() override;
};

class IsInGroupValue : public BoolCalculatedValue
{
public:
    IsInGroupValue(ShadowAI* botAI, std::string const name = "in group") : BoolCalculatedValue(botAI, name) {}

    bool Calculate() override;
};

class DeathCountValue : public ManualSetValue<uint32>
{
public:
    DeathCountValue(ShadowAI* botAI, std::string const name = "death count") : ManualSetValue<uint32>(botAI, 0, name)
    {
    }
};

class ExperienceValue : public MemoryCalculatedValue<uint32>
{
public:
    ExperienceValue(ShadowAI* botAI, std::string const name = "experience", uint32 checkInterval = 60)
        : MemoryCalculatedValue<uint32>(botAI, name, checkInterval)
    {
    }

    bool EqualToLast(uint32 value) override;
    uint32 Calculate() override;
};

#endif
