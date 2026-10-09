/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_PVPTRIGGERS_H
#define _SHADOW_PVPTRIGGERS_H

#include "Trigger.h"

class ShadowAI;

class EnemyPlayerNear : public Trigger
{
public:
    EnemyPlayerNear(ShadowAI* botAI) : Trigger(botAI, "enemy player near", 3) {}

    bool IsActive() override;
};

class PlayerHasNoFlag : public Trigger
{
public:
    PlayerHasNoFlag(ShadowAI* botAI) : Trigger(botAI, "player has no flag") {}

    bool IsActive() override;
};

// NOTE this trigger is only active when bot is actively returning flag
// (not when hiding in base because enemy has flag too)
class PlayerHasFlag : public Trigger
{
public:
    PlayerHasFlag(ShadowAI* botAI) : Trigger(botAI, "player has flag") {}

    bool IsActive() override;
    static bool IsCapturingFlag(Player* bot);
};

class EnemyFlagCarrierNear : public Trigger
{
public:
    EnemyFlagCarrierNear(ShadowAI* botAI) : Trigger(botAI, "enemy flagcarrier near") {}

    bool IsActive() override;
};

class TeamFlagCarrierNear : public Trigger
{
public:
    TeamFlagCarrierNear(ShadowAI* botAI) : Trigger(botAI, "team flagcarrier near") {}

    bool IsActive() override;
};

class TeamHasFlag : public Trigger
{
public:
    TeamHasFlag(ShadowAI* botAI) : Trigger(botAI, "team has flag") {}

    bool IsActive() override;
};

class EnemyTeamHasFlag : public Trigger
{
public:
    EnemyTeamHasFlag(ShadowAI* botAI) : Trigger(botAI, "enemy team has flag") {}

    bool IsActive() override;
};

class PlayerIsInBattleground : public Trigger
{
public:
    PlayerIsInBattleground(ShadowAI* botAI) : Trigger(botAI, "in Battleground") {}

    bool IsActive() override;
};

class BgWaitingTrigger : public Trigger
{
public:
    BgWaitingTrigger(ShadowAI* botAI) : Trigger(botAI, "bg waiting", 30) {}

    bool IsActive() override;
};

class BgActiveTrigger : public Trigger
{
public:
    BgActiveTrigger(ShadowAI* botAI) : Trigger(botAI, "bg active", 1) {}

    bool IsActive() override;
};

class BgInviteActiveTrigger : public Trigger
{
public:
    BgInviteActiveTrigger(ShadowAI* botAI) : Trigger(botAI, "bg invite active", 10) {}

    bool IsActive() override;
};

class InsideBGTrigger : public Trigger
{
public:
    InsideBGTrigger(ShadowAI* botAI) : Trigger(botAI, "inside bg", 1) {}

    bool IsActive() override;
};
class PlayerIsInBattlegroundWithoutFlag : public Trigger
{
public:
    PlayerIsInBattlegroundWithoutFlag(ShadowAI* botAI) : Trigger(botAI, "in Battleground without flag") {}

    bool IsActive() override;
};

class PlayerWantsInBattlegroundTrigger : public Trigger
{
public:
    PlayerWantsInBattlegroundTrigger(ShadowAI* botAI) : Trigger(botAI, "wants in bg") {}

    bool IsActive() override;
};

class VehicleNearTrigger : public Trigger
{
public:
    VehicleNearTrigger(ShadowAI* botAI) : Trigger(botAI, "vehicle near", 10) {}

    bool IsActive() override;
};

class InVehicleTrigger : public Trigger
{
public:
    InVehicleTrigger(ShadowAI* botAI) : Trigger(botAI, "in vehicle") {}

    bool IsActive() override;
};

class AllianceNoSnowfallGY : public Trigger
{
public:
    AllianceNoSnowfallGY(ShadowAI* botAI) : Trigger(botAI, "alliance no snowfall gy") {}

    bool IsActive() override;
};

#endif
