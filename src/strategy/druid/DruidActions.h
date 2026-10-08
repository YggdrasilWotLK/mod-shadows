/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_DRUIDACTIONS_H
#define _SHADOW_DRUIDACTIONS_H

#include "GenericSpellActions.h"
#include "SharedDefines.h"

class ShadowAI;
class Unit;

class CastFaerieFireAction : public CastDebuffSpellAction
{
public:
    CastFaerieFireAction(ShadowAI* botAI) : CastDebuffSpellAction(botAI, "faerie fire") {}
};

class CastFaerieFireFeralAction : public CastSpellAction
{
public:
    CastFaerieFireFeralAction(ShadowAI* botAI) : CastSpellAction(botAI, "faerie fire (feral)") {}
};

class CastRejuvenationAction : public CastHealingSpellAction
{
public:
    CastRejuvenationAction(ShadowAI* botAI) : CastHealingSpellAction(botAI, "rejuvenation") {}
};

class CastRegrowthAction : public CastHealingSpellAction
{
public:
    CastRegrowthAction(ShadowAI* botAI) : CastHealingSpellAction(botAI, "regrowth") {}
};

class CastHealingTouchAction : public CastHealingSpellAction
{
public:
    CastHealingTouchAction(ShadowAI* botAI) : CastHealingSpellAction(botAI, "healing touch") {}
};

class CastRejuvenationOnPartyAction : public HealPartyMemberAction
{
public:
    CastRejuvenationOnPartyAction(ShadowAI* botAI)
        : HealPartyMemberAction(botAI, "rejuvenation", 15.0f, HealingManaEfficiency::VERY_HIGH)
    {
    }
};

class CastRegrowthOnPartyAction : public HealPartyMemberAction
{
public:
    CastRegrowthOnPartyAction(ShadowAI* botAI)
        : HealPartyMemberAction(botAI, "regrowth", 35.0f, HealingManaEfficiency::HIGH)
    {
    }

    bool isUseful() override;
    Unit* GetTarget() override;
};

class CastHealingTouchOnPartyAction : public HealPartyMemberAction
{
public:
    CastHealingTouchOnPartyAction(ShadowAI* botAI)
        : HealPartyMemberAction(botAI, "healing touch", 50.0f, HealingManaEfficiency::LOW)
    {
    }
};

class CastReviveAction : public ResurrectPartyMemberAction
{
public:
    CastReviveAction(ShadowAI* botAI) : ResurrectPartyMemberAction(botAI, "revive") {}

    NextAction** getPrerequisites() override;
};

class CastRebirthAction : public ResurrectPartyMemberAction
{
public:
    CastRebirthAction(ShadowAI* botAI) : ResurrectPartyMemberAction(botAI, "rebirth") {}

    NextAction** getPrerequisites() override;
    bool isUseful() override;
};

class CastMarkOfTheWildAction : public CastBuffSpellAction
{
public:
    CastMarkOfTheWildAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "mark of the wild") {}
};

class CastMarkOfTheWildOnPartyAction : public BuffOnPartyAction
{
public:
    CastMarkOfTheWildOnPartyAction(ShadowAI* botAI) : BuffOnPartyAction(botAI, "mark of the wild") {}
};

class CastSurvivalInstinctsAction : public CastBuffSpellAction
{
public:
    CastSurvivalInstinctsAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "survival instincts") {}
};

class CastFrenziedRegenerationAction : public CastBuffSpellAction
{
public:
    CastFrenziedRegenerationAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "frenzied regeneration") {}
};

class CastThornsAction : public CastBuffSpellAction
{
public:
    CastThornsAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "thorns") {}
};

class CastThornsOnPartyAction : public BuffOnPartyAction
{
public:
    CastThornsOnPartyAction(ShadowAI* botAI) : BuffOnPartyAction(botAI, "thorns") {}
};

class CastThornsOnMainTankAction : public BuffOnMainTankAction
{
public:
    CastThornsOnMainTankAction(ShadowAI* botAI) : BuffOnMainTankAction(botAI, "thorns", false) {}
};

class CastOmenOfClarityAction : public CastBuffSpellAction
{
public:
    CastOmenOfClarityAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "omen of clarity") {}
};

class CastWrathAction : public CastSpellAction
{
public:
    CastWrathAction(ShadowAI* botAI) : CastSpellAction(botAI, "wrath") {}
};

class CastStarfallAction : public CastSpellAction
{
public:
    CastStarfallAction(ShadowAI* botAI) : CastSpellAction(botAI, "starfall") {}
};

class CastHurricaneAction : public CastSpellAction
{
public:
    CastHurricaneAction(ShadowAI* botAI) : CastSpellAction(botAI, "hurricane") {}
    ActionThreatType getThreatType() override { return ActionThreatType::Aoe; }
};

class CastMoonfireAction : public CastDebuffSpellAction
{
public:
    CastMoonfireAction(ShadowAI* botAI) : CastDebuffSpellAction(botAI, "moonfire", true) {}
};

class CastInsectSwarmAction : public CastDebuffSpellAction
{
public:
    CastInsectSwarmAction(ShadowAI* botAI) : CastDebuffSpellAction(botAI, "insect swarm", true) {}
};

class CastStarfireAction : public CastSpellAction
{
public:
    CastStarfireAction(ShadowAI* botAI) : CastSpellAction(botAI, "starfire") {}
};

