/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_DRUIDSHAPESHIFTACTIONS_H
#define _SHADOW_DRUIDSHAPESHIFTACTIONS_H

#include "GenericSpellActions.h"

class ShadowAI;

class CastBearFormAction : public CastBuffSpellAction
{
public:
    CastBearFormAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "bear form") {}

    bool isPossible() override;
    bool isUseful() override;
};

class CastDireBearFormAction : public CastBuffSpellAction
{
public:
    CastDireBearFormAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "dire bear form") {}

    NextAction** getAlternatives() override;
};

class CastCatFormAction : public CastBuffSpellAction
{
public:
    CastCatFormAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "cat form") {}
};

class CastTreeFormAction : public CastBuffSpellAction
{
public:
    CastTreeFormAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "tree of life") {}
    bool isUseful() override;
};

class CastMoonkinFormAction : public CastBuffSpellAction
{
public:
    CastMoonkinFormAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "moonkin form") {}
};

class CastAquaticFormAction : public CastBuffSpellAction
{
public:
    CastAquaticFormAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "aquatic form") {}
};

class CastTravelFormAction : public CastBuffSpellAction
{
public:
    CastTravelFormAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "travel form") {}

    bool isUseful() override;
};

class CastCasterFormAction : public CastBuffSpellAction
{
public:
    CastCasterFormAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "caster form") {}

    bool isUseful() override;
    bool isPossible() override { return true; }
    bool Execute(Event event) override;
};

class CastCancelTreeFormAction : public CastBuffSpellAction
{
public:
    CastCancelTreeFormAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "cancel tree form") {}

    bool isUseful() override;
    bool isPossible() override { return true; }
    bool Execute(Event event) override;
};

#endif
