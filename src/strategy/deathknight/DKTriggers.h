/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_DKTRIGGERS_H
#define _SHADOW_DKTRIGGERS_H

#include "GenericTriggers.h"

class ShadowAI;

BUFF_TRIGGER(HornOfWinterTrigger, "horn of winter");
BUFF_TRIGGER(BoneShieldTrigger, "bone shield");
BUFF_TRIGGER(ImprovedIcyTalonsTrigger, "improved icy talons");
// DEBUFF_CHECKISOWNER_TRIGGER(PlagueStrikeDebuffTrigger, "blood plague");
class PlagueStrikeDebuffTrigger : public DebuffTrigger
{
public:
    PlagueStrikeDebuffTrigger(ShadowAI* botAI) : DebuffTrigger(botAI, "blood plague", 1, true, .0f) {}
};

class PlagueStrike3sDebuffTrigger : public DebuffTrigger
{
public:
    PlagueStrike3sDebuffTrigger(ShadowAI* botAI) : DebuffTrigger(botAI, "blood plague", 1, true, .0f, 3000) {}
};

// DEBUFF_CHECKISOWNER_TRIGGER(IcyTouchDebuffTrigger, "frost fever");
class IcyTouchDebuffTrigger : public DebuffTrigger
{
public:
    IcyTouchDebuffTrigger(ShadowAI* botAI) : DebuffTrigger(botAI, "frost fever", 1, true, .0f) {}
};

class IcyTouch3sDebuffTrigger : public DebuffTrigger
{
public:
    IcyTouch3sDebuffTrigger(ShadowAI* botAI) : DebuffTrigger(botAI, "frost fever", 1, true, .0f, 3000) {}
};

BUFF_TRIGGER(UnbreakableArmorTrigger, "unbreakable armor");
class PlagueStrikeDebuffOnAttackerTrigger : public DebuffOnMeleeAttackerTrigger
{
public:
    PlagueStrikeDebuffOnAttackerTrigger(ShadowAI* botAI)
        : DebuffOnMeleeAttackerTrigger(botAI, "blood plague", true, .0f)
    {
    }
};

class IcyTouchDebuffOnAttackerTrigger : public DebuffOnMeleeAttackerTrigger
{
public:
    IcyTouchDebuffOnAttackerTrigger(ShadowAI* botAI) : DebuffOnMeleeAttackerTrigger(botAI, "frost fever", true, .0f)
    {
    }
};

class DKPresenceTrigger : public BuffTrigger
{
public:
    DKPresenceTrigger(ShadowAI* botAI) : BuffTrigger(botAI, "blood presence") {}

    bool IsActive() override;
};

class BloodTapTrigger : public BuffTrigger
{
public:
    BloodTapTrigger(ShadowAI* botAI) : BuffTrigger(botAI, "blood tap") {}
};

class RaiseDeadTrigger : public BuffTrigger
{
public:
    RaiseDeadTrigger(ShadowAI* botAI) : BuffTrigger(botAI, "raise dead") {}
};

class RuneStrikeTrigger : public SpellCanBeCastTrigger
{
public:
    RuneStrikeTrigger(ShadowAI* botAI) : SpellCanBeCastTrigger(botAI, "rune strike") {}
};

class DeathCoilTrigger : public SpellCanBeCastTrigger
{
public:
    DeathCoilTrigger(ShadowAI* botAI) : SpellCanBeCastTrigger(botAI, "death coil") {}
};

class PestilenceGlyphTrigger : public SpellTrigger
{
public:
    PestilenceGlyphTrigger(ShadowAI* botAI) : SpellTrigger(botAI, "pestilence") {}
    virtual bool IsActive() override;
};

class BloodStrikeTrigger : public DebuffTrigger
{
public:
    BloodStrikeTrigger(ShadowAI* botAI) : DebuffTrigger(botAI, "blood strike", 1, true) {}
};

class HowlingBlastTrigger : public DebuffTrigger
{
public:
    HowlingBlastTrigger(ShadowAI* botAI) : DebuffTrigger(botAI, "howling blast", 1, true) {}
};

class MindFreezeInterruptSpellTrigger : public InterruptSpellTrigger
{
public:
    MindFreezeInterruptSpellTrigger(ShadowAI* botAI) : InterruptSpellTrigger(botAI, "mind freeze") {}
};

class StrangulateInterruptSpellTrigger : public InterruptSpellTrigger
{
public:
    StrangulateInterruptSpellTrigger(ShadowAI* botAI) : InterruptSpellTrigger(botAI, "strangulate") {}
};

class KillingMachineTrigger : public BoostTrigger
{
public:
    KillingMachineTrigger(ShadowAI* botAI) : BoostTrigger(botAI, "killing machine") {}
};

class MindFreezeOnEnemyHealerTrigger : public InterruptEnemyHealerTrigger
{
public:
    MindFreezeOnEnemyHealerTrigger(ShadowAI* botAI) : InterruptEnemyHealerTrigger(botAI, "mind freeze") {}
};

class ChainsOfIceSnareTrigger : public SnareTargetTrigger
{
public:
    ChainsOfIceSnareTrigger(ShadowAI* botAI) : SnareTargetTrigger(botAI, "chains of ice") {}
};

class StrangulateOnEnemyHealerTrigger : public InterruptEnemyHealerTrigger
{
public:
    StrangulateOnEnemyHealerTrigger(ShadowAI* botAI) : InterruptEnemyHealerTrigger(botAI, "strangulate") {}
};

class HighBloodRuneTrigger : public Trigger
{
public:
    HighBloodRuneTrigger(ShadowAI* botAI) : Trigger(botAI, "high blood rune") {}
    bool IsActive() override;
};

class HighFrostRuneTrigger : public Trigger
{
public:
    HighFrostRuneTrigger(ShadowAI* botAI) : Trigger(botAI, "high frost rune") {}
    bool IsActive() override;
};

class HighUnholyRuneTrigger : public Trigger
{
public:
    HighUnholyRuneTrigger(ShadowAI* botAI) : Trigger(botAI, "high unholy rune") {}
    bool IsActive() override;
};

class NoRuneTrigger : public Trigger
{
public:
    NoRuneTrigger(ShadowAI* botAI) : Trigger(botAI, "no rune") {}
    bool IsActive() override;
};

class FreezingFogTrigger : public HasAuraTrigger
{
public:
    FreezingFogTrigger(ShadowAI* botAI) : HasAuraTrigger(botAI, "freezing fog") {}
};

class DesolationTrigger : public BuffTrigger
{
public:
    DesolationTrigger(ShadowAI* botAI) : BuffTrigger(botAI, "desolation", 1, false, true, 10000) {}
    bool IsActive() override;
};

class DeathAndDecayCooldownTrigger : public SpellCooldownTrigger
{
public:
    DeathAndDecayCooldownTrigger(ShadowAI* botAI) : SpellCooldownTrigger(botAI, "death and decay") {}
    bool IsActive() override;
};

class ArmyOfTheDeadTrigger : public BoostTrigger
{
public:
    ArmyOfTheDeadTrigger(ShadowAI* botAI) : BoostTrigger(botAI, "army of the dead") {}
};

#endif
