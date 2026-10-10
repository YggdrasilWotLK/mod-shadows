/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#include "NonCombatActions.h"

#include "Event.h"
#include "Shadows.h"

bool DrinkAction::Execute(Event event)
{
    // Already drinking: keep the regen state, do not re-sit or re-delay.
    if (botAI->IsEating())
        return true;

    if (botAI->HasCheat(BotCheatMask::food))
    {
        bot->ClearUnitState(UNIT_STATE_CHASE);
        bot->ClearUnitState(UNIT_STATE_FOLLOW);

        if (bot->isMoving())
            bot->StopMoving();

        bot->SetStandState(UNIT_STAND_STATE_SIT);
        botAI->InterruptSpell();

        // Regen duration stays proportional to the missing mana, but it no
        // longer sleeps the whole AI: the engine keeps ticking (combat and
        // chat commands stay live) and only routine actions are suppressed.
        float mp = bot->GetPowerPct(POWER_MANA);
        float baseMs = bot->InBattleground() ? 12000.0f : 18000.0f;
        botAI->StartEating((uint32)(baseMs * (100.0f - mp) / 100.0f / 1000.0f) + 1);
        botAI->SetNextCheckDelay(botAI->GetReactDelay());

        bot->AddAura(25990, bot);
        return true;
        // return botAI->CastSpell(24707, bot);
    }

    return UseItemAction::Execute(event);
}

bool DrinkAction::isUseful() 
{ 
    return UseItemAction::isUseful() && 
        AI_VALUE2(bool, "has mana", "self target") &&
        AI_VALUE2(uint8, "mana", "self target") < 100;
}

bool DrinkAction::isPossible()
{
    return !bot->IsInCombat() && 
        !bot->IsMounted() &&
        !botAI->HasAnyAuraOf(GetTarget(), "dire bear form", "bear form", "cat form", "travel form",
            "aquatic form","flight form", "swift flight form", nullptr) &&
        (botAI->HasCheat(BotCheatMask::food) || UseItemAction::isPossible());
}

bool EatAction::Execute(Event event)
{
    // Already eating: keep the regen state, do not re-sit or re-delay.
    if (botAI->IsEating())
        return true;

    if (botAI->HasCheat(BotCheatMask::food))
    {
        bot->ClearUnitState(UNIT_STATE_CHASE);
        bot->ClearUnitState(UNIT_STATE_FOLLOW);

        if (bot->isMoving())
            bot->StopMoving();

        bot->SetStandState(UNIT_STAND_STATE_SIT);
        botAI->InterruptSpell();

        // See DrinkAction::Execute: duration without sleeping the AI.
        float hp = bot->GetHealthPct();
        float baseMs = bot->InBattleground() ? 12000.0f : 18000.0f;
        botAI->StartEating((uint32)(baseMs * (100.0f - hp) / 100.0f / 1000.0f) + 1);
        botAI->SetNextCheckDelay(botAI->GetReactDelay());

        bot->AddAura(25990, bot);
        return true;
    }

    return UseItemAction::Execute(event);
}

bool EatAction::isUseful() 
{ 
    return UseItemAction::isUseful() && 
        AI_VALUE2(uint8, "health", "self target") < 100;
}

bool EatAction::isPossible()
{
    return !bot->IsInCombat() && 
        !bot->IsMounted() &&
        !botAI->HasAnyAuraOf(GetTarget(), "dire bear form", "bear form", "cat form", "travel form",
            "aquatic form","flight form", "swift flight form", nullptr) &&
        (botAI->HasCheat(BotCheatMask::food) || UseItemAction::isPossible());
}
