/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_WARLOCKTRIGGERS_H
#define _SHADOW_WARLOCKTRIGGERS_H

#include "GenericTriggers.h"
#include "ShadowAI.h"
#include "Shadows.h"
#include "CureTriggers.h"
#include "Trigger.h"
#include <set>

class ShadowAI;

// Buff and Out of Combat Triggers

class DemonArmorTrigger : public BuffTrigger
{
public:
    DemonArmorTrigger(ShadowAI* botAI) : BuffTrigger(botAI, "demon armor") {}

    bool IsActive() override;
};

class SoulLinkTrigger : public BuffTrigger
{
public:
    SoulLinkTrigger(ShadowAI* botAI) : BuffTrigger(botAI, "soul link") {}
    bool IsActive() override;
};

class OutOfSoulShardsTrigger : public Trigger
{
public:
    OutOfSoulShardsTrigger(ShadowAI* botAI) : Trigger(botAI, "no soul shard", 2) {}
    bool IsActive() override;
};

class TooManySoulShardsTrigger : public Trigger
{
public:
    TooManySoulShardsTrigger(ShadowAI* botAI) : Trigger(botAI, "too many soul shards") {}
    bool IsActive() override;
};

class FirestoneTrigger : public BuffTrigger
{
public:
    FirestoneTrigger(ShadowAI* botAI) : BuffTrigger(botAI, "firestone") {}
    bool IsActive() override;
};

class SpellstoneTrigger : public BuffTrigger
{
public:
    SpellstoneTrigger(ShadowAI* botAI) : BuffTrigger(botAI, "spellstone") {}
    bool IsActive() override;
};

class OutOfSoulstoneTrigger : public Trigger
{
public:
    OutOfSoulstoneTrigger(ShadowAI* botAI) : Trigger(botAI, "no soulstone") {}
    bool IsActive() override;
};

class SoulstoneTrigger : public Trigger
{
public:
    SoulstoneTrigger(ShadowAI* botAI) : Trigger(botAI, "soulstone") {}

    bool IsActive() override
    {
        static const std::vector<uint32> soulstoneSpellIds = {20707, 20762, 20763, 20764, 20765, 27239, 47883};

        if (AI_VALUE2(uint32, "item count", "soulstone") == 0)
            return false;

        for (uint32 spellId : soulstoneSpellIds)
        {
            if (!bot->HasSpellCooldown(spellId))
                return true;  // Ready to use
        }

        return false;  // All are on cooldown
    }
};

class WarlockConjuredItemTrigger : public ItemCountTrigger
{
public:
    WarlockConjuredItemTrigger(ShadowAI* botAI, std::string const item) : ItemCountTrigger(botAI, item, 1) {}
    bool IsActive() override;
};

class HasSpellstoneTrigger : public WarlockConjuredItemTrigger
{
public:
    HasSpellstoneTrigger(ShadowAI* botAI) : WarlockConjuredItemTrigger(botAI, "spellstone") {}
};

class HasFirestoneTrigger : public WarlockConjuredItemTrigger
{
public:
    HasFirestoneTrigger(ShadowAI* botAI) : WarlockConjuredItemTrigger(botAI, "firestone") {}
};

class HasHealthstoneTrigger : public WarlockConjuredItemTrigger
{
public:
    HasHealthstoneTrigger(ShadowAI* botAI) : WarlockConjuredItemTrigger(botAI, "healthstone") {}
};

class WrongPetTrigger : public Trigger
{
public:
    WrongPetTrigger(ShadowAI* botAI) : Trigger(botAI, "wrong pet") {}
    bool IsActive() override;
};


// CC and Pet Triggers

class BanishTrigger : public HasCcTargetTrigger
{
public:
    BanishTrigger(ShadowAI* botAI) : HasCcTargetTrigger(botAI, "banish") {}
    bool IsActive() override;
};

class FearTrigger : public HasCcTargetTrigger
{
public:
    FearTrigger(ShadowAI* botAI) : HasCcTargetTrigger(botAI, "fear") {}
    bool IsActive() override;
};

