/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_HUNTERACTIONS_H
#define _SHADOW_HUNTERACTIONS_H

#include "AiObject.h"
#include "Event.h"
#include "GenericSpellActions.h"
#include "Unit.h"

class ShadowAI;
class Unit;

// Buff and Out of Combat Spells

class CastTrueshotAuraAction : public CastBuffSpellAction
{
public:
    CastTrueshotAuraAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "trueshot aura") {}
};

class CastAspectOfTheHawkAction : public CastBuffSpellAction
{
public:
    CastAspectOfTheHawkAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "aspect of the hawk") {}
    bool isUseful() override;
};

class CastAspectOfTheMonkeyAction : public CastBuffSpellAction
{
public:
    CastAspectOfTheMonkeyAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "aspect of the monkey") {}
};

class CastAspectOfTheDragonhawkAction : public CastBuffSpellAction
{
public:
    CastAspectOfTheDragonhawkAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "aspect of the dragonhawk") {}
};

class CastAspectOfTheWildAction : public CastBuffSpellAction
{
public:
    CastAspectOfTheWildAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "aspect of the wild") {}
};

class CastAspectOfTheCheetahAction : public CastBuffSpellAction
{
public:
    CastAspectOfTheCheetahAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "aspect of the cheetah") {}

    bool isUseful() override;
};

class CastAspectOfThePackAction : public CastBuffSpellAction
{
public:
    CastAspectOfThePackAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "aspect of the pack") {}
};

class CastAspectOfTheViperAction : public CastBuffSpellAction
{
public:
    CastAspectOfTheViperAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "aspect of the viper") {}
};

// Cooldown Spells

class CastRapidFireAction : public CastBuffSpellAction
{
public:
    CastRapidFireAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "rapid fire") {}
};

class CastDeterrenceAction : public CastBuffSpellAction
{
public:
    CastDeterrenceAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "deterrence") {}
};

class CastReadinessAction : public CastBuffSpellAction
{
public:
    CastReadinessAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "readiness") {}
};

class CastDisengageAction : public CastSpellAction
{
public:
    CastDisengageAction(ShadowAI* botAI) : CastSpellAction(botAI, "disengage") {}

    bool Execute(Event event) override;
    bool isUseful() override;
};

// CC Spells

class CastScareBeastAction : public CastSpellAction
{
public:
    CastScareBeastAction(ShadowAI* botAI) : CastSpellAction(botAI, "scare beast") {}
};

class CastScareBeastCcAction : public CastSpellAction
{
public:
    CastScareBeastCcAction(ShadowAI* botAI) : CastSpellAction(botAI, "scare beast on cc") {}

    Value<Unit*>* GetTargetValue() override;
    bool Execute(Event event) override;
};

class CastFreezingTrap : public CastDebuffSpellAction
{
public:
    CastFreezingTrap(ShadowAI* botAI) : CastDebuffSpellAction(botAI, "freezing trap") {}

    Value<Unit*>* GetTargetValue() override;
};

class CastWyvernStingAction : public CastDebuffSpellAction
{
public:
    CastWyvernStingAction(ShadowAI* botAI) : CastDebuffSpellAction(botAI, "wyvern sting", true) {}
};

class CastSilencingShotAction : public CastSpellAction
{
public:
    CastSilencingShotAction(ShadowAI* botAI) : CastSpellAction(botAI, "silencing shot") {}
};

class CastConcussiveShotAction : public CastSnareSpellAction
{
public:
    CastConcussiveShotAction(ShadowAI* botAI) : CastSnareSpellAction(botAI, "concussive shot") {}
};

class CastIntimidationAction : public CastBuffSpellAction
{
public:
    CastIntimidationAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "intimidation", false, 5000) {}
    std::string const GetTargetName() override { return "pet target"; }
};

// Threat Spells

class CastDistractingShotAction : public CastSpellAction
{
public:
    CastDistractingShotAction(ShadowAI* botAI) : CastSpellAction(botAI, "distracting shot") {}
};

class CastMisdirectionOnMainTankAction : public BuffOnMainTankAction
{
public:
    CastMisdirectionOnMainTankAction(ShadowAI* ai) : BuffOnMainTankAction(ai, "misdirection", true) {}
};

