/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_AOEVALUES_H
#define _SHADOW_AOEVALUES_H

#include "AiObjectContext.h"
#include "GameObject.h"
#include "Object.h"
#include "Value.h"

class ShadowAI;

class AoePositionValue : public CalculatedValue<WorldLocation>
{
public:
    AoePositionValue(ShadowAI* botAI) : CalculatedValue<WorldLocation>(botAI, "aoe position") {}

    WorldLocation Calculate() override;
};

class AoeCountValue : public CalculatedValue<uint8>
{
public:
    AoeCountValue(ShadowAI* botAI) : CalculatedValue<uint8>(botAI, "aoe count") {}

    uint8 Calculate() override;
};

class HasAreaDebuffValue : public BoolCalculatedValue, public Qualified
{
public:
    HasAreaDebuffValue(ShadowAI* botAI) : BoolCalculatedValue(botAI) {}

    Unit* GetTarget()
    {
        AiObjectContext* ctx = AiObject::context;

        return ctx->GetValue<Unit*>(qualifier)->Get();
    }
    virtual bool Calculate();
};

class AreaDebuffValue : public CalculatedValue<Aura*>
{
public:
    AreaDebuffValue(ShadowAI* botAI) : CalculatedValue<Aura*>(botAI, "area debuff", 1) {}

    Aura* Calculate() override;
};

#endif
