/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_ROGUETRIGGERS_H
#define _SHADOW_ROGUETRIGGERS_H

#include "GenericTriggers.h"

class ShadowAI;

class KickInterruptSpellTrigger : public InterruptSpellTrigger
{
public:
    KickInterruptSpellTrigger(ShadowAI* botAI) : InterruptSpellTrigger(botAI, "kick") {}
};

class SliceAndDiceTrigger : public BuffTrigger
{
public:
    SliceAndDiceTrigger(ShadowAI* botAI) : BuffTrigger(botAI, "slice and dice") {}
};

class HungerForBloodTrigger : public BuffTrigger
{
public:
    HungerForBloodTrigger(ShadowAI* botAI) : BuffTrigger(botAI, "hunger for blood") {}
};

class AdrenalineRushTrigger : public BoostTrigger
{
public:
    AdrenalineRushTrigger(ShadowAI* botAI) : BoostTrigger(botAI, "adrenaline rush") {}

    // bool isPossible();
};

class BladeFuryTrigger : public BoostTrigger
{
public:
    BladeFuryTrigger(ShadowAI* botAI) : BoostTrigger(botAI, "blade fury") {}
};


class RuptureTrigger : public DebuffTrigger
{
public:
    RuptureTrigger(ShadowAI* botAI) : DebuffTrigger(botAI, "rupture", 1, true) {}
};

class ExposeArmorTrigger : public DebuffTrigger
{
public:
    ExposeArmorTrigger(ShadowAI* botAI) : DebuffTrigger(botAI, "expose armor") {}
    virtual bool IsActive() override;
};

class KickInterruptEnemyHealerSpellTrigger : public InterruptEnemyHealerTrigger
{
public:
    KickInterruptEnemyHealerSpellTrigger(ShadowAI* botAI) : InterruptEnemyHealerTrigger(botAI, "kick") {}
};

class InStealthTrigger : public HasAuraTrigger
{
public:
    InStealthTrigger(ShadowAI* botAI) : HasAuraTrigger(botAI, "stealth") {}
};

class NoStealthTrigger : public HasNoAuraTrigger
{
public:
    NoStealthTrigger(ShadowAI* botAI) : HasNoAuraTrigger(botAI, "stealth") {}
};

class UnstealthTrigger : public BuffTrigger
{
public:
    UnstealthTrigger(ShadowAI* botAI) : BuffTrigger(botAI, "stealth", 3) {}

    bool IsActive() override;
};

class StealthTrigger : public Trigger
{
public:
    StealthTrigger(ShadowAI* botAI) : Trigger(botAI, "stealth") {}

    bool IsActive() override;
};

class SapTrigger : public HasCcTargetTrigger
{
public:
    SapTrigger(ShadowAI* botAI) : HasCcTargetTrigger(botAI, "sap") {}

    bool IsPossible();
};

class SprintTrigger : public BuffTrigger
{
public:
    SprintTrigger(ShadowAI* botAI) : BuffTrigger(botAI, "sprint", 3) {}

    bool IsPossible();
    bool IsActive() override;
};

class MainHandWeaponNoEnchantTrigger : public BuffTrigger
{
public:
    MainHandWeaponNoEnchantTrigger(ShadowAI* ai) : BuffTrigger(ai, "main hand", 1) {}
    virtual bool IsActive();
};

class OffHandWeaponNoEnchantTrigger : public BuffTrigger
{
public:
    OffHandWeaponNoEnchantTrigger(ShadowAI* ai) : BuffTrigger(ai, "off hand", 1) {}
    virtual bool IsActive();
};

class TricksOfTheTradeOnMainTankTrigger : public BuffOnMainTankTrigger
{
public:
    TricksOfTheTradeOnMainTankTrigger(ShadowAI* ai) : BuffOnMainTankTrigger(ai, "tricks of the trade", true) {}
};



#endif
