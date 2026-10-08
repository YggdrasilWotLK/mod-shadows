/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_RANGETRIGGERS_H
#define _SHADOW_RANGETRIGGERS_H

#include "ShadowAIConfig.h"
#include "Trigger.h"

class ShadowAI;

class EnemyTooCloseForSpellTrigger : public Trigger
{
public:
    EnemyTooCloseForSpellTrigger(ShadowAI* botAI) : Trigger(botAI, "enemy too close for spell") {}

    bool IsActive() override;
};

class EnemyTooCloseForShootTrigger : public Trigger
{
public:
    EnemyTooCloseForShootTrigger(ShadowAI* botAI) : Trigger(botAI, "enemy too close for shoot") {}

    bool IsActive() override;
};

class EnemyTooCloseForAutoShotTrigger : public Trigger
{
public:
    EnemyTooCloseForAutoShotTrigger(ShadowAI* botAI) : Trigger(botAI, "enemy too close for auto shot") {}

    bool IsActive() override;
};

class EnemyTooCloseForMeleeTrigger : public Trigger
{
public:
    EnemyTooCloseForMeleeTrigger(ShadowAI* botAI) : Trigger(botAI, "enemy too close for melee", 5) {}

    bool IsActive() override;
};

class EnemyIsCloseTrigger : public Trigger
{
public:
    EnemyIsCloseTrigger(ShadowAI* botAI) : Trigger(botAI, "enemy is close") {}

    bool IsActive() override;
};

class EnemyWithinMeleeTrigger : public Trigger
{
public:
    EnemyWithinMeleeTrigger(ShadowAI* botAI) : Trigger(botAI, "enemy within melee") {}

    bool IsActive() override;
};

class OutOfRangeTrigger : public Trigger
{
public:
    OutOfRangeTrigger(ShadowAI* botAI, std::string const name, float distance)
        : Trigger(botAI, name), distance(distance)
    {
    }

    bool IsActive() override;
    std::string const GetTargetName() override { return "current target"; }

protected:
    float distance;
};

class EnemyOutOfMeleeTrigger : public OutOfRangeTrigger
{
public:
    EnemyOutOfMeleeTrigger(ShadowAI* botAI)
        : OutOfRangeTrigger(botAI, "enemy out of melee range", sShadowAIConfig->meleeDistance)
    {
    }

    // bool IsActive() override;
};

class EnemyOutOfSpellRangeTrigger : public OutOfRangeTrigger
{
public:
    EnemyOutOfSpellRangeTrigger(ShadowAI* botAI);
};

class PartyMemberToHealOutOfSpellRangeTrigger : public OutOfRangeTrigger
{
public:
    PartyMemberToHealOutOfSpellRangeTrigger(ShadowAI* botAI);

    bool IsActive() override;
    std::string const GetTargetName() override { return "party member to heal"; }
};

class FarFromMasterTrigger : public Trigger
{
public:
    FarFromMasterTrigger(ShadowAI* botAI, std::string const name = "far from master", float distance = 12.0f,
                         int32 checkInterval = 50)
        : Trigger(botAI, name, checkInterval), distance(distance)
    {
    }

    bool IsActive() override;

private:
    float distance;
};

class OutOfReactRangeTrigger : public FarFromMasterTrigger
{
public:
    OutOfReactRangeTrigger(ShadowAI* botAI) : FarFromMasterTrigger(botAI, "out of react range", 50.0f, 5) {}
};

class TooCloseToCreatureTrigger : public Trigger
{
public:
    TooCloseToCreatureTrigger(ShadowAI* ai) : Trigger(ai, "too close to creature trigger") {}

    bool TooCloseToCreature(uint32 creatureId, float range, bool alive = true);
};

class TooCloseToPlayerWithDebuffTrigger : public Trigger
{
public:
    TooCloseToPlayerWithDebuffTrigger(ShadowAI* ai) : Trigger(ai, "too cloose to player with debuff trigger") {}

    bool TooCloseToPlayerWithDebuff(uint32 spellId, float range);
};

class TooFarFromPlayerWithAuraTrigger : public Trigger
{
public:
    TooFarFromPlayerWithAuraTrigger(ShadowAI* ai) : Trigger(ai, "too far from player with aura trigger") {}

    bool TooFarFromPlayerWithAura(uint32 spellId, float range, bool selfInclude = false);
};

#endif
