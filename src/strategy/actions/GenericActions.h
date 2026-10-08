/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_GENERICACTIONS_H
#define _SHADOW_GENERICACTIONS_H

#include "AttackAction.h"
#include "Action.h"
#include "ShadowAI.h"

class ShadowAI;

class MeleeAction : public AttackAction
{
public:
    MeleeAction(ShadowAI* botAI) : AttackAction(botAI, "melee") {}

    std::string const GetTargetName() override { return "current target"; }
    bool isUseful() override;
};

class TogglePetSpellAutoCastAction : public Action
{
public:
    TogglePetSpellAutoCastAction(ShadowAI* ai) : Action(ai, "toggle pet spell") {}
    virtual bool Execute(Event event) override;
};

class PetAttackAction : public Action
{
public:
    PetAttackAction(ShadowAI* ai) : Action(ai, "pet attack") {}
    virtual bool Execute(Event event) override;
};

class SetPetStanceAction : public Action
{
public:
    SetPetStanceAction(ShadowAI* botAI) : Action(botAI, "set pet stance") {}

    bool Execute(Event event) override;
};

#endif
