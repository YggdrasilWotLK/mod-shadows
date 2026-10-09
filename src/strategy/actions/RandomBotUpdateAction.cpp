/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#include "RandomBotUpdateAction.h"

#include "Event.h"
#include "Shadows.h"

bool RandomBotUpdateAction::Execute(Event event)
{
    if (!sRandomShadowMgr->IsRandomBot(bot))
        return false;

    if (bot->GetGroup() && botAI->GetGroupMaster())
    {
        auto groupMasterBotAI = GET_SHADOW_AI(botAI->GetGroupMaster());
        if (!groupMasterBotAI || groupMasterBotAI->IsRealPlayer())
            return true;
    }

    if (botAI->HasPlayerNearby(sShadowAIConfig->grindDistance))
        return true;

    return sRandomShadowMgr->ProcessBot(bot);
}

bool RandomBotUpdateAction::isUseful() { return AI_VALUE(bool, "random bot update"); }
