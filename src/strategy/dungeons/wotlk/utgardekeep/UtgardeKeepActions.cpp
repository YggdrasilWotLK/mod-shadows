#include "Playerbots.h"
#include "UtgardeKeepActions.h"
#include "UtgardeKeepStrategy.h"

bool AttackFrostTombAction::isUseful() { return !botAI->IsHeal(bot); }
bool AttackFrostTombAction::Execute(Event event)
{
    Unit* frostTomb = nullptr;

    // Target is not findable from threat table using AI_VALUE2(),
    // therefore need to search manually for the unit name
    GuidVector targets = AI_VALUE(GuidVector, "possible targets no los");

    for (auto& target : targets)
    {
        Unit* unit = botAI->GetUnit(target);
        if (unit && unit->GetEntry() == NPC_FROST_TOMB)
        {
            frostTomb = unit;
            break;
        }
    }
    if (!frostTomb || AI_VALUE(Unit*, "current target") == frostTomb)
    {
        return false;
    }
    return Attack(frostTomb);
}

// TODO: Possibly add player stacking behaviour close to tank, to prevent Skarvald charging ranged
bool AttackDalronnAction::Execute(Event event)
{
    Unit* boss = AI_VALUE2(Unit*, "find target", "dalronn the controller");
    if (!boss) { return false; }

    if (AI_VALUE(Unit*, "current target") == boss)
    {
        return false;
    }
    return Attack(boss);
}