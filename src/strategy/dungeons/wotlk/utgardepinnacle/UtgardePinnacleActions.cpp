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

    // Tank stops attacking but stands still
    if (boss->GetVictim() == bot)
        return false;

    // Warrior/Mage/Shaman must stay close to try to spellsteal/purge Bane
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
	
    // Warrior/Mage/Shaman try to reflect when Bane aura is active
    if (boss->HasAura(SPELL_BANE))
    {
        switch (bot->getClass())
        {
            case CLASS_WARRIOR:
                if (botAI->CanCastSpell(30356, boss, true))
                    return botAI->CastSpell(30356, boss);
                break;
            case CLASS_MAGE:
                if (botAI->CastSpell(30449, boss))
                    return true;
                break;
            case CLASS_SHAMAN:
                if (botAI->CastSpell(8012, boss))
                    return true;
                break;
        }
    }
    
    // Everyone else runs away (including warrior/mage/shaman if spell failed)
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
    
    // Healer: stay within 20 yards of tank
    if (botAI->IsHeal(bot))
    {
        Unit* tank = boss->GetVictim();
        if (tank)
        {
            float distToTank = sqrt(pow(targetX - tank->GetPositionX(), 2) + pow(targetY - tank->GetPositionY(), 2));
            if (distToTank > 20.0f)
            {
                // Clamp position to 20 yards from tank
                float tankDirX = targetX - tank->GetPositionX();
                float tankDirY = targetY - tank->GetPositionY();
                float tankLen = sqrt(tankDirX * tankDirX + tankDirY * tankDirY);
                if (tankLen > 0)
                {
                    tankDirX /= tankLen;
                    tankDirY /= tankLen;
                }
                targetX = tank->GetPositionX() + tankDirX * 20.0f;
                targetY = tank->GetPositionY() + tankDirY * 20.0f;
            }
        }
    }
    
    float minX = 351.0f;
    float maxX = 434.0f;
    float minY = -342.0f;
    float maxY = -306.0f;
    
    targetX = std::max(minX, std::min(maxX, targetX));
    targetY = std::max(minY, std::min(maxY, targetY));
    
    return MoveTo(bot->GetMapId(), targetX, targetY, targetZ);
}
