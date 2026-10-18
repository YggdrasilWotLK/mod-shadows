/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#include "UseItemAction.h"

#include "ChatHelper.h"
#include "Event.h"
#include "ItemUsageValue.h"
#include "Shadows.h"
#include "ItemPackets.h"

bool UseItemAction::Execute(Event event)
{
    std::string name = event.getParam();
    if (name.empty())
        name = getName();

    std::vector<Item*> items = AI_VALUE2(std::vector<Item*>, "inventory items", name);
    GuidVector gos = chat->parseGameobjects(name);

    bool const announce = event.getOwner() != nullptr;

    if (gos.empty())
    {
        if (!items.empty())
        {
            return UseItemAuto(*items.begin(), announce);
        }
    }
    else
    {
        if (items.empty())
            return UseGameObject(*gos.begin());
        else
            return UseItemOnGameObject(*items.begin(), *gos.begin(), announce);
    }

    botAI->TellError("No items (or game objects) available");
    return false;
}

bool UseItemAction::UseGameObject(ObjectGuid guid)
{
    GameObject* go = botAI->GetGameObject(guid);
    if (!go || !go->isSpawned() /* || go->GetGoState() != GO_STATE_READY*/)
        return false;

    go->Use(bot);

    std::ostringstream out;
    out << "Using " << chat->FormatGameobject(go);
    botAI->TellMasterNoFacing(out.str());
    return true;
}

bool UseItemAction::UseItemAuto(Item* item, bool announce)
{
    return UseItem(item, ObjectGuid::Empty, nullptr, nullptr, announce);
}

bool UseItemAction::UseItemOnGameObject(Item* item, ObjectGuid go, bool announce)
{
    return UseItem(item, go, nullptr, nullptr, announce);
}

bool UseItemAction::UseItemOnItem(Item* item, Item* itemTarget) { return UseItem(item, ObjectGuid::Empty, itemTarget); }

bool UseItemAction::UseFeast(Item* item)
{
    ItemTemplate const* proto = item->GetTemplate();

    uint32 feastSpell = 0;
    for (uint8 i = 0; i < MAX_ITEM_PROTO_SPELLS; ++i)
    {
        if (proto->Spells[i].SpellId > 0)
        {
            feastSpell = proto->Spells[i].SpellId;
            break;
        }
    }

    if (!feastSpell)
        return false;

    if (bot->IsNonMeleeSpellCast(false))
        return false;

    if (bot->IsInCombat())
    {
        std::ostringstream out;
        out << "Can't set down " << chat->FormatItem(proto) << " in combat";
        botAI->TellMasterNoFacing(out.str());
        return false;
    }

    if (bot->isMoving())
    {
        bot->StopMoving();
        botAI->SetNextCheckDelay(sShadowAIConfig->globalCoolDown);

        std::ostringstream out;
        out << "I can't use " << chat->FormatItem(proto) << " while moving";
        botAI->TellMasterNoFacing(out.str());
        return false;
    }

    float x = bot->GetPositionX();
    float y = bot->GetPositionY();
    float z = bot->GetPositionZ();

    if (!botAI->CanCastSpell(feastSpell, x, y, z, false, nullptr))
    {
        std::ostringstream out;
        out << "Can't set down " << chat->FormatItem(proto) << " right now";
        botAI->TellMasterNoFacing(out.str());
        return false;
    }

    WorldPacket packet(CMSG_USE_ITEM);
    packet << uint8(item->GetBagSlot()) << uint8(item->GetSlot()) << uint8(1) << feastSpell << item->GetGUID()
           << uint32(0) << uint8(0);

    packet << uint32(TARGET_FLAG_DEST_LOCATION);
    packet << ObjectGuid::Empty.WriteAsPacked();
    packet << x << y << z;

    bot->ClearUnitState(UNIT_STATE_CHASE);
    bot->ClearUnitState(UNIT_STATE_FOLLOW);

    std::ostringstream out;
    out << "Setting down " << chat->FormatItem(proto);
    botAI->TellMasterNoFacing(out.str());

    bot->GetSession()->HandleUseItemOpcode(packet);

    if (SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(feastSpell))
        botAI->SetNextCheckDelay(spellInfo->CalcCastTime() + sShadowAIConfig->reactDelay);
    else
        botAI->SetNextCheckDelay(sShadowAIConfig->globalCoolDown);

    return true;
}

