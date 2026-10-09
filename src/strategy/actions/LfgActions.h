/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_LFGACTIONS_H
#define _SHADOW_LFGACTIONS_H

#include "InventoryAction.h"

class ShadowAI;

class LfgJoinAction : public InventoryAction
{
public:
    LfgJoinAction(ShadowAI* botAI, std::string const name = "lfg join") : InventoryAction(botAI, name) {}

    bool Execute(Event event) override;
    bool isUseful() override;

protected:
    bool JoinLFG();
    uint32 GetRoles();
};

class LfgAcceptAction : public LfgJoinAction
{
public:
    LfgAcceptAction(ShadowAI* botAI) : LfgJoinAction(botAI, "lfg accept") {}

    bool Execute(Event event) override;
    bool isUseful() override { return true; }
};

class LfgRoleCheckAction : public LfgJoinAction
{
public:
    LfgRoleCheckAction(ShadowAI* botAI) : LfgJoinAction(botAI, "lfg role check") {}

    bool Execute(Event event) override;
    bool isUseful() override { return true; }
};

class LfgLeaveAction : public Action
{
public:
    LfgLeaveAction(ShadowAI* botAI) : Action(botAI, "lfg leave") {}

    bool Execute(Event event) override;
    bool isUseful() override;
};

class LfgTeleportAction : public Action
{
public:
    LfgTeleportAction(ShadowAI* botAI) : Action(botAI, "lfg teleport") {}

    bool Execute(Event event) override;
};

#endif
