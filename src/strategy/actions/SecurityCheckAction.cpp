/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#include "SecurityCheckAction.h"

#include "Event.h"
#include "Playerbots.h"

bool SecurityCheckAction::isUseful()
{
    if (!sRandomPlayerbotMgr->IsRandomBot(bot) || !botAI)
        return false;
    Player* secMaster = botAI->GetMaster();
    if (!secMaster || !secMaster->GetSession())
        return false;
    if (secMaster->GetSession()->GetSecurity() >= SEC_GAMEMASTER)
        return false;
    return !GET_PLAYERBOT_AI(secMaster);
}

bool SecurityCheckAction::Execute(Event event)
{
    if (Group* group = bot->GetGroup())
    {
        LootMethod method = group->GetLootMethod();
        ItemQualities threshold = group->GetLootThreshold();
        if (method == MASTER_LOOT || method == FREE_FOR_ALL || threshold > ITEM_QUALITY_UNCOMMON)
        {
            Player* groupMaster = botAI->GetGroupMaster();
            if (groupMaster && groupMaster->GetSession() &&
                (groupMaster->GetSession()->GetSecurity() == SEC_PLAYER) &&
                (!bot->GetGuildId() || bot->GetGuildId() != groupMaster->GetGuildId()))
            {
                botAI->TellError("I will play with this loot type only if I'm in your guild :/");
                botAI->ChangeStrategy("+passive,+stay", BOT_STATE_NON_COMBAT);
                botAI->ChangeStrategy("+passive,+stay", BOT_STATE_COMBAT);
            }
            return true;
        }
    }

    return false;
}
