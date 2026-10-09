#ifndef _SHADOW_WOTLKDUNGEONUPMULTIPLIERS_H
#define _SHADOW_WOTLKDUNGEONUPMULTIPLIERS_H

#include "Multiplier.h"

class SkadiMultiplier : public Multiplier
{
    public:
        SkadiMultiplier(ShadowAI* ai) : Multiplier(ai, "skadi the ruthless") {}

    public:
        virtual float GetValue(Action* action);
};

class YmironMultiplier : public Multiplier
{
    public:
        YmironMultiplier(ShadowAI* ai) : Multiplier(ai, "king ymiron") {}

    public:
        virtual float GetValue(Action* action);
};

#endif
