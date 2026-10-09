#pragma once

class ShadowAI;
class Player;
class ItemTemplate;
class Quest;
class Creature;
class Group;

class BroadcastHelper
{
public:
    BroadcastHelper();

public:
    enum ToChannel
    {
        TO_GUILD = 1,
        TO_WORLD = 2,
        TO_GENERAL = 3,
        TO_TRADE = 4,
        TO_LOOKING_FOR_GROUP = 5,
        TO_LOCAL_DEFENSE = 6,
        TO_WORLD_DEFENSE = 7,
        TO_GUILD_RECRUITMENT = 8
    };

    static uint8_t GetLocale();
    static bool BroadcastTest(
        ShadowAI* ai,
        Player* bot
    );
    static bool BroadcastToChannelWithGlobalChance(
        ShadowAI* ai,
        std::string message,
        std::list<std::pair<ToChannel, uint32_t>> toChannels
    );
    static bool BroadcastLootingItem(
        ShadowAI* ai,
        Player* bot,
        const ItemTemplate* proto
    );
    static bool BroadcastQuestAccepted(
        ShadowAI* ai,
        Player* bot,
        const Quest* quest
    );
    static bool BroadcastQuestUpdateAddKill(
        ShadowAI* ai,
        Player* bot,
        Quest const* quest,
        uint32_t availableCount,
        uint32_t requiredCount,
        std::string obectiveName
    );
    static bool BroadcastQuestUpdateAddItem(
        ShadowAI* ai,
        Player* bot,
        Quest const* quest,
        uint32_t availableCount,
        uint32_t requiredCount,
        const ItemTemplate* proto
    );
    static bool BroadcastQuestUpdateFailedTimer(
        ShadowAI* ai,
        Player* bot,
        Quest const* quest
    );
    static bool BroadcastQuestUpdateComplete(
        ShadowAI* ai,
        Player* bot,
        Quest const* quest
    );
    static bool BroadcastQuestTurnedIn(
        ShadowAI* ai,
        Player* bot,
        Quest const* quest
    );
    static bool BroadcastKill(
        ShadowAI* ai,
        Player* bot,
        Creature* creature
    );
    static bool BroadcastLevelup(
        ShadowAI* ai,
        Player* bot
    );
    static bool BroadcastGuildMemberPromotion(
        ShadowAI* ai,
        Player* bot,
        Player* player
    );
    static bool BroadcastGuildMemberDemotion(
        ShadowAI* ai,
        Player* bot,
        Player* player
    );
    static bool BroadcastGuildGroupOrRaidInvite(
        ShadowAI* ai,
        Player* bot,
        Player* player,
        Group* group
    );
    static bool BroadcastSuggestInstance(
        ShadowAI* ai,
        std::vector<std::string>& allowedInstances,
        Player* bot
    );
    static bool BroadcastSuggestQuest(
        ShadowAI* ai,
        std::vector<uint32>& quests,
        Player* bot
    );
    static bool BroadcastSuggestGrindMaterials(
        ShadowAI* ai,
        std::string item,
        Player* bot
    );
    static bool BroadcastSuggestGrindReputation(
        ShadowAI* ai,
        std::vector<std::string> levels,
        std::vector<std::string> allowedFactions,
        Player* bot
    );
    static bool BroadcastSuggestSell(
        ShadowAI* ai,
        const ItemTemplate* proto,
        uint32_t count,
        uint32_t price,
        Player* bot
    );
    static bool BroadcastSuggestSomething(
        ShadowAI* ai,
        Player* bot
    );
    static bool BroadcastSuggestSomethingToxic(
        ShadowAI* ai,
        Player* bot
    );
    static bool BroadcastSuggestToxicLinks(
        ShadowAI* ai,
        Player* bot
    );
    static bool BroadcastSuggestThunderfury(
        ShadowAI* ai,
        Player* bot
    );
};