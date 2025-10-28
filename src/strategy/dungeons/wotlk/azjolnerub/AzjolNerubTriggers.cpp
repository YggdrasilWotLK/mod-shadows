#include "Playerbots.h"
#include "AzjolNerubTriggers.h"
#include "AiObject.h"
#include "AiObjectContext.h"


bool KrikthirWebWrapTrigger::IsActive()
{
    if (!botAI->IsDps(bot)) { return false; }

    // Target is not findable from threat table using AI_VALUE2(),
    // therefore need to search manually for the unit name
    GuidVector targets = AI_VALUE(GuidVector, "possible targets no los");

    for (auto i = targets.begin(); i != targets.end(); ++i)
    {
        Unit* unit = botAI->GetUnit(*i);
        if (unit && unit->GetEntry() == NPC_WEB_WRAP)
        {
            return true;
        }
    }

    return false;
}

bool KrikthirWatchersTrigger::IsActive()
{
    GuidVector attackers = AI_VALUE(GuidVector, "attackers");
    
    bool hasWatcher = false;
    bool hasKrikthir = false;
    
    for (auto i = attackers.begin(); i != attackers.end(); ++i)
    {
        Unit* unit = botAI->GetUnit(*i);
        if (!unit) { continue; }
        
        uint32 entry = unit->GetEntry();
        
        if (entry == NPC_KRIKTHIR)
        {
            hasKrikthir = true;
        }
        else if (entry == NPC_WATCHER_SILTHIK || entry == NPC_WATCHER_GASHRA || 
                 entry == NPC_WATCHER_NARJIL || entry == NPC_WATCHER_SKIRMISHER ||
                 entry == NPC_WATCHER_SHADOWCASTER || entry == NPC_WATCHER_WARRIOR)
        {
            hasWatcher = true;
        }
    }
    
    return hasWatcher && !hasKrikthir;
}

// bool AnubarakImpaleTrigger::IsActive()
// {
//     Unit* boss = AI_VALUE2(Unit*, "find target", "anub'arak");
//     if (!boss) { return false; }
//     GuidVector triggers = AI_VALUE(GuidVector, "possible triggers");
//     for (auto i = triggers.begin(); i != triggers.end(); i++)
//     {
//         Unit* unit = botAI->GetUnit(*i);

//         if (unit)
//         {
//             bot->Yell("TRIGGER="+unit->GetName(), LANG_UNIVERSAL);
//         }
//     }
//     return false;
// }

bool AnubarakPoundTrigger::IsActive()
{
    Unit* boss = AI_VALUE2(Unit*, "find target", "anub'arak");
    if (!boss) { return false; }

    return boss->HasUnitState(UNIT_STATE_CASTING) && boss->FindCurrentSpellBySpellId(SPELL_POUND);
}