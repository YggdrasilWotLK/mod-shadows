
#ifndef _SHADOW_RAIDBWLSTRATEGY_H
#define _SHADOW_RAIDBWLSTRATEGY_H

#include "AiObjectContext.h"
#include "Multiplier.h"
#include "Strategy.h"

class RaidBwlStrategy : public Strategy
{
public:
    RaidBwlStrategy(ShadowAI* ai) : Strategy(ai) {}
    virtual std::string const getName() override { return "bwl"; }
    virtual void InitTriggers(std::vector<TriggerNode*>& triggers) override;
    // virtual void InitMultipliers(std::vector<Multiplier*> &multipliers) override;
};

#endif