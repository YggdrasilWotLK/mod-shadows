/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_MAGETRIGGERS_H
#define _SHADOW_MAGETRIGGERS_H

#include "CureTriggers.h"
#include "GenericTriggers.h"
#include "SharedDefines.h"
#include "Trigger.h"
#include "Shadows.h"
#include "ShadowAI.h"
#include <set>
#include <unordered_set>

class ShadowAI;

// Buff and Out of Combat Triggers

class ArcaneIntellectOnPartyTrigger : public BuffOnPartyTrigger
{
public:
    ArcaneIntellectOnPartyTrigger(ShadowAI* botAI) : BuffOnPartyTrigger(botAI, "arcane intellect", 2 * 2000) {}

    bool IsActive() override;
};

class ArcaneIntellectTrigger : public BuffTrigger
{
public:
    ArcaneIntellectTrigger(ShadowAI* botAI) : BuffTrigger(botAI, "arcane intellect", 2 * 2000) {}
    bool IsActive() override;
};

class MageArmorTrigger : public BuffTrigger
{
public:
    MageArmorTrigger(ShadowAI* botAI) : BuffTrigger(botAI, "mage armor", 5 * 2000) {}
    bool IsActive() override;
};

class NoFocusMagicTrigger : public Trigger
{
public:
    NoFocusMagicTrigger(ShadowAI* botAI) : Trigger(botAI, "no focus magic") {}
    bool IsActive() override;
};

class IceBarrierTrigger : public BuffTrigger
{
public:
    IceBarrierTrigger(ShadowAI* botAI) : BuffTrigger(botAI, "ice barrier") {}
};

class NoManaGemTrigger : public Trigger
{
public:
    NoManaGemTrigger(ShadowAI* botAI) : Trigger(botAI, "no mana gem") {}

    bool IsActive() override;
};

class FireWardTrigger : public DeflectSpellTrigger
{
public:
    FireWardTrigger(ShadowAI* botAI) : DeflectSpellTrigger(botAI, "fire ward") {}
};

class FrostWardTrigger : public DeflectSpellTrigger
{
public:
    FrostWardTrigger(ShadowAI* botAI) : DeflectSpellTrigger(botAI, "frost ward") {}
};

// Proc and Boost Triggers

class HotStreakTrigger : public HasAuraTrigger
{
public:
    HotStreakTrigger(ShadowAI* botAI) : HasAuraTrigger(botAI, "hot streak") {}
};

class FirestarterTrigger : public HasAuraTrigger
{
public:
    FirestarterTrigger(ShadowAI* botAI) : HasAuraTrigger(botAI, "firestarter") {}
};

class MissileBarrageTrigger : public HasAuraTrigger
{
public:
    MissileBarrageTrigger(ShadowAI* botAI) : HasAuraTrigger(botAI, "missile barrage") {}
};

class ArcaneBlastTrigger : public BuffTrigger
{
public:
    ArcaneBlastTrigger(ShadowAI* botAI) : BuffTrigger(botAI, "arcane blast") {}
};

class ArcaneBlastStackTrigger : public HasAuraStackTrigger
{
public:
    ArcaneBlastStackTrigger(ShadowAI* botAI) : HasAuraStackTrigger(botAI, "arcane blast", 4, 1) {}
};

class ArcaneBlast4StacksAndMissileBarrageTrigger : public TwoTriggers
{
public:
    ArcaneBlast4StacksAndMissileBarrageTrigger(ShadowAI* ai)
        : TwoTriggers(ai, "arcane blast stack", "missile barrage")
    {
    }
};

class CombustionTrigger : public BoostTrigger
{
public:
    CombustionTrigger(ShadowAI* botAI) : BoostTrigger(botAI, "combustion") {}
};

class IcyVeinsCooldownTrigger : public SpellCooldownTrigger
{
public:
    IcyVeinsCooldownTrigger(ShadowAI* botAI) : SpellCooldownTrigger(botAI, "icy veins") {}
};

class DeepFreezeCooldownTrigger : public SpellCooldownTrigger
{
public:
    DeepFreezeCooldownTrigger(ShadowAI* botAI) : SpellCooldownTrigger(botAI, "deep freeze") {}

    bool IsActive() override;
};

class ColdSnapTrigger : public TwoTriggers
{
public:
    ColdSnapTrigger(ShadowAI* ai) : TwoTriggers(ai, "icy veins on cd", "deep freeze on cd") {}
};

class MirrorImageTrigger : public BoostTrigger
{
public:
    MirrorImageTrigger(ShadowAI* botAI) : BoostTrigger(botAI, "mirror image") {}
};

class IcyVeinsTrigger : public BoostTrigger
{
public:
    IcyVeinsTrigger(ShadowAI* botAI) : BoostTrigger(botAI, "icy veins") {}
};

class ArcanePowerTrigger : public BoostTrigger
{
public:
    ArcanePowerTrigger(ShadowAI* botAI) : BoostTrigger(botAI, "arcane power") {}
};
class PresenceOfMindTrigger : public BoostTrigger
{
public:
    PresenceOfMindTrigger(ShadowAI* botAI) : BoostTrigger(botAI, "presence of mind") {}
};

// CC, Interrupt, and Dispel Triggers

class PolymorphTrigger : public HasCcTargetTrigger
{
public:
    PolymorphTrigger(ShadowAI* botAI) : HasCcTargetTrigger(botAI, "polymorph") {}
};

class RemoveCurseTrigger : public NeedCureTrigger
{
public:
    RemoveCurseTrigger(ShadowAI* botAI) : NeedCureTrigger(botAI, "remove curse", DISPEL_CURSE) {}
};

