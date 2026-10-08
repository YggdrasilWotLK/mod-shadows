#ifndef _SHADOW_WOTLKDUNGEONPOSSTRATEGY_H
#define _SHADOW_WOTLKDUNGEONPOSSTRATEGY_H
#include "Multiplier.h"
#include "Strategy.h"

class WotlkDungeonPoSStrategy : public Strategy
{
public:
    WotlkDungeonPoSStrategy(ShadowAI* ai) : Strategy(ai) {}
    std::string const getName() override { return "pit of saron"; }
    void InitTriggers(std::vector<TriggerNode*> &triggers) override;
    void InitMultipliers(std::vector<Multiplier*> &multipliers) override;

};

#endif  // !_SHADOW_WOTLKDUNGEONFOSSTRATEGY_H
