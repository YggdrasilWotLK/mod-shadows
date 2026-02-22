/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _PLAYERBOT_DISCPRIESTSTRATEGY_H
#define _PLAYERBOT_DISCPRIESTSTRATEGY_H

#include "GenericPriestStrategy.h"

class PlayerbotAI;

class DiscPriestStrategy : public GenericPriestStrategy
{
public:
    DiscPriestStrategy(PlayerbotAI* botAI);

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    NextAction** getDefaultActions() override;
    std::string const getName() override { return "disc heal"; }
    uint32 GetType() const override { return STRATEGY_TYPE_HEAL | STRATEGY_TYPE_RANGED; }
};

#endif