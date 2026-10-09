#ifndef _SHADOW_RAIDMCTRIGGERS_H
#define _SHADOW_RAIDMCTRIGGERS_H

#include "ShadowAI.h"
#include "Shadows.h"
#include "Trigger.h"

class McLivingBombDebuffTrigger : public Trigger
{
public:
    McLivingBombDebuffTrigger(ShadowAI* botAI) : Trigger(botAI, "mc living bomb debuff") {}
    bool IsActive() override;
};

class McBaronGeddonInfernoTrigger : public Trigger
{
public:
    McBaronGeddonInfernoTrigger(ShadowAI* botAI) : Trigger(botAI, "mc baron geddon inferno") {}
    bool IsActive() override;
};

#endif
