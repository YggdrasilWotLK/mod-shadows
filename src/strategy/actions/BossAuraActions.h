/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_BOSSAURAACTION_H
#define _SHADOW_BOSSAURAACTION_H

#include <string>

#include "Action.h"

class ShadowAI;

class BossFireResistanceAction : public Action
{
public:
    BossFireResistanceAction(ShadowAI* botAI, std::string const bossName)
        : Action(botAI, bossName + " fire resistance action"), bossName(bossName)
    {
    }
    bool Execute(Event event) override;
    bool isUseful() override;

private:
    std::string bossName;
};

class BossFrostResistanceAction : public Action
{
public:
    BossFrostResistanceAction(ShadowAI* botAI, std::string const bossName)
        : Action(botAI, bossName + " frost resistance action"), bossName(bossName)
    {
    }
    bool Execute(Event event) override;
    bool isUseful() override;

private:
    std::string bossName;
};

class BossNatureResistanceAction : public Action
{
public:
    BossNatureResistanceAction(ShadowAI* botAI, std::string const bossName)
        : Action(botAI, bossName + " nature resistance action"), bossName(bossName)
    {
    }
    bool Execute(Event event) override;
    bool isUseful() override;

private:
    std::string bossName;
};

class BossShadowResistanceAction : public Action
{
public:
    BossShadowResistanceAction(ShadowAI* botAI, std::string const bossName)
        : Action(botAI, bossName + " shadow resistance action"), bossName(bossName)
    {
    }
    bool Execute(Event event) override;
    bool isUseful() override;

private:
    std::string bossName;
};

#endif
