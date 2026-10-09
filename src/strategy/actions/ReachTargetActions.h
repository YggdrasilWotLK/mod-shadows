/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_REACHTARGETACTIONS_H
#define _SHADOW_REACHTARGETACTIONS_H

#include "GenericSpellActions.h"
#include "MovementActions.h"

class ShadowAI;

class ReachTargetAction : public MovementAction
{
public:
    ReachTargetAction(ShadowAI* botAI, std::string const name, float distance)
        : MovementAction(botAI, name), distance(distance)
    {
    }

    bool Execute(Event event) override;
    bool isUseful() override;
    std::string const GetTargetName() override;

protected:
    float distance;
};

class CastReachTargetSpellAction : public CastSpellAction
{
public:
    CastReachTargetSpellAction(ShadowAI* botAI, std::string const spell, float distance)
        : CastSpellAction(botAI, spell), distance(distance)
    {
    }

    bool isUseful() override;

protected:
    float distance;
};

class ReachMeleeAction : public ReachTargetAction
{
public:
    ReachMeleeAction(ShadowAI* botAI) : ReachTargetAction(botAI, "reach melee", sShadowAIConfig->meleeDistance) {}
};

class ReachSpellAction : public ReachTargetAction
{
public:
    ReachSpellAction(ShadowAI* botAI);
};

class ReachPartyMemberToHealAction : public ReachTargetAction
{
public:
    ReachPartyMemberToHealAction(ShadowAI* botAI);

    std::string const GetTargetName() override;
};

class ReachPartyMemberToResurrectAction : public ReachTargetAction
{
public:
    ReachPartyMemberToResurrectAction(ShadowAI* botAI);

    std::string const GetTargetName() override;
};

#endif
