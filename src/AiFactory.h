/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_AIFACTORY_H
#define _SHADOW_AIFACTORY_H

#include <map>

#include "Common.h"

class AiObjectContext;
class Engine;
class Player;
class ShadowAI;

enum BotRoles : uint8;

class AiFactory
{
public:
    static AiObjectContext* createAiObjectContext(Player* player, ShadowAI* botAI);
    static Engine* createCombatEngine(Player* player, ShadowAI* const facade, AiObjectContext* aiObjectContext);
    static Engine* createNonCombatEngine(Player* player, ShadowAI* const facade, AiObjectContext* aiObjectContext);
    static Engine* createDeadEngine(Player* player, ShadowAI* const facade, AiObjectContext* aibjectContext);
    static void AddDefaultNonCombatStrategies(Player* player, ShadowAI* const facade, Engine* nonCombatEngine);
    static void AddDefaultDeadStrategies(Player* player, ShadowAI* const facade, Engine* deadEngine);
    static void AddDefaultCombatStrategies(Player* player, ShadowAI* const facade, Engine* engine);

    static uint8 GetPlayerSpecTab(Player* player);
    static std::map<uint8, uint32> GetPlayerSpecTabs(Player* player);
    static bool IsFeralTank(Player* player);
    static BotRoles GetPlayerRoles(Player* player);
    static std::string GetPlayerSpecName(Player* player);
};

#endif
