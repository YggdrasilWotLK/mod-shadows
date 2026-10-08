#ifndef _SHADOW_WOTLKDUNGEONNEXTRIGGERS_H
#define _SHADOW_WOTLKDUNGEONNEXTRIGGERS_H

#include "Trigger.h"
#include "ShadowAIConfig.h"
#include "GenericTriggers.h"
#include "DungeonStrategyUtils.h"

enum NexusIDs
{
    // Faction Commander
    NPC_ALLIANCE_COMMANDER          = 27949,
    NPC_HORDE_COMMANDER             = 27947,
    NPC_COMMANDER_STOUTBEARD        = 26796,
    NPC_COMMANDER_KOLURG            = 26798,
    // SPELL_FRIGHTENING_SHOUT         = 19134,
    SPELL_WHIRLWIND                 = 38618,

    // Grand Magus Telestra
    NPC_TELESTRA                    = 26731,
    NPC_FIRE_MAGUS                  = 26928,
    NPC_FROST_MAGUS                 = 26930,
    NPC_ARCANE_MAGUS                = 26929,

    // Anomalus
    BUFF_RIFT_SHIELD                = 47748,

    // Ormorok the Tree Shaper
    // NPC_CRYSTAL_SPIKE               = 27099,
    GO_CRYSTAL_SPIKE                = 188537,
};

class FactionCommanderWhirlwindTrigger : public Trigger
{
public:
    FactionCommanderWhirlwindTrigger(ShadowAI* ai) : Trigger(ai, "faction commander whirlwind") {}
    bool IsActive() override;
};

class TelestraFirebombTrigger : public Trigger
{
public:
    TelestraFirebombTrigger(ShadowAI* ai) : Trigger(ai, "telestra firebomb spread") {}
    bool IsActive() override;
};

class TelestraSplitPhaseTrigger : public Trigger
{
public:
    TelestraSplitPhaseTrigger(ShadowAI* ai) : Trigger(ai, "telestra split phase") {}
    bool IsActive() override;
};

class ChaoticRiftTrigger : public Trigger
{
public:
    ChaoticRiftTrigger(ShadowAI* ai) : Trigger(ai, "chaotic rift") {}
    bool IsActive() override;
};

class OrmorokSpikesTrigger : public Trigger
{
public:
    OrmorokSpikesTrigger(ShadowAI* ai) : Trigger(ai, "ormorok spikes") {}
    bool IsActive() override;
};

class OrmorokStackTrigger : public Trigger
{
public:
    OrmorokStackTrigger(ShadowAI* ai) : Trigger(ai, "ormorok stack") {}
    bool IsActive() override;
};

class IntenseColdTrigger : public Trigger
{
public:
    IntenseColdTrigger(ShadowAI* ai) : Trigger(ai, "intense cold") {}
    bool IsActive() override;
};

class KeristraszaPositioningTrigger : public Trigger
{
public:
    KeristraszaPositioningTrigger(ShadowAI* ai) : Trigger(ai, "keristrasza positioning") {}
    bool IsActive() override;
};

#endif
