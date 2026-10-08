/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#include "QuestStrategies.h"

#include "Shadows.h"

QuestStrategy::QuestStrategy(ShadowAI* botAI) : PassTroughStrategy(botAI) { supported.push_back("accept quest"); }

void QuestStrategy::InitTriggers(std::vector<TriggerNode*>& triggers)
{
    PassTroughStrategy::InitTriggers(triggers);

    triggers.push_back(
        new TriggerNode("quest share", NextAction::array(0, new NextAction("accept quest share", relevance), nullptr)));
}

void DefaultQuestStrategy::InitTriggers(std::vector<TriggerNode*>& triggers)
{
    QuestStrategy::InitTriggers(triggers);

    triggers.push_back(new TriggerNode(
        "use game object", NextAction::array(0, new NextAction("talk to quest giver", relevance), nullptr)));
    triggers.push_back(new TriggerNode(
        "gossip hello", NextAction::array(0, new NextAction("talk to quest giver", relevance), nullptr)));
    triggers.push_back(new TriggerNode(
        "complete quest", NextAction::array(0, new NextAction("talk to quest giver", relevance), nullptr)));
}

DefaultQuestStrategy::DefaultQuestStrategy(ShadowAI* botAI) : QuestStrategy(botAI) {}

void AcceptAllQuestsStrategy::InitTriggers(std::vector<TriggerNode*>& triggers)
{
    QuestStrategy::InitTriggers(triggers);

    triggers.push_back(
        new TriggerNode("use game object", NextAction::array(0, new NextAction("talk to quest giver", relevance),
                                                             new NextAction("accept all quests", relevance), nullptr)));
    triggers.push_back(
        new TriggerNode("gossip hello", NextAction::array(0, new NextAction("talk to quest giver", relevance),
                                                          new NextAction("accept all quests", relevance), nullptr)));
    triggers.push_back(
        new TriggerNode("complete quest", NextAction::array(0, new NextAction("talk to quest giver", relevance),
                                                            new NextAction("accept all quests", relevance), nullptr)));
}

AcceptAllQuestsStrategy::AcceptAllQuestsStrategy(ShadowAI* botAI) : QuestStrategy(botAI) {}