class CastEntanglingRootsAction : public CastSpellAction
{
public:
    CastEntanglingRootsAction(ShadowAI* botAI) : CastSpellAction(botAI, "entangling roots") {}
};

class CastEntanglingRootsCcAction : public CastSpellAction
{
public:
    CastEntanglingRootsCcAction(ShadowAI* botAI) : CastSpellAction(botAI, "entangling roots on cc") {}
    Value<Unit*>* GetTargetValue() override;
    bool Execute(Event event) override;
};

class CastHibernateAction : public CastSpellAction
{
public:
    CastHibernateAction(ShadowAI* botAI) : CastSpellAction(botAI, "hibernate") {}
};

class CastHibernateCcAction : public CastSpellAction
{
public:
    CastHibernateCcAction(ShadowAI* botAI) : CastSpellAction(botAI, "hibernate on cc") {}
    Value<Unit*>* GetTargetValue() override;
    bool Execute(Event event) override;
};

class CastNaturesGraspAction : public CastBuffSpellAction
{
public:
    CastNaturesGraspAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "nature's grasp") {}
};

class CastCurePoisonAction : public CastCureSpellAction
{
public:
    CastCurePoisonAction(ShadowAI* botAI) : CastCureSpellAction(botAI, "cure poison") {}
};

class CastCurePoisonOnPartyAction : public CurePartyMemberAction
{
public:
    CastCurePoisonOnPartyAction(ShadowAI* botAI) : CurePartyMemberAction(botAI, "cure poison", DISPEL_POISON) {}
};

class CastAbolishPoisonAction : public CastCureSpellAction
{
public:
    CastAbolishPoisonAction(ShadowAI* botAI) : CastCureSpellAction(botAI, "abolish poison") {}
    NextAction** getAlternatives() override;
};

class CastAbolishPoisonOnPartyAction : public CurePartyMemberAction
{
public:
    CastAbolishPoisonOnPartyAction(ShadowAI* botAI) : CurePartyMemberAction(botAI, "abolish poison", DISPEL_POISON)
    {
    }

    NextAction** getAlternatives() override;
};

class CastBarkskinAction : public CastBuffSpellAction
{
public:
    CastBarkskinAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "barkskin") {}
};

class CastInnervateAction : public CastSpellAction
{
public:
    CastInnervateAction(ShadowAI* botAI) : CastSpellAction(botAI, "innervate") {}

    std::string const GetTargetName() override { return "self target"; }
};

class CastTranquilityAction : public CastAoeHealSpellAction
{
public:
    CastTranquilityAction(ShadowAI* botAI)
        : CastAoeHealSpellAction(botAI, "tranquility", 15.0f, HealingManaEfficiency::MEDIUM)
    {
    }
};

class CastNaturesSwiftnessAction : public CastBuffSpellAction
{
public:
    CastNaturesSwiftnessAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "nature's swiftness") {}
};

class CastWildGrowthOnPartyAction : public HealPartyMemberAction
{
public:
    CastWildGrowthOnPartyAction(ShadowAI* ai)
        : HealPartyMemberAction(ai, "wild growth", 15.0f, HealingManaEfficiency::VERY_HIGH)
    {
    }
};

class CastPartySwiftmendAction : public HealPartyMemberAction
{
public:
    CastPartySwiftmendAction(ShadowAI* ai)
        : HealPartyMemberAction(ai, "swiftmend", 15.0f, HealingManaEfficiency::MEDIUM)
    {
    }
};

class CastPartyNourishAction : public HealPartyMemberAction
{
public:
    CastPartyNourishAction(ShadowAI* ai) : HealPartyMemberAction(ai, "nourish", 25.0f, HealingManaEfficiency::LOW) {}
};

class CastDruidRemoveCurseOnPartyAction : public CurePartyMemberAction
{
public:
    CastDruidRemoveCurseOnPartyAction(ShadowAI* ai) : CurePartyMemberAction(ai, "remove curse", DISPEL_CURSE) {}
};

class CastInsectSwarmOnAttackerAction : public CastDebuffSpellOnAttackerAction
{
public:
    CastInsectSwarmOnAttackerAction(ShadowAI* ai) : CastDebuffSpellOnAttackerAction(ai, "insect swarm") {}
};

class CastMoonfireOnAttackerAction : public CastDebuffSpellOnAttackerAction
{
public:
    CastMoonfireOnAttackerAction(ShadowAI* ai) : CastDebuffSpellOnAttackerAction(ai, "moonfire") {}
};

class CastEnrageAction : public CastBuffSpellAction
{
public:
    CastEnrageAction(ShadowAI* ai) : CastBuffSpellAction(ai, "enrage") {}
};


class CastRejuvenationOnNotFullAction : public HealPartyMemberAction
{
public:
    CastRejuvenationOnNotFullAction(ShadowAI* ai)
        : HealPartyMemberAction(ai, "rejuvenation", 5.0f, HealingManaEfficiency::VERY_HIGH)
    {
    }
    bool isUseful() override;
    Unit* GetTarget() override;
};

class CastForceOfNatureAction : public CastSpellAction
{
public:
    CastForceOfNatureAction(ShadowAI* botAI) : CastSpellAction(botAI, "force of nature") {}
};

#endif