class SpellLockInterruptSpellTrigger : public InterruptSpellTrigger
{
public:
    SpellLockInterruptSpellTrigger(ShadowAI* botAI) : InterruptSpellTrigger(botAI, "spell lock") {}
};

class DevourMagicPurgeTrigger : public TargetAuraDispelTrigger
{
public:
    DevourMagicPurgeTrigger(ShadowAI* botAI) : TargetAuraDispelTrigger(botAI, "devour magic", DISPEL_MAGIC) {}
};

class DevourMagicCleanseTrigger : public PartyMemberNeedCureTrigger
{
public:
    DevourMagicCleanseTrigger(ShadowAI* botAI) : PartyMemberNeedCureTrigger(botAI, "devour magic", DISPEL_MAGIC) {}
};

// DoT/Curse Triggers

class CorruptionTrigger : public DebuffTrigger
{
public:
    CorruptionTrigger(ShadowAI* botAI) : DebuffTrigger(botAI, "corruption", 1, true, 0.5f) {}
    bool IsActive() override
    {
        return BuffTrigger::IsActive() && !botAI->HasAura("seed of corruption", GetTarget(), false, true);
    }
};

class CorruptionOnAttackerTrigger : public DebuffOnAttackerTrigger
{
public:
    CorruptionOnAttackerTrigger(ShadowAI* botAI) : DebuffOnAttackerTrigger(botAI, "corruption", true) {}
    bool IsActive() override
    {
        return BuffTrigger::IsActive() && !botAI->HasAura("seed of corruption", GetTarget(), false, true);
    }
};

class ImmolateTrigger : public DebuffTrigger
{
public:
    ImmolateTrigger(ShadowAI* botAI) : DebuffTrigger(botAI, "immolate", 1, true, 0.5f) {}
    bool IsActive() override { return BuffTrigger::IsActive(); }
};

class ImmolateOnAttackerTrigger : public DebuffOnAttackerTrigger
{
public:
    ImmolateOnAttackerTrigger(ShadowAI* ai) : DebuffOnAttackerTrigger(ai, "immolate", true) {}
    bool IsActive() override { return BuffTrigger::IsActive(); }
};

class UnstableAfflictionTrigger : public DebuffTrigger
{
public:
    UnstableAfflictionTrigger(ShadowAI* ai) : DebuffTrigger(ai, "unstable affliction", 1, true, 0.5f) {}
    bool IsActive() override { return BuffTrigger::IsActive(); }
};

class UnstableAfflictionOnAttackerTrigger : public DebuffOnAttackerTrigger
{
public:
    UnstableAfflictionOnAttackerTrigger(ShadowAI* ai) : DebuffOnAttackerTrigger(ai, "unstable affliction", true) {}
    bool IsActive() override { return BuffTrigger::IsActive(); }
};

class HauntTrigger : public DebuffTrigger
{
public:
    HauntTrigger(ShadowAI* ai) : DebuffTrigger(ai, "haunt", 1, true, 0) {}
};

class CurseOfAgonyTrigger : public DebuffTrigger
{
public:
    CurseOfAgonyTrigger(ShadowAI* botAI) : DebuffTrigger(botAI, "curse of agony", 1, true, 0.5f) {}
    bool IsActive() override { return BuffTrigger::IsActive(); }
};

class CurseOfAgonyOnAttackerTrigger : public DebuffOnAttackerTrigger
{
public:
    CurseOfAgonyOnAttackerTrigger(ShadowAI* botAI) : DebuffOnAttackerTrigger(botAI, "curse of agony", true) {}
    bool IsActive() override { return BuffTrigger::IsActive(); }
};

class CurseOfTheElementsTrigger : public DebuffTrigger
{
public:
    CurseOfTheElementsTrigger(ShadowAI* botAI) : DebuffTrigger(botAI, "curse of the elements", 1, true, 0.5f) {}
    bool IsActive() override;
};

