#include "Playerbots.h"
#include "UtgardePinnacleActions.h"
#include "UtgardePinnacleStrategy.h"

bool AvoidFreezingCloudAction::Execute(Event event)
{
    Unit* closestTrigger = nullptr;
    GuidVector objects = AI_VALUE(GuidVector, "nearest hostile npcs");

    for (auto i = objects.begin(); i != objects.end(); ++i)
    {
        Unit* unit = botAI->GetUnit(*i);
        if (unit && unit->GetEntry() == NPC_BREATH_TRIGGER)
        {
            if (!closestTrigger || bot->GetExactDist2d(unit) < bot->GetExactDist2d(closestTrigger))
                closestTrigger = unit;
        }
    }

    if (!closestTrigger)
        return false;

    float distance = bot->GetExactDist2d(closestTrigger->GetPosition());
    float radius = 3.0f;
    float distanceExtra = 3.0f;

    if (distance < radius + distanceExtra - 1.0f)
        return MoveAway(closestTrigger, radius + distanceExtra - distance);

    return false;
}

bool AvoidSkadiWhirlwindAction::Execute(Event event)
{
    Unit* boss = AI_VALUE2(Unit*, "find target", "skadi the ruthless");
    if (!boss)
        return false;

    float distance = bot->GetExactDist2d(boss->GetPosition());
    float radius = 5.0f;
    float distanceExtra = 2.0f;

    if (distance < radius + distanceExtra)
    {
        if (botAI->IsTank(bot))
            return MoveAway(boss, (2.0f * radius) + distanceExtra - distance);
        return MoveAway(boss, radius + distanceExtra - distance);
    }

    return false;
}

bool AvoidYmironBaneAction::Execute(Event event)
{
    Creature* boss = bot->FindNearestCreature(26861, 100.0f);
    if (!boss)
        return false;

    Pet* pet = bot->GetPet();
    if (pet)
        pet->AttackStop();

    if (!boss->HasAura(SPELL_BANE))
    {
        switch (bot->getClass())
        {
            case CLASS_WARRIOR:
            case CLASS_MAGE:
            case CLASS_SHAMAN:
                return false;
        }
    }
	
    if (boss->HasAura(SPELL_BANE))
    {
        switch (bot->getClass())
        {
            case CLASS_WARRIOR:
                if (botAI->CanCastSpell(30356, boss, true))
                    return botAI->CastSpell(30356, boss);
				break;
            case CLASS_MAGE:
                return botAI->CastSpell(30449, boss);
            case CLASS_SHAMAN:
                return botAI->CastSpell(8012, boss);
        }
    }
	
    if (boss->GetVictim() == bot)
        return false;

    float botX = bot->GetPositionX();
    float botY = bot->GetPositionY();
    float bossX = boss->GetPositionX();
    float bossY = boss->GetPositionY();
    
    float dirX = botX - bossX;
    float dirY = botY - bossY;
    float len = sqrt(dirX * dirX + dirY * dirY);
    
    if (len > 0)
    {
        dirX /= len;
        dirY /= len;
    }
    
    float moveDistance = 10.0f;
    float targetX = botX + dirX * moveDistance;
    float targetY = botY + dirY * moveDistance;
    float targetZ = 104.76f;
    
    float minX = 351.0f;
    float maxX = 434.0f;
    float minY = -342.0f;
    float maxY = -306.0f;
    
    targetX = std::max(minX, std::min(maxX, targetX));
    targetY = std::max(minY, std::min(maxY, targetY));
    
    return MoveTo(bot->GetMapId(), targetX, targetY, targetZ);
}