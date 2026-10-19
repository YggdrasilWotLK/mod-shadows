/*
 * Copyright (C) 2016+ YggdrasilCore <yggdrasilcore.github.io>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#include "NearestNpcsValue.h"

#include "CellImpl.h"
#include "GridNotifiers.h"
#include "GridNotifiersImpl.h"
#include "Shadows.h"
#include "Vehicle.h"

void NearestNpcsValue::FindUnits(std::list<Unit*>& targets)
{
    Ycore::AnyUnitInObjectRangeCheck u_check(bot, range);
    Ycore::UnitListSearcher<Ycore::AnyUnitInObjectRangeCheck> searcher(bot, targets, u_check);
    Cell::VisitObjects(bot, searcher, range);
}

bool NearestNpcsValue::AcceptUnit(Unit* unit) { return !unit->IsPlayer(); }

void NearestHostileNpcsValue::FindUnits(std::list<Unit*>& targets)
{
    Ycore::AnyUnitInObjectRangeCheck u_check(bot, range);
    Ycore::UnitListSearcher<Ycore::AnyUnitInObjectRangeCheck> searcher(bot, targets, u_check);
    Cell::VisitObjects(bot, searcher, range);
}

bool NearestHostileNpcsValue::AcceptUnit(Unit* unit) { return unit->IsHostileTo(bot) && !unit->IsPlayer(); }

void NearestVehiclesValue::FindUnits(std::list<Unit*>& targets)
{
    Ycore::AnyUnitInObjectRangeCheck u_check(bot, range);
    Ycore::UnitListSearcher<Ycore::AnyUnitInObjectRangeCheck> searcher(bot, targets, u_check);
    Cell::VisitObjects(bot, searcher, range);
}

bool NearestVehiclesValue::AcceptUnit(Unit* unit)
{
    if (!unit || !unit->IsVehicle() || !unit->IsAlive())
        return false;

    Vehicle* veh = unit->GetVehicleKit();
    if (!veh || !veh->GetAvailableSeatCount())
        return false;

    return true;
}

void NearestTriggersValue::FindUnits(std::list<Unit*>& targets)
{
    Ycore::AnyUnfriendlyUnitInObjectRangeCheck u_check(bot, bot, range);
    Ycore::UnitListSearcher<Ycore::AnyUnfriendlyUnitInObjectRangeCheck> searcher(bot, targets, u_check);
    Cell::VisitObjects(bot, searcher, range);
}

bool NearestTriggersValue::AcceptUnit(Unit* unit) { return !unit->IsPlayer(); }

void NearestTotemsValue::FindUnits(std::list<Unit*>& targets)
{
    Ycore::AnyUnitInObjectRangeCheck u_check(bot, range);
    Ycore::UnitListSearcher<Ycore::AnyUnitInObjectRangeCheck> searcher(bot, targets, u_check);
    Cell::VisitObjects(bot, searcher, range);
}

bool NearestTotemsValue::AcceptUnit(Unit* unit) { return unit->IsTotem(); }
