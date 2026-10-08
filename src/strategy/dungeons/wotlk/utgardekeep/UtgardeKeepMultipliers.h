#ifndef _SHADOW_WOTLKDUNGEONUKMULTIPLIERS_H
#define _SHADOW_WOTLKDUNGEONUKMULTIPLIERS_H

#include "Multiplier.h"

class PrinceKelesethMultiplier : public Multiplier
{
    public:
        PrinceKelesethMultiplier(ShadowAI* ai) : Multiplier(ai, "prince keleseth") {}

    public:
        virtual float GetValue(Action* action);
};

class SkarvaldAndDalronnMultiplier : public Multiplier
{
    public:
        SkarvaldAndDalronnMultiplier(ShadowAI* ai) : Multiplier(ai, "skarvald and dalronn") {}

    public:
        virtual float GetValue(Action* action);
};

#endif