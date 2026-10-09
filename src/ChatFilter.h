/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_CHATFILTER_H
#define _SHADOW_CHATFILTER_H

#include <vector>

#include "Common.h"
#include "ShadowAIAware.h"

class ShadowAI;

class ChatFilter : public ShadowAIAware
{
public:
    ChatFilter(ShadowAI* botAI) : ShadowAIAware(botAI) {}
    virtual ~ChatFilter() {}

    virtual std::string const Filter(std::string& message);
};

class CompositeChatFilter : public ChatFilter
{
public:
    CompositeChatFilter(ShadowAI* botAI);

    virtual ~CompositeChatFilter();
    std::string const Filter(std::string& message) override;

private:
    std::vector<ChatFilter*> filters;
};

#endif
