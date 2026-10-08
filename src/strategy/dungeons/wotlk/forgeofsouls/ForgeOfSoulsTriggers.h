#ifndef _SHADOW_WOTLKDUNGEONFOSTRIGGERS_H
#define _SHADOW_WOTLKDUNGEONFOSTRIGGERS_H

#include "Trigger.h"
#include "ShadowAIConfig.h"
#include "GenericTriggers.h"
#include "DungeonStrategyUtils.h"

enum ForgeOfSoulsBronjahmIDs
{
    // Bronjahm
    NPC_CORRUPTED_SOUL_FRAGMENT = 36535,

    SPELL_CORRUPT_SOUL          = 68839,
    SPELL_SOULSTORM_VISUAL      = 68870,
    SPELL_SOULSTORM_VISUAL2     = 68904,
    SPELL_SOULSTORM             = 68872,

    // Devourer of Souls
    SPELL_WAILING_SOULS         = 68899,
};

class MoveFromBronjahmTrigger : public Trigger
{
public:
    MoveFromBronjahmTrigger(ShadowAI* ai) : Trigger(ai, "move from bronjahm") {}

    bool IsActive() override;
};

class SwitchToSoulFragment : public Trigger
{
public:
    SwitchToSoulFragment(ShadowAI* ai) : Trigger(ai, "switch to soul fragment") {}

    bool IsActive() override;
};

class BronjahmPositionTrigger : public Trigger
{
public:
    BronjahmPositionTrigger(ShadowAI* ai) : Trigger(ai, "bronjahm position") {}
    bool IsActive() override;
};

class DevourerOfSoulsTrigger : public Trigger
{
public:
    DevourerOfSoulsTrigger(ShadowAI* ai) : Trigger(ai, "devourer of souls") {}
    bool IsActive() override;
};

#endif
