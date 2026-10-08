#ifndef _SHADOW_WOTLKDUNGEONCOSMULTIPLIERS_H
#define _SHADOW_WOTLKDUNGEONCOSMULTIPLIERS_H

#include "Multiplier.h"

class EpochMultiplier : public Multiplier
{
    public:
        EpochMultiplier(ShadowAI* ai) : Multiplier(ai, "chrono-lord epoch") {}

    public:
        virtual float GetValue(Action* action);
};

#endif
