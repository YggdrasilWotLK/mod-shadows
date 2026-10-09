#ifndef _SHADOW_WOTLKDUNGEONNEXMULTIPLIERS_H
#define _SHADOW_WOTLKDUNGEONNEXMULTIPLIERS_H

#include "Multiplier.h"

class FactionCommanderMultiplier : public Multiplier
{
    public:
        FactionCommanderMultiplier(ShadowAI* ai) : Multiplier(ai, "faction commander") {}

    public:
        virtual float GetValue(Action* action);
};

class TelestraMultiplier : public Multiplier
{
    public:
        TelestraMultiplier(ShadowAI* ai) : Multiplier(ai, "grand magus telestra") {}

    public:
        virtual float GetValue(Action* action);
};

class AnomalusMultiplier : public Multiplier
{
    public:
        AnomalusMultiplier(ShadowAI* ai) : Multiplier(ai, "anomalus") {}

    public:
        virtual float GetValue(Action* action);
};

class OrmorokMultiplier : public Multiplier
{
    public:
        OrmorokMultiplier(ShadowAI* ai) : Multiplier(ai, "ormorok the tree-shaper") {}

    public:
        virtual float GetValue(Action* action);
};

#endif
