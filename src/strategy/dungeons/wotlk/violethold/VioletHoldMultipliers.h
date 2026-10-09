#ifndef _SHADOW_WOTLKDUNGEONVHMULTIPLIERS_H
#define _SHADOW_WOTLKDUNGEONVHMULTIPLIERS_H

#include "Multiplier.h"

class ErekemMultiplier : public Multiplier
{
    public:
        ErekemMultiplier(ShadowAI* ai) : Multiplier(ai, "erekem") {}

    public:
        virtual float GetValue(Action* action);
};

class IchoronMultiplier : public Multiplier
{
    public:
        IchoronMultiplier(ShadowAI* ai) : Multiplier(ai, "ichoron") {}

    public:
        virtual float GetValue(Action* action);
};

class ZuramatMultiplier : public Multiplier
{
    public:
        ZuramatMultiplier(ShadowAI* ai) : Multiplier(ai, "zuramat the obliterator") {}

    public:
        virtual float GetValue(Action* action);
};

#endif
