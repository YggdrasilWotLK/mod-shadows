/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_CURETRIGGERS_H
#define _SHADOW_CURETRIGGERS_H

#include "GenericTriggers.h"

class ShadowAI;
class Unit;

class NeedCureTrigger : public SpellTrigger
{
public:
    NeedCureTrigger(ShadowAI* botAI, std::string const spell, uint32 dispelType)
        : SpellTrigger(botAI, spell, 1 * 1000), dispelType(dispelType)
    {
    }

    std::string const GetTargetName() override { return "self target"; }
    bool IsActive() override;

protected:
    uint32 dispelType;
};

class TargetAuraDispelTrigger : public NeedCureTrigger
{
public:
    TargetAuraDispelTrigger(ShadowAI* botAI, std::string const spell, uint32 dispelType)
        : NeedCureTrigger(botAI, spell, dispelType)
    {
    }

    std::string const GetTargetName() override { return "current target"; }
};

class PartyMemberNeedCureTrigger : public NeedCureTrigger
{
public:
    PartyMemberNeedCureTrigger(ShadowAI* botAI, std::string const spell, uint32 dispelType)
        : NeedCureTrigger(botAI, spell, dispelType)
    {
    }

    Value<Unit*>* GetTargetValue() override;
    bool IsActive() override;
};

class NeedWorldBuffTrigger : public Trigger
{
public:
    NeedWorldBuffTrigger(ShadowAI* botAI) : Trigger(botAI) {}

    bool IsActive() override;
};

#endif