class CastFeignDeathAction : public CastBuffSpellAction
{
public:
    CastFeignDeathAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "feign death") {}
};

// Pet Spells

class FeedPetAction : public Action
{
public:
    FeedPetAction(ShadowAI* botAI) : Action(botAI, "feed pet") {}

    bool Execute(Event event) override;
};

class CastCallPetAction : public CastBuffSpellAction
{
public:
    CastCallPetAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "call pet") {}
};

class CastMendPetAction : public CastAuraSpellAction
{
public:
    CastMendPetAction(ShadowAI* botAI) : CastAuraSpellAction(botAI, "mend pet") {}
    std::string const GetTargetName() override { return "pet target"; }
};

class CastRevivePetAction : public CastBuffSpellAction
{
public:
    CastRevivePetAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "revive pet") {}
};

class CastKillCommandAction : public CastBuffSpellAction
{
public:
    CastKillCommandAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "kill command", false, 5000) {}
    std::string const GetTargetName() override { return "pet target"; }
};

class CastBestialWrathAction : public CastBuffSpellAction
{
public:
    CastBestialWrathAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "bestial wrath", false, 5000) {}
    std::string const GetTargetName() override { return "pet target"; }
};

// Direct Damage Spells

class CastAutoShotAction : public CastSpellAction
{
public:
    CastAutoShotAction(ShadowAI* botAI) : CastSpellAction(botAI, "auto shot") {}
    ActionThreatType getThreatType() override { return ActionThreatType::None; }
    bool isUseful() override;
};

class CastArcaneShotAction : public CastSpellAction
{
public:
    CastArcaneShotAction(ShadowAI* botAI) : CastSpellAction(botAI, "arcane shot") {}
    bool isUseful() override;
};

class CastAimedShotAction : public CastSpellAction
{
public:
    CastAimedShotAction(ShadowAI* botAI) : CastSpellAction(botAI, "aimed shot") {}
};

class CastChimeraShotAction : public CastSpellAction
{
public:
    CastChimeraShotAction(ShadowAI* botAI) : CastSpellAction(botAI, "chimera shot") {}
};

class CastSteadyShotAction : public CastSpellAction
{
public:
    CastSteadyShotAction(ShadowAI* botAI) : CastSpellAction(botAI, "steady shot") {}
};

class CastKillShotAction : public CastSpellAction
{
public:
    CastKillShotAction(ShadowAI* botAI) : CastSpellAction(botAI, "kill shot") {}
};

// DoT/Debuff Spells

class CastHuntersMarkAction : public CastDebuffSpellAction
{
public:
    CastHuntersMarkAction(ShadowAI* botAI) : CastDebuffSpellAction(botAI, "hunter's mark") {}
    bool isUseful() override
    {
        // Bypass TTL check
        return CastAuraSpellAction::isUseful();
    }
};

class CastTranquilizingShotAction : public CastSpellAction
{
public:
    CastTranquilizingShotAction(ShadowAI* botAI) : CastSpellAction(botAI, "tranquilizing shot") {}
};

class CastViperStingAction : public CastDebuffSpellAction
{
public:
    CastViperStingAction(ShadowAI* botAI) : CastDebuffSpellAction(botAI, "viper sting", true) {}
    bool isUseful() override;
};

class CastSerpentStingAction : public CastDebuffSpellAction
{
public:
    CastSerpentStingAction(ShadowAI* botAI) : CastDebuffSpellAction(botAI, "serpent sting", true) {}
    bool isUseful() override
    {
        // Bypass TTL check
        return CastAuraSpellAction::isUseful();
    }
};

class CastScorpidStingAction : public CastDebuffSpellAction
{
public:
    CastScorpidStingAction(ShadowAI* botAI) : CastDebuffSpellAction(botAI, "scorpid sting", true) {}
    bool isUseful() override
    {
        // Bypass TTL check
        return CastAuraSpellAction::isUseful();
    }
};

class CastSerpentStingOnAttackerAction : public CastDebuffSpellOnAttackerAction
{
public:
    CastSerpentStingOnAttackerAction(ShadowAI* botAI) : CastDebuffSpellOnAttackerAction(botAI, "serpent sting", true) {}
    bool isUseful() override
    {
        // Bypass TTL check
        return CastAuraSpellAction::isUseful();
    }
};