bool UseItemAction::UseItem(Item* item, ObjectGuid goGuid, Item* itemTarget, Unit* unitTarget, bool announce)
{
    if (bot->CanUseItem(item) != EQUIP_ERR_OK)
    {
        if (announce)
            TellCantUse(item);

        return false;
    }

    if (bot->IsNonMeleeSpellCast(false))
    {
        if (announce)
        {
            std::ostringstream out;
            out << "Can't use " << chat->FormatItem(item->GetTemplate()) << " while casting";
            botAI->TellMasterNoFacing(out.str());
        }

        return false;
    }

    if (ItemUsageValue::IsFeastItem(item->GetTemplate()))
    {
        if (!announce)
            return false;

        return UseFeast(item);
    }

    uint8 bagIndex = item->GetBagSlot();
    uint8 slot = item->GetSlot();
    uint8 spell_index [[maybe_unused]] = 0;
    uint8 cast_count = 1;
    ObjectGuid item_guid = item->GetGUID();
    uint32 glyphIndex = 0;
    uint8 castFlags = 0;
    uint32 targetFlag = TARGET_FLAG_NONE;
    uint32 spellId = 0;
    for (uint8 i = 0; i < MAX_ITEM_PROTO_SPELLS; ++i)
    {
        if (item->GetTemplate()->Spells[i].SpellId > 0)
        {
            spellId = item->GetTemplate()->Spells[i].SpellId;
            if (!botAI->CanCastSpell(spellId, bot, false, itemTarget, item))
            {
                if (announce)
                {
                    std::ostringstream out;
                    out << "Can't use " << chat->FormatItem(item->GetTemplate()) << " right now";
                    botAI->TellMasterNoFacing(out.str());
                }

                return false;
            }
        }
    }

    WorldPacket packet(CMSG_USE_ITEM);
    packet << bagIndex << slot << cast_count << spellId << item_guid << glyphIndex << castFlags;

    bool targetSelected = false;

    std::ostringstream out;
    out << "Using " << chat->FormatItem(item->GetTemplate());

    if (item->GetTemplate()->Stackable > 1)
    {
        uint32 count = item->GetCount();
        if (count > 1)
            out << " (" << count << " available) ";
        else
            out << " (the last one!)";
    }

    if (goGuid)
    {
        GameObject* go = botAI->GetGameObject(goGuid);
        if (!go || !go->isSpawned())
            return false;

        targetFlag = TARGET_FLAG_GAMEOBJECT;

        packet << targetFlag;
        packet << goGuid.WriteAsPacked();
        out << " on " << chat->FormatGameobject(go);
        targetSelected = true;
    }

    if (itemTarget)
    {
        if (item->GetTemplate()->Class == ITEM_CLASS_GEM)
        {
            bool fit = SocketItem(itemTarget, item) || SocketItem(itemTarget, item, true);
            if (!fit)
                botAI->TellMaster("Socket does not fit");

            return fit;
        }
        else
        {
            targetFlag = TARGET_FLAG_ITEM;
            packet << targetFlag;
            packet << itemTarget->GetGUID().WriteAsPacked();
            out << " on " << chat->FormatItem(itemTarget->GetTemplate());
            targetSelected = true;
        }
    }

    Player* master = GetMaster();
    if (!targetSelected && item->GetTemplate()->Class != ITEM_CLASS_CONSUMABLE && master &&
        botAI->HasActivePlayerMaster() && !selfOnly)
    {
        if (ObjectGuid masterSelection = master->GetTarget())
        {
            Unit* unit = botAI->GetUnit(masterSelection);
            if (unit)
            {
                targetFlag = TARGET_FLAG_UNIT;
                packet << targetFlag << masterSelection.WriteAsPacked();
                out << " on " << unit->GetName();
                targetSelected = true;
            }
        }
    }

    if (!targetSelected && item->GetTemplate()->Class != ITEM_CLASS_CONSUMABLE && unitTarget)
    {
        targetFlag = TARGET_FLAG_UNIT;
        packet << targetFlag << unitTarget->GetGUID().WriteAsPacked();
        out << " on " << unitTarget->GetName();
        targetSelected = true;
    }

    if (uint32 questid = item->GetTemplate()->StartQuest)
    {
        if (Quest const* qInfo = sObjectMgr->GetQuestTemplate(questid))
        {
            WorldPacket packet(CMSG_QUESTGIVER_ACCEPT_QUEST, 8 + 4 + 4);
            packet << item_guid;
            packet << questid;
            packet << uint32(0);
            bot->GetSession()->HandleQuestgiverAcceptQuestOpcode(packet);

            std::ostringstream out;
            out << "Got quest " << chat->FormatQuest(qInfo);
            botAI->TellMasterNoFacing(out.str());
            return true;
        }
    }

    bot->ClearUnitState(UNIT_STATE_CHASE);
    bot->ClearUnitState(UNIT_STATE_FOLLOW);

    if (bot->isMoving())
    {
        bot->StopMoving();
        botAI->SetNextCheckDelay(sShadowAIConfig->globalCoolDown);

        if (announce)
        {
            std::ostringstream out;
            out << "I can't use " << chat->FormatItem(item->GetTemplate()) << " while moving";
            botAI->TellMasterNoFacing(out.str());
        }

        return false;
    }

    for (uint8 i = 0; i < MAX_ITEM_PROTO_SPELLS; i++)
    {
        uint32 spellId = item->GetTemplate()->Spells[i].SpellId;
        if (!spellId)
            continue;

        if (!botAI->CanCastSpell(spellId, bot, false))
            continue;

        SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(spellId);
        if (spellInfo->Targets & TARGET_FLAG_ITEM)
        {
            Item* itemForSpell = AI_VALUE2(Item*, "item for spell", spellId);
            if (!itemForSpell)
                continue;

            if (itemForSpell->GetEnchantmentId(TEMP_ENCHANTMENT_SLOT))
                continue;

            if (bot->GetTrader())
            {
                if (selfOnly)
                    return false;

                targetFlag = TARGET_FLAG_TRADE_ITEM;
                packet << targetFlag << (uint8)1 << ObjectGuid((uint64)TRADE_SLOT_NONTRADED).WriteAsPacked();
                targetSelected = true;
                out << " on traded item";
            }
            else
            {
                targetFlag = TARGET_FLAG_ITEM;
                packet << targetFlag;
                packet << itemForSpell->GetGUID().WriteAsPacked();
                targetSelected = true;
                out << " on " << chat->FormatItem(itemForSpell->GetTemplate());
            }
            uint32 castTime = spellInfo->CalcCastTime();
            botAI->SetNextCheckDelay(castTime + sShadowAIConfig->reactDelay);
        }

        break;
    }

    if (!targetSelected)
    {
        targetFlag = TARGET_FLAG_NONE;
        packet << targetFlag;

        // Use the actual target if provided
        if (unitTarget)
        {
            packet << unitTarget->GetGUID();
            targetSelected = true;
            // If the target is bot or is an enemy, say "on self"
            if (unitTarget == bot || (unitTarget->IsHostileTo(bot)))
                out << " on self";
            else
                out << " on " << unitTarget->GetName();
        }
        else
        {
            packet << bot->GetPackGUID();
            targetSelected = true;
            out << " on self";
        }
    }

    ItemTemplate const* proto = item->GetTemplate();
    bool isDrink = proto->Spells[0].SpellCategory == 59;
    bool isFood = proto->Spells[0].SpellCategory == 11;
    if (proto->Class == ITEM_CLASS_CONSUMABLE &&
        (proto->SubClass == ITEM_SUBCLASS_FOOD || proto->SubClass == ITEM_SUBCLASS_CONSUMABLE) && (isFood || isDrink))
    {
        if (bot->IsInCombat())
            return false;

        // Eating inhibited by a direct order that is still being carried
        // out: do not consume the item and do not sit back down.
        if (botAI->IsEatingInhibited())
            return false;

        // Already eating/drinking: keep the regen state, do not consume
        // another item or re-delay the AI.
        if (botAI->IsEating())
            return true;

        // bot->SetStandState(UNIT_STAND_STATE_SIT);
        botAI->InterruptSpell();
        float hp = bot->GetHealthPct();
        float mp = bot->GetPower(POWER_MANA) * 100.0f / bot->GetMaxPower(POWER_MANA);
        float p = 0.f;
        if (isDrink && isFood)
        {
            p = std::min(hp, mp);
            TellConsumableUse(item, "Feasting", p);
        }
        else if (isDrink)
        {
            p = mp;
            TellConsumableUse(item, "Drinking", p);
        }
        else if (isFood)
        {
            p = std::min(hp, mp);
            TellConsumableUse(item, "Eating", p);
        }

        // Regen duration stays proportional to the missing health/mana, but it
        // no longer sleeps the whole AI: the engine keeps ticking (combat and
        // chat commands stay live) and only routine actions are suppressed.
        // Capped at a single food/drink aura duration; regen completion,
        // combat, movement or commands end eating earlier.
        float baseMs = bot->InBattleground() ? 20000.0f : 27000.0f;
        uint32 eatDuration = (uint32)(baseMs * (100.0f - p) / 100.0f / 1000.0f) + 1;
        if (eatDuration > 30)
            eatDuration = 30;

        botAI->StartEating(eatDuration);
        botAI->SetNextCheckDelay(botAI->GetReactDelay());

        // botAI->SetNextCheckDelay(27000.0f * (100 - p) / 100.0f);
        //  botAI->SetNextCheckDelay(20000);
        bot->GetSession()->HandleUseItemOpcode(packet);

        return true;
    }

    if (!spellId)
        return false;

    // botAI->SetNextCheckDelay(sShadowAIConfig->globalCoolDown);
    botAI->TellMasterNoFacing(out.str());
    bot->GetSession()->HandleUseItemOpcode(packet);
    return true;
}

