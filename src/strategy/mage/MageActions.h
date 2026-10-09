/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_MAGEACTIONS_H
#define _SHADOW_MAGEACTIONS_H

#include "GenericSpellActions.h"
#include "SharedDefines.h"
#include "UseItemAction.h"

class ShadowAI;

// Buff and Out of Combat Actions

class CastMoltenArmorAction : public CastBuffSpellAction
{
public:
    CastMoltenArmorAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "molten armor") {}
};

class CastMageArmorAction : public CastBuffSpellAction
{
public:
    CastMageArmorAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "mage armor") {}
};

class CastIceArmorAction : public CastBuffSpellAction
{
public:
    CastIceArmorAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "ice armor") {}
};

class CastFrostArmorAction : public CastBuffSpellAction
{
public:
    CastFrostArmorAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "frost armor") {}
};

class CastArcaneIntellectAction : public CastBuffSpellAction
{
public:
    CastArcaneIntellectAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "arcane intellect") {}
};

class CastArcaneIntellectOnPartyAction : public BuffOnPartyAction
{
public:
    CastArcaneIntellectOnPartyAction(ShadowAI* botAI) : BuffOnPartyAction(botAI, "arcane intellect") {}
};

class CastFocusMagicOnPartyAction : public CastSpellAction
{
public:
    CastFocusMagicOnPartyAction(ShadowAI* botAI) : CastSpellAction(botAI, "focus magic") {}
    Unit* GetTarget() override;
};

class CastSummonWaterElementalAction : public CastBuffSpellAction
{
public:
    CastSummonWaterElementalAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "summon water elemental") {}
};

// Boost Actions

class CastCombustionAction : public CastBuffSpellAction
{
public:
    CastCombustionAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "combustion") {}
};

class CastArcanePowerAction : public CastBuffSpellAction
{
public:
    CastArcanePowerAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "arcane power") {}
};

class CastPresenceOfMindAction : public CastBuffSpellAction
{
public:
    CastPresenceOfMindAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "presence of mind") {}
};

class CastIcyVeinsAction : public CastBuffSpellAction
{
public:
    CastIcyVeinsAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "icy veins") {}
};

class CastColdSnapAction : public CastBuffSpellAction
{
public:
    CastColdSnapAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "cold snap") {}
};

// Defensive Actions

class CastFireWardAction : public CastBuffSpellAction
{
public:
    CastFireWardAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "fire ward") {}
};

class CastFrostWardAction : public CastBuffSpellAction
{
public:
    CastFrostWardAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "frost ward") {}
};

class CastIceBarrierAction : public CastBuffSpellAction
{
public:
    CastIceBarrierAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "ice barrier") {}
};

class CastInvisibilityAction : public CastBuffSpellAction
{
public:
    CastInvisibilityAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "invisibility") {}
};
class CastIceBlockAction : public CastBuffSpellAction
{
public:
    CastIceBlockAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "ice block") {}
};

class CastMirrorImageAction : public CastBuffSpellAction
{
public:
    CastMirrorImageAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "mirror image") {}
};

class CastBlinkBackAction : public CastSpellAction
{
public:
    CastBlinkBackAction(ShadowAI* botAI) : CastSpellAction(botAI, "blink") {}
    bool Execute(Event event) override;
};

class CastManaShieldAction : public CastBuffSpellAction
{
public:
    CastManaShieldAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "mana shield") {}
};

// Utility Actions

class CastEvocationAction : public CastSpellAction
{
public:
    CastEvocationAction(ShadowAI* botAI) : CastSpellAction(botAI, "evocation") {}
    std::string const GetTargetName() override { return "self target"; }
};

class CastConjureManaGemAction : public CastBuffSpellAction
{
public:
    CastConjureManaGemAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "conjure mana gem") {}
};

class CastConjureFoodAction : public CastBuffSpellAction
{
public:
    CastConjureFoodAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "conjure food") {}
};

