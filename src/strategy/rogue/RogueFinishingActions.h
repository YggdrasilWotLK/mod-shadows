/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_ROGUEFINISHINGACTIONS_H
#define _SHADOW_ROGUEFINISHINGACTIONS_H

#include "GenericSpellActions.h"

class ShadowAI;

class CastEviscerateAction : public CastMeleeSpellAction
{
public:
    CastEviscerateAction(ShadowAI* botAI) : CastMeleeSpellAction(botAI, "eviscerate") {}
};

class CastSliceAndDiceAction : public CastMeleeSpellAction
{
public:
    CastSliceAndDiceAction(ShadowAI* botAI) : CastMeleeSpellAction(botAI, "slice and dice") {}
};

class CastExposeArmorAction : public CastDebuffSpellAction
{
public:
    CastExposeArmorAction(ShadowAI* botAI) : CastDebuffSpellAction(botAI, "expose armor", false, 25.0f) {}
};

class CastRuptureAction : public CastDebuffSpellAction
{
public:
    CastRuptureAction(ShadowAI* botAI) : CastDebuffSpellAction(botAI, "rupture", true, 6.0f) {}
};

class CastKidneyShotAction : public CastMeleeSpellAction
{
public:
    CastKidneyShotAction(ShadowAI* botAI) : CastMeleeSpellAction(botAI, "kidney shot") {}
};

#endif
