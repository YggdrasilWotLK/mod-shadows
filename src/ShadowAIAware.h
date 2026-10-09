/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_SHADOWAIAWARE_H
#define _SHADOW_SHADOWAIAWARE_H

class ShadowAI;

class ShadowAIAware
{
public:
    ShadowAIAware(ShadowAI* botAI) : botAI(botAI) {}

protected:
    ShadowAI* botAI;
};

#endif
