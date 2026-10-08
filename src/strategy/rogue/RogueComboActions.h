/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_ROGUECOMBOACTIONS_H
#define _SHADOW_ROGUECOMBOACTIONS_H

#include "GenericSpellActions.h"

class ShadowAI;

class CastComboAction : public CastMeleeSpellAction
{
public:
    CastComboAction(ShadowAI* botAI, std::string const name) : CastMeleeSpellAction(botAI, name) {}

    bool isUseful() override;
};

class CastSinisterStrikeAction : public CastSpellAction
{
public:
    CastSinisterStrikeAction(ShadowAI* botAI) : CastSpellAction(botAI, "sinister strike") {}
};

class CastMutilateAction : public CastSpellAction
{
public:
    CastMutilateAction(ShadowAI* botAI) : CastSpellAction(botAI, "mutilate") {}
};

class CastRiposteAction : public CastSpellAction
{
public:
    CastRiposteAction(ShadowAI* botAI) : CastSpellAction(botAI, "riposte") {}
};

class CastGougeAction : public CastSpellAction
{
public:
    CastGougeAction(ShadowAI* botAI) : CastSpellAction(botAI, "gouge") {}
};

class CastBackstabAction : public CastSpellAction
{
public:
    CastBackstabAction(ShadowAI* botAI) : CastSpellAction(botAI, "backstab") {}
};

#endif
