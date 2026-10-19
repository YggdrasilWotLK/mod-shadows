/*
 * Copyright (C) 2016+ YggdrasilCore <yggdrasilcore.github.io>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#include "NearestNonBotPlayersValue.h"

#include "CellImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "Shadows.h"

void NearestNonBotPlayersValue::FindUnits(std::list<Unit*>& targets)
{
    Ycore::AnyUnitInObjectRangeCheck u_check(bot, range);
    Ycore::UnitListSearcher<Ycore::AnyUnitInObjectRangeCheck> searcher(bot, targets, u_check);
    Cell::VisitObjects(bot, searcher, range);
}

bool NearestNonBotPlayersValue::AcceptUnit(Unit* unit)
{
    ObjectGuid guid = unit->GetGUID();
    return guid.IsPlayer() && !GET_SHADOW_AI(((Player*)unit)) &&
           (!((Player*)unit)->IsGameMaster() || ((Player*)unit)->isGMVisible());
}
