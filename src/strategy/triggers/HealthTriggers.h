/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_HEALTHTRIGGERS_H
#define _SHADOW_HEALTHTRIGGERS_H

#include <stdexcept>

#include "ShadowAIConfig.h"
#include "Trigger.h"

class ShadowAI;

class ValueInRangeTrigger : public Trigger
{
public:
    ValueInRangeTrigger(ShadowAI* botAI, std::string const name, float maxValue, float minValue)
        : Trigger(botAI, name), maxValue(maxValue), minValue(minValue)
    {
    }

    virtual float GetValue() = 0;
    bool IsActive() override
    {
        float value = GetValue();
        return value < maxValue && value >= minValue;
    }

protected:
    float maxValue, minValue;
};

class HealthInRangeTrigger : public ValueInRangeTrigger
{
public:
    HealthInRangeTrigger(ShadowAI* botAI, std::string const name, float maxValue, float minValue = 0)
        : ValueInRangeTrigger(botAI, name, maxValue, minValue)
    {
    }

    bool IsActive() override;
    float GetValue() override;
};

class LowHealthTrigger : public HealthInRangeTrigger
{
public:
    LowHealthTrigger(ShadowAI* botAI, std::string const name = "low health",
                     float value = sShadowAIConfig->lowHealth, float minValue = 0)
        : HealthInRangeTrigger(botAI, name, value, minValue)
    {
    }

    std::string const GetTargetName() override { return "self target"; }
};

class CriticalHealthTrigger : public LowHealthTrigger
{
public:
    CriticalHealthTrigger(ShadowAI* botAI)
        : LowHealthTrigger(botAI, "critical health", sShadowAIConfig->criticalHealth, 0)
    {
    }
};

class MediumHealthTrigger : public LowHealthTrigger
{
public:
    MediumHealthTrigger(ShadowAI* botAI)
        : LowHealthTrigger(botAI, "medium health", sShadowAIConfig->mediumHealth, 0)
    {
    }
};

class AlmostFullHealthTrigger : public LowHealthTrigger
{
public:
    AlmostFullHealthTrigger(ShadowAI* botAI)
        : LowHealthTrigger(botAI, "almost full health", sShadowAIConfig->almostFullHealth,
                           sShadowAIConfig->mediumHealth)
    {
    }
};

class PartyMemberLowHealthTrigger : public HealthInRangeTrigger
{
public:
    PartyMemberLowHealthTrigger(ShadowAI* botAI, std::string const name = "party member low health",
                                float value = sShadowAIConfig->lowHealth,
                                float minValue = 0)
        : HealthInRangeTrigger(botAI, name, value, minValue)
    {
    }

    std::string const GetTargetName() override { return "party member to heal"; }
};

class PartyMemberCriticalHealthTrigger : public PartyMemberLowHealthTrigger
{
public:
    PartyMemberCriticalHealthTrigger(ShadowAI* botAI)
        : PartyMemberLowHealthTrigger(botAI, "party member critical health", sShadowAIConfig->criticalHealth, 0)
    {
    }
};

class PartyMemberMediumHealthTrigger : public PartyMemberLowHealthTrigger
{
public:
    PartyMemberMediumHealthTrigger(ShadowAI* botAI)
        : PartyMemberLowHealthTrigger(botAI, "party member medium health", sShadowAIConfig->mediumHealth,
                                      0)
    {
    }
};

class PartyMemberAlmostFullHealthTrigger : public PartyMemberLowHealthTrigger
{
public:
    PartyMemberAlmostFullHealthTrigger(ShadowAI* botAI)
        : PartyMemberLowHealthTrigger(botAI, "party member almost full health", sShadowAIConfig->almostFullHealth,
                                      0)
    {
    }
};

class TargetLowHealthTrigger : public HealthInRangeTrigger
{
public:
    TargetLowHealthTrigger(ShadowAI* botAI, float value, float minValue = 0)
        : HealthInRangeTrigger(botAI, "target low health", value, minValue)
    {
    }

    std::string const GetTargetName() override { return "current target"; }
};

class TargetCriticalHealthTrigger : public TargetLowHealthTrigger
{
public:
    TargetCriticalHealthTrigger(ShadowAI* botAI) : TargetLowHealthTrigger(botAI, 20) {}
};

class PartyMemberDeadTrigger : public Trigger
{
public:
    PartyMemberDeadTrigger(ShadowAI* botAI) : Trigger(botAI, "resurrect", 1 * 1000) {}

    std::string const GetTargetName() override { return "party member to resurrect"; }
    bool IsActive() override;
};

class CombatPartyMemberDeadTrigger : public Trigger
{
public:
    CombatPartyMemberDeadTrigger(ShadowAI* ai) : Trigger(ai, "combat party member to resurrect", 1) {}
    std::string const GetTargetName() override { return "party member to resurrect"; }
    bool IsActive() override;
};

class DeadTrigger : public Trigger
{
public:
    DeadTrigger(ShadowAI* botAI) : Trigger(botAI, "dead") {}

    std::string const GetTargetName() override { return "self target"; }
    bool IsActive() override;
};

class AoeHealTrigger : public Trigger
{
public:
    AoeHealTrigger(ShadowAI* botAI, std::string const name, std::string const type, int32 count)
        : Trigger(botAI, name), count(count), type(type)
    {
    }  // reorder args - whipowill
    bool IsActive() override;

protected:
    int32 count;
    std::string const type;
};

class AoeInGroupTrigger : public Trigger
{
public:
    AoeInGroupTrigger(ShadowAI* ai, std::string name, std::string type)
        : Trigger(ai, name), type(type)
    {
    }
    bool IsActive() override;

protected:
    std::string type;
};

#endif
