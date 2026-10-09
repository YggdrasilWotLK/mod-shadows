/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_GENERICTRIGGERS_H
#define _SHADOW_GENERICTRIGGERS_H

#include <utility>

#include "HealthTriggers.h"
#include "RangeTriggers.h"
#include "Trigger.h"
#include "Player.h"

class ShadowAI;
class Unit;

class StatAvailable : public Trigger
{
public:
    StatAvailable(ShadowAI* botAI, int32 amount, std::string const name = "stat available")
        : Trigger(botAI, name), amount(amount)
    {
    }

protected:
    int32 amount;
};

class HighManaTrigger : public Trigger
{
public:
    HighManaTrigger(ShadowAI* botAI) : Trigger(botAI, "high mana") {}

    bool IsActive() override;
};

class EnoughManaTrigger : public Trigger
{
public:
    EnoughManaTrigger(ShadowAI* botAI) : Trigger(botAI, "enough mana") {}

    bool IsActive() override;
};

class AlmostFullManaTrigger : public Trigger
{
public:
    AlmostFullManaTrigger(ShadowAI* botAI) : Trigger(botAI, "almost full mana") {}

    bool IsActive() override;
};

class RageAvailable : public StatAvailable
{
public:
    RageAvailable(ShadowAI* botAI, int32 amount) : StatAvailable(botAI, amount, "rage available") {}

    bool IsActive() override;
};

class LightRageAvailableTrigger : public RageAvailable
{
public:
    LightRageAvailableTrigger(ShadowAI* botAI) : RageAvailable(botAI, 20) {}
};

class MediumRageAvailableTrigger : public RageAvailable
{
public:
    MediumRageAvailableTrigger(ShadowAI* botAI) : RageAvailable(botAI, 40) {}
};

class HighRageAvailableTrigger : public RageAvailable
{
public:
    HighRageAvailableTrigger(ShadowAI* botAI) : RageAvailable(botAI, 60) {}
};

class EnergyAvailable : public StatAvailable
{
public:
    EnergyAvailable(ShadowAI* botAI, int32 amount) : StatAvailable(botAI, amount, "energy available") {}

    bool IsActive() override;
};

class LightEnergyAvailableTrigger : public EnergyAvailable
{
public:
    LightEnergyAvailableTrigger(ShadowAI* botAI) : EnergyAvailable(botAI, 20) {}
};

class MediumEnergyAvailableTrigger : public EnergyAvailable
{
public:
    MediumEnergyAvailableTrigger(ShadowAI* botAI) : EnergyAvailable(botAI, 40) {}
};

class HighEnergyAvailableTrigger : public EnergyAvailable
{
public:
    HighEnergyAvailableTrigger(ShadowAI* botAI) : EnergyAvailable(botAI, 60) {}
};

class ComboPointsAvailableTrigger : public StatAvailable
{
public:
    ComboPointsAvailableTrigger(ShadowAI* botAI, int32 amount = 5)
        : StatAvailable(botAI, amount, "combo points available")
    {
    }

    bool IsActive() override;
};

class TargetWithComboPointsLowerHealTrigger : public ComboPointsAvailableTrigger
{
public:
    TargetWithComboPointsLowerHealTrigger(ShadowAI* ai, int32 combo_point = 5, float lifeTime = 8.0f)
        : ComboPointsAvailableTrigger(ai, combo_point), lifeTime(lifeTime)
    {
    }
    bool IsActive() override;

private:
    float lifeTime;
};

class ComboPointsNotFullTrigger : public StatAvailable
{
public:
    ComboPointsNotFullTrigger(ShadowAI* botAI, int32 amount = 5, std::string const name = "combo points not full")
        : StatAvailable(botAI, amount, name)
    {
    }

    bool IsActive() override;
};

class LoseAggroTrigger : public Trigger
{
public:
    LoseAggroTrigger(ShadowAI* botAI) : Trigger(botAI, "lose aggro") {}

    bool IsActive() override;
};

class HasAggroTrigger : public Trigger
{
public:
    HasAggroTrigger(ShadowAI* botAI) : Trigger(botAI, "have aggro") {}

    bool IsActive() override;
};

class SpellTrigger : public Trigger
{
public:
    SpellTrigger(ShadowAI* botAI, std::string const spell, int32 checkInterval = 1)
        : Trigger(botAI, spell, checkInterval), spell(spell)
    {
    }

