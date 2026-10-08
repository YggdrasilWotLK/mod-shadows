/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_SAYACTION_H
#define _SHADOW_SAYACTION_H

#include "Action.h"
#include "ShadowAI.h"
#include "NamedObjectContext.h"

class ShadowAI;
class SayAction : public Action, public Qualified
{
public:
    SayAction(ShadowAI* botAI);

    bool Execute(Event event) override;
    bool isUseful() override;
    std::string const getName() override { return "say::" + qualifier; }

private:
    static std::map<std::string, std::vector<std::string>> stringTable;
    static std::map<std::string, uint32> probabilityTable;
};

class ChatReplyAction : public Action
{
public:
    ChatReplyAction(ShadowAI* ai) : Action(ai, "chat message") {}
    virtual bool Execute(Event event) { return true; }
    bool isUseful() { return true; }

    static void ChatReplyDo(Player* bot, uint32& type, uint32& guid1, uint32& guid2, std::string& msg, std::string& chanName, std::string& name);
    static bool HandleThunderfuryReply(Player* bot, ChatChannelSource chatChannelSource, std::string& msg, std::string& name);
    static bool HandleToxicLinksReply(Player* bot, ChatChannelSource chatChannelSource, std::string& msg, std::string& name);
    static bool HandleWTBItemsReply(Player* bot, ChatChannelSource chatChannelSource, std::string& msg, std::string& name);
    static bool HandleLFGQuestsReply(Player* bot, ChatChannelSource chatChannelSource, std::string& msg, std::string& name);
    static bool SendGeneralResponse(Player* bot, ChatChannelSource chatChannelSource, std::string& responseMessage, std::string& name);
    static std::string GenerateReplyMessage(Player* bot, std::string& incomingMessage, uint32& guid1, std::string& name);
};
#endif
