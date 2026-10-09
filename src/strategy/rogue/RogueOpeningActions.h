/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_ROGUEOPENINGACTIONS_H
#define _SHADOW_ROGUEOPENINGACTIONS_H

#include "GenericSpellActions.h"

class ShadowAI;
class Unit;

class CastSapAction : public CastMeleeSpellAction
{
public:
    CastSapAction(ShadowAI* botAI) : CastMeleeSpellAction(botAI, "sap") {}

    Value<Unit*>* GetTargetValue() override;
    bool isUseful() override { return true; }
};

class CastGarroteAction : public CastDebuffSpellAction
{
public:
    CastGarroteAction(ShadowAI* botAI) : CastDebuffSpellAction(botAI, "garrote", true, 8.0f) {}
};

class CastCheapShotAction : public CastMeleeSpellAction
{
public:
    CastCheapShotAction(ShadowAI* botAI) : CastMeleeSpellAction(botAI, "cheap shot") {}
};

class CastAmbushAction : public CastMeleeSpellAction
{
public:
    CastAmbushAction(ShadowAI* botAI) : CastMeleeSpellAction(botAI, "ambush") {}
};

#endif
