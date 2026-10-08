/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_DRUIDBEARACTIONS_H
#define _SHADOW_DRUIDBEARACTIONS_H

#include "GenericSpellActions.h"
#include "ReachTargetActions.h"

class ShadowAI;

class CastFeralChargeBearAction : public CastReachTargetSpellAction
{
public:
    CastFeralChargeBearAction(ShadowAI* botAI) : CastReachTargetSpellAction(botAI, "feral charge - bear", 1.5f) {}
};

class CastGrowlAction : public CastSpellAction
{
public:
    CastGrowlAction(ShadowAI* botAI) : CastSpellAction(botAI, "growl") {}
};

class CastMaulAction : public CastMeleeSpellAction
{
public:
    CastMaulAction(ShadowAI* botAI) : CastMeleeSpellAction(botAI, "maul") {}

    bool isUseful() override;
};

class CastBashAction : public CastMeleeSpellAction
{
public:
    CastBashAction(ShadowAI* botAI) : CastMeleeSpellAction(botAI, "bash") {}
};

class CastSwipeAction : public CastMeleeSpellAction
{
public:
    CastSwipeAction(ShadowAI* botAI) : CastMeleeSpellAction(botAI, "swipe") {}
};

class CastDemoralizingRoarAction : public CastMeleeDebuffSpellAction
{
public:
    CastDemoralizingRoarAction(ShadowAI* botAI) : CastMeleeDebuffSpellAction(botAI, "demoralizing roar") {}
};

class CastMangleBearAction : public CastMeleeSpellAction
{
public:
    CastMangleBearAction(ShadowAI* botAI) : CastMeleeSpellAction(botAI, "mangle (bear)") {}
};

class CastSwipeBearAction : public CastMeleeSpellAction
{
public:
    CastSwipeBearAction(ShadowAI* botAI) : CastMeleeSpellAction(botAI, "swipe (bear)") {}
};

class CastLacerateAction : public CastMeleeSpellAction
{
public:
    CastLacerateAction(ShadowAI* botAI) : CastMeleeSpellAction(botAI, "lacerate") {}
};

class CastBashOnEnemyHealerAction : public CastSpellOnEnemyHealerAction
{
public:
    CastBashOnEnemyHealerAction(ShadowAI* botAI) : CastSpellOnEnemyHealerAction(botAI, "bash") {}
};

#endif
