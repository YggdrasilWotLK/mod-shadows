#ifndef _SHADOW_WOTLKDUNGEONDTKACTIONS_H
#define _SHADOW_WOTLKDUNGEONDTKACTIONS_H

#include "Action.h"
#include "AttackAction.h"
#include "GenericSpellActions.h"
#include "ShadowAI.h"
#include "Shadows.h"
#include "DrakTharonKeepTriggers.h"

const Position NOVOS_PARTY_POSITION = Position(-378.852f, -760.349f, 28.587f);

class CorpseExplodeSpreadAction : public MovementAction
{
public:
    CorpseExplodeSpreadAction(ShadowAI* ai) : MovementAction(ai, "corpse explode spread") {}
    bool Execute(Event event) override;
};

class AvoidArcaneFieldAction : public MovementAction
{
public:
    AvoidArcaneFieldAction(ShadowAI* ai) : MovementAction(ai, "avoid arcane field") {}
    bool Execute(Event event) override;
};

class NovosDefaultPositionAction : public MovementAction
{
public:
    NovosDefaultPositionAction(ShadowAI* ai) : MovementAction(ai, "novos default position") {}
    bool Execute(Event event) override;
    bool isUseful() override;
};

class NovosTargetPriorityAction : public AttackAction
{
public:
    NovosTargetPriorityAction(ShadowAI* ai) : AttackAction(ai, "novos target priority") {}
    bool Execute(Event event) override;
    // bool isUseful() override;
};

class CastSlayingStrikeAction : public CastMeleeSpellAction
{
public:
    CastSlayingStrikeAction(ShadowAI* botAI) : CastMeleeSpellAction(botAI, "slaying strike") {}
};

class CastTauntAction : public CastSpellAction
{
public:
    CastTauntAction(ShadowAI* botAI) : CastSpellAction(botAI, "taunt") {}
};

class CastBoneArmorAction : public CastSpellAction
{
public:
    CastBoneArmorAction(ShadowAI* botAI) : CastSpellAction(botAI, "bone armor") {}
};

class CastTouchOfLifeAction : public CastSpellAction
{
public:
    CastTouchOfLifeAction(ShadowAI* botAI) : CastSpellAction(botAI, "touch of life") {}
};

#endif
