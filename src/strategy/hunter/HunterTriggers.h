/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_HUNTERTRIGGERS_H
#define _SHADOW_HUNTERTRIGGERS_H

#include "CureTriggers.h"
#include "GenericTriggers.h"
#include "Trigger.h"
#include "ShadowAI.h"
#include <set>

class ShadowAI;

// Buff and Out of Combat Triggers

class HunterAspectOfTheMonkeyTrigger : public BuffTrigger
{
public:
    HunterAspectOfTheMonkeyTrigger(ShadowAI* botAI) : BuffTrigger(botAI, "aspect of the monkey") {}
};

class HunterAspectOfTheHawkTrigger : public BuffTrigger
{
public:
    HunterAspectOfTheHawkTrigger(ShadowAI* botAI) : BuffTrigger(botAI, "aspect of the hawk") {}
    bool IsActive() override;
};

class HunterAspectOfTheWildTrigger : public BuffTrigger
{
public:
    HunterAspectOfTheWildTrigger(ShadowAI* botAI) : BuffTrigger(botAI, "aspect of the wild") {}
};

class HunterAspectOfTheViperTrigger : public BuffTrigger
{
public:
    HunterAspectOfTheViperTrigger(ShadowAI* botAI) : BuffTrigger(botAI, "aspect of the viper") {}
    bool IsActive() override;
};

class HunterAspectOfThePackTrigger : public BuffTrigger
{
public:
    HunterAspectOfThePackTrigger(ShadowAI* botAI) : BuffTrigger(botAI, "aspect of the pack") {}
    bool IsActive() override;
};

class TrueshotAuraTrigger : public BuffTrigger
{
public:
    TrueshotAuraTrigger(ShadowAI* botAI) : BuffTrigger(botAI, "trueshot aura") {}
};

class NoTrackTrigger : public BuffTrigger
{
public:
    NoTrackTrigger(ShadowAI* botAI) : BuffTrigger(botAI, "no track") {}
    bool IsActive() override;
};

class HunterLowAmmoTrigger : public AmmoCountTrigger
{
public:
    HunterLowAmmoTrigger(ShadowAI* botAI) : AmmoCountTrigger(botAI, "ammo", 1, 30) {}

    bool IsActive() override;
};

class HunterNoAmmoTrigger : public AmmoCountTrigger
{
public:
    HunterNoAmmoTrigger(ShadowAI* botAI) : AmmoCountTrigger(botAI, "ammo", 1, 10) {}
};

class HunterHasAmmoTrigger : public AmmoCountTrigger
{
public:
    HunterHasAmmoTrigger(ShadowAI* botAI) : AmmoCountTrigger(botAI, "ammo", 1, 10) {}

    bool IsActive() override;
};

// Cooldown Triggers

class RapidFireTrigger : public BoostTrigger
{
public:
    RapidFireTrigger(ShadowAI* botAI) : BoostTrigger(botAI, "rapid fire") {}
};

class BestialWrathTrigger : public BuffTrigger
{
public:
    BestialWrathTrigger(ShadowAI* botAI) : BuffTrigger(botAI, "bestial wrath") {}
};

class IntimidationTrigger : public BuffTrigger
{
public:
    IntimidationTrigger(ShadowAI* botAI) : BuffTrigger(botAI, "intimidation") {}
};

class KillCommandTrigger : public BuffTrigger
{
public:
    KillCommandTrigger(ShadowAI* botAI) : BuffTrigger(botAI, "kill command") {}
    bool IsActive() override;
};

class LockAndLoadTrigger : public BuffTrigger
{
public:
    LockAndLoadTrigger(ShadowAI* botAI) : BuffTrigger(botAI, "lock and load") {}

    bool IsActive() override
    {
        return botAI->HasAura("lock and load", botAI->GetBot());
    }
};

// CC Triggers

class FreezingTrapTrigger : public HasCcTargetTrigger
{
public:
    FreezingTrapTrigger(ShadowAI* botAI) : HasCcTargetTrigger(botAI, "freezing trap") {}
};

class ConsussiveShotSnareTrigger : public SnareTargetTrigger
{
public:
    ConsussiveShotSnareTrigger(ShadowAI* botAI) : SnareTargetTrigger(botAI, "concussive shot") {}
};

