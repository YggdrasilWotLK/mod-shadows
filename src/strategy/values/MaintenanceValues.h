/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_MAINTANCEVALUE_H
#define _SHADOW_MAINTANCEVALUE_H

#include "Value.h"

class ShadowAI;

class CanMoveAroundValue : public BoolCalculatedValue
{
public:
    CanMoveAroundValue(ShadowAI* botAI) : BoolCalculatedValue(botAI, "can move around", 2 * 2000) {}

    bool Calculate() override;
};

class ShouldHomeBindValue : public BoolCalculatedValue
{
public:
    ShouldHomeBindValue(ShadowAI* botAI) : BoolCalculatedValue(botAI, "should home bind", 2 * 2000) {}

    bool Calculate() override;
};

class ShouldRepairValue : public BoolCalculatedValue
{
public:
    ShouldRepairValue(ShadowAI* botAI) : BoolCalculatedValue(botAI, "should repair", 2 * 2000) {}

    bool Calculate() override;
};

class CanRepairValue : public BoolCalculatedValue
{
public:
    CanRepairValue(ShadowAI* botAI) : BoolCalculatedValue(botAI, "can repair", 2 * 2000) {}

    bool Calculate() override;
};

class ShouldSellValue : public BoolCalculatedValue
{
public:
    ShouldSellValue(ShadowAI* botAI) : BoolCalculatedValue(botAI, "should sell", 2 * 2000) {}

    bool Calculate() override;
};

class CanSellValue : public BoolCalculatedValue
{
public:
    CanSellValue(ShadowAI* botAI) : BoolCalculatedValue(botAI, "can sell", 2 * 2000) {}

    bool Calculate() override;
};

class CanFightEqualValue : public BoolCalculatedValue
{
public:
    CanFightEqualValue(ShadowAI* botAI) : BoolCalculatedValue(botAI, "can fight equal", 2 * 2000) {}

    bool Calculate() override;
};

class CanFightEliteValue : public BoolCalculatedValue
{
public:
    CanFightEliteValue(ShadowAI* botAI) : BoolCalculatedValue(botAI, "can fight elite") {}

    bool Calculate() override;
};

class CanFightBossValue : public BoolCalculatedValue
{
public:
    CanFightBossValue(ShadowAI* botAI) : BoolCalculatedValue(botAI, "can fight boss") {}

    bool Calculate() override;
};

#endif