    std::string const GetTargetName() override { return "current target"; }
    std::string const getName() override { return spell; }
    bool IsActive() override;

protected:
    std::string spell;
};

class SpellCanBeCastTrigger : public SpellTrigger
{
public:
    SpellCanBeCastTrigger(ShadowAI* botAI, std::string const spell) : SpellTrigger(botAI, spell) {}

    bool IsActive() override;
};

class SpellNoCooldownTrigger : public SpellTrigger
{
public:
    SpellNoCooldownTrigger(ShadowAI* botAI, std::string const spell) : SpellTrigger(botAI, spell) {}

    bool IsActive() override;
};

class SpellCooldownTrigger : public SpellTrigger
{
public:
    SpellCooldownTrigger(ShadowAI* botAI, std::string const spell) : SpellTrigger(botAI, spell) {}

    std::string const GetTargetName() override { return "self target"; }
    bool IsActive() override;
};

// TODO: check other targets
class InterruptSpellTrigger : public SpellTrigger
{
public:
    InterruptSpellTrigger(ShadowAI* botAI, std::string const spell) : SpellTrigger(botAI, spell) {}

    bool IsActive() override;
};

class DeflectSpellTrigger : public SpellTrigger
{
public:
    DeflectSpellTrigger(ShadowAI* botAI, std::string const spell) : SpellTrigger(botAI, spell) {}

    bool IsActive() override;
};

class AttackerCountTrigger : public Trigger
{
public:
    AttackerCountTrigger(ShadowAI* botAI, int32 amount, float distance = sShadowAIConfig->sightDistance)
        : Trigger(botAI), amount(amount), distance(distance)
    {
    }

    bool IsActive() override;
    std::string const getName() override { return "attacker count"; }

protected:
    int32 amount;
    float distance;
};

class HasAttackersTrigger : public AttackerCountTrigger
{
public:
    HasAttackersTrigger(ShadowAI* botAI) : AttackerCountTrigger(botAI, 1) {}
};

class MyAttackerCountTrigger : public AttackerCountTrigger
{
public:
    MyAttackerCountTrigger(ShadowAI* botAI, int32 amount) : AttackerCountTrigger(botAI, amount) {}

    bool IsActive() override;
    std::string const getName() override { return "my attacker count"; }
};

class BeingAttackedTrigger : public MyAttackerCountTrigger
{
public:
    BeingAttackedTrigger(ShadowAI* botAI) : MyAttackerCountTrigger(botAI, 1) {}
    std::string const getName() override { return "being attacked"; }
};

class MediumThreatTrigger : public MyAttackerCountTrigger
{
public:
    MediumThreatTrigger(ShadowAI* botAI) : MyAttackerCountTrigger(botAI, 2) {}
    bool IsActive() override;
};

class LowTankThreatTrigger : public Trigger
{
public:
    LowTankThreatTrigger(ShadowAI* botAI) : Trigger(botAI, "low tank threat") {}
    bool IsActive() override;
};

class AoeTrigger : public AttackerCountTrigger
{
public:
    AoeTrigger(ShadowAI* botAI, int32 amount = 3, float range = 15.0f)
        : AttackerCountTrigger(botAI, amount), range(range)
    {
    }

    bool IsActive() override;
    std::string const getName() override { return "aoe"; }

private:
    float range;
};

class NoFoodTrigger : public Trigger
{
public:
    NoFoodTrigger(ShadowAI* botAI) : Trigger(botAI, "no food trigger") {}

    bool IsActive() override;
};

class NoDrinkTrigger : public Trigger
{
public:
    NoDrinkTrigger(ShadowAI* botAI) : Trigger(botAI, "no drink trigger") {}

    bool IsActive() override;
};

class LightAoeTrigger : public AoeTrigger
{
public:
    LightAoeTrigger(ShadowAI* botAI) : AoeTrigger(botAI, 2, 8.0f) {}
};

class MediumAoeTrigger : public AoeTrigger
{
public:
    MediumAoeTrigger(ShadowAI* botAI) : AoeTrigger(botAI, 3, 8.0f) {}
};

class HighAoeTrigger : public AoeTrigger
{
public:
    HighAoeTrigger(ShadowAI* botAI) : AoeTrigger(botAI, 4, 8.0f) {}
};

