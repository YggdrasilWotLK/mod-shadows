/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#include "DiscPriestStrategy.h"

#include "GenericPriestStrategyActionNodeFactory.h"
#include "Playerbots.h"

DiscPriestStrategy::DiscPriestStrategy(PlayerbotAI* botAI) : GenericPriestStrategy(botAI)
{
    actionNodeFactories.Add(new GenericPriestStrategyActionNodeFactory());
}

NextAction** DiscPriestStrategy::getDefaultActions()
{
    return NextAction::array(0, new NextAction("shoot", ACTION_DEFAULT), nullptr);
}

void DiscPriestStrategy::InitTriggers(std::vector<TriggerNode*>& triggers)
{
    GenericPriestStrategy::InitTriggers(triggers);

    // 1st priority: shield anyone missing it (no weakened soul, no existing shield)
    triggers.push_back(new TriggerNode(
        "party member almost full health",
        NextAction::array(0, new NextAction("power word: shield on weakened soul", ACTION_LIGHT_HEAL + 4), nullptr)));

    triggers.push_back(new TriggerNode(
        "party member medium health",
        NextAction::array(0, new NextAction("power word: shield on weakened soul", ACTION_LIGHT_HEAL + 9), nullptr)));

    triggers.push_back(new TriggerNode(
        "party member low health",
        NextAction::array(0, new NextAction("power word: shield on weakened soul", ACTION_MEDIUM_HEAL + 5), nullptr)));

    triggers.push_back(new TriggerNode(
        "party member critical health",
        NextAction::array(0, new NextAction("power word: shield on weakened soul", ACTION_CRITICAL_HEAL + 6), nullptr)));

    // 2nd priority: penance on damaged targets
    triggers.push_back(new TriggerNode(
        "party member critical health",
        NextAction::array(0, new NextAction("penance on party", ACTION_CRITICAL_HEAL + 5), nullptr)));

    triggers.push_back(new TriggerNode(
        "party member low health",
        NextAction::array(0, new NextAction("penance on party", ACTION_MEDIUM_HEAL + 4), nullptr)));

    triggers.push_back(new TriggerNode(
        "party member medium health",
        NextAction::array(0, new NextAction("penance on party", ACTION_LIGHT_HEAL + 8), nullptr)));

    // 3rd priority: prayer of mending on damaged targets
    triggers.push_back(new TriggerNode(
        "party member critical health",
        NextAction::array(0, new NextAction("prayer of mending on party", ACTION_CRITICAL_HEAL + 4), nullptr)));

    triggers.push_back(new TriggerNode(
        "party member low health",
        NextAction::array(0, new NextAction("prayer of mending on party", ACTION_MEDIUM_HEAL + 3), nullptr)));

    triggers.push_back(new TriggerNode(
        "party member medium health",
        NextAction::array(0, new NextAction("prayer of mending on party", ACTION_LIGHT_HEAL + 7), nullptr)));

    triggers.push_back(new TriggerNode(
        "party member almost full health",
        NextAction::array(0, new NextAction("prayer of mending on party", ACTION_LIGHT_HEAL + 3), nullptr)));

    // 4th priority: renew on targets under 60% (medium health threshold covers this)
    triggers.push_back(new TriggerNode(
        "party member critical health",
        NextAction::array(0, new NextAction("renew on party", ACTION_CRITICAL_HEAL + 3), nullptr)));

    triggers.push_back(new TriggerNode(
        "party member low health",
        NextAction::array(0, new NextAction("renew on party", ACTION_MEDIUM_HEAL + 2), nullptr)));

    triggers.push_back(new TriggerNode(
        "party member medium health",
        NextAction::array(0, new NextAction("renew on party", ACTION_LIGHT_HEAL + 6), nullptr)));

    // 5th priority: flash heal as emergency
    triggers.push_back(new TriggerNode(
        "party member critical health",
        NextAction::array(0, new NextAction("flash heal on party", ACTION_CRITICAL_HEAL + 2), nullptr)));

    triggers.push_back(new TriggerNode(
        "party member low health",
        NextAction::array(0, new NextAction("flash heal on party", ACTION_MEDIUM_HEAL + 1), nullptr)));

    triggers.push_back(new TriggerNode(
        "party member medium health",
        NextAction::array(0, new NextAction("flash heal on party", ACTION_LIGHT_HEAL + 5), nullptr)));

    // Move to heal out-of-range targets
    triggers.push_back(new TriggerNode(
        "party member to heal out of spell range",
        NextAction::array(0, new NextAction("reach party member to heal", ACTION_CRITICAL_HEAL + 10), nullptr)));

    // Pain suppression for emergencies
    triggers.push_back(new TriggerNode(
        "critical health",
        NextAction::array(0, new NextAction("pain suppression", ACTION_EMERGENCY + 1), nullptr)));

    triggers.push_back(new TriggerNode(
        "protect party member",
        NextAction::array(0, new NextAction("pain suppression on party", ACTION_EMERGENCY), nullptr)));
}