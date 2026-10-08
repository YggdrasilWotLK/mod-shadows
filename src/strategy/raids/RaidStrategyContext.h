#ifndef _SHADOW_RAIDSTRATEGYCONTEXT_H_
#define _SHADOW_RAIDSTRATEGYCONTEXT_H_

#include "Strategy.h"
#include "RaidAq20Strategy.h"
#include "RaidMcStrategy.h"
#include "RaidBwlStrategy.h"
#include "RaidKarazhanStrategy.h"
#include "RaidNaxxStrategy.h"
#include "RaidOsStrategy.h"
#include "RaidEoEStrategy.h"
#include "RaidVoAStrategy.h"
#include "RaidUlduarStrategy.h"
#include "RaidOnyxiaStrategy.h"
#include "RaidIccStrategy.h"

class RaidStrategyContext : public NamedObjectContext<Strategy>
{
public:
    RaidStrategyContext() : NamedObjectContext<Strategy>(false, true)
    {
        creators["aq20"] = &RaidStrategyContext::aq20;
        creators["mc"] = &RaidStrategyContext::mc;
        creators["bwl"] = &RaidStrategyContext::bwl;
        creators["karazhan"] = &RaidStrategyContext::karazhan;
        creators["naxx"] = &RaidStrategyContext::naxx;
        creators["wotlk-os"] = &RaidStrategyContext::wotlk_os;
        creators["wotlk-eoe"] = &RaidStrategyContext::wotlk_eoe;
        creators["voa"] = &RaidStrategyContext::voa;
        creators["uld"] = &RaidStrategyContext::uld;
        creators["onyxia"] = &RaidStrategyContext::onyxia;
        creators["icc"] = &RaidStrategyContext::icc;
    }

private:
    static Strategy* aq20(ShadowAI* botAI) { return new RaidAq20Strategy(botAI); }
    static Strategy* mc(ShadowAI* botAI) { return new RaidMcStrategy(botAI); }
    static Strategy* bwl(ShadowAI* botAI) { return new RaidBwlStrategy(botAI); }
    static Strategy* karazhan(ShadowAI* botAI) { return new RaidKarazhanStrategy(botAI); }
    static Strategy* naxx(ShadowAI* botAI) { return new RaidNaxxStrategy(botAI); }
    static Strategy* wotlk_os(ShadowAI* botAI) { return new RaidOsStrategy(botAI); }
    static Strategy* wotlk_eoe(ShadowAI* botAI) { return new RaidEoEStrategy(botAI); }
    static Strategy* voa(ShadowAI* botAI) { return new RaidVoAStrategy(botAI); }
    static Strategy* onyxia(ShadowAI* botAI) { return new RaidOnyxiaStrategy(botAI); }
    static Strategy* uld(ShadowAI* botAI) { return new RaidUlduarStrategy(botAI); }
    static Strategy* icc(ShadowAI* botAI) { return new RaidIccStrategy(botAI); }
};

#endif
