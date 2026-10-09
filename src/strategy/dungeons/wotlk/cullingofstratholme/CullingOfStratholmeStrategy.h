#ifndef _SHADOW_WOTLKDUNGEONCOSSTRATEGY_H
#define _SHADOW_WOTLKDUNGEONCOSSTRATEGY_H

#include "Multiplier.h"
#include "AiObjectContext.h"
#include "Strategy.h"


class WotlkDungeonCoSStrategy : public Strategy
{
public:
    WotlkDungeonCoSStrategy(ShadowAI* ai) : Strategy(ai) {}
    virtual std::string const getName() override { return "culling of stratholme"; }
    virtual void InitTriggers(std::vector<TriggerNode*> &triggers) override;
    virtual void InitMultipliers(std::vector<Multiplier*> &multipliers) override;
};

#endif
