#include "Playerbots.h"
#include "AzjolNerubActions.h"
#include "AzjolNerubStrategy.h"


bool AttackWebWrapAction::isUseful() { return !botAI->IsHeal(bot); }
bool AttackWebWrapAction::Execute(Event event)
{
    Unit* webWrap = nullptr;

    // Target is not findable from threat table using AI_VALUE2(),
    // therefore need to search manually for the unit name
    GuidVector targets = AI_VALUE(GuidVector, "possible targets no los");

    for (auto i = targets.begin(); i != targets.end(); ++i)
    {
        Unit* unit = botAI->GetUnit(*i);
        if (unit && unit->GetEntry() == NPC_WEB_WRAP)
        {
            webWrap = unit;
            break;
        }
    }
    if (!webWrap || AI_VALUE(Unit*, "current target") == webWrap)
    {
        return false;
    }

    return Attack(webWrap);
}

bool WatchersTargetAction::isUseful() { return !botAI->IsHeal(bot); }
bool WatchersTargetAction::Execute(Event event)
{
    // Always prioritise web wraps
    Unit* currTarget = AI_VALUE(Unit*, "current target");
    if (currTarget && currTarget->GetEntry() == NPC_WEB_WRAP) { return false; }

    // Do not search all units in range!
    // There are many adds we don't want to aggro in close proximity,
    // only check in-combat adds now.
    GuidVector attackers = AI_VALUE(GuidVector, "attackers");
    Unit* priorityTargets[4] = {nullptr, nullptr, nullptr, nullptr};

    for (auto& attacker : attackers)
    {
        Unit* npc = botAI->GetUnit(attacker);
        if (!npc)
        {
            continue;
        }
        switch (npc->GetEntry())
        {
            // Focus skirmishers first
            case NPC_WATCHER_SKIRMISHER:
                priorityTargets[0] = npc;
                break;
            // Then shadowcaster. This doesn't work so well for the shadowcaster
            // + skirmisher pack - ideally we would kill the watcher second.
            // But don't want to make this unnecessarily complex and rigid...
            // Will revisit if this causes problems in heroic.
            case NPC_WATCHER_SHADOWCASTER:
                priorityTargets[1] = npc;
                break;
            // Named watcher next
            case NPC_WATCHER_SILTHIK:
            case NPC_WATCHER_GASHRA:
            case NPC_WATCHER_NARJIL:
                priorityTargets[2] = npc;
                break;
            // Warrior last
            case NPC_WATCHER_WARRIOR:
                priorityTargets[3] = npc;
                break;
        }
    }

    for (Unit* target : priorityTargets)
    {
        // Attack the first valid split target in the priority list
        if (target)
        {
            if (currTarget != target)
            {
                // bot->Yell("ATTACKING "+target->GetName(), LANG_UNIVERSAL);
                return Attack(target);
            }
            // Don't continue loop here, the target exists so we don't
            // want to move down the prio list. We just don't need to send attack
            // command again, just return false and exit the loop that way
            return false;
        }
    }

    return false;
}

