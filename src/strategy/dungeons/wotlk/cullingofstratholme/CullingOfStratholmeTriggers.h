#ifndef _SHADOW_WOTLKDUNGEONCOSTRIGGERS_H
#define _SHADOW_WOTLKDUNGEONCOSTRIGGERS_H

#include "Trigger.h"
#include "ShadowAIConfig.h"
#include "GenericTriggers.h"
#include "DungeonStrategyUtils.h"

enum CullingOfStratholmeIDs
{
    // Salramm the Fleshcrafter
    NPC_GHOUL_MINION                   = 27733,
};

class ExplodeGhoulTrigger : public Trigger
{
public:
    ExplodeGhoulTrigger(ShadowAI* ai) : Trigger(ai, "explode ghoul") {}
    bool IsActive() override;
};

class EpochRangedTrigger : public Trigger
{
public:
    EpochRangedTrigger(ShadowAI* ai) : Trigger(ai, "chrono-lord epoch ranged") {}
    bool IsActive() override;
};

#endif