void UseItemAction::TellCantUse(Item* item)
{
    ItemTemplate const* proto = item->GetTemplate();

    std::ostringstream out;
    out << "Can't use " << chat->FormatItem(proto);

    if (proto->RequiredLevel > bot->GetLevel())
        out << " (requires level " << proto->RequiredLevel << ")";
    else if (proto->RequiredSkill && bot->GetSkillValue(proto->RequiredSkill) == 0)
        out << " (requires " << ChatHelper::FormatSkill(proto->RequiredSkill) << ")";
    else if (proto->RequiredSkill && bot->GetSkillValue(proto->RequiredSkill) < proto->RequiredSkillRank)
        out << " (requires higher " << ChatHelper::FormatSkill(proto->RequiredSkill) << " rank)";

    botAI->TellMasterNoFacing(out.str());
}

void UseItemAction::TellConsumableUse(Item* item, std::string const action, float percent)
{
    std::ostringstream out;
    out << action << " " << chat->FormatItem(item->GetTemplate());

    if (item->GetTemplate()->Stackable > 1)
        out << "/x" << item->GetCount();

    out << " (" << round(percent) << "%)";
    botAI->TellMasterNoFacing(out.str());
}

bool UseItemAction::SocketItem(Item* item, Item* gem, bool replace)
{
    WorldPacket packet(CMSG_SOCKET_GEMS);
    packet << item->GetGUID();

    bool fits = false;
    for (uint32 enchant_slot = SOCK_ENCHANTMENT_SLOT; enchant_slot < SOCK_ENCHANTMENT_SLOT + MAX_GEM_SOCKETS;
         ++enchant_slot)
    {
        uint8 SocketColor = item->GetTemplate()->Socket[enchant_slot - SOCK_ENCHANTMENT_SLOT].Color;
        GemPropertiesEntry const* gemProperty = sGemPropertiesStore.LookupEntry(gem->GetTemplate()->GemProperties);
        if (gemProperty && (gemProperty->color & SocketColor))
        {
            if (fits)
            {
                packet << ObjectGuid::Empty;
                continue;
            }

            uint32 enchant_id = item->GetEnchantmentId(EnchantmentSlot(enchant_slot));
            if (!enchant_id)
            {
                packet << gem->GetGUID();
                fits = true;
                continue;
            }

            SpellItemEnchantmentEntry const* enchantEntry = sSpellItemEnchantmentStore.LookupEntry(enchant_id);
            if (!enchantEntry || !enchantEntry->GemID)
            {
                packet << gem->GetGUID();
                fits = true;
                continue;
            }

            if (replace && enchantEntry->GemID != gem->GetTemplate()->ItemId)
            {
                packet << gem->GetGUID();
                fits = true;
                continue;
            }
        }

        packet << ObjectGuid::Empty;
    }

    if (fits)
    {
        std::ostringstream out;
        out << "Socketing " << chat->FormatItem(item->GetTemplate());
        out << " with " << chat->FormatItem(gem->GetTemplate());
        botAI->TellMaster(out);

        WorldPackets::Item::SocketGems nicePacket(std::move(packet));
        nicePacket.Read();
        bot->GetSession()->HandleSocketOpcode(nicePacket);
    }

    return fits;
}