class PartyMemberRemoveCurseTrigger : public PartyMemberNeedCureTrigger
{
public:
    PartyMemberRemoveCurseTrigger(ShadowAI* botAI) : PartyMemberNeedCureTrigger(botAI, "remove curse", DISPEL_CURSE)
    {
    }
};

class SpellstealTrigger : public TargetAuraDispelTrigger
{
public:
    SpellstealTrigger(ShadowAI* botAI) : TargetAuraDispelTrigger(botAI, "spellsteal", DISPEL_MAGIC) {}
};

class CounterspellEnemyHealerTrigger : public InterruptEnemyHealerTrigger
{
public:
    CounterspellEnemyHealerTrigger(ShadowAI* botAI) : InterruptEnemyHealerTrigger(botAI, "counterspell") {}
};

class CounterspellInterruptSpellTrigger : public InterruptSpellTrigger
{
public:
    CounterspellInterruptSpellTrigger(ShadowAI* botAI) : InterruptSpellTrigger(botAI, "counterspell") {}
};

// Damage and Debuff Triggers

class LivingBombTrigger : public DebuffTrigger
{
public:
    LivingBombTrigger(ShadowAI* botAI) : DebuffTrigger(botAI, "living bomb", 1, true) {}
    bool IsActive() override { return BuffTrigger::IsActive(); }
};

class LivingBombOnAttackersTrigger : public DebuffOnAttackerTrigger
{
public:
    LivingBombOnAttackersTrigger(ShadowAI* ai) : DebuffOnAttackerTrigger(ai, "living bomb", true) {}
    bool IsActive() override { return BuffTrigger::IsActive(); }
};

class FireballTrigger : public DebuffTrigger
{
public:
    FireballTrigger(ShadowAI* botAI) : DebuffTrigger(botAI, "fireball", 1, true) {}
};

class ImprovedScorchTrigger : public DebuffTrigger
{
public:
    ImprovedScorchTrigger(ShadowAI* botAI) : DebuffTrigger(botAI, "improved scorch", 1, true, 0.5f) {}
    bool IsActive() override;
};

class PyroblastTrigger : public DebuffTrigger
{
public:
    PyroblastTrigger(ShadowAI* botAI) : DebuffTrigger(botAI, "pyroblast", 1, true) {}
};

class FrostfireBoltTrigger : public DebuffTrigger
{
public:
    FrostfireBoltTrigger(ShadowAI* botAI) : DebuffTrigger(botAI, "frostfire bolt", 1, true) {}
};

class FingersOfFrostTrigger : public HasAuraTrigger
{
public:
    FingersOfFrostTrigger(ShadowAI* botAI) : HasAuraTrigger(botAI, "fingers of frost") {}
};

class BrainFreezeTrigger : public HasAuraTrigger
{
public:
    BrainFreezeTrigger(ShadowAI* botAI) : HasAuraTrigger(botAI, "fireball!") {}
};

class FrostNovaOnTargetTrigger : public DebuffTrigger
{
public:
    FrostNovaOnTargetTrigger(ShadowAI* botAI) : DebuffTrigger(botAI, "frost nova", 1, false) {}
    bool IsActive() override;
};

class FrostbiteOnTargetTrigger : public DebuffTrigger
{
public:
    FrostbiteOnTargetTrigger(ShadowAI* botAI) : DebuffTrigger(botAI, "frostbite", 1, false) {}
    bool IsActive() override;
};

class FlamestrikeNearbyTrigger : public Trigger
{
public:
    FlamestrikeNearbyTrigger(ShadowAI* botAI, float radius = 30.0f)
        : Trigger(botAI, "flamestrike nearby"), radius(radius)
    {
    }
    bool IsActive() override;

protected:
    float radius;
    static const std::set<uint32> FLAMESTRIKE_SPELL_IDS;
};

class FlamestrikeBlizzardTrigger : public TwoTriggers
{
public:
    FlamestrikeBlizzardTrigger(ShadowAI* ai) : TwoTriggers(ai, "flamestrike nearby", "medium aoe") {}
};

class BlizzardChannelCheckTrigger : public Trigger
{
public:
    BlizzardChannelCheckTrigger(ShadowAI* botAI, uint32 minEnemies = 2)
        : Trigger(botAI, "blizzard channel check"), minEnemies(minEnemies) {}

    bool IsActive() override;

protected:
    uint32 minEnemies;
    static const std::set<uint32> BLIZZARD_SPELL_IDS;
};

class BlastWaveOffCdTrigger : public SpellNoCooldownTrigger
{
public:
    BlastWaveOffCdTrigger(ShadowAI* botAI) : SpellNoCooldownTrigger(botAI, "blast wave") {}
};

class BlastWaveOffCdTriggerAndMediumAoeTrigger : public TwoTriggers
{
public:
    BlastWaveOffCdTriggerAndMediumAoeTrigger(ShadowAI* ai) : TwoTriggers(ai, "blast wave off cd", "medium aoe") {}
};

class NoFirestarterStrategyTrigger : public Trigger
{
public:
    NoFirestarterStrategyTrigger(ShadowAI* botAI) : Trigger(botAI, "no firestarter strategy") {}

    bool IsActive() override
    {
        return !botAI->HasStrategy("firestarter", BOT_STATE_COMBAT);
    }
};

class EnemyIsCloseAndNoFirestarterStrategyTrigger : public TwoTriggers
{
public:
    EnemyIsCloseAndNoFirestarterStrategyTrigger(ShadowAI* botAI)
        : TwoTriggers(botAI, "enemy is close", "no firestarter strategy") {}
};

class EnemyTooCloseForSpellAndNoFirestarterStrategyTrigger : public TwoTriggers
{
public:
    EnemyTooCloseForSpellAndNoFirestarterStrategyTrigger(ShadowAI* botAI)
        : TwoTriggers(botAI, "enemy too close for spell", "no firestarter strategy") {}
};

#endif
