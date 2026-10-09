/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_SHADOWDUNGEONSUGGESTIONMGR_H
#define _SHADOW_SHADOWDUNGEONSUGGESTIONMGR_H

#include <map>
#include <vector>

#include "Common.h"
#include "DBCEnums.h"

struct DungeonSuggestion
{
    std::string name;
    Difficulty difficulty;
    uint8 min_level;
    uint8 max_level;
    std::string abbrevation;
    std::string strategy;
};

class ShadowDungeonSuggestionMgr
{
public:
    ShadowDungeonSuggestionMgr(){};
    ~ShadowDungeonSuggestionMgr(){};
    static ShadowDungeonSuggestionMgr* instance()
    {
        static ShadowDungeonSuggestionMgr instance;
        return &instance;
    }

    void LoadDungeonSuggestions();
    std::vector<DungeonSuggestion> const GetDungeonSuggestions();

private:
    std::vector<DungeonSuggestion> m_dungeonSuggestions;
};

#define sShadowDungeonSuggestionMgr ShadowDungeonSuggestionMgr::instance()

#endif