bool UseItemAction::isPossible() { return getName() == "use" || AI_VALUE2(uint32, "item count", getName()) > 0; }

bool UseSpellItemAction::isUseful() { return AI_VALUE2(bool, "spell cast useful", getName()); }

bool UseHealingPotion::isUseful() { return AI_VALUE2(bool, "combat", "self target"); }

bool UseManaPotion::isUseful() { return AI_VALUE2(bool, "combat", "self target"); }

bool UseHearthStone::Execute(Event event)
{
    if (bot->isMoving())
    {
        MotionMaster& mm = *bot->GetMotionMaster();
        bot->StopMoving();
        mm.Clear();
    }

    bool used = UseItemAction::Execute(event);
    if (used)
    {
        RESET_AI_VALUE(bool, "combat::self target");
        RESET_AI_VALUE(WorldPosition, "current position");
        botAI->SetNextCheckDelay(10 * IN_MILLISECONDS);
    }

    return used;
}

bool UseHearthStone::isUseful() { return !bot->InBattleground(); }

bool UseRandomRecipe::isUseful()
{
    return !bot->IsInCombat() && !botAI->HasActivePlayerMaster() && !bot->InBattleground();
}

bool UseRandomRecipe::isPossible() { return AI_VALUE2(uint32, "item count", "recipe") > 0; }

