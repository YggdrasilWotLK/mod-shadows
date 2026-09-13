/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#include "AreaTriggerAction.h"

#include <ctime>
#include <unordered_map>
#include <unordered_set>

#include "Event.h"
#include "LastMovementValue.h"
#include "Playerbots.h"
#include "Transport.h"

static std::unordered_map<ObjectGuid, time_t> mapSeparationSince;
static std::unordered_set<ObjectGuid> mapSeparationNotified;
static const time_t MAP_SEPARATION_MESSAGE_DELAY = 5;

bool ReachAreaTriggerAction::Execute(Event event)
{
    if (botAI->IsRealPlayer())  // Do not trigger own area trigger.
        return false;

    uint32 triggerId;
    WorldPacket p(event.getPacket());
    p.rpos(0);
    p >> triggerId;

    AreaTrigger const* at = sObjectMgr->GetAreaTrigger(triggerId);
    if (!at)
        return false;

    if (!sObjectMgr->GetAreaTriggerTeleport(triggerId))
    {
        WorldPacket p1(CMSG_AREATRIGGER);
        p1 << triggerId;
        p1.rpos(0);
        bot->GetSession()->HandleAreaTriggerOpcode(p1);

        return true;
    }

    if (bot->GetMapId() != at->map)
    {
        Player* master = botAI->GetMaster();
        if (master && master->GetMapId() != bot->GetMapId())
        {
            ObjectGuid guid = bot->GetGUID();
            time_t now = time(nullptr);
            if (mapSeparationNotified.find(guid) == mapSeparationNotified.end())
            {
                auto it = mapSeparationSince.find(guid);
                if (it == mapSeparationSince.end())
                    mapSeparationSince[guid] = now;
                else if (now - it->second >= MAP_SEPARATION_MESSAGE_DELAY)
                {
                    botAI->TellError("I won't follow: too far away");
                    mapSeparationNotified.insert(guid);
                    mapSeparationSince.erase(it);
                }
            }
            return true;
        }
        mapSeparationSince.erase(bot->GetGUID());
        mapSeparationNotified.erase(bot->GetGUID());
        botAI->TellError("I won't follow: too far away");
        return true;
    }

    bot->GetMotionMaster()->MovePoint(at->map, at->x, at->y, at->z);

    float distance = bot->GetDistance(at->x, at->y, at->z);
    float delay = 1000.0f * distance / bot->GetSpeed(MOVE_RUN) + sPlayerbotAIConfig->reactDelay;
    botAI->TellError("Wait for me");
    botAI->SetNextCheckDelay(delay);
    context->GetValue<LastMovement&>("last area trigger")->Get().lastAreaTrigger = triggerId;

    return true;
}

bool AreaTriggerAction::Execute(Event event)
{
    LastMovement& movement = context->GetValue<LastMovement&>("last area trigger")->Get();

    uint32 triggerId = movement.lastAreaTrigger;
    movement.lastAreaTrigger = 0;

    if (!sObjectMgr->GetAreaTrigger(triggerId))
        return false;

    if (!sObjectMgr->GetAreaTriggerTeleport(triggerId))
        return true;

    WorldPacket p(CMSG_AREATRIGGER);
    p << triggerId;
    p.rpos(0);
    bot->GetSession()->HandleAreaTriggerOpcode(p);

    botAI->TellMaster("Hello");
    return true;
}
