#ifndef _SHADOW_WOTLKDUNGEONOKMULTIPLIERS_H
#define _SHADOW_WOTLKDUNGEONOKMULTIPLIERS_H

#include "Multiplier.h"

class ElderNadoxMultiplier : public Multiplier
{
    public:
        ElderNadoxMultiplier(ShadowAI* ai) : Multiplier(ai, "elder nadox") {}

    public:
        virtual float GetValue(Action* action);
};

class JedogaShadowseekerMultiplier : public Multiplier
{
    public:
        JedogaShadowseekerMultiplier(ShadowAI* ai) : Multiplier(ai, "jedoga shadowseeker") {}

    public:
        virtual float GetValue(Action* action);
};

class ForgottenOneMultiplier : public Multiplier
{
    public:
        ForgottenOneMultiplier(ShadowAI* ai) : Multiplier(ai, "forgotten one") {}

    public:
        virtual float GetValue(Action* action);
};

#endif
