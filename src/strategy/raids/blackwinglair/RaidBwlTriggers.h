#ifndef _SHADOW_RAIDBWLTRIGGERS_H
#define _SHADOW_RAIDBWLTRIGGERS_H

#include "ShadowAI.h"
#include "Shadows.h"
#include "Trigger.h"

class BwlSuppressionDeviceTrigger : public Trigger
{
public:
    BwlSuppressionDeviceTrigger(ShadowAI* botAI) : Trigger(botAI, "bwl suppression device") {}
    bool IsActive() override;
};

class BwlAfflictionBronzeTrigger : public Trigger
{
public:
    BwlAfflictionBronzeTrigger(ShadowAI* botAI) : Trigger(botAI, "bwl affliction bronze") {}
    bool IsActive() override;
};

#endif