bool UseRandomRecipe::Execute(Event event [[maybe_unused]])
{
    std::vector<Item*> recipes = AI_VALUE2(std::vector<Item*>, "inventory items", "recipe");

    std::string recipeName = "";

    for (auto& recipe : recipes)
    {
        recipeName = recipe->GetTemplate()->Name1;
    }

    if (recipeName.empty())
        return false;

    bool used = UseItemAction::Execute(Event(name, recipeName));

    if (used)
        botAI->SetNextCheckDelay(3.0 * IN_MILLISECONDS);

    return used;
}

bool UseRandomQuestItem::isUseful()
{
    return !botAI->HasActivePlayerMaster() && !bot->InBattleground() && !bot->HasUnitState(UNIT_STATE_IN_FLIGHT);
}

bool UseRandomQuestItem::isPossible() { return AI_VALUE2(uint32, "item count", "quest") > 0; }

bool UseRandomQuestItem::Execute(Event event [[maybe_unused]])
{
    Unit* unitTarget = nullptr;
    ObjectGuid goTarget;

    std::vector<Item*> questItems = AI_VALUE2(std::vector<Item*>, "inventory items", "quest");
    if (questItems.empty())
        return false;

    Item* item = nullptr;
    for (uint8 i = 0; i < 5; i++)
    {
        auto itr = questItems.begin();
        std::advance(itr, urand(0, questItems.size() - 1));
        Item* questItem = *itr;

        ItemTemplate const* proto = questItem->GetTemplate();
        if (proto->StartQuest)
        {
            Quest const* qInfo = sObjectMgr->GetQuestTemplate(proto->StartQuest);
            if (bot->CanTakeQuest(qInfo, false))
            {
                item = questItem;
                break;
            }
        }

    }

    if (!item)
        return false;

    bool used = UseItem(item, goTarget, nullptr, unitTarget);
    if (used)
        botAI->SetNextCheckDelay(sShadowAIConfig->globalCoolDown);

    return used;
}
