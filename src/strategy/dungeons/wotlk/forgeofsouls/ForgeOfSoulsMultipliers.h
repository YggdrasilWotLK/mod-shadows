#ifndef _SHADOW_WOTLKDUNGEONFOSMULTIPLIERS_H
#define _SHADOW_WOTLKDUNGEONFOSMULTIPLIERS_H

#include "Multiplier.h"

class BronjahmMultiplier : public Multiplier
{
    public:
    BronjahmMultiplier(ShadowAI* ai) : Multiplier(ai, "bronjahm") {}

    public:
        virtual float GetValue(Action* action);
};

class AttackFragmentMultiplier : public Multiplier
{
public:
    AttackFragmentMultiplier(ShadowAI* ai) : Multiplier(ai, "attack fragment") { }

    float GetValue(Action* action) override;
};


#endif
