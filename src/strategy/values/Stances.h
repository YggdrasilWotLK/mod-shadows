/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_STANCES_H
#define _SHADOW_STANCES_H

#include "Action.h"
#include "Formations.h"

class ShadowAI;
class Unit;

class Stance : public Formation
{
public:
    Stance(ShadowAI* botAI, std::string const name) : Formation(botAI, name) {}

    WorldLocation GetLocation() override;
    std::string const GetTargetName() override;
    float GetMaxDistance() override;

protected:
    virtual Unit* GetTarget();
    virtual WorldLocation GetLocationInternal() = 0;
    virtual WorldLocation GetNearLocation(float angle, float distance);
};

class MoveStance : public Stance
{
public:
    MoveStance(ShadowAI* botAI, std::string const name) : Stance(botAI, name) {}

protected:
    WorldLocation GetLocationInternal();
    virtual float GetAngle() = 0;
};

class StanceValue : public ManualSetValue<Stance*>
{
public:
    StanceValue(ShadowAI* botAI);
    ~StanceValue();

    std::string const Save() override;
    bool Load(std::string const value) override;
};

class SetStanceAction : public Action
{
public:
    SetStanceAction(ShadowAI* botAI) : Action(botAI, "set Stance") {}

    bool Execute(Event event) override;
};

#endif