class BuffTrigger : public SpellTrigger
{
public:
    BuffTrigger(ShadowAI* botAI, std::string const spell, int32 checkInterval = 1, bool checkIsOwner = false, bool checkDuration = false, uint32 beforeDuration = 0)
        : SpellTrigger(botAI, spell, checkInterval)
    {
        this->checkIsOwner = checkIsOwner;
        this->checkDuration = checkDuration;
        this->beforeDuration = beforeDuration;
    }

public:
    std::string const GetTargetName() override { return "self target"; }
    bool IsActive() override;

protected:
    bool checkIsOwner;
    bool checkDuration;
    uint32 beforeDuration;
};

class BuffOnPartyTrigger : public BuffTrigger
{
public:
    BuffOnPartyTrigger(ShadowAI* botAI, std::string const spell, int32 checkInterval = 1)
        : BuffTrigger(botAI, spell, checkInterval)
    {
    }

    Value<Unit*>* GetTargetValue() override;
    std::string const getName() override { return spell + " on party"; }
};

class ProtectPartyMemberTrigger : public Trigger
{
public:
    ProtectPartyMemberTrigger(ShadowAI* botAI) : Trigger(botAI, "protect party member") {}

    std::string const GetTargetName() override { return "party member to protect"; }
    bool IsActive() override;
};

class NoAttackersTrigger : public Trigger
{
public:
    NoAttackersTrigger(ShadowAI* botAI) : Trigger(botAI, "no attackers") {}

    bool IsActive() override;
};

class NoTargetTrigger : public Trigger
{
public:
    NoTargetTrigger(ShadowAI* botAI) : Trigger(botAI, "no target") {}

    bool IsActive() override;
};

class InvalidTargetTrigger : public Trigger
{
public:
    InvalidTargetTrigger(ShadowAI* botAI) : Trigger(botAI, "invalid target") {}

    bool IsActive() override;
};

class TargetInSightTrigger : public Trigger
{
public:
    TargetInSightTrigger(ShadowAI* botAI) : Trigger(botAI, "target in sight") {}

    bool IsActive() override;
};

class DebuffTrigger : public BuffTrigger
{
public:
    DebuffTrigger(ShadowAI* botAI, std::string const spell, int32 checkInterval = 1, bool checkIsOwner = false,
                  float needLifeTime = 8.0f, uint32 beforeDuration = 0)
        : BuffTrigger(botAI, spell, checkInterval, checkIsOwner, false, beforeDuration), needLifeTime(needLifeTime)
    {
    }

    std::string const GetTargetName() override { return "current target"; }
    bool IsActive() override;

protected:
    float needLifeTime;
};

class DebuffOnBossTrigger : public DebuffTrigger
{
public:
    DebuffOnBossTrigger(ShadowAI* botAI, std::string const spell, int32 checkInterval = 1, bool checkIsOwner = false)
        : DebuffTrigger(botAI, spell, checkInterval, checkIsOwner)
    {
    }
    bool IsActive() override;
};

class DebuffOnAttackerTrigger : public DebuffTrigger
{
public:
    DebuffOnAttackerTrigger(ShadowAI* botAI, std::string const spell, bool checkIsOwner = true,
                            float needLifeTime = 8.0f)
        : DebuffTrigger(botAI, spell, 1, checkIsOwner, needLifeTime)
    {
    }

    Value<Unit*>* GetTargetValue() override;
    std::string const getName() override { return spell + " on attacker"; }
};

class DebuffOnMeleeAttackerTrigger : public DebuffTrigger
{
public:
    DebuffOnMeleeAttackerTrigger(ShadowAI* botAI, std::string const spell, bool checkIsOwner = true,
                                 float needLifeTime = 8.0f)
        : DebuffTrigger(botAI, spell, 1, checkIsOwner, needLifeTime)
    {
    }

    Value<Unit*>* GetTargetValue() override;
    std::string const getName() override { return spell + " on attacker"; }
};

class BoostTrigger : public BuffTrigger
{
public:
    BoostTrigger(ShadowAI* botAI, std::string const spell, float balance = 50.f)
        : BuffTrigger(botAI, spell, 1), balance(balance)
    {
    }

    bool IsActive() override;

protected:
    float balance;
};

class GenericBoostTrigger : public Trigger
{
public:
    GenericBoostTrigger(ShadowAI* botAI, float balance = 50.f)
        : Trigger(botAI, "generic boost", 1), balance(balance)
    {
    }