bool WatchersTankPositionAction::Execute(Event event)
{
    // Only tanks should use this action
    if (!botAI->IsTank(bot))
        return false;

    Unit* watcher = nullptr;
    GuidVector attackers = AI_VALUE(GuidVector, "attackers");
    
    // Find any watcher in combat
    for (auto& attacker : attackers)
    {
        Unit* unit = botAI->GetUnit(attacker);
        if (!unit) { continue; }
        
        uint32 entry = unit->GetEntry();
        if (entry == NPC_WATCHER_SILTHIK || entry == NPC_WATCHER_GASHRA || 
            entry == NPC_WATCHER_NARJIL || entry == NPC_WATCHER_SKIRMISHER ||
            entry == NPC_WATCHER_SHADOWCASTER || entry == NPC_WATCHER_WARRIOR)
        {
            watcher = unit;
            break;
        }
    }
    
    if (!watcher)
        return false;
    
    // Main tank should pick up watchers and bring them to stack position
    if (botAI->IsMainTank(bot) && botAI->HasAggro(watcher))
    {
        float distance = bot->GetExactDist2d(AN_WATCHER_STACK_POSITION.GetPositionX(), 
                                             AN_WATCHER_STACK_POSITION.GetPositionY());
        
        if (distance > 3.0f)
        {
            return MoveTo(bot->GetMapId(), 
                         AN_WATCHER_STACK_POSITION.GetPositionX(),
                         AN_WATCHER_STACK_POSITION.GetPositionY(), 
                         AN_WATCHER_STACK_POSITION.GetPositionZ(),
                         false, false, false, false, MovementPriority::MOVEMENT_COMBAT);
        }
        
        // Face the watcher when in position
        if (distance <= 3.0f)
        {
            bot->SetFacingToObject(watcher);
            return true;
        }
    }
    
    // Assist tank should also move to stack position
    if (botAI->IsAssistTank(bot))
    {
        float distance = bot->GetExactDist2d(AN_WATCHER_STACK_POSITION.GetPositionX(), 
                                             AN_WATCHER_STACK_POSITION.GetPositionY());
        
        if (distance > 3.0f)
        {
            return MoveTo(bot->GetMapId(), 
                         AN_WATCHER_STACK_POSITION.GetPositionX(),
                         AN_WATCHER_STACK_POSITION.GetPositionY(), 
                         AN_WATCHER_STACK_POSITION.GetPositionZ(),
                         false, false, false, false, MovementPriority::MOVEMENT_COMBAT);
        }
        
        if (distance <= 3.0f && watcher)
        {
            bot->SetFacingToObject(watcher);
            return true;
        }
    }
    
    return false;
}

bool WatchersGroupStackAction::Execute(Event event)
{
    // This is for non-tanks to stack on the tank
    if (botAI->IsTank(bot))
        return false;
    
    // Check if watchers are active
    GuidVector attackers = AI_VALUE(GuidVector, "attackers");
    bool hasWatcher = false;
    bool hasKrikthir = false;
    
    for (auto& attacker : attackers)
    {
        Unit* unit = botAI->GetUnit(attacker);
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
    
    // Only stack when watchers are active and Krik'thir is not
    if (!hasWatcher || hasKrikthir)
        return false;
    
    // Find the main tank
    Unit* tank = nullptr;
    GuidVector members = AI_VALUE(GuidVector, "group members");
    
    for (auto& memberGuid : members)
    {
        Unit* member = botAI->GetUnit(memberGuid);
        if (!member || !member->IsAlive())
            continue;
        
        if (botAI->IsMainTank(member))
        {
            tank = member;
            break;
        }
    }
    
    // If no main tank found, try assist tank
    if (!tank)
    {
        for (auto& memberGuid : members)
        {
            Unit* member = botAI->GetUnit(memberGuid);
            if (!member || !member->IsAlive())
                continue;
            
            if (botAI->IsTank(member))
            {
                tank = member;
                break;
            }
        }
    }
    
    if (!tank)
        return false;
    
    float distance = bot->GetExactDist2d(tank);
    
    // Stack within 8 yards of the tank for AoE
    if (distance > 8.0f)
    {
        return MoveTo(bot->GetMapId(), 
                     tank->GetPositionX(),
                     tank->GetPositionY(), 
                     tank->GetPositionZ(),
                     false, false, false, false, MovementPriority::MOVEMENT_COMBAT);
    }
    
    return false;
}

bool AnubarakDodgePoundAction::isUseful() { return !AI_VALUE2(bool, "behind", "current target"); }
bool AnubarakDodgePoundAction::Execute(Event event)
{
    Unit* boss = AI_VALUE2(Unit*, "find target", "anub'arak");
    if (!boss) { return false; }

    float distance = bot->GetExactDist2d(boss->GetPosition());
    // Extra units to move into the boss, instead of being just 1 pixel past his midpoint.
    // Can be adjusted - this value tends to mirror how a human would play,
    // and visibly ensures you won't get hit while not creating excessive movements.
    float distanceExtra = 2.0f;
    return Move(bot->GetAngle(boss), distance + distanceExtra);
}