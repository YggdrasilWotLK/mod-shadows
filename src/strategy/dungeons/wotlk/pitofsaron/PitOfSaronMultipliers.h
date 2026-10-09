#ifndef _SHADOW_WOTLKDUNGEONPOSMULTIPLIERS_H
#define _SHADOW_WOTLKDUNGEONPOSMULTIPLIERS_H

#include "Multiplier.h"

class IckAndKrickMultiplier : public Multiplier
{
    public:
    IckAndKrickMultiplier(ShadowAI* ai) : Multiplier(ai, "ick and krick") {}

    public:
        virtual float GetValue(Action* action);
};

class GarfrostMultiplier : public Multiplier
{
public:
    GarfrostMultiplier(ShadowAI* ai) : Multiplier(ai, "garfrost") { }

    float GetValue(Action* action) override;
};


#endif