class CastConjureWaterAction : public CastBuffSpellAction
{
public:
    CastConjureWaterAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "conjure water") {}
};

class UseManaSapphireAction : public UseItemAction
{
public:
    UseManaSapphireAction(ShadowAI* botAI) : UseItemAction(botAI, "mana sapphire") {}
    bool isUseful() override;
};
class UseManaEmeraldAction : public UseItemAction
{
public:
    UseManaEmeraldAction(ShadowAI* botAI) : UseItemAction(botAI, "mana emerald") {}
    bool isUseful() override;
};

class UseManaRubyAction : public UseItemAction
{
public:
    UseManaRubyAction(ShadowAI* botAI) : UseItemAction(botAI, "mana ruby") {}
    bool isUseful() override;
};

class UseManaCitrineAction : public UseItemAction
{
public:
    UseManaCitrineAction(ShadowAI* botAI) : UseItemAction(botAI, "mana citrine") {}
    bool isUseful() override;
};

class UseManaJadeAction : public UseItemAction
{
public:
    UseManaJadeAction(ShadowAI* botAI) : UseItemAction(botAI, "mana jade") {}
    bool isUseful() override;
};

class UseManaAgateAction : public UseItemAction
{
public:
    UseManaAgateAction(ShadowAI* botAI) : UseItemAction(botAI, "mana agate") {}
    bool isUseful() override;
};

// CC, Interrupt, and Dispel Actions

class CastPolymorphAction : public CastBuffSpellAction
{
public:
    CastPolymorphAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "polymorph") {}
    Value<Unit*>* GetTargetValue() override;
};

class CastSpellstealAction : public CastSpellAction
{
public:
    CastSpellstealAction(ShadowAI* botAI) : CastSpellAction(botAI, "spellsteal") {}
};

class CastCounterspellAction : public CastSpellAction
{
public:
    CastCounterspellAction(ShadowAI* botAI) : CastSpellAction(botAI, "counterspell") {}
};

class CastCounterspellOnEnemyHealerAction : public CastSpellOnEnemyHealerAction
{
public:
    CastCounterspellOnEnemyHealerAction(ShadowAI* botAI) : CastSpellOnEnemyHealerAction(botAI, "counterspell") {}
};

class CastFrostNovaAction : public CastSpellAction
{
public:
    CastFrostNovaAction(ShadowAI* botAI) : CastSpellAction(botAI, "frost nova") {}
    bool isUseful() override;
};

class CastDeepFreezeAction : public CastSpellAction
{
public:
    CastDeepFreezeAction(ShadowAI* botAI) : CastSpellAction(botAI, "deep freeze") {}
    bool isPossible() override { return true; }
};

class CastRemoveCurseAction : public CastCureSpellAction
{
public:
    CastRemoveCurseAction(ShadowAI* botAI) : CastCureSpellAction(botAI, "remove curse") {}
};

class CastRemoveLesserCurseAction : public CastCureSpellAction
{
public:
    CastRemoveLesserCurseAction(ShadowAI* botAI) : CastCureSpellAction(botAI, "remove lesser curse") {}
};

class CastRemoveCurseOnPartyAction : public CurePartyMemberAction
{
public:
    CastRemoveCurseOnPartyAction(ShadowAI* botAI) : CurePartyMemberAction(botAI, "remove curse", DISPEL_CURSE) {}
};

class CastRemoveLesserCurseOnPartyAction : public CurePartyMemberAction
{
public:
    CastRemoveLesserCurseOnPartyAction(ShadowAI* botAI)
        : CurePartyMemberAction(botAI, "remove lesser curse", DISPEL_CURSE)
    {
    }
};

// Damage and Debuff Actions

class CastFireballAction : public CastSpellAction
{
public:
    CastFireballAction(ShadowAI* botAI) : CastSpellAction(botAI, "fireball") {}
};

