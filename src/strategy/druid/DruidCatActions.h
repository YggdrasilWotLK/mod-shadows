/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_DRUIDCATACTIONS_H
#define _SHADOW_DRUIDCATACTIONS_H

#include "GenericSpellActions.h"
#include "ReachTargetActions.h"

class ShadowAI;

class CastFeralChargeCatAction : public CastReachTargetSpellAction
{
public:
    CastFeralChargeCatAction(ShadowAI* botAI) : CastReachTargetSpellAction(botAI, "feral charge - cat", 1.5f) {}
};

class CastCowerAction : public CastBuffSpellAction
{
public:
    CastCowerAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "cower") {}
};

class CastBerserkAction : public CastBuffSpellAction
{
public:
    CastBerserkAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "berserk") {}
};

class CastTigersFuryAction : public CastBuffSpellAction
{
public:
    CastTigersFuryAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "tiger's fury") {}
};

class CastSavageRoarAction : public CastBuffSpellAction
{
public:
    CastSavageRoarAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "savage roar") {}
    std::string const GetTargetName() override { return "current target"; }
};

class CastRakeAction : public CastDebuffSpellAction
{
public:
    CastRakeAction(ShadowAI* botAI) : CastDebuffSpellAction(botAI, "rake", true, 6.0f) {}
};

class CastRakeOnMeleeAttackersAction : public CastDebuffSpellOnMeleeAttackerAction
{
public:
    CastRakeOnMeleeAttackersAction(ShadowAI* botAI) : CastDebuffSpellOnMeleeAttackerAction(botAI, "rake", true, 6.0f) {}
};

class CastClawAction : public CastMeleeSpellAction
{
public:
    CastClawAction(ShadowAI* botAI) : CastMeleeSpellAction(botAI, "claw") {}
};

class CastMangleCatAction : public CastMeleeSpellAction
{
public:
    CastMangleCatAction(ShadowAI* botAI) : CastMeleeSpellAction(botAI, "mangle (cat)") {}
};

class CastSwipeCatAction : public CastMeleeSpellAction
{
public:
    CastSwipeCatAction(ShadowAI* botAI) : CastMeleeSpellAction(botAI, "swipe (cat)") {}
};

class CastFerociousBiteAction : public CastMeleeSpellAction
{
public:
    CastFerociousBiteAction(ShadowAI* botAI) : CastMeleeSpellAction(botAI, "ferocious bite") {}
};

class CastRipAction : public CastMeleeDebuffSpellAction
{
public:
    CastRipAction(ShadowAI* botAI) : CastMeleeDebuffSpellAction(botAI, "rip", true, 12.0f) {}
};

class CastShredAction : public CastMeleeSpellAction
{
public:
    CastShredAction(ShadowAI* botAI) : CastMeleeSpellAction(botAI, "shred") {}
};

class CastProwlAction : public CastBuffSpellAction
{
public:
    CastProwlAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "prowl") {}
};

class CastDashAction : public CastBuffSpellAction
{
public:
    CastDashAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "dash") {}
};

class CastRavageAction : public CastMeleeSpellAction
{
public:
    CastRavageAction(ShadowAI* botAI) : CastMeleeSpellAction(botAI, "ravage") {}
};

class CastPounceAction : public CastMeleeSpellAction
{
public:
    CastPounceAction(ShadowAI* botAI) : CastMeleeSpellAction(botAI, "pounce") {}
};

#endif