class CurseOfDoomTrigger : public DebuffTrigger
{
public:
    CurseOfDoomTrigger(ShadowAI* botAI) : DebuffTrigger(botAI, "curse of doom", 1, true, 0.5f) {}
    bool IsActive() override { return BuffTrigger::IsActive(); }
};

class CurseOfExhaustionTrigger : public DebuffTrigger
{
public:
    CurseOfExhaustionTrigger(ShadowAI* botAI) : DebuffTrigger(botAI, "curse of exhaustion", 1, true, 0.5f) {}
    bool IsActive() override { return BuffTrigger::IsActive(); }
};

class CurseOfTonguesTrigger : public DebuffTrigger
{
public:
    CurseOfTonguesTrigger(ShadowAI* botAI) : DebuffTrigger(botAI, "curse of tongues", 1, true, 0.5f) {}
    bool IsActive() override { return BuffTrigger::IsActive(); }
};

class CurseOfWeaknessTrigger : public DebuffTrigger
{
public:
    CurseOfWeaknessTrigger(ShadowAI* botAI) : DebuffTrigger(botAI, "curse of weakness", 1, true, 0.5f) {}
    bool IsActive() override;
};

// Proc/Cooldown Triggers

class LifeTapTrigger : public Trigger
{
public:
    LifeTapTrigger(ShadowAI* ai) : Trigger(ai, "life tap") {}
    bool IsActive() override;
};

class LifeTapGlyphBuffTrigger : public BuffTrigger
{
public:
    LifeTapGlyphBuffTrigger(ShadowAI* ai) : BuffTrigger(ai, "life tap") {}
    bool IsActive() override;
};

class MetamorphosisTrigger : public BoostTrigger
{
public:
    MetamorphosisTrigger(ShadowAI* ai) : BoostTrigger(ai, "metamorphosis") {}
};

class DemonicEmpowermentTrigger : public BuffTrigger
{
public:
    DemonicEmpowermentTrigger(ShadowAI* ai) : BuffTrigger(ai, "demonic empowerment") {}
    bool IsActive() override;
};

class ImmolationAuraActiveTrigger : public HasAuraTrigger
{
public:
    ImmolationAuraActiveTrigger(ShadowAI* ai) : HasAuraTrigger(ai, "immolation aura") {}
};

class ShadowTranceTrigger : public HasAuraTrigger
{
public:
    ShadowTranceTrigger(ShadowAI* botAI) : HasAuraTrigger(botAI, "shadow trance") {}
};

class BacklashTrigger : public HasAuraTrigger
{
public:
    BacklashTrigger(ShadowAI* botAI) : HasAuraTrigger(botAI, "backlash") {}
};

class DecimationTrigger : public HasAuraTrigger
{
public:
    DecimationTrigger(ShadowAI* ai) : HasAuraTrigger(ai, "decimation") {}
    bool IsActive() override;
};

class MoltenCoreTrigger : public HasAuraTrigger
{
public:
    MoltenCoreTrigger(ShadowAI* ai) : HasAuraTrigger(ai, "molten core") {}
};

class MetamorphosisNotActiveTrigger : public HasNoAuraTrigger
{
public:
    MetamorphosisNotActiveTrigger(ShadowAI* ai) : HasNoAuraTrigger(ai, "metamorphosis") {}
};

class MetaMeleeEnemyTooCloseForSpellTrigger : public TwoTriggers
{
public:
    MetaMeleeEnemyTooCloseForSpellTrigger(ShadowAI* ai)
        : TwoTriggers(ai, "enemy too close for spell", "metamorphosis not active") {}
};

class RainOfFireChannelCheckTrigger : public Trigger
{
public:
    RainOfFireChannelCheckTrigger(ShadowAI* botAI, uint32 minEnemies = 2)
        : Trigger(botAI, "rain of fire channel check"), minEnemies(minEnemies)
    {
    }

    bool IsActive() override;

protected:
    uint32 minEnemies;
    static const std::set<uint32> RAIN_OF_FIRE_SPELL_IDS;
};

#endif
