#ifndef _SHADOW_WOTLKDUNGEONUKTRIGGERS_H
#define _SHADOW_WOTLKDUNGEONUKTRIGGERS_H

#include "Trigger.h"
#include "ShadowAIConfig.h"
#include "GenericTriggers.h"
#include "DungeonStrategyUtils.h"

enum UtgardeKeepIDs
{
    // Prince Keleseth
    SPELL_FROST_TOMB               = 48400,
    NPC_FROST_TOMB                 = 23965,
};

class KelesethFrostTombTrigger : public Trigger
{
public:
    KelesethFrostTombTrigger(ShadowAI* ai) : Trigger(ai, "keleseth frost tomb") {}
    bool IsActive() override;
};

class DalronnDpsTrigger : public Trigger
{
public:
    DalronnDpsTrigger(ShadowAI* ai) : Trigger(ai, "dalronn dps") {}
    bool IsActive() override;
};

#endif