class CastImmolationTrapAction : public CastSpellAction
{
public:
    CastImmolationTrapAction(ShadowAI* botAI) : CastSpellAction(botAI, "immolation trap") {}
    bool isUseful() override;
};

class CastExplosiveTrapAction : public CastSpellAction
{
public:
    CastExplosiveTrapAction(ShadowAI* botAI) : CastSpellAction(botAI, "explosive trap") {}
};

class CastBlackArrow : public CastDebuffSpellAction
{
public:
    CastBlackArrow(ShadowAI* botAI) : CastDebuffSpellAction(botAI, "black arrow", true) {}
    bool isUseful() override
    {
        if (botAI->HasStrategy("trap weave", BOT_STATE_COMBAT))
            return false;
        // Bypass TTL check
        return CastAuraSpellAction::isUseful();
    }
};

class CastExplosiveShotAction : public CastDebuffSpellAction
{
public:
    CastExplosiveShotAction(ShadowAI* botAI) : CastDebuffSpellAction(botAI, "explosive shot", true, 0.0f) {}
    bool isUseful() override
    {
        // Bypass TTL check
        return CastAuraSpellAction::isUseful();
    }
};

// Rank 4
class CastExplosiveShotRank4Action : public CastDebuffSpellAction
{
public:
    CastExplosiveShotRank4Action(ShadowAI* botAI) : CastDebuffSpellAction(botAI, "explosive shot", true, 0.0f) {}

    bool Execute(Event event) override { return botAI->CastSpell(60053, GetTarget()); }
    bool isUseful() override
    {
        Unit* target = GetTarget();
        if (!target)
            return false;
        return !target->HasAura(60053);
    }
};

// Rank 3
class CastExplosiveShotRank3Action : public CastDebuffSpellAction
{
public:
    CastExplosiveShotRank3Action(ShadowAI* botAI) : CastDebuffSpellAction(botAI, "explosive shot", true, 0.0f) {}

    bool Execute(Event event) override { return botAI->CastSpell(60052, GetTarget()); }
    bool isUseful() override
    {
        Unit* target = GetTarget();
        if (!target)
            return false;
        return !target->HasAura(60052);
    }
};

// Rank 2
class CastExplosiveShotRank2Action : public CastDebuffSpellAction
{
public:
    CastExplosiveShotRank2Action(ShadowAI* botAI) : CastDebuffSpellAction(botAI, "explosive shot", true, 0.0f) {}

    bool Execute(Event event) override { return botAI->CastSpell(60051, GetTarget()); }
    bool isUseful() override
    {
        Unit* target = GetTarget();
        if (!target)
            return false;
        return !target->HasAura(60051);
    }
};

// Rank 1
class CastExplosiveShotRank1Action : public CastDebuffSpellAction
{
public:
    CastExplosiveShotRank1Action(ShadowAI* botAI) : CastDebuffSpellAction(botAI, "explosive shot", true, 0.0f) {}

    bool Execute(Event event) override { return botAI->CastSpell(53301, GetTarget()); }
    bool isUseful() override
    {
        Unit* target = GetTarget();
        if (!target)
            return false;
        return !target->HasAura(53301);
    }
};

// Melee Spells

class CastWingClipAction : public CastSpellAction
{
public:
    CastWingClipAction(ShadowAI* botAI) : CastSpellAction(botAI, "wing clip") {}

    bool isUseful() override;
    NextAction** getPrerequisites() override;
};

class CastRaptorStrikeAction : public CastSpellAction
{
public:
    CastRaptorStrikeAction(ShadowAI* botAI) : CastSpellAction(botAI, "raptor strike") {}
};

class CastMongooseBiteAction : public CastSpellAction
{
public:
    CastMongooseBiteAction(ShadowAI* botAI) : CastSpellAction(botAI, "mongoose bite") {}
};

// AoE Spells

class CastMultiShotAction : public CastSpellAction
{
public:
    CastMultiShotAction(ShadowAI* botAI) : CastSpellAction(botAI, "multi-shot") {}
};

class CastVolleyAction : public CastSpellAction
{
public:
    CastVolleyAction(ShadowAI* botAI) : CastSpellAction(botAI, "volley") {}
    ActionThreatType getThreatType() override { return ActionThreatType::Aoe; }
};

#endif
