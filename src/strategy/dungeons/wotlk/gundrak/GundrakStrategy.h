#ifndef _SHADOW_WOTLKDUNGEONGDSTRATEGY_H
#define _SHADOW_WOTLKDUNGEONGDSTRATEGY_H

#include "Multiplier.h"
#include "AiObjectContext.h"
#include "Strategy.h"


class WotlkDungeonGDStrategy : public Strategy
{
public:
    WotlkDungeonGDStrategy(ShadowAI* ai) : Strategy(ai) {}
    virtual std::string const getName() override { return "gundrak"; }
    virtual void InitTriggers(std::vector<TriggerNode*> &triggers) override;
    virtual void InitMultipliers(std::vector<Multiplier*> &multipliers) override;
};

#endif
