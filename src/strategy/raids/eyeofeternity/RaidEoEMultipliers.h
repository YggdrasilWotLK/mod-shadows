
#ifndef _PLAYERRBOT_RAIDEOEMULTIPLIERS_H
#define _PLAYERRBOT_RAIDEOEMULTIPLIERS_H

#include "Multiplier.h"

class MalygosMultiplier : public Multiplier
{
public:
    MalygosMultiplier(ShadowAI* ai) : Multiplier(ai, "malygos") {}

public:
    virtual float GetValue(Action* action);
};

#endif
