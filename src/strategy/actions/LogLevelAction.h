/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_LOGLEVELACTION_H
#define _SHADOW_LOGLEVELACTION_H

#include "Action.h"
#include "LogCommon.h"

class ShadowAI;

class LogLevelAction : public Action
{
public:
    LogLevelAction(ShadowAI* botAI) : Action(botAI, "log") {}

    bool Execute(Event event) override;

public:
    static std::string const logLevel2string(LogLevel level);
    static LogLevel string2logLevel(std::string const level);
};

#endif
