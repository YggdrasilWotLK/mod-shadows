/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_SHADOWDBSTORE_H
#define _SHADOW_SHADOWDBSTORE_H

#include <vector>

#include "Common.h"

class ShadowAI;

class ShadowDbStore
{
public:
    ShadowDbStore() {}
    virtual ~ShadowDbStore() {}
    static ShadowDbStore* instance()
    {
        static ShadowDbStore instance;
        return &instance;
    }

    void Save(ShadowAI* botAI);
    void Load(ShadowAI* botAI);
    void Reset(ShadowAI* botAI);

private:
    void SaveValue(uint32 guid, std::string const key, std::string const value);
    std::string const FormatStrategies(std::string const type, std::vector<std::string> strategies);
};

#define sShadowDbStore ShadowDbStore::instance()

#endif