class ScareBeastTrigger : public HasCcTargetTrigger
{
public:
    ScareBeastTrigger(ShadowAI* botAI) : HasCcTargetTrigger(botAI, "scare beast") {}
};

class SilencingShotTrigger : public InterruptSpellTrigger
{
public:
    SilencingShotTrigger(ShadowAI* botAI) : InterruptSpellTrigger(botAI, "silencing shot") {}
};

// DoT/Debuff Triggers

class HuntersMarkTrigger : public DebuffTrigger
{
public:
    HuntersMarkTrigger(ShadowAI* botAI) : DebuffTrigger(botAI, "hunter's mark", 1, true, 0.5f) {}
    bool IsActive() override { return BuffTrigger::IsActive(); }
};

class ExplosiveShotTrigger : public DebuffTrigger
{
public:
    ExplosiveShotTrigger(ShadowAI* botAI) : DebuffTrigger(botAI, "explosive shot", 1, true) {}
    bool IsActive() override { return BuffTrigger::IsActive(); }
};

class BlackArrowTrigger : public DebuffTrigger
{
public:
    BlackArrowTrigger(ShadowAI* botAI) : DebuffTrigger(botAI, "black arrow", 1, true) {}
    bool IsActive() override;
};

class HunterNoStingsActiveTrigger : public DebuffTrigger
{
public:
    HunterNoStingsActiveTrigger(ShadowAI* botAI) : DebuffTrigger(botAI, "no stings") {}
    bool IsActive() override;
};

class SerpentStingOnAttackerTrigger : public DebuffOnAttackerTrigger
{
public:
    SerpentStingOnAttackerTrigger(ShadowAI* botAI) : DebuffOnAttackerTrigger(botAI, "serpent sting", true) {}
    bool IsActive() override;
};

// Damage/Combat Triggers

class AutoShotTrigger : public Trigger
{
public:
    AutoShotTrigger(ShadowAI* botAI) : Trigger(botAI, "auto shot") {}
};

class SwitchToRangedTrigger : public Trigger
{
public:
    SwitchToRangedTrigger(ShadowAI* botAI) : Trigger(botAI, "switch to ranged") {}

    bool IsActive() override;
};

class SwitchToMeleeTrigger : public Trigger
{
public:
    SwitchToMeleeTrigger(ShadowAI* botAI) : Trigger(botAI, "switch to melee") {}

    bool IsActive() override;
};

class MisdirectionOnMainTankTrigger : public BuffOnMainTankTrigger
{
public:
    MisdirectionOnMainTankTrigger(ShadowAI* ai) : BuffOnMainTankTrigger(ai, "misdirection", true) {}
};

class TargetRemoveEnrageTrigger : public TargetAuraDispelTrigger
{
public:
    TargetRemoveEnrageTrigger(ShadowAI* ai) : TargetAuraDispelTrigger(ai, "tranquilizing shot", DISPEL_ENRAGE) {}
};

class TargetRemoveMagicTrigger : public TargetAuraDispelTrigger
{
public:
    TargetRemoveMagicTrigger(ShadowAI* ai) : TargetAuraDispelTrigger(ai, "tranquilizing shot", DISPEL_MAGIC) {}
};

class ImmolationTrapNoCdTrigger : public SpellNoCooldownTrigger
{
public:
    ImmolationTrapNoCdTrigger(ShadowAI* ai) : SpellNoCooldownTrigger(ai, "immolation trap") {}
};

BEGIN_TRIGGER(HuntersPetDeadTrigger, Trigger)
END_TRIGGER()

BEGIN_TRIGGER(HuntersPetLowHealthTrigger, Trigger)
END_TRIGGER()

BEGIN_TRIGGER(HuntersPetMediumHealthTrigger, Trigger)
END_TRIGGER()

BEGIN_TRIGGER(HunterPetNotHappy, Trigger)
END_TRIGGER()

class VolleyChannelCheckTrigger : public Trigger
{
public:
    VolleyChannelCheckTrigger(ShadowAI* botAI, uint32 minEnemies = 2)
        : Trigger(botAI, "volley channel check"), minEnemies(minEnemies)
    {
    }

    bool IsActive() override;

protected:
    uint32 minEnemies;
    static const std::set<uint32> VOLLEY_SPELL_IDS;
};

#endif
