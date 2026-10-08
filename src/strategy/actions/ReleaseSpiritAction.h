/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef SHADOW_RELEASESPIRITACTION_H
#define SHADOW_RELEASESPIRITACTION_H

#include "Action.h"
#include "ReviveFromCorpseAction.h"

class ShadowAI;

class ReleaseSpiritAction : public Action
{
public:
    ReleaseSpiritAction(ShadowAI* botAI, const std::string& name = "release")
        : Action(botAI, name) {}

    bool Execute(Event event) override;
    void LogRelease(const std::string& releaseType, bool isAutoRelease = false) const;

protected:
    void IncrementDeathCount() const;
};

class AutoReleaseSpiritAction : public ReleaseSpiritAction
{
public:
    AutoReleaseSpiritAction(ShadowAI* botAI, const std::string& name = "auto release")
        : ReleaseSpiritAction(botAI, name) {}

    bool Execute(Event event) override;
    bool isUseful() override;

private:
    bool HandleBattlegroundSpiritHealer();
    bool ShouldAutoRelease() const;
    bool ShouldDelayBattlegroundRelease() const;

    time_t m_bgGossipTime = 0;
};

class RepopAction : public SpiritHealerAction
{
public:
    RepopAction(ShadowAI* botAI, const std::string& name = "repop")
        : SpiritHealerAction(botAI, name) {}

    bool Execute(Event event) override;
    bool isUseful() override;

private:
    int64 CalculateDeadTime() const;
    void PerformGraveyardTeleport(const GraveyardStruct* graveyard) const;
};

// SelfResurrectAction action registration
class SelfResurrectAction : public Action
{
public:
    SelfResurrectAction(ShadowAI* ai) : Action(ai, "self resurrect") {}
    virtual bool Execute(Event event) override;
    bool isUseful() override;
};

#endif