    bool IsActive() override;

protected:
    float balance;
};

class HealerShouldAttackTrigger : public Trigger
{
public:
    HealerShouldAttackTrigger(ShadowAI* botAI)
        : Trigger(botAI, "healer should attack", 1)
    {
    }

    bool IsActive() override;
};

class RandomTrigger : public Trigger
{
public:
    RandomTrigger(ShadowAI* botAI, std::string const name, int32 probability = 7);

    bool IsActive() override;

protected:
    int32 probability;
    uint32 lastCheck;
};

class AndTrigger : public Trigger
{
public:
    AndTrigger(ShadowAI* botAI, Trigger* ls, Trigger* rs) : Trigger(botAI), ls(ls), rs(rs) {}
    virtual ~AndTrigger()
    {
        delete ls;
        delete rs;
    }

    bool IsActive() override;
    std::string const getName() override;

protected:
    Trigger* ls;
    Trigger* rs;
};

class TwoTriggers : public Trigger
{
public:
    explicit TwoTriggers(ShadowAI* botAI, std::string name1 = "", std::string name2 = "") : Trigger(botAI)
    {
        this->name1 = std::move(name1);
        this->name2 = std::move(name2);
    }
    bool IsActive() override;
    std::string const getName() override;

protected:
    std::string name1;
    std::string name2;
};

class SnareTargetTrigger : public DebuffTrigger
{
public:
    SnareTargetTrigger(ShadowAI* botAI, std::string const spell) : DebuffTrigger(botAI, spell) {}

    Value<Unit*>* GetTargetValue() override;
    std::string const getName() override { return spell + " on snare target"; }
};

class LowManaTrigger : public Trigger
{
public:
    LowManaTrigger(ShadowAI* botAI) : Trigger(botAI, "low mana") {}

    bool IsActive() override;
};

class MediumManaTrigger : public Trigger
{
public:
    MediumManaTrigger(ShadowAI* botAI) : Trigger(botAI, "medium mana") {}

    bool IsActive() override;
};

BEGIN_TRIGGER(PanicTrigger, Trigger)
std::string const getName() override { return "panic"; }
END_TRIGGER()

BEGIN_TRIGGER(OutNumberedTrigger, Trigger)
std::string const getName() override { return "outnumbered"; }
END_TRIGGER()

class NoPetTrigger : public Trigger
{
public:
    NoPetTrigger(ShadowAI* botAI) : Trigger(botAI, "no pet", 5 * 1000) {}

    virtual bool IsActive() override;
};

class HasPetTrigger : public Trigger
{
public:
    HasPetTrigger(ShadowAI* ai) : Trigger(ai, "has pet", 5 * 1000) {}

    virtual bool IsActive() override;
};

class PetAttackTrigger : public Trigger
{
public:
    PetAttackTrigger(ShadowAI* ai) : Trigger(ai, "pet attack") {}

    virtual bool IsActive() override;
};

class ItemCountTrigger : public Trigger
{
public:
    ItemCountTrigger(ShadowAI* botAI, std::string const item, int32 count, int32 interval = 30 * 1000)
        : Trigger(botAI, item, interval), item(item), count(count)
    {
    }

    bool IsActive() override;
    std::string const getName() override { return "item count"; }

protected:
    std::string const item;
    int32 count;
};

class AmmoCountTrigger : public ItemCountTrigger
{
public:
    AmmoCountTrigger(ShadowAI* botAI, std::string const item, uint32 count = 1, int32 interval = 30 * 1000)
        : ItemCountTrigger(botAI, item, count, interval)
    {
    }
    bool IsActive() override;
};

class HasAuraTrigger : public Trigger
{
public:
    HasAuraTrigger(ShadowAI* botAI, std::string const spell, int32 checkInterval = 1)
        : Trigger(botAI, spell, checkInterval)
    {
    }

    std::string const GetTargetName() override { return "self target"; }
    bool IsActive() override;
};

class HasAuraStackTrigger : public Trigger
{
public:
    HasAuraStackTrigger(ShadowAI* ai, std::string spell, int stack, int checkInterval = 1)
        : Trigger(ai, spell, checkInterval), stack(stack)
    {
    }

    std::string const GetTargetName() override { return "self target"; }
    bool IsActive() override;

private:
    int stack;
};

