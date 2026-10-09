/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_CUSTOMSTRATEGY_H
#define _SHADOW_CUSTOMSTRATEGY_H

#include <map>

#include "Strategy.h"

class ShadowAI;

class CustomStrategy : public Strategy, public Qualified
{
public:
    CustomStrategy(ShadowAI* botAI);

    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    std::string const getName() override { return std::string("custom::" + qualifier); }
    void Reset();

    static std::map<std::string, std::string> actionLinesCache;

private:
    std::vector<std::string> actionLines;
    void LoadActionLines(uint32 owner);
};

#endif
