/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_PALADINBUFFSTRATEGIES_H
#define _SHADOW_PALADINBUFFSTRATEGIES_H

#include "Strategy.h"

class ShadowAI;

class PaladinBuffManaStrategy : public Strategy
{
public:
    PaladinBuffManaStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "bmana"; }
};

class PaladinBuffHealthStrategy : public Strategy
{
public:
    PaladinBuffHealthStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "bhealth"; }
};

class PaladinBuffDpsStrategy : public Strategy
{
public:
    PaladinBuffDpsStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "bdps"; }
};

class PaladinBuffArmorStrategy : public Strategy
{
public:
    PaladinBuffArmorStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "barmor"; }
};

class PaladinBuffAoeStrategy : public Strategy
{
public:
    PaladinBuffAoeStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "baoe"; }
};

class PaladinBuffCastStrategy : public Strategy
{
public:
    PaladinBuffCastStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "bcast"; }
};

class PaladinBuffSpeedStrategy : public Strategy
{
public:
    PaladinBuffSpeedStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "bspeed"; }
};

class PaladinBuffThreatStrategy : public Strategy
{
public:
    PaladinBuffThreatStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "bthreat"; }
};

class PaladinBuffStatsStrategy : public Strategy
{
public:
    PaladinBuffStatsStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "bstats"; }
};

class PaladinShadowResistanceStrategy : public Strategy
{
public:
    PaladinShadowResistanceStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "rshadow"; }
};

class PaladinFrostResistanceStrategy : public Strategy
{
public:
    PaladinFrostResistanceStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "rfrost"; }
};

class PaladinFireResistanceStrategy : public Strategy
{
public:
    PaladinFireResistanceStrategy(ShadowAI* botAI) : Strategy(botAI) {}

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return "rfire"; }
};

#endif