class HasNoAuraTrigger : public Trigger
{
public:
    HasNoAuraTrigger(ShadowAI* botAI, std::string const spell) : Trigger(botAI, spell) {}

    std::string const GetTargetName() override { return "self target"; }
    bool IsActive() override;
};

class TimerTrigger : public Trigger
{
public:
    TimerTrigger(ShadowAI* botAI) : Trigger(botAI, "timer"), lastCheck(0) {}

    bool IsActive() override;

private:
    time_t lastCheck;
};

class TimerBGTrigger : public Trigger
{
public:
    TimerBGTrigger(ShadowAI* botAI) : Trigger(botAI, "timer bg"), lastCheck(0) {}

    bool IsActive() override;

private:
    time_t lastCheck;
};

class TankAssistTrigger : public NoAttackersTrigger
{
public:
    TankAssistTrigger(ShadowAI* botAI) : NoAttackersTrigger(botAI) {}

    bool IsActive() override;
};

class IsBehindTargetTrigger : public Trigger
{
public:
    IsBehindTargetTrigger(ShadowAI* botAI) : Trigger(botAI, "behind target") {}

    bool IsActive() override;
};

class IsNotBehindTargetTrigger : public Trigger
{
public:
    IsNotBehindTargetTrigger(ShadowAI* botAI) : Trigger(botAI, "is not behind target") {}

    bool IsActive() override;
};

class IsNotFacingTargetTrigger : public Trigger
{
public:
    IsNotFacingTargetTrigger(ShadowAI* botAI) : Trigger(botAI, "not facing target") {}

    bool IsActive() override;
};

class HasCcTargetTrigger : public Trigger
{
public:
    HasCcTargetTrigger(ShadowAI* botAI, std::string const name) : Trigger(botAI, name) {}

    bool IsActive() override;
};

class NoMovementTrigger : public Trigger
{
public:
    NoMovementTrigger(ShadowAI* botAI, std::string const name) : Trigger(botAI, name) {}

    bool IsActive() override;
};

class NoPossibleTargetsTrigger : public Trigger
{
public:
    NoPossibleTargetsTrigger(ShadowAI* botAI) : Trigger(botAI, "no possible targets") {}

    bool IsActive() override;
};

class NotDpsTargetActiveTrigger : public Trigger
{
public:
    NotDpsTargetActiveTrigger(ShadowAI* botAI) : Trigger(botAI, "not dps target active") {}

    bool IsActive() override;
};

class NotDpsAoeTargetActiveTrigger : public Trigger
{
public:
    NotDpsAoeTargetActiveTrigger(ShadowAI* botAI) : Trigger(botAI, "not dps aoe target active") {}

    bool IsActive() override;
};

class PossibleAddsTrigger : public Trigger
{
public:
    PossibleAddsTrigger(ShadowAI* botAI) : Trigger(botAI, "possible adds") {}

    bool IsActive() override;
};

class IsSwimmingTrigger : public Trigger
{
public:
    IsSwimmingTrigger(ShadowAI* botAI) : Trigger(botAI, "swimming") {}

    bool IsActive() override;
};

class HasNearestAddsTrigger : public Trigger
{
public:
    HasNearestAddsTrigger(ShadowAI* botAI) : Trigger(botAI, "has nearest adds") {}

    bool IsActive() override;
};

class HasItemForSpellTrigger : public Trigger
{
public:
    HasItemForSpellTrigger(ShadowAI* botAI, std::string const spell) : Trigger(botAI, spell) {}

    bool IsActive() override;
};

class TargetChangedTrigger : public Trigger
{
public:
    TargetChangedTrigger(ShadowAI* botAI) : Trigger(botAI, "target changed") {}

    bool IsActive() override;
};

class InterruptEnemyHealerTrigger : public SpellTrigger
{
public:
    InterruptEnemyHealerTrigger(ShadowAI* botAI, std::string const spell) : SpellTrigger(botAI, spell) {}

    Value<Unit*>* GetTargetValue() override;
    std::string const getName() override { return spell + " on enemy healer"; }
};

class RandomBotUpdateTrigger : public RandomTrigger
{
public:
    RandomBotUpdateTrigger(ShadowAI* botAI) : RandomTrigger(botAI, "random bot update", 30 * 1000) {}

    bool IsActive() override;
};

