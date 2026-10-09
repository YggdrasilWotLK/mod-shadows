/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_SHAREDVALUECONTEXT_H
#define _SHADOW_SHAREDVALUECONTEXT_H

#include "LootValues.h"
#include "NamedObjectContext.h"
#include "Shadows.h"
#include "PvpValues.h"
#include "QuestValues.h"

class ShadowAI;

class SharedValueContext : public NamedObjectContext<UntypedValue>
{
public:
    SharedValueContext() : NamedObjectContext(true)
    {
        creators["bg masters"] = &SharedValueContext::bg_masters;
        creators["drop map"] = &SharedValueContext::drop_map;
        creators["item drop list"] = &SharedValueContext::item_drop_list;
        creators["entry loot list"] = &SharedValueContext::entry_loot_list;

        creators["entry quest relation"] = &SharedValueContext::entry_quest_relation;
        creators["quest guidp map"] = &SharedValueContext::quest_guidp_map;
        creators["quest givers"] = &SharedValueContext::quest_givers;
    }

private:
    static UntypedValue* bg_masters(ShadowAI* botAI) { return new BgMastersValue(botAI); }
    static UntypedValue* drop_map(ShadowAI* botAI) { return new DropMapValue(botAI); }
    static UntypedValue* item_drop_list(ShadowAI* botAI) { return new ItemDropListValue(botAI); }
    static UntypedValue* entry_loot_list(ShadowAI* botAI) { return new EntryLootListValue(botAI); }

    static UntypedValue* entry_quest_relation(ShadowAI* botAI) { return new EntryQuestRelationMapValue(botAI); }
    static UntypedValue* quest_guidp_map(ShadowAI* botAI) { return new QuestGuidpMapValue(botAI); }
    static UntypedValue* quest_givers(ShadowAI* botAI) { return new QuestGiversValue(botAI); }

    // Global acess functions
public:
    static SharedValueContext* instance()
    {
        static SharedValueContext instance;
        return &instance;
    }

    template <class T>
    Value<T>* getGlobalValue(std::string const name)
    {
        // should never reach here
        SharedNamedObjectContextList<UntypedValue> sValueContexts;
        sValueContexts.Add(this);
        NamedObjectContextList<UntypedValue> valueContexts(sValueContexts);
        ShadowAI* botAI = new ShadowAI();

        UntypedValue* value = valueContexts.GetContextObject(name, botAI);
        delete botAI;
        return dynamic_cast<Value<T>*>(value);
    }

    template <class T>
    Value<T>* getGlobalValue(std::string const name, std::string const param)
    {
        return getGlobalValue<T>((std::string(name) + "::" + param));
    }

    template <class T>
    Value<T>* getGlobalValue(std::string const name, uint32 param)
    {
        std::ostringstream out;
        out << param;
        return getGlobalValue<T>(name, out.str());
    }
};

#define sSharedValueContext SharedValueContext::instance()

#endif
