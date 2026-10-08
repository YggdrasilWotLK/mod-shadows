/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#include "ArcaneMageStrategy.h"
#include "Shadows.h"

// ===== Action Node Factory =====
class ArcaneMageStrategyActionNodeFactory : public NamedObjectFactory<ActionNode>
{
public:
    ArcaneMageStrategyActionNodeFactory()
    {
        creators["arcane blast"] = &arcane_blast;
        creators["arcane barrage"] = &arcane_barrage;
        creators["arcane missiles"] = &arcane_missiles;
        creators["fire blast"] = &fire_blast;
        creators["frostbolt"] = &frostbolt;
        creators["arcane power"] = &arcane_power;
        creators["icy veins"] = &icy_veins;
    }

private:
    static ActionNode* arcane_blast(ShadowAI*) { return new ActionNode("arcane blast", nullptr, nullptr, nullptr); }
    static ActionNode* arcane_barrage(ShadowAI*) { return new ActionNode("arcane barrage", nullptr, nullptr, nullptr); }
    static ActionNode* arcane_missiles(ShadowAI*) { return new ActionNode("arcane missiles", nullptr, nullptr, nullptr); }
    static ActionNode* fire_blast(ShadowAI*) { return new ActionNode("fire blast", nullptr, nullptr, nullptr); }
    static ActionNode* frostbolt(ShadowAI*) { return new ActionNode("frostbolt", nullptr, nullptr, nullptr); }
    static ActionNode* arcane_power(ShadowAI*) { return new ActionNode("arcane power", nullptr, nullptr, nullptr); }
    static ActionNode* icy_veins(ShadowAI*) { return new ActionNode("icy veins", nullptr, nullptr, nullptr); }
};

// ===== Single Target Strategy =====
ArcaneMageStrategy::ArcaneMageStrategy(ShadowAI* botAI) : GenericMageStrategy(botAI)
{
    actionNodeFactories.Add(new ArcaneMageStrategyActionNodeFactory());
}

// ===== Default Actions =====
NextAction** ArcaneMageStrategy::getDefaultActions()
{
    return NextAction::array(0, new NextAction("arcane blast", 5.6f),
                                new NextAction("arcane missiles", 5.5f),
                                new NextAction("arcane barrage", 5.4f),   // cast while moving
                                new NextAction("fire blast", 5.3f),       // cast while moving if arcane barrage isn't available/learned
                                new NextAction("frostbolt", 5.2f),        // for arcane immune targets
                                new NextAction("shoot", 5.1f), nullptr);
}

// ===== Trigger Initialization ===
void ArcaneMageStrategy::InitTriggers(std::vector<TriggerNode*>& triggers)
{
    GenericMageStrategy::InitTriggers(triggers);

    // Proc Trigger
    triggers.push_back(new TriggerNode("arcane blast 4 stacks and missile barrage", NextAction::array(0, new NextAction("arcane missiles", 15.0f), nullptr)));
}
