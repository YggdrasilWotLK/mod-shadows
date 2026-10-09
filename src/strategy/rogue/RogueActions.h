/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_ROGUEACTIONS_H
#define _SHADOW_ROGUEACTIONS_H

#include "GenericSpellActions.h"
#include "UseItemAction.h"

class ShadowAI;

class CastEvasionAction : public CastBuffSpellAction
{
public:
    CastEvasionAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "evasion") {}
};

class CastCloakOfShadowsAction : public CastBuffSpellAction
{
public:
    CastCloakOfShadowsAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "cloak of shadows") {}
};

class CastHungerForBloodAction : public CastBuffSpellAction
{
public:
    CastHungerForBloodAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "hunger for blood") {}
    std::string const GetTargetName() override { return "current target"; }
};

class CastSprintAction : public CastBuffSpellAction
{
public:
    CastSprintAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "sprint") {}

    std::string const GetTargetName() override { return "self target"; }
};

class CastStealthAction : public CastBuffSpellAction
{
public:
    CastStealthAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "stealth") {}

    std::string const GetTargetName() override { return "self target"; }
    bool isUseful() override;
    bool isPossible() override;
};

class UnstealthAction : public Action
{
public:
    UnstealthAction(ShadowAI* botAI) : Action(botAI, "unstealth") {}

    bool Execute(Event event) override;
};

class CheckStealthAction : public Action
{
public:
    CheckStealthAction(ShadowAI* botAI) : Action(botAI, "check stealth") {}

    bool isPossible() override { return true; }
    bool Execute(Event event) override;
};

class CastKickAction : public CastSpellAction
{
public:
    CastKickAction(ShadowAI* botAI) : CastSpellAction(botAI, "kick") {}
};

class CastFeintAction : public CastBuffSpellAction
{
public:
    CastFeintAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "feint") {}
};

class CastDismantleAction : public CastSpellAction
{
public:
    CastDismantleAction(ShadowAI* botAI) : CastSpellAction(botAI, "dismantle") {}
};

class CastDistractAction : public CastSpellAction
{
public:
    CastDistractAction(ShadowAI* botAI) : CastSpellAction(botAI, "distract") {}
};

class CastVanishAction : public CastBuffSpellAction
{
public:
    CastVanishAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "vanish") {}

    bool isUseful() override;
};

class CastBlindAction : public CastDebuffSpellAction
{
public:
    CastBlindAction(ShadowAI* botAI) : CastDebuffSpellAction(botAI, "blind") {}
};

class CastBladeFlurryAction : public CastBuffSpellAction
{
public:
    CastBladeFlurryAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "blade flurry") {}
};

class CastAdrenalineRushAction : public CastBuffSpellAction
{
public:
    CastAdrenalineRushAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "adrenaline rush") {}
};

class CastKillingSpreeAction : public CastMeleeSpellAction
{
public:
    CastKillingSpreeAction(ShadowAI* botAI) : CastMeleeSpellAction(botAI, "killing spree") {}
};

class CastKickOnEnemyHealerAction : public CastSpellOnEnemyHealerAction
{
public:
    CastKickOnEnemyHealerAction(ShadowAI* botAI) : CastSpellOnEnemyHealerAction(botAI, "kick") {}
};

class CastEnvenomAction : public CastMeleeSpellAction
{
public:
    CastEnvenomAction(ShadowAI* ai) : CastMeleeSpellAction(ai, "envenom") {}
    bool isUseful() override;
    bool isPossible() override;
};

class CastTricksOfTheTradeOnMainTankAction : public BuffOnMainTankAction
{
public:
    CastTricksOfTheTradeOnMainTankAction(ShadowAI* ai) : BuffOnMainTankAction(ai, "tricks of the trade", true) {}
    virtual bool isUseful() override;
};

class UseDeadlyPoisonAction : public UseItemAction
{
public:
    UseDeadlyPoisonAction(ShadowAI* ai) : UseItemAction(ai, "Deadly Poison") {}
    virtual bool Execute(Event event) override;
    virtual bool isPossible() override;
};

class UseInstantPoisonAction : public UseItemAction
{
public:
    UseInstantPoisonAction(ShadowAI* ai) : UseItemAction(ai, "Instant Poison") {}
    virtual bool Execute(Event event) override;
    virtual bool isPossible() override;
};

class UseInstantPoisonOffHandAction : public UseItemAction
{
public:
    UseInstantPoisonOffHandAction(ShadowAI* ai) : UseItemAction(ai, "Instant Poison Off Hand") {}
    virtual bool Execute(Event event) override;
    virtual bool isPossible() override;
};

class FanOfKnivesAction : public CastMeleeSpellAction
{
public:
    FanOfKnivesAction(ShadowAI* ai) : CastMeleeSpellAction(ai, "fan of knives") {}
    ActionThreatType getThreatType() override { return ActionThreatType::Aoe; }
};

#endif
