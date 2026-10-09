#ifndef _SHADOW_RAIDAQ20ACTIONS_H
#define _SHADOW_RAIDAQ20ACTIONS_H

#include "MovementActions.h"
#include "ShadowAI.h"
#include "Shadows.h"

class Aq20UseCrystalAction : public MovementAction
{
public:
    Aq20UseCrystalAction(ShadowAI* botAI, std::string const name = "aq20 use crystal") : MovementAction(botAI, name) {}
    bool Execute(Event event) override;
};
#endif