class NoNonBotPlayersAroundTrigger : public Trigger
{
public:
    NoNonBotPlayersAroundTrigger(ShadowAI* botAI) : Trigger(botAI, "no non bot players around", 10 * 1000) {}

    bool IsActive() override;
};

class NewPlayerNearbyTrigger : public Trigger
{
public:
    NewPlayerNearbyTrigger(ShadowAI* botAI) : Trigger(botAI, "new player nearby", 10 * 1000) {}

    bool IsActive() override;
};

class CollisionTrigger : public Trigger
{
public:
    CollisionTrigger(ShadowAI* botAI) : Trigger(botAI, "collision", 5 * 1000) {}

    bool IsActive() override;
};

class StayTimeTrigger : public Trigger
{
public:
    StayTimeTrigger(ShadowAI* botAI, uint32 delay, std::string const name)
        : Trigger(botAI, name, 5 * 1000), delay(delay)
    {
    }

    bool IsActive() override;

private:
    uint32 delay;
};

class SitTrigger : public StayTimeTrigger
{
public:
    SitTrigger(ShadowAI* botAI) : StayTimeTrigger(botAI, sShadowAIConfig->sitDelay, "sit") {}
};

class ReturnToStayPositionTrigger : public Trigger
{
public:
    ReturnToStayPositionTrigger(ShadowAI* ai) : Trigger(ai, "return to stay position", 2) {}

    virtual bool IsActive() override;
};

class ReturnTrigger : public StayTimeTrigger
{
public:
    ReturnTrigger(ShadowAI* botAI) : StayTimeTrigger(botAI, sShadowAIConfig->returnDelay, "return") {}
};

class GiveItemTrigger : public Trigger
{
public:
    GiveItemTrigger(ShadowAI* botAI, std::string const name, std::string const item)
        : Trigger(botAI, name, 2 * 1000), item(item)
    {
    }

    bool IsActive() override;

protected:
    std::string const item;
};

class GiveFoodTrigger : public GiveItemTrigger
{
public:
    GiveFoodTrigger(ShadowAI* botAI) : GiveItemTrigger(botAI, "give food", "conjured food") {}

    bool IsActive() override;
};

class GiveWaterTrigger : public GiveItemTrigger
{
public:
    GiveWaterTrigger(ShadowAI* botAI) : GiveItemTrigger(botAI, "give water", "conjured water") {}

    bool IsActive() override;
};

class IsMountedTrigger : public Trigger
{
public:
    IsMountedTrigger(ShadowAI* botAI) : Trigger(botAI, "mounted", 1) {}

    bool IsActive() override;
};

class CorpseNearTrigger : public Trigger
{
public:
    CorpseNearTrigger(ShadowAI* botAI) : Trigger(botAI, "corpse near", 1 * 1000) {}

    bool IsActive() override;
};

class IsFallingTrigger : public Trigger
{
public:
    IsFallingTrigger(ShadowAI* botAI) : Trigger(botAI, "falling", 10 * 1000) {}

    bool IsActive() override;
};

class IsFallingFarTrigger : public Trigger
{
public:
    IsFallingFarTrigger(ShadowAI* botAI) : Trigger(botAI, "falling far", 10 * 1000) {}

    bool IsActive() override;
};

class HasAreaDebuffTrigger : public Trigger
{
public:
    HasAreaDebuffTrigger(ShadowAI* botAI) : Trigger(botAI, "have area debuff") {}

    bool IsActive() override;
};

class BuffOnMainTankTrigger : public BuffTrigger
{
public:
    BuffOnMainTankTrigger(ShadowAI* botAI, std::string spell, bool checkIsOwner = false, int checkInterval = 1)
        : BuffTrigger(botAI, spell, checkInterval, checkIsOwner)
    {
    }

public:
    virtual Value<Unit*>* GetTargetValue();
};

class SelfResurrectTrigger : public Trigger
{
public:
    SelfResurrectTrigger(ShadowAI* ai) : Trigger(ai, "can self resurrect") {}

    bool IsActive() override { return !bot->IsAlive() && bot->GetUInt32Value(PLAYER_SELF_RES_SPELL); }
};

class NewPetTrigger : public Trigger
{
public:
    NewPetTrigger(ShadowAI* ai) : Trigger(ai, "new pet"), lastPetGuid(ObjectGuid::Empty), triggered(false) {}

    bool IsActive() override;

private:
    ObjectGuid lastPetGuid;
    bool triggered;
};

#endif
