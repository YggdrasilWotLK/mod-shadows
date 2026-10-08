#ifndef _SHADOW_RAIDKARAZHANACTIONS_H
#define _SHADOW_RAIDKARAZHANACTIONS_H

#include "Action.h"
#include "MovementActions.h"

class KarazhanAttumenTheHuntsmanStackBehindAction : public MovementAction
{
public:
    KarazhanAttumenTheHuntsmanStackBehindAction(ShadowAI* botAI, std::string const name = "karazhan attumen the huntsman stack behind") : MovementAction(botAI, name) {}

    bool Execute(Event event) override;
    bool isUseful() override;
};

class KarazhanMoroesMarkTargetAction : public Action
{
public:
    KarazhanMoroesMarkTargetAction(ShadowAI* botAI, std::string const name = "karazhan moroes mark target") : Action(botAI, name) {}

    bool Execute(Event event) override;
};

class KarazhanMaidenOfVirtuePositionBossAction : public MovementAction
{
public:
    KarazhanMaidenOfVirtuePositionBossAction(ShadowAI* botAI, std::string const name = "karazhan maiden of virtue position boss") : MovementAction(botAI, name) {}

    bool Execute(Event event) override;
    bool isUseful() override;
};

class KarazhanMaidenOfVirtuePositionRangedAction : public MovementAction
{
public:
    KarazhanMaidenOfVirtuePositionRangedAction(ShadowAI* botAI, std::string const name = "karazhan maiden of virtue position ranged") : MovementAction(botAI, name) {}

    bool Execute(Event event) override;
    bool isUseful() override;
};

class KarazhanBigBadWolfPositionBossAction : public MovementAction
{
public:
    KarazhanBigBadWolfPositionBossAction(ShadowAI* botAI, std::string const name = "karazhan big bad wolf position boss") : MovementAction(botAI, name) {}

    bool Execute(Event event) override;
    bool isUseful() override;
};

class KarazhanBigBadWolfRunAwayAction : public MovementAction
{
public:
    KarazhanBigBadWolfRunAwayAction(ShadowAI* botAI, std::string const name = "karazhan big bad wolf run away") : MovementAction(botAI, name) {}

    bool Execute(Event event) override;
    bool isUseful() override;

private:
    size_t currentIndex = 0;
};

class KarazhanRomuloAndJulianneMarkTargetAction : public Action
{
public:
    KarazhanRomuloAndJulianneMarkTargetAction(ShadowAI* botAI, std::string const name = "karazhan romulo and julianne mark target") : Action(botAI, name) {}

    bool Execute(Event event) override;
};

class KarazhanWizardOfOzMarkTargetAction : public Action
{
public:
    KarazhanWizardOfOzMarkTargetAction(ShadowAI* botAI, std::string const name = "karazhan wizard of oz mark target") : Action(botAI, name) {}

    bool Execute(Event event) override;
};

class KarazhanWizardOfOzScorchStrawmanAction : public Action
{
public:
    KarazhanWizardOfOzScorchStrawmanAction(ShadowAI* botAI, std::string const name = "karazhan wizard of oz scorch strawman") : Action(botAI, name) {}

    bool Execute(Event event) override;
};

class KarazhanTheCuratorMarkTargetAction : public Action
{
public:
    KarazhanTheCuratorMarkTargetAction(ShadowAI* botAI, std::string const name = "karazhan the curator mark target") : Action(botAI, name) {}

    bool Execute(Event event) override;
};

class KarazhanTheCuratorPositionBossAction : public MovementAction
{
public:
    KarazhanTheCuratorPositionBossAction(ShadowAI* botAI, std::string const name = "karazhan the curator position boss") : MovementAction(botAI, name) {}

    bool Execute(Event event) override;
    bool isUseful() override;
};

class KarazhanTheCuratorSpreadRangedAction : public MovementAction
{
public:
    KarazhanTheCuratorSpreadRangedAction(ShadowAI* botAI, std::string const name = "karazhan the curator spread ranged") : MovementAction(botAI, name) {}

    bool Execute(Event event) override;
    bool isUseful() override;
};

class KarazhanTerestianIllhoofMarkTargetAction : public Action
{
public:
    KarazhanTerestianIllhoofMarkTargetAction(ShadowAI* botAI, std::string const name = "karazhan terestian illhoof mark target") : Action(botAI, name) {}

    bool Execute(Event event) override;
};

class KarazhanShadeOfAranArcaneExplosionRunAwayAction : public MovementAction
{
public:
    KarazhanShadeOfAranArcaneExplosionRunAwayAction(ShadowAI* botAI, std::string const name = "karazhan shade of aran arcane explosion run away") : MovementAction(botAI, name) {}

    bool Execute(Event event) override;
    bool isUseful() override;
};

class KarazhanShadeOfAranFlameWreathStopMovementAction : public MovementAction
{
public:
    KarazhanShadeOfAranFlameWreathStopMovementAction(ShadowAI* botAI, std::string const name = "karazhan shade of aran flame wreath stop bot") : MovementAction(botAI, name) {}

    bool Execute(Event event) override;
};

class KarazhanShadeOfAranMarkConjuredElementalAction : public Action
{
public:
    KarazhanShadeOfAranMarkConjuredElementalAction(ShadowAI* botAI, std::string const name = "karazhan shade of aran mark conjured elemental") : Action(botAI, name) {}

    bool Execute(Event event) override;
};

class KarazhanShadeOfAranSpreadRangedAction : public MovementAction
{
public:
    KarazhanShadeOfAranSpreadRangedAction(ShadowAI* botAI, std::string const name = "karazhan shade of aran spread ranged") : MovementAction(botAI, name) {}

    bool Execute(Event event) override;
    bool isUseful() override;
};

class KarazhanNetherspiteBlockRedBeamAction : public MovementAction
{
public:
    KarazhanNetherspiteBlockRedBeamAction(ShadowAI* botAI, std::string const name = "karazhan netherspite block red beam") : MovementAction(botAI, name) {}

    bool Execute(Event event) override;
    bool isUseful() override;
};

class KarazhanNetherspiteBlockBlueBeamAction : public MovementAction
{
public:
    KarazhanNetherspiteBlockBlueBeamAction(ShadowAI* botAI, std::string const name = "karazhan netherspite block blue beam") : MovementAction(botAI, name) {}

    bool Execute(Event event) override;
    bool isUseful() override;
};

class KarazhanNetherspiteBlockGreenBeamAction : public MovementAction
{
public:
    KarazhanNetherspiteBlockGreenBeamAction(ShadowAI* botAI, std::string const name = "karazhan netherspite block green beam") : MovementAction(botAI, name) {}

    bool Execute(Event event) override;
    bool isUseful() override;
};

class KarazhanNetherspiteAvoidBeamAndVoidZoneAction : public MovementAction
{
public:
    KarazhanNetherspiteAvoidBeamAndVoidZoneAction(ShadowAI* botAI, std::string const name = "karazhan netherspite avoid beam and void zone") : MovementAction(botAI, name) {}

    bool Execute(Event event) override;
    bool isUseful() override;
};

class KarazhanNetherspiteBanishPhaseAvoidVoidZoneAction : public MovementAction
{
public:
    KarazhanNetherspiteBanishPhaseAvoidVoidZoneAction(ShadowAI* botAI, std::string const name = "karazhan netherspite banish phase avoid void zone") : MovementAction(botAI, name) {}

    bool Execute(Event event) override;
    bool isUseful() override;
};

class KarazhanPrinceMalchezaarNonTankAvoidHazardAction : public MovementAction
{
public:
    KarazhanPrinceMalchezaarNonTankAvoidHazardAction(ShadowAI* botAI, std::string const name = "karazhan prince malchezaar non-tank avoid hazard") : MovementAction(botAI, name) {}

    bool Execute(Event event) override;
    bool isUseful() override;
};

class KarazhanPrinceMalchezaarTankAvoidHazardAction : public MovementAction
{
public:
    KarazhanPrinceMalchezaarTankAvoidHazardAction(ShadowAI* botAI, std::string const name = "karazhan prince malchezaar tank avoid hazard") : MovementAction(botAI, name) {}

    bool Execute(Event event) override;
    bool isUseful() override;
};

#endif
