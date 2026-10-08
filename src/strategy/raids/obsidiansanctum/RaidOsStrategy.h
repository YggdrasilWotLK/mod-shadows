#ifndef _SHADOW_RAIDOSSTRATEGY_H
#define _SHADOW_RAIDOSSTRATEGY_H

#include "AiObjectContext.h"
#include "Multiplier.h"
#include "Strategy.h"

class RaidOsStrategy : public Strategy
{
public:
    RaidOsStrategy(ShadowAI* ai) : Strategy(ai) {}
    virtual std::string const getName() override { return "wotlk-os"; }
    virtual void InitTriggers(std::vector<TriggerNode*> &triggers) override;
    virtual void InitMultipliers(std::vector<Multiplier*> &multipliers) override;
};

#endif
