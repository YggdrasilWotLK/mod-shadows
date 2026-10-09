#ifndef _SHADOW_RAIDAQ20TRIGGERS_H
#define _SHADOW_RAIDAQ20TRIGGERS_H

#include "ShadowAI.h"
#include "Shadows.h"
#include "Trigger.h"

class Aq20MoveToCrystalTrigger : public Trigger
{
public:
    Aq20MoveToCrystalTrigger(ShadowAI* botAI) : Trigger(botAI, "aq20 move to crystal") {}
    bool IsActive() override;
};
#endif
