/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_CHATSHORTCUTACTION_H
#define _SHADOW_CHATSHORTCUTACTION_H

#include "MovementActions.h"

class ShadowAI;

class PositionsResetAction : public Action
{
public:
    PositionsResetAction(ShadowAI* botAI, std::string const name) : Action(botAI, name) {}

    void ResetReturnPosition();
    void SetReturnPosition(float x, float y, float z);
    void ResetStayPosition();
    void SetStayPosition(float x, float y, float z);
};

class FollowChatShortcutAction : public MovementAction
{
public:
    FollowChatShortcutAction(ShadowAI* botAI) : MovementAction(botAI, "follow chat shortcut") {}

    bool Execute(Event event) override;
};

class StayChatShortcutAction : public PositionsResetAction
{
public:
    StayChatShortcutAction(ShadowAI* botAI) : PositionsResetAction(botAI, "stay chat shortcut") {}

    bool Execute(Event event) override;
};

class MoveFromGroupChatShortcutAction : public Action
{
public:
    MoveFromGroupChatShortcutAction(ShadowAI* botAI) : Action(botAI, "move from group chat shortcut") {}

    bool Execute(Event event) override;
};

class FleeChatShortcutAction : public PositionsResetAction
{
public:
    FleeChatShortcutAction(ShadowAI* botAI) : PositionsResetAction(botAI, "flee chat shortcut") {}

    bool Execute(Event event) override;
};

class GoawayChatShortcutAction : public PositionsResetAction
{
public:
    GoawayChatShortcutAction(ShadowAI* botAI) : PositionsResetAction(botAI, "runaway chat shortcut") {}

    bool Execute(Event event) override;
};

class GrindChatShortcutAction : public PositionsResetAction
{
public:
    GrindChatShortcutAction(ShadowAI* botAI) : PositionsResetAction(botAI, "grind chat shortcut") {}

    bool Execute(Event event) override;
};

class TankAttackChatShortcutAction : public PositionsResetAction
{
public:
    TankAttackChatShortcutAction(ShadowAI* botAI) : PositionsResetAction(botAI, "tank attack chat shortcut") {}

    bool Execute(Event event) override;
};

class MaxDpsChatShortcutAction : public Action
{
public:
    MaxDpsChatShortcutAction(ShadowAI* botAI) : Action(botAI, "max dps chat shortcut") {}

    bool Execute(Event event) override;
};

class NaxxChatShortcutAction : public Action
{
public:
    NaxxChatShortcutAction(ShadowAI* ai) : Action(ai, "naxx chat shortcut") {}
    virtual bool Execute(Event event);
};

class BwlChatShortcutAction : public Action
{
public:
    BwlChatShortcutAction(ShadowAI* ai) : Action(ai, "bwl chat shortcut") {}
    virtual bool Execute(Event event);
};
#endif
