/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_DKACTIONS_H
#define _SHADOW_DKACTIONS_H

#include "Event.h"
#include "GenericSpellActions.h"

class ShadowAI;

class CastBloodPresenceAction : public CastBuffSpellAction
{
public:
    CastBloodPresenceAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "blood presence") {}
};

class CastFrostPresenceAction : public CastBuffSpellAction
{
public:
    CastFrostPresenceAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "frost presence") {}
};

class CastUnholyPresenceAction : public CastBuffSpellAction
{
public:
    CastUnholyPresenceAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "unholy presence") {}
};

class CastDeathchillAction : public CastBuffSpellAction
{
public:
    CastDeathchillAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "deathchill") {}

    NextAction** getPrerequisites() override;
};

class CastDarkCommandAction : public CastSpellAction
{
public:
    CastDarkCommandAction(ShadowAI* botAI) : CastSpellAction(botAI, "dark command") {}
};

BEGIN_RANGED_SPELL_ACTION(CastDeathGripAction, "death grip")
END_SPELL_ACTION()

// Unholy presence
class CastUnholyMeleeSpellAction : public CastMeleeSpellAction
{
public:
    CastUnholyMeleeSpellAction(ShadowAI* botAI, std::string const spell) : CastMeleeSpellAction(botAI, spell) {}

    NextAction** getPrerequisites() override;
};

// Frost presence
class CastFrostMeleeSpellAction : public CastMeleeSpellAction
{
public:
    CastFrostMeleeSpellAction(ShadowAI* botAI, std::string const spell) : CastMeleeSpellAction(botAI, spell) {}

    NextAction** getPrerequisites() override;
};

// Blood presence
class CastBloodMeleeSpellAction : public CastMeleeSpellAction
{
public:
    CastBloodMeleeSpellAction(ShadowAI* botAI, std::string const spell) : CastMeleeSpellAction(botAI, spell) {}

    NextAction** getPrerequisites() override;
};

class CastRuneStrikeAction : public CastMeleeSpellAction
{
public:
    CastRuneStrikeAction(ShadowAI* botAI) : CastMeleeSpellAction(botAI, "rune strike") {}
};

// debuff
//  BEGIN_DEBUFF_ACTION(CastPestilenceAction, "pestilence")
//  END_SPELL_ACTION()

class CastPestilenceAction : public CastSpellAction
{
public:
    CastPestilenceAction(ShadowAI* ai) : CastSpellAction(ai, "pestilence") {}
    ActionThreatType getThreatType() override { return ActionThreatType::None; }
};

// debuff
//  BEGIN_DEBUFF_ACTION(CastHowlingBlastAction, "howling blast")
//  END_SPELL_ACTION()

class CastHowlingBlastAction : public CastSpellAction
{
public:
    CastHowlingBlastAction(ShadowAI* ai) : CastSpellAction(ai, "howling blast") {}
};

// debuff it
//  BEGIN_DEBUFF_ACTION(CastIcyTouchAction, "icy touch")
//  END_SPELL_ACTION()

class CastIcyTouchAction : public CastSpellAction
{
public:
    CastIcyTouchAction(ShadowAI* ai) : CastSpellAction(ai, "icy touch") {}
};

class CastIcyTouchOnAttackerAction : public CastDebuffSpellOnAttackerAction
{
public:
    CastIcyTouchOnAttackerAction(ShadowAI* botAI)
        : CastDebuffSpellOnAttackerAction(botAI, "icy touch", true, .0f)
    {
    }
};

// debuff ps

class CastPlagueStrikeAction : public CastSpellAction
{
public:
    CastPlagueStrikeAction(ShadowAI* ai) : CastSpellAction(ai, "plague strike") {}
};
// BEGIN_DEBUFF_ACTION(CastPlagueStrikeAction, "plague strike")
// END_SPELL_ACTION()

class CastPlagueStrikeOnAttackerAction : public CastDebuffSpellOnMeleeAttackerAction
{
public:
    CastPlagueStrikeOnAttackerAction(ShadowAI* botAI)
        : CastDebuffSpellOnMeleeAttackerAction(botAI, "plague strike", true, .0f)
    {
    }
};

// debuff
BEGIN_DEBUFF_ACTION(CastMarkOfBloodAction, "mark of blood")
END_SPELL_ACTION()

class CastMarkOfBloodOnAttackerAction : public CastDebuffSpellOnAttackerAction
{
public:
    CastMarkOfBloodOnAttackerAction(ShadowAI* botAI) : CastDebuffSpellOnAttackerAction(botAI, "mark of blood", true)
    {
    }
};

class CastUnholyBlightAction : public CastBuffSpellAction
{
public:
    CastUnholyBlightAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "unholy blight") {}
};

class CastSummonGargoyleAction : public CastSpellAction
{
public:
    CastSummonGargoyleAction(ShadowAI* botAI) : CastSpellAction(botAI, "summon gargoyle") {}
};

class CastGhoulFrenzyAction : public CastBuffSpellAction
{
public:
    CastGhoulFrenzyAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "ghoul frenzy", false, 5000) {}
    std::string const GetTargetName() override { return "pet target"; }
};

BEGIN_MELEE_SPELL_ACTION(CastCorpseExplosionAction, "corpse explosion")
END_SPELL_ACTION()

BEGIN_MELEE_SPELL_ACTION(CastAntiMagicShellAction, "anti magic shell")
END_SPELL_ACTION()

