#ifndef _SHADOW_WOTLKDUNGEONHOLMULTIPLIERS_H
#define _SHADOW_WOTLKDUNGEONHOLMULTIPLIERS_H

#include "Multiplier.h"

class BjarngrimMultiplier : public Multiplier
{
    public:
        BjarngrimMultiplier(ShadowAI* ai) : Multiplier(ai, "general bjarngrim") {}

    public:
        virtual float GetValue(Action* action);
};

class VolkhanMultiplier : public Multiplier
{
    public:
        VolkhanMultiplier(ShadowAI* ai) : Multiplier(ai, "volkhan") {}

    public:
        virtual float GetValue(Action* action);
};

class IonarMultiplier : public Multiplier
{
    public:
        IonarMultiplier(ShadowAI* ai) : Multiplier(ai, "ionar") {}

    public:
        virtual float GetValue(Action* action);
};

class LokenMultiplier : public Multiplier
{
    public:
        LokenMultiplier(ShadowAI* ai) : Multiplier(ai, "loken") {}

    public:
        virtual float GetValue(Action* action);
};

#endif
