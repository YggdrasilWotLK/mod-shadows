#ifndef _SHADOW_TRADESTATUSEXTENDEDACTION_H
#define _SHADOW_TRADESTATUSEXTENDEDACTION_H

#include "QueryItemUsageAction.h"

class Player;
class ShadowAI;

class TradeStatusExtendedAction : public QueryItemUsageAction
{
public:
    TradeStatusExtendedAction(ShadowAI* botAI) : QueryItemUsageAction(botAI, "trade status extended") {}

    bool Execute(Event event) override;
};

#endif