BEGIN_MELEE_SPELL_ACTION(CastAntiMagicZoneAction, "anti magic zone")
END_SPELL_ACTION()

class CastChainsOfIceAction : public CastSpellAction
{
public:
    CastChainsOfIceAction(ShadowAI* botAI) : CastSpellAction(botAI, "chains of ice") {}
};

class CastHungeringColdAction : public CastMeleeSpellAction
{
public:
    CastHungeringColdAction(ShadowAI* botAI) : CastMeleeSpellAction(botAI, "hungering cold") {}
};

class CastHeartStrikeAction : public CastMeleeSpellAction
{
public:
    CastHeartStrikeAction(ShadowAI* botAI) : CastMeleeSpellAction(botAI, "heart strike") {}
};

class CastBloodStrikeAction : public CastMeleeSpellAction
{
public:
    CastBloodStrikeAction(ShadowAI* botAI) : CastMeleeSpellAction(botAI, "blood strike") {}
};

class CastFrostStrikeAction : public CastMeleeSpellAction
{
public:
    CastFrostStrikeAction(ShadowAI* botAI) : CastMeleeSpellAction(botAI, "frost strike") {}
};

class CastObliterateAction : public CastMeleeSpellAction
{
public:
    CastObliterateAction(ShadowAI* botAI) : CastMeleeSpellAction(botAI, "obliterate") {}
};

class CastDeathStrikeAction : public CastMeleeSpellAction
{
public:
    CastDeathStrikeAction(ShadowAI* botAI) : CastMeleeSpellAction(botAI, "death strike") {}
};

class CastScourgeStrikeAction : public CastMeleeSpellAction
{
public:
    CastScourgeStrikeAction(ShadowAI* botAI) : CastMeleeSpellAction(botAI, "scourge strike") {}
};

class CastDeathCoilAction : public CastSpellAction
{
public:
    CastDeathCoilAction(ShadowAI* botAI) : CastSpellAction(botAI, "death coil") {}
};

class CastBloodBoilAction : public CastMeleeSpellAction
{
public:
    CastBloodBoilAction(ShadowAI* botAI) : CastMeleeSpellAction(botAI, "blood boil") {}
};

class CastDeathAndDecayAction : public CastSpellAction
{
public:
    CastDeathAndDecayAction(ShadowAI* botAI) : CastSpellAction(botAI, "death and decay") {}
    // ActionThreatType getThreatType() override { return ActionThreatType::Aoe; }
};

class CastHornOfWinterAction : public CastSpellAction
{
public:
    CastHornOfWinterAction(ShadowAI* botAI) : CastSpellAction(botAI, "horn of winter") {}
};

class CastImprovedIcyTalonsAction : public CastBuffSpellAction
{
public:
    CastImprovedIcyTalonsAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "improved icy talons") {}
};

class CastBoneShieldAction : public CastBuffSpellAction
{
public:
    CastBoneShieldAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "bone shield") {}
};

class CastDeathPactAction : public CastBuffSpellAction
{
public:
    CastDeathPactAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "death pact") {}
};

class CastDeathRuneMasteryAction : public CastBuffSpellAction
{
public:
    CastDeathRuneMasteryAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "death rune mastery") {}
};

class CastDancingRuneWeaponAction : public CastSpellAction
{
public:
    CastDancingRuneWeaponAction(ShadowAI* botAI) : CastSpellAction(botAI, "dancing rune weapon") {}
};

class CastEmpowerRuneWeaponAction : public CastBuffSpellAction
{
public:
    CastEmpowerRuneWeaponAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "empower rune weapon") {}
};

class CastArmyOfTheDeadAction : public CastBuffSpellAction
{
public:
    CastArmyOfTheDeadAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "army of the dead") {}
};

class CastRaiseDeadAction : public CastBuffSpellAction
{
public:
    CastRaiseDeadAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "raise dead") {}
    virtual bool Execute(Event event) override;
};

class CastKillingMachineAction : public CastBuffSpellAction
{
public:
    CastKillingMachineAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "killing machine") {}
};

class CastIceboundFortitudeAction : public CastBuffSpellAction
{
public:
    CastIceboundFortitudeAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "icebound fortitude") {}
};

class CastUnbreakableArmorAction : public CastBuffSpellAction
{
public:
    CastUnbreakableArmorAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "unbreakable armor") {}
};

class CastVampiricBloodAction : public CastBuffSpellAction
{
public:
    CastVampiricBloodAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "vampiric blood") {}
};

class CastMindFreezeAction : public CastMeleeSpellAction
{
public:
    CastMindFreezeAction(ShadowAI* botAI) : CastMeleeSpellAction(botAI, "mind freeze") {}
};

class CastStrangulateAction : public CastMeleeSpellAction
{
public:
    CastStrangulateAction(ShadowAI* botAI) : CastMeleeSpellAction(botAI, "strangulate") {}
};

class CastMindFreezeOnEnemyHealerAction : public CastSpellOnEnemyHealerAction
{
public:
    CastMindFreezeOnEnemyHealerAction(ShadowAI* botAI) : CastSpellOnEnemyHealerAction(botAI, "mind freeze") {}
};

class CastRuneTapAction : public CastMeleeSpellAction
{
public:
    CastRuneTapAction(ShadowAI* botAI) : CastMeleeSpellAction(botAI, "rune tap") {}
};

class CastBloodTapAction : public CastMeleeSpellAction
{
public:
    CastBloodTapAction(ShadowAI* botAI) : CastMeleeSpellAction(botAI, "blood tap") {}
};

#endif
