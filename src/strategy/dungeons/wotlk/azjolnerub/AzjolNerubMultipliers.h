#ifndef _SHADOW_WOTLKDUNGEONANMULTIPLIERS_H
#define _SHADOW_WOTLKDUNGEONANMULTIPLIERS_H

#include "Multiplier.h"

class KrikthirMultiplier : public Multiplier
{
    public:
        KrikthirMultiplier(ShadowAI* ai) : Multiplier(ai, "krik'thir the gatewatcher") {}

    public:
        virtual float GetValue(Action* action);
};

#endif
