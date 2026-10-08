#ifndef _SHADOW_RAIDMCSTRATEGY_H
#define _SHADOW_RAIDMCSTRATEGY_H

#include "AiObjectContext.h"
#include "Multiplier.h"
#include "Strategy.h"

class RaidMcStrategy : public Strategy
{
public:
    RaidMcStrategy(ShadowAI* ai) : Strategy(ai) {}
    virtual std::string const getName() override { return "mc"; }
    virtual void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    // virtual void InitMultipliers(std::vector<Multiplier*> &multipliers) override;
};

#endif
