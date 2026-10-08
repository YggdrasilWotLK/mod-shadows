
#ifndef _SHADOW_RAIDVOASTRATEGY_H
#define _SHADOW_RAIDVOASTRATEGY_H

#include "Strategy.h"
#include "ShadowAI.h"
#include "string"
#include "Trigger.h"
#include "vector"

class RaidVoAStrategy : public Strategy
{
public:
    RaidVoAStrategy(ShadowAI* ai) : Strategy(ai) {}
    virtual std::string const getName() override { return "voa"; }
    virtual void InitTriggers(std::vector<TriggerNode*>& triggers) override;
};

#endif
