#ifndef _SHADOW_WOTLKDUNGEONHOSMULTIPLIERS_H
#define _SHADOW_WOTLKDUNGEONHOSMULTIPLIERS_H

#include "Multiplier.h"

class KrystallusMultiplier : public Multiplier
{
    public:
        KrystallusMultiplier(ShadowAI* ai) : Multiplier(ai, "krystallus") {}

    public:
        virtual float GetValue(Action* action);
};

class SjonnirMultiplier : public Multiplier
{
    public:
        SjonnirMultiplier(ShadowAI* ai) : Multiplier(ai, "sjonnir the ironshaper") {}

    public:
        virtual float GetValue(Action* action);
};

#endif