class CastScorchAction : public CastSpellAction
{
public:
    CastScorchAction(ShadowAI* botAI) : CastSpellAction(botAI, "scorch") {}
};

class CastFireBlastAction : public CastSpellAction
{
public:
    CastFireBlastAction(ShadowAI* botAI) : CastSpellAction(botAI, "fire blast") {}
};

class CastArcaneBlastAction : public CastBuffSpellAction
{
public:
    CastArcaneBlastAction(ShadowAI* botAI) : CastBuffSpellAction(botAI, "arcane blast") {}
    std::string const GetTargetName() override { return "current target"; }
};

class CastArcaneBarrageAction : public CastSpellAction
{
public:
    CastArcaneBarrageAction(ShadowAI* botAI) : CastSpellAction(botAI, "arcane barrage") {}
};

class CastArcaneMissilesAction : public CastSpellAction
{
public:
    CastArcaneMissilesAction(ShadowAI* botAI) : CastSpellAction(botAI, "arcane missiles") {}
};

class CastPyroblastAction : public CastSpellAction
{
public:
    CastPyroblastAction(ShadowAI* botAI) : CastSpellAction(botAI, "pyroblast") {}
};

class CastLivingBombAction : public CastDebuffSpellAction
{
public:
    CastLivingBombAction(ShadowAI* botAI) : CastDebuffSpellAction(botAI, "living bomb", true) {}
    bool isUseful() override
    {
        // Bypass TTL check
        return CastAuraSpellAction::isUseful();
    }
};

class CastLivingBombOnAttackersAction : public CastDebuffSpellOnAttackerAction
{
public:
    CastLivingBombOnAttackersAction(ShadowAI* botAI) : CastDebuffSpellOnAttackerAction(botAI, "living bomb", true) {}
    bool isUseful() override
    {
        // Bypass TTL check
        return CastAuraSpellAction::isUseful();
    }
};

class CastFrostboltAction : public CastSpellAction
{
public:
    CastFrostboltAction(ShadowAI* botAI) : CastSpellAction(botAI, "frostbolt") {}
};

class CastFrostfireBoltAction : public CastSpellAction
{
public:
    CastFrostfireBoltAction(ShadowAI* botAI) : CastSpellAction(botAI, "frostfire bolt") {}
};

class CastIceLanceAction : public CastSpellAction
{
public:
    CastIceLanceAction(ShadowAI* botAI) : CastSpellAction(botAI, "ice lance") {}
};

class CastBlizzardAction : public CastSpellAction
{
public:
    CastBlizzardAction(ShadowAI* botAI) : CastSpellAction(botAI, "blizzard") {}
    ActionThreatType getThreatType() override { return ActionThreatType::Aoe; }
};

class CastConeOfColdAction : public CastSpellAction
{
public:
    CastConeOfColdAction(ShadowAI* botAI) : CastSpellAction(botAI, "cone of cold") {}
    ActionThreatType getThreatType() override { return ActionThreatType::Aoe; }
    bool isUseful() override;
};

class CastFlamestrikeAction : public CastDebuffSpellAction
{
public:
    CastFlamestrikeAction(ShadowAI* botAI) : CastDebuffSpellAction(botAI, "flamestrike", true, 0.0f) {}
    ActionThreatType getThreatType() override { return ActionThreatType::Aoe; }
};

class CastDragonsBreathAction : public CastSpellAction
{
public:
    CastDragonsBreathAction(ShadowAI* botAI) : CastSpellAction(botAI, "dragon's breath") {}
    ActionThreatType getThreatType() override { return ActionThreatType::Aoe; }
    bool isUseful() override;
};

class CastBlastWaveAction : public CastSpellAction
{
public:
    CastBlastWaveAction(ShadowAI* botAI) : CastSpellAction(botAI, "blast wave") {}
    ActionThreatType getThreatType() override { return ActionThreatType::Aoe; }
    bool isUseful() override;
};

#endif
