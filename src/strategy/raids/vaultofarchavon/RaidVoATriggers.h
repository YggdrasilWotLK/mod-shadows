#ifndef _SHADOW_RAIDVOATRIGGERS_H
#define _SHADOW_RAIDVOATRIGGERS_H

#include "EventMap.h"
#include "GenericTriggers.h"
#include "ShadowAIConfig.h"
#include "Trigger.h"

enum VoAIDs
{
    // Emalon the Storm Watcher
    AURA_OVERCHARGE = 64217,
    BOSS_EMALON = 33993,
    NPC_TEMPEST_MINION = 33998,
    SPELL_LIGHTNING_NOVA_10_MAN = 64216,
    SPELL_LIGHTNING_NOVA_25_MAN = 65279,
};

//
// Emalon the Storm Watcher
//
class EmalonMarkBossTrigger : public Trigger
{
public:
    EmalonMarkBossTrigger(ShadowAI* ai) : Trigger(ai, "emalon mark boss trigger") {}
    bool IsActive() override;
};

class EmalonLightingNovaTrigger : public Trigger
{
public:
    EmalonLightingNovaTrigger(ShadowAI* ai) : Trigger(ai, "emalon lighting nova trigger") {}
    bool IsActive() override;
};

class EmalonOverchargeTrigger : public Trigger
{
public:
    EmalonOverchargeTrigger(ShadowAI* ai) : Trigger(ai, "emalon overcharge trigger") {}
    bool IsActive() override;
};

class EmalonFallFromFloorTrigger : public Trigger
{
public:
    EmalonFallFromFloorTrigger(ShadowAI* ai) : Trigger(ai, "emalon fall from floor trigger") {}
    bool IsActive() override;
};

#endif
