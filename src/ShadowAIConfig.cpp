/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#include "ShadowAIConfig.h"
#include <iostream>
#include "Config.h"
#include "NewRpgInfo.h"
#include "ShadowDungeonSuggestionMgr.h"
#include "ShadowFactory.h"
#include "Shadows.h"
#include "RandomItemMgr.h"
#include "RandomShadowFactory.h"
#include "RandomShadowMgr.h"
#include "Talentspec.h"

template <class T>
void LoadList(std::string const value, T& list)
{
    std::vector<std::string> ids = split(value, ',');
    for (std::vector<std::string>::iterator i = ids.begin(); i != ids.end(); i++)
    {
        uint32 id = atoi((*i).c_str());
        // if (!id)
        //     continue;
        list.push_back(id);
    }
}

template <class T>
void LoadSet(std::string const value, T& set)
{
    std::vector<std::string> ids = split(value, ',');
    for (std::vector<std::string>::iterator i = ids.begin(); i != ids.end(); i++)
    {
        uint32 id = atoi((*i).c_str());
        // if (!id)
        //     continue;
        set.insert(id);
    }
}

template <class T>
void LoadListString(std::string const value, T& list)
{
    std::vector<std::string> strings = split(value, ',');
    for (std::vector<std::string>::iterator i = strings.begin(); i != strings.end(); i++)
    {
        std::string const string = *i;
        if (string.empty())
            continue;

        list.push_back(string);
    }
}

bool ShadowAIConfig::Initialize()
{
    LOG_INFO("server.loading", "Initializing mod-shadows, based on AI Shadows by ike3 and the original Shadows by blueboy");

    enabled = sConfigMgr->GetOption<bool>("AiShadow.Enabled", true);
    if (!enabled)
    {
        LOG_INFO("server.loading", "Shadows Module is disabled in shadows.conf");
        return false;
    }

    globalCoolDown = sConfigMgr->GetOption<int32>("AiShadow.GlobalCooldown", 1500);
    maxWaitForMove = sConfigMgr->GetOption<int32>("AiShadow.MaxWaitForMove", 5000);
    disableMoveSplinePath = sConfigMgr->GetOption<int32>("AiShadow.DisableMoveSplinePath", 0);
    maxMovementSearchTime = sConfigMgr->GetOption<int32>("AiShadow.MaxMovementSearchTime", 3);
    expireActionTime = sConfigMgr->GetOption<int32>("AiShadow.ExpireActionTime", 5000);
    dispelAuraDuration = sConfigMgr->GetOption<int32>("AiShadow.DispelAuraDuration", 700);
    reactDelay = sConfigMgr->GetOption<int32>("AiShadow.ReactDelay", 100);
    dynamicReactDelay = sConfigMgr->GetOption<bool>("AiShadow.DynamicReactDelay", true);
    passiveDelay = sConfigMgr->GetOption<int32>("AiShadow.PassiveDelay", 10000);
    repeatDelay = sConfigMgr->GetOption<int32>("AiShadow.RepeatDelay", 2000);
    errorDelay = sConfigMgr->GetOption<int32>("AiShadow.ErrorDelay", 100);
    rpgDelay = sConfigMgr->GetOption<int32>("AiShadow.RpgDelay", 10000);
    sitDelay = sConfigMgr->GetOption<int32>("AiShadow.SitDelay", 20000);
    returnDelay = sConfigMgr->GetOption<int32>("AiShadow.ReturnDelay", 2000);
    lootDelay = sConfigMgr->GetOption<int32>("AiShadow.LootDelay", 1000);
    minBotsForGreaterBuff = sConfigMgr->GetOption<int32>("AiShadow.MinBotsForGreaterBuff", 3);
    rpWarningCooldown     = sConfigMgr->GetOption<int32>("AiShadow.RPWarningCooldown", 30);
    disabledWithoutRealPlayerLoginDelay = sConfigMgr->GetOption<int32>("AiShadow.DisabledWithoutRealPlayerLoginDelay", 30);
    disabledWithoutRealPlayerLogoutDelay = sConfigMgr->GetOption<int32>("AiShadow.DisabledWithoutRealPlayerLogoutDelay", 300);

    farDistance = sConfigMgr->GetOption<float>("AiShadow.FarDistance", 20.0f);
    sightDistance = sConfigMgr->GetOption<float>("AiShadow.SightDistance", 100.0f);
    spellDistance = sConfigMgr->GetOption<float>("AiShadow.SpellDistance", 28.5f);
    shootDistance = sConfigMgr->GetOption<float>("AiShadow.ShootDistance", 5.0f);
    healDistance = sConfigMgr->GetOption<float>("AiShadow.HealDistance", 38.5f);
    lootDistance = sConfigMgr->GetOption<float>("AiShadow.LootDistance", 15.0f);
    fleeDistance = sConfigMgr->GetOption<float>("AiShadow.FleeDistance", 5.0f);
    aggroDistance = sConfigMgr->GetOption<float>("AiShadow.AggroDistance", 22.0f);
    tooCloseDistance = sConfigMgr->GetOption<float>("AiShadow.TooCloseDistance", 5.0f);
    meleeDistance = sConfigMgr->GetOption<float>("AiShadow.MeleeDistance", 0.75f);
    followDistance = sConfigMgr->GetOption<float>("AiShadow.FollowDistance", 1.5f);
    whisperDistance = sConfigMgr->GetOption<float>("AiShadow.WhisperDistance", 6000.0f);
    contactDistance = sConfigMgr->GetOption<float>("AiShadow.ContactDistance", 0.45f);
    aoeRadius = sConfigMgr->GetOption<float>("AiShadow.AoeRadius", 10.0f);
    rpgDistance = sConfigMgr->GetOption<float>("AiShadow.RpgDistance", 200.0f);
    grindDistance = sConfigMgr->GetOption<float>("AiShadow.GrindDistance", 75.0f);
    reactDistance = sConfigMgr->GetOption<float>("AiShadow.ReactDistance", 150.0f);

    criticalHealth = sConfigMgr->GetOption<int32>("AiShadow.CriticalHealth", 25);
    lowHealth = sConfigMgr->GetOption<int32>("AiShadow.LowHealth", 45);
    mediumHealth = sConfigMgr->GetOption<int32>("AiShadow.MediumHealth", 65);
    almostFullHealth = sConfigMgr->GetOption<int32>("AiShadow.AlmostFullHealth", 85);
    lowMana = sConfigMgr->GetOption<int32>("AiShadow.LowMana", 15);
    mediumMana = sConfigMgr->GetOption<int32>("AiShadow.MediumMana", 40);
    highMana = sConfigMgr->GetOption<int32>("AiShadow.HighMana", 65);
    autoSaveMana = sConfigMgr->GetOption<bool>("AiShadow.AutoSaveMana", true);
    saveManaThreshold = sConfigMgr->GetOption<int32>("AiShadow.SaveManaThreshold", 60);
    autoAvoidAoe = sConfigMgr->GetOption<bool>("AiShadow.AutoAvoidAoe", true);
    maxAoeAvoidRadius = sConfigMgr->GetOption<float>("AiShadow.MaxAoeAvoidRadius", 15.0f);
    LoadSet<std::set<uint32>>(sConfigMgr->GetOption<std::string>("AiShadow.AoeAvoidSpellWhitelist", "50759,57491,13810,29946"),
                              aoeAvoidSpellWhitelist);
    tellWhenAvoidAoe = sConfigMgr->GetOption<bool>("AiShadow.TellWhenAvoidAoe", false);

    randomGearLoweringChance = sConfigMgr->GetOption<float>("AiShadow.RandomGearLoweringChance", 0.0f);
    incrementalGearInit = sConfigMgr->GetOption<bool>("AiShadow.IncrementalGearInit", true);
    randomGearQualityLimit = sConfigMgr->GetOption<int32>("AiShadow.RandomGearQualityLimit", 3);
    randomGearScoreLimit = sConfigMgr->GetOption<int32>("AiShadow.RandomGearScoreLimit", 0);

    randomBotMinLevelChance = sConfigMgr->GetOption<float>("AiShadow.RandomBotMinLevelChance", 0.1f);
    randomBotMaxLevelChance = sConfigMgr->GetOption<float>("AiShadow.RandomBotMaxLevelChance", 0.1f);
    randomBotRpgChance = sConfigMgr->GetOption<float>("AiShadow.RandomBotRpgChance", 0.20f);

    iterationsPerTick = sConfigMgr->GetOption<int32>("AiShadow.IterationsPerTick", 10);

    allowAccountBots = sConfigMgr->GetOption<bool>("AiShadow.AllowAccountBots", true);
    allowGuildBots = sConfigMgr->GetOption<bool>("AiShadow.AllowGuildBots", true);
    allowTrustedAccountBots = sConfigMgr->GetOption<bool>("AiShadow.AllowTrustedAccountBots", true);
    disabledWithoutRealPlayer = sConfigMgr->GetOption<bool>("AiShadow.DisabledWithoutRealPlayer", false);
    randomBotGuildNearby = sConfigMgr->GetOption<bool>("AiShadow.RandomBotGuildNearby", false);
    randomBotInvitePlayer = sConfigMgr->GetOption<bool>("AiShadow.RandomBotInvitePlayer", false);
    inviteChat = sConfigMgr->GetOption<bool>("AiShadow.InviteChat", false);

    randomBotMapsAsString = sConfigMgr->GetOption<std::string>("AiShadow.RandomBotMaps", "0,1,530,571");
    LoadList<std::vector<uint32>>(randomBotMapsAsString, randomBotMaps);
    probTeleToBankers = sConfigMgr->GetOption<float>("AiShadow.ProbTeleToBankers", 0.25f);
    enableWeightTeleToCityBankers = sConfigMgr->GetOption<bool>("AiShadow.EnableWeightTeleToCityBankers", false);
    weightTeleToStormwind = sConfigMgr->GetOption<int>("AiShadow.TeleToStormwindWeight", 2);
    weightTeleToIronforge = sConfigMgr->GetOption<int>("AiShadow.TeleToIronforgeWeight", 1);
    weightTeleToDarnassus = sConfigMgr->GetOption<int>("AiShadow.TeleToDarnassusWeight", 1);
    weightTeleToExodar = sConfigMgr->GetOption<int>("AiShadow.TeleToExodarWeight", 1);
    weightTeleToOrgrimmar = sConfigMgr->GetOption<int>("AiShadow.TeleToOrgrimmarWeight", 2);
    weightTeleToUndercity = sConfigMgr->GetOption<int>("AiShadow.TeleToUndercityWeight", 1);
    weightTeleToThunderBluff = sConfigMgr->GetOption<int>("AiShadow.TeleToThunderBluffWeight", 1);
    weightTeleToSilvermoonCity = sConfigMgr->GetOption<int>("AiShadow.TeleToSilvermoonCityWeight", 1);
    weightTeleToShattrathCity = sConfigMgr->GetOption<int>("AiShadow.TeleToShattrathCityWeight", 1);
    weightTeleToDalaran = sConfigMgr->GetOption<int>("AiShadow.TeleToDalaranWeight", 1);
    LoadList<std::vector<uint32>>(
        sConfigMgr->GetOption<std::string>("AiShadow.RandomBotQuestItems",
                                           "5175,5176,5177,5178,6948,11000,12382,13704,16309"),
        randomBotQuestItems);
    LoadList<std::vector<uint32>>(sConfigMgr->GetOption<std::string>("AiShadow.RandomBotSpellIds", "54197"),
                                  randomBotSpellIds);
    LoadList<std::vector<uint32>>(
        sConfigMgr->GetOption<std::string>("AiShadow.PvpProhibitedZoneIds",
                                           "2255,656,2361,2362,2363,976,35,2268,3425,392,541,1446,3828,3712,3738,3565,"
                                           "3539,3623,4152,3988,4658,4284,4418,4436,4275,4323,4395,3703,4298,3951"),
        pvpProhibitedZoneIds);
    LoadList<std::vector<uint32>>(
        sConfigMgr->GetOption<std::string>("AiShadow.PvpProhibitedAreaIds",
                                           "976,35,392,2268,4161,4010,4317,4312,3649,3887,3958,3724,4080,3938,3754"),
        pvpProhibitedAreaIds);
    fastReactInBG = sConfigMgr->GetOption<bool>("AiShadow.FastReactInBG", true);
    LoadList<std::vector<uint32>>(
        sConfigMgr->GetOption<std::string>("AiShadow.RandomBotQuestIds", "3802,5505,6502,7761,7848,10277,10285,11492,13188,13189,24499,24511,24710,24712"),
        randomBotQuestIds);

    LoadSet<std::set<uint32>>(
        sConfigMgr->GetOption<std::string>("AiShadow.DisallowedGameObjects",
                                           "176213,17155,2656,74448,19020,3719,3658,3705,3706,105579,75293,2857,"
                                           "179490,141596,160836,160845,179516,176224,181085,176112,128308,128403,"
                                           "165739,165738,175245,175970,176325,176327,123329,2560"),
        disallowedGameObjects);
    botAutologin = sConfigMgr->GetOption<bool>("AiShadow.BotAutologin", false);
    randomBotAutologin = sConfigMgr->GetOption<bool>("AiShadow.RandomBotAutologin", true);
    minRandomBots = sConfigMgr->GetOption<int32>("AiShadow.MinRandomBots", 500);
    maxRandomBots = sConfigMgr->GetOption<int32>("AiShadow.MaxRandomBots", 500);
    randomBotUpdateInterval = sConfigMgr->GetOption<int32>("AiShadow.RandomBotUpdateInterval", 20);
    randomBotCountChangeMinInterval =
        sConfigMgr->GetOption<int32>("AiShadow.RandomBotCountChangeMinInterval", 30 * MINUTE);
    randomBotCountChangeMaxInterval =
        sConfigMgr->GetOption<int32>("AiShadow.RandomBotCountChangeMaxInterval", 2 * HOUR);
    minRandomBotInWorldTime = sConfigMgr->GetOption<int32>("AiShadow.MinRandomBotInWorldTime", 2 * HOUR);
    maxRandomBotInWorldTime = sConfigMgr->GetOption<int32>("AiShadow.MaxRandomBotInWorldTime", 14 * 24 * HOUR);
    minRandomBotRandomizeTime = sConfigMgr->GetOption<int32>("AiShadow.MinRandomBotRandomizeTime", 2 * HOUR);
    maxRandomBotRandomizeTime = sConfigMgr->GetOption<int32>("AiShadow.MaxRandomBotRandomizeTime", 14 * 24 * HOUR);
    minRandomBotChangeStrategyTime =
        sConfigMgr->GetOption<int32>("AiShadow.MinRandomBotChangeStrategyTime", 30 * MINUTE);
    maxRandomBotChangeStrategyTime =
        sConfigMgr->GetOption<int32>("AiShadow.MaxRandomBotChangeStrategyTime", 2 * HOUR);
    minRandomBotReviveTime = sConfigMgr->GetOption<int32>("AiShadow.MinRandomBotReviveTime", MINUTE);
    maxRandomBotReviveTime = sConfigMgr->GetOption<int32>("AiShadow.MaxRandomBotReviveTime", 5 * MINUTE);
    minRandomBotTeleportInterval = sConfigMgr->GetOption<int32>("AiShadow.MinRandomBotTeleportInterval", 1 * HOUR);
    maxRandomBotTeleportInterval = sConfigMgr->GetOption<int32>("AiShadow.MaxRandomBotTeleportInterval", 5 * HOUR);
    permanantlyInWorldTime =
        sConfigMgr->GetOption<int32>("AiShadow.PermanantlyInWorldTime", 1 * YEAR);
    randomBotTeleportDistance = sConfigMgr->GetOption<int32>("AiShadow.RandomBotTeleportDistance", 100);
    randomBotsPerInterval = sConfigMgr->GetOption<int32>("AiShadow.RandomBotsPerInterval", 60);
    minRandomBotsPriceChangeInterval =
        sConfigMgr->GetOption<int32>("AiShadow.MinRandomBotsPriceChangeInterval", 2 * HOUR);
    maxRandomBotsPriceChangeInterval =
        sConfigMgr->GetOption<int32>("AiShadow.MaxRandomBotsPriceChangeInterval", 48 * HOUR);
    randomBotJoinLfg = sConfigMgr->GetOption<bool>("AiShadow.RandomBotJoinLfg", true);

    restrictHealerDPS = sConfigMgr->GetOption<bool>("AiShadow.HealerDPSMapRestriction", false);
    LoadList<std::vector<uint32>>(
        sConfigMgr->GetOption<std::string>("AiShadow.RestrictedHealerDPSMaps",
                                             "33,34,36,43,47,48,70,90,109,129,209,229,230,329,349,389,429,1001,1004,"
                                             "1007,269,540,542,543,545,546,547,552,553,554,555,556,557,558,560,585,574,"
                                             "575,576,578,595,599,600,601,602,604,608,619,632,650,658,668,409,469,509,"
                                             "531,532,534,544,548,550,564,565,580,249,533,603,615,616,624,631,649,724"),
        restrictedHealerDPSMaps);

    //////////////////////////// ICC

    EnableICCBuffs = sConfigMgr->GetOption<bool>("AiShadow.EnableICCBuffs", true);

    //////////////////////////// CHAT
    enableBroadcasts = sConfigMgr->GetOption<bool>("AiShadow.EnableBroadcasts", true);
    randomBotTalk = sConfigMgr->GetOption<bool>("AiShadow.RandomBotTalk", false);
    randomBotEmote = sConfigMgr->GetOption<bool>("AiShadow.RandomBotEmote", false);
    randomBotSuggestDungeons = sConfigMgr->GetOption<bool>("AiShadow.RandomBotSuggestDungeons", true);
    randomBotSayWithoutMaster = sConfigMgr->GetOption<bool>("AiShadow.RandomBotSayWithoutMaster", false);

    // broadcastChanceMaxValue is used in urand(1, broadcastChanceMaxValue) for broadcasts,
    // lowering it will increase the chance, setting it to 0 will disable broadcasts
    // for internal use, not intended to be change by the user
    broadcastChanceMaxValue = enableBroadcasts ? 30000 : 0;

    // all broadcast chances should be in range 1-broadcastChanceMaxValue, value of 0 will disable this particular
    // broadcast setting value to max does not guarantee the broadcast, as there are some internal randoms as well
    broadcastToGuildGlobalChance = sConfigMgr->GetOption<int32>("AiShadow.BroadcastToGuildGlobalChance", 30000);
    broadcastToWorldGlobalChance = sConfigMgr->GetOption<int32>("AiShadow.BroadcastToWorldGlobalChance", 30000);
    broadcastToGeneralGlobalChance = sConfigMgr->GetOption<int32>("AiShadow.BroadcastToGeneralGlobalChance", 30000);
    broadcastToTradeGlobalChance = sConfigMgr->GetOption<int32>("AiShadow.BroadcastToTradeGlobalChance", 30000);
    broadcastToLFGGlobalChance = sConfigMgr->GetOption<int32>("AiShadow.BroadcastToLFGGlobalChance", 30000);
    broadcastToLocalDefenseGlobalChance =
        sConfigMgr->GetOption<int32>("AiShadow.BroadcastToLocalDefenseGlobalChance", 30000);
    broadcastToWorldDefenseGlobalChance =
        sConfigMgr->GetOption<int32>("AiShadow.BroadcastToWorldDefenseGlobalChance", 30000);
    broadcastToGuildRecruitmentGlobalChance =
        sConfigMgr->GetOption<int32>("AiShadow.BroadcastToGuildRecruitmentGlobalChance", 30000);

    broadcastChanceLootingItemPoor = sConfigMgr->GetOption<int32>("AiShadow.BroadcastChanceLootingItemPoor", 30);
    broadcastChanceLootingItemNormal =
        sConfigMgr->GetOption<int32>("AiShadow.BroadcastChanceLootingItemNormal", 300);
    broadcastChanceLootingItemUncommon =
        sConfigMgr->GetOption<int32>("AiShadow.BroadcastChanceLootingItemUncommon", 10000);
    broadcastChanceLootingItemRare = sConfigMgr->GetOption<int32>("AiShadow.BroadcastChanceLootingItemRare", 20000);
    broadcastChanceLootingItemEpic = sConfigMgr->GetOption<int32>("AiShadow.BroadcastChanceLootingItemEpic", 30000);
    broadcastChanceLootingItemLegendary =
        sConfigMgr->GetOption<int32>("AiShadow.BroadcastChanceLootingItemLegendary", 30000);
    broadcastChanceLootingItemArtifact =
        sConfigMgr->GetOption<int32>("AiShadow.BroadcastChanceLootingItemArtifact", 30000);

    broadcastChanceQuestAccepted = sConfigMgr->GetOption<int32>("AiShadow.BroadcastChanceQuestAccepted", 6000);
    broadcastChanceQuestUpdateObjectiveCompleted =
        sConfigMgr->GetOption<int32>("AiShadow.BroadcastChanceQuestUpdateObjectiveCompleted", 300);
    broadcastChanceQuestUpdateObjectiveProgress =
        sConfigMgr->GetOption<int32>("AiShadow.BroadcastChanceQuestUpdateObjectiveProgress", 300);
    broadcastChanceQuestUpdateFailedTimer =
        sConfigMgr->GetOption<int32>("AiShadow.BroadcastChanceQuestUpdateFailedTimer", 300);
    broadcastChanceQuestUpdateComplete =
        sConfigMgr->GetOption<int32>("AiShadow.BroadcastChanceQuestUpdateComplete", 1000);
    broadcastChanceQuestTurnedIn = sConfigMgr->GetOption<int32>("AiShadow.BroadcastChanceQuestTurnedIn", 10000);

    broadcastChanceKillNormal = sConfigMgr->GetOption<int32>("AiShadow.BroadcastChanceKillNormal", 30);
    broadcastChanceKillElite = sConfigMgr->GetOption<int32>("AiShadow.BroadcastChanceKillElite", 300);
    broadcastChanceKillRareelite = sConfigMgr->GetOption<int32>("AiShadow.BroadcastChanceKillRareelite", 3000);
    broadcastChanceKillWorldboss = sConfigMgr->GetOption<int32>("AiShadow.BroadcastChanceKillWorldboss", 20000);
    broadcastChanceKillRare = sConfigMgr->GetOption<int32>("AiShadow.BroadcastChanceKillRare", 10000);
    broadcastChanceKillUnknown = sConfigMgr->GetOption<int32>("AiShadow.BroadcastChanceKillUnknown", 100);
    broadcastChanceKillPet = sConfigMgr->GetOption<int32>("AiShadow.BroadcastChanceKillPet", 10);
    broadcastChanceKillPlayer = sConfigMgr->GetOption<int32>("AiShadow.BroadcastChanceKillPlayer", 30);

    broadcastChanceLevelupGeneric = sConfigMgr->GetOption<int32>("AiShadow.BroadcastChanceLevelupGeneric", 20000);
    broadcastChanceLevelupTenX = sConfigMgr->GetOption<int32>("AiShadow.BroadcastChanceLevelupTenX", 30000);
    broadcastChanceLevelupMaxLevel = sConfigMgr->GetOption<int32>("AiShadow.BroadcastChanceLevelupMaxLevel", 30000);

    broadcastChanceSuggestInstance = sConfigMgr->GetOption<int32>("AiShadow.BroadcastChanceSuggestInstance", 5000);
    broadcastChanceSuggestQuest = sConfigMgr->GetOption<int32>("AiShadow.BroadcastChanceSuggestQuest", 10000);
    broadcastChanceSuggestGrindMaterials =
        sConfigMgr->GetOption<int32>("AiShadow.BroadcastChanceSuggestGrindMaterials", 5000);
    broadcastChanceSuggestGrindReputation =
        sConfigMgr->GetOption<int32>("AiShadow.BroadcastChanceSuggestGrindReputation", 5000);
    broadcastChanceSuggestSell = sConfigMgr->GetOption<int32>("AiShadow.BroadcastChanceSuggestSell", 300);
    broadcastChanceSuggestSomething =
        sConfigMgr->GetOption<int32>("AiShadow.BroadcastChanceSuggestSomething", 30000);

    broadcastChanceSuggestSomethingToxic =
        sConfigMgr->GetOption<int32>("AiShadow.BroadcastChanceSuggestSomethingToxic", 0);

    broadcastChanceSuggestToxicLinks = sConfigMgr->GetOption<int32>("AiShadow.BroadcastChanceSuggestToxicLinks", 0);
    toxicLinksPrefix = sConfigMgr->GetOption<std::string>("AiShadow.ToxicLinksPrefix", "gnomes");

    broadcastChanceSuggestThunderfury =
        sConfigMgr->GetOption<int32>("AiShadow.BroadcastChanceSuggestThunderfury", 1);

    // does not depend on global chance
    broadcastChanceGuildManagement = sConfigMgr->GetOption<int32>("AiShadow.BroadcastChanceGuildManagement", 30000);
    ////////////////////////////

    toxicLinksRepliesChance = sConfigMgr->GetOption<int32>("AiShadow.ToxicLinksRepliesChance", 30);    // 0-100
    thunderfuryRepliesChance = sConfigMgr->GetOption<int32>("AiShadow.ThunderfuryRepliesChance", 40);  // 0-100
    guildRepliesRate = sConfigMgr->GetOption<int32>("AiShadow.GuildRepliesRate", 100);                 // 0-100
    suggestDungeonsInLowerCaseRandomly =
        sConfigMgr->GetOption<bool>("AiShadow.SuggestDungeonsInLowerCaseRandomly", false);

    ////////////////////////// !CHAT

    randomBotJoinBG = sConfigMgr->GetOption<bool>("AiShadow.RandomBotJoinBG", true);
    randomBotAutoJoinBG = sConfigMgr->GetOption<bool>("AiShadow.RandomBotAutoJoinBG", false);

    randomBotAutoJoinArenaBracket = sConfigMgr->GetOption<int32>("AiShadow.RandomBotAutoJoinArenaBracket", 7);

    randomBotAutoJoinICBrackets = sConfigMgr->GetOption<std::string>("AiShadow.RandomBotAutoJoinICBrackets", "0,1");
    randomBotAutoJoinEYBrackets = sConfigMgr->GetOption<std::string>("AiShadow.RandomBotAutoJoinEYBrackets", "0,1,2");
    randomBotAutoJoinAVBrackets = sConfigMgr->GetOption<std::string>("AiShadow.RandomBotAutoJoinAVBrackets", "0,1,2,3");
    randomBotAutoJoinABBrackets = sConfigMgr->GetOption<std::string>("AiShadow.RandomBotAutoJoinABBrackets", "0,1,2,3,4,5,6");
    randomBotAutoJoinWSBrackets = sConfigMgr->GetOption<std::string>("AiShadow.RandomBotAutoJoinWSBrackets", "0,1,2,3,4,5,6,7");

    randomBotAutoJoinBGICCount = sConfigMgr->GetOption<int32>("AiShadow.RandomBotAutoJoinBGICCount", 0);
    randomBotAutoJoinBGEYCount = sConfigMgr->GetOption<int32>("AiShadow.RandomBotAutoJoinBGEYCount", 0);
    randomBotAutoJoinBGAVCount = sConfigMgr->GetOption<int32>("AiShadow.RandomBotAutoJoinBGAVCount", 0);
    randomBotAutoJoinBGABCount = sConfigMgr->GetOption<int32>("AiShadow.RandomBotAutoJoinBGABCount", 0);
    randomBotAutoJoinBGWSCount = sConfigMgr->GetOption<int32>("AiShadow.RandomBotAutoJoinBGWSCount", 0);

    randomBotAutoJoinBGRatedArena2v2Count =
        sConfigMgr->GetOption<int32>("AiShadow.RandomBotAutoJoinBGRatedArena2v2Count", 0);
    randomBotAutoJoinBGRatedArena3v3Count =
        sConfigMgr->GetOption<int32>("AiShadow.RandomBotAutoJoinBGRatedArena3v3Count", 0);
    randomBotAutoJoinBGRatedArena5v5Count =
        sConfigMgr->GetOption<int32>("AiShadow.RandomBotAutoJoinBGRatedArena5v5Count", 0);
    logInGroupOnly = sConfigMgr->GetOption<bool>("AiShadow.LogInGroupOnly", true);
    logValuesPerTick = sConfigMgr->GetOption<bool>("AiShadow.LogValuesPerTick", false);
    fleeingEnabled = sConfigMgr->GetOption<bool>("AiShadow.FleeingEnabled", true);
    summonAtInnkeepersEnabled = sConfigMgr->GetOption<bool>("AiShadow.SummonAtInnkeepersEnabled", true);
    randomBotMinLevel = sConfigMgr->GetOption<int32>("AiShadow.RandomBotMinLevel", 1);
    randomBotMaxLevel = sConfigMgr->GetOption<int32>("AiShadow.RandomBotMaxLevel", 80);
    if (randomBotMaxLevel > sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL))
        randomBotMaxLevel = sWorld->getIntConfig(CONFIG_MAX_PLAYER_LEVEL);
    randomBotLoginAtStartup = sConfigMgr->GetOption<bool>("AiShadow.RandomBotLoginAtStartup", true);
    randomBotTeleLowerLevel = sConfigMgr->GetOption<int32>("AiShadow.RandomBotTeleLowerLevel", 1);
    randomBotTeleHigherLevel = sConfigMgr->GetOption<int32>("AiShadow.RandomBotTeleHigherLevel", 3);
    openGoSpell = sConfigMgr->GetOption<int32>("AiShadow.OpenGoSpell", 6477);

    // Zones for NewRpgStrategy teleportation brackets
    std::vector<uint32> zoneIds = {
        // Classic WoW - Low-level zones
        1, 12, 14, 85, 141, 215, 3430, 3524,
        // Classic WoW - Mid-level zones
        17, 38, 40, 130, 148, 3433, 3525,
        // Classic WoW - High-level zones
        10, 11, 44, 267, 331, 400, 406,
        // Classic WoW - Higher-level zones
        3, 8, 15, 16, 33, 45, 47, 51, 357, 405, 440,
        // Classic WoW - Top-level zones
        4, 28, 46, 139, 361, 490, 618, 1377,
        // The Burning Crusade - Zones
        3483, 3518, 3519, 3520, 3521, 3522, 3523, 4080,
        // Wrath of the Lich King - Zones
        65, 66, 67, 210, 394, 495, 2817, 3537, 3711, 4197
    };

    for (uint32 zoneId : zoneIds)
    {
        std::string setting = "AiShadow.ZoneBracket." + std::to_string(zoneId);
        std::string value = sConfigMgr->GetOption<std::string>(setting, "");

        if (!value.empty())
        {
            size_t commaPos = value.find(',');
            if (commaPos != std::string::npos)
            {
                uint32 minLevel = atoi(value.substr(0, commaPos).c_str());
                uint32 maxLevel = atoi(value.substr(commaPos + 1).c_str());
                zoneBrackets[zoneId] = std::make_pair(minLevel, maxLevel);
            }
        }
    }

    randomChangeMultiplier = sConfigMgr->GetOption<float>("AiShadow.RandomChangeMultiplier", 1.0);

    randomBotCombatStrategies = sConfigMgr->GetOption<std::string>("AiShadow.RandomBotCombatStrategies", "");
    randomBotNonCombatStrategies = sConfigMgr->GetOption<std::string>("AiShadow.RandomBotNonCombatStrategies", "");
    combatStrategies = sConfigMgr->GetOption<std::string>("AiShadow.CombatStrategies", "");
    nonCombatStrategies = sConfigMgr->GetOption<std::string>("AiShadow.NonCombatStrategies", "");
    applyInstanceStrategies = sConfigMgr->GetOption<bool>("AiShadow.ApplyInstanceStrategies", true);

    commandPrefix = sConfigMgr->GetOption<std::string>("AiShadow.CommandPrefix", "");
    commandSeparator = sConfigMgr->GetOption<std::string>("AiShadow.CommandSeparator", "\\\\");

    commandServerPort = sConfigMgr->GetOption<int32>("AiShadow.CommandServerPort", 8888);
    perfMonEnabled = sConfigMgr->GetOption<bool>("AiShadow.PerfMonEnabled", false);

    useGroundMountAtMinLevel = sConfigMgr->GetOption<int32>("AiShadow.UseGroundMountAtMinLevel", 20);
    useFastGroundMountAtMinLevel = sConfigMgr->GetOption<int32>("AiShadow.UseFastGroundMountAtMinLevel", 40);
    useFlyMountAtMinLevel = sConfigMgr->GetOption<int32>("AiShadow.UseFlyMountAtMinLevel", 60);
    useFastFlyMountAtMinLevel = sConfigMgr->GetOption<int32>("AiShadow.UseFastFlyMountAtMinLevel", 70);

    // stagger bot flightpath takeoff
    delayMin = sConfigMgr->GetOption<uint32>("AiShadow.BotTaxiDelayMinMs", 350u);
    delayMax = sConfigMgr->GetOption<uint32>("AiShadow.BotTaxiDelayMaxMs", 5000u);
    gapMs = sConfigMgr->GetOption<uint32>("AiShadow.BotTaxiGapMs", 200u);
    gapJitterMs = sConfigMgr->GetOption<uint32>("AiShadow.BotTaxiGapJitterMs", 100u);

    LOG_INFO("server.loading", "Loading TalentSpecs...");

    for (uint32 cls = 1; cls < MAX_CLASSES; ++cls)
    {
        if (cls == 10)
        {
            continue;
        }
        for (uint32 spec = 0; spec < MAX_SPECNO; ++spec)
        {
            std::ostringstream os;
            os << "AiShadow.PremadeSpecName." << cls << "." << spec;
            premadeSpecName[cls][spec] = sConfigMgr->GetOption<std::string>(os.str().c_str(), "", false);
            os.str("");
            os.clear();
            os << "AiShadow.PremadeSpecGlyph." << cls << "." << spec;
            premadeSpecGlyph[cls][spec] = sConfigMgr->GetOption<std::string>(os.str().c_str(), "", false);
            std::vector<std::string> splitSpecGlyph = split(premadeSpecGlyph[cls][spec], ',');
            for (std::string& split : splitSpecGlyph)
            {
                if (split.size() != 0)
                {
                    parsedSpecGlyph[cls][spec].push_back(atoi(split.c_str()));
                }
            }
            for (uint32 level = 0; level < MAX_LEVEL; ++level)
            {
                std::ostringstream os;
                os << "AiShadow.PremadeSpecLink." << cls << "." << spec << "." << level;
                premadeSpecLink[cls][spec][level] = sConfigMgr->GetOption<std::string>(os.str().c_str(), "", false);
                parsedSpecLinkOrder[cls][spec][level] = ParseTempTalentsOrder(cls, premadeSpecLink[cls][spec][level]);
            }
        }
        for (uint32 spec = 0; spec < 3; ++spec)
        {
            for (uint32 points = 0; points < 21; ++points)
            {
                std::ostringstream os;
                os << "AiShadow.PremadeHunterPetLink." << spec << "." << points;
                premadeHunterPetLink[spec][points] = sConfigMgr->GetOption<std::string>(os.str().c_str(), "", false);
                parsedHunterPetLinkOrder[spec][points] =
                    ParseTempPetTalentsOrder(spec, premadeHunterPetLink[spec][points]);
            }
        }
        for (uint32 spec = 0; spec < MAX_SPECNO; ++spec)
        {
            std::ostringstream os;
            os << "AiShadow.RandomClassSpecProb." << cls << "." << spec;
            uint32 def;
            if (spec <= 1)
                def = 33;
            else if (spec == 2)
                def = 34;
            else
                def = 0;
            randomClassSpecProb[cls][spec] = sConfigMgr->GetOption<uint32>(os.str().c_str(), def, false);
            os.str("");
            os.clear();
            os << "AiShadow.RandomClassSpecIndex." << cls << "." << spec;
            randomClassSpecIndex[cls][spec] = sConfigMgr->GetOption<uint32>(os.str().c_str(), spec, false);
        }
    }

    botCheats.clear();
    LoadListString<std::vector<std::string>>(sConfigMgr->GetOption<std::string>("AiShadow.BotCheats", "food,taxi,raid"),
                                             botCheats);

    botCheatMask = 0;

    if (std::find(botCheats.begin(), botCheats.end(), "food") != botCheats.end())
        botCheatMask |= (uint32)BotCheatMask::food;
    if (std::find(botCheats.begin(), botCheats.end(), "taxi") != botCheats.end())
        botCheatMask |= (uint32)BotCheatMask::taxi;
    if (std::find(botCheats.begin(), botCheats.end(), "gold") != botCheats.end())
        botCheatMask |= (uint32)BotCheatMask::gold;
    if (std::find(botCheats.begin(), botCheats.end(), "health") != botCheats.end())
        botCheatMask |= (uint32)BotCheatMask::health;
    if (std::find(botCheats.begin(), botCheats.end(), "mana") != botCheats.end())
        botCheatMask |= (uint32)BotCheatMask::mana;
    if (std::find(botCheats.begin(), botCheats.end(), "power") != botCheats.end())
        botCheatMask |= (uint32)BotCheatMask::power;
    if (std::find(botCheats.begin(), botCheats.end(), "raid") != botCheats.end())
        botCheatMask |= (uint32)BotCheatMask::raid;

    LoadListString<std::vector<std::string>>(sConfigMgr->GetOption<std::string>("AiShadow.AllowedLogFiles", ""),
                                             allowedLogFiles);
    LoadListString<std::vector<std::string>>(sConfigMgr->GetOption<std::string>("AiShadow.TradeActionExcludedPrefixes", ""),
                                             tradeActionExcludedPrefixes);

    worldBuffs.clear();
    loadWorldBuff();
    LOG_INFO("shadows", "Loading World Buff Feature...");

    randomBotAccountPrefix = sConfigMgr->GetOption<std::string>("AiShadow.RandomBotAccountPrefix", "rndbot");
    randomBotAccountCount = sConfigMgr->GetOption<int32>("AiShadow.RandomBotAccountCount", 0);
    deleteRandomBotAccounts = sConfigMgr->GetOption<bool>("AiShadow.DeleteRandomBotAccounts", false);
    randomBotGuildCount = sConfigMgr->GetOption<int32>("AiShadow.RandomBotGuildCount", 20);
    randomBotGuildSizeMax = sConfigMgr->GetOption<int32>("AiShadow.RandomBotGuildSizeMax", 15);
    deleteRandomBotGuilds = sConfigMgr->GetOption<bool>("AiShadow.DeleteRandomBotGuilds", false);

    guildTaskEnabled = sConfigMgr->GetOption<bool>("AiShadow.EnableGuildTasks", false);
    minGuildTaskChangeTime = sConfigMgr->GetOption<int32>("AiShadow.MinGuildTaskChangeTime", 3 * 24 * 3600);
    maxGuildTaskChangeTime = sConfigMgr->GetOption<int32>("AiShadow.MaxGuildTaskChangeTime", 4 * 24 * 3600);
    minGuildTaskAdvertisementTime = sConfigMgr->GetOption<int32>("AiShadow.MinGuildTaskAdvertisementTime", 300);
    maxGuildTaskAdvertisementTime = sConfigMgr->GetOption<int32>("AiShadow.MaxGuildTaskAdvertisementTime", 12 * 3600);
    minGuildTaskRewardTime = sConfigMgr->GetOption<int32>("AiShadow.MinGuildTaskRewardTime", 300);
    maxGuildTaskRewardTime = sConfigMgr->GetOption<int32>("AiShadow.MaxGuildTaskRewardTime", 3600);
    guildTaskAdvertCleanupTime = sConfigMgr->GetOption<int32>("AiShadow.GuildTaskAdvertCleanupTime", 300);
    guildTaskKillTaskDistance = sConfigMgr->GetOption<int32>("AiShadow.GuildTaskKillTaskDistance", 2000);
    targetPosRecalcDistance = sConfigMgr->GetOption<float>("AiShadow.TargetPosRecalcDistance", 0.1f);

    // cosmetics (by lidocain)
    randomBotShowCloak = sConfigMgr->GetOption<bool>("AiShadow.RandomBotShowCloak", true);
    randomBotShowHelmet = sConfigMgr->GetOption<bool>("AiShadow.RandomBotShowHelmet", true);

    // SPP switches
    enableGreet = sConfigMgr->GetOption<bool>("AiShadow.EnableGreet", true);
    summonWhenGroup = sConfigMgr->GetOption<bool>("AiShadow.SummonWhenGroup", true);
    randomBotFixedLevel = sConfigMgr->GetOption<bool>("AiShadow.RandomBotFixedLevel", false);
    disableRandomLevels = sConfigMgr->GetOption<bool>("AiShadow.DisableRandomLevels", false);
    randomBotRandomPassword = sConfigMgr->GetOption<bool>("AiShadow.RandomBotRandomPassword", true);
    downgradeMaxLevelBot = sConfigMgr->GetOption<bool>("AiShadow.DowngradeMaxLevelBot", true);
    equipmentPersistence = sConfigMgr->GetOption<bool>("AiShadow.EquipmentPersistence", false);
    equipmentPersistenceLevel = sConfigMgr->GetOption<int32>("AiShadow.EquipmentPersistenceLevel", 80);
    groupInvitationPermission = sConfigMgr->GetOption<int32>("AiShadow.GroupInvitationPermission", 1);
    keepAltsInGroup = sConfigMgr->GetOption<bool>("AiShadow.KeepAltsInGroup", false);
    allowSummonInCombat = sConfigMgr->GetOption<bool>("AiShadow.AllowSummonInCombat", true);
    allowSummonWhenMasterIsDead = sConfigMgr->GetOption<bool>("AiShadow.AllowSummonWhenMasterIsDead", true);
    allowSummonWhenBotIsDead = sConfigMgr->GetOption<bool>("AiShadow.AllowSummonWhenBotIsDead", true);
    reviveBotWhenSummoned = sConfigMgr->GetOption<int32>("AiShadow.ReviveBotWhenSummoned", 1);
    botRepairWhenSummon = sConfigMgr->GetOption<bool>("AiShadow.BotRepairWhenSummon", true);
    autoInitOnly = sConfigMgr->GetOption<bool>("AiShadow.AutoInitOnly", false);
    autoInitEquipLevelLimitRatio = sConfigMgr->GetOption<float>("AiShadow.AutoInitEquipLevelLimitRatio", 1.0);

    maxAddedBots = sConfigMgr->GetOption<int32>("AiShadow.MaxAddedBots", 40);
    addClassCommand = sConfigMgr->GetOption<int32>("AiShadow.AddClassCommand", 1);
    addClassAccountPoolSize = sConfigMgr->GetOption<int32>("AiShadow.AddClassAccountPoolSize", 50);
    maintenanceCommand = sConfigMgr->GetOption<int32>("AiShadow.MaintenanceCommand", 1);

    altMaintenanceAttunementQs = sConfigMgr->GetOption<bool>("AiShadow.AltMaintenanceAttunementQuests", true);
    altMaintenanceBags = sConfigMgr->GetOption<bool>("AiShadow.AltMaintenanceBags", true);
    altMaintenanceAmmo = sConfigMgr->GetOption<bool>("AiShadow.AltMaintenanceAmmo", true);
    altMaintenanceFood = sConfigMgr->GetOption<bool>("AiShadow.AltMaintenanceFood", true);
    altMaintenanceReagents = sConfigMgr->GetOption<bool>("AiShadow.AltMaintenanceReagents", true);
    altMaintenanceConsumables = sConfigMgr->GetOption<bool>("AiShadow.AltMaintenanceConsumables", true);
    altMaintenancePotions = sConfigMgr->GetOption<bool>("AiShadow.AltMaintenancePotions", true);
    altMaintenanceTalentTree = sConfigMgr->GetOption<bool>("AiShadow.AltMaintenanceTalentTree", true);
    altMaintenancePet = sConfigMgr->GetOption<bool>("AiShadow.AltMaintenancePet", true);
    altMaintenancePetTalents = sConfigMgr->GetOption<bool>("AiShadow.AltMaintenancePetTalents", true);
    altMaintenanceClassSpells = sConfigMgr->GetOption<bool>("AiShadow.AltMaintenanceClassSpells", true);
    altMaintenanceAvailableSpells = sConfigMgr->GetOption<bool>("AiShadow.AltMaintenanceAvailableSpells", true);
    altMaintenanceSkills = sConfigMgr->GetOption<bool>("AiShadow.AltMaintenanceSkills", true);
    altMaintenanceReputation = sConfigMgr->GetOption<bool>("AiShadow.AltMaintenanceReputation", true);
    altMaintenanceSpecialSpells = sConfigMgr->GetOption<bool>("AiShadow.AltMaintenanceSpecialSpells", true);
    altMaintenanceMounts = sConfigMgr->GetOption<bool>("AiShadow.AltMaintenanceMounts", true);
    altMaintenanceGlyphs = sConfigMgr->GetOption<bool>("AiShadow.AltMaintenanceGlyphs", true);
    altMaintenanceKeyring = sConfigMgr->GetOption<bool>("AiShadow.AltMaintenanceKeyring", true);
    altMaintenanceGemsEnchants = sConfigMgr->GetOption<bool>("AiShadow.AltMaintenanceGemsEnchants", true);

    autoGearCommand = sConfigMgr->GetOption<int32>("AiShadow.AutoGearCommand", 1);
    autoGearCommandAltBots = sConfigMgr->GetOption<int32>("AiShadow.AutoGearCommandAltBots", 1);
    autoGearQualityLimit = sConfigMgr->GetOption<int32>("AiShadow.AutoGearQualityLimit", 3);
    autoGearScoreLimit = sConfigMgr->GetOption<int32>("AiShadow.AutoGearScoreLimit", 0);

    randomBotXPRate = sConfigMgr->GetOption<float>("AiShadow.RandomBotXPRate", 1.0);
    randomBotAllianceRatio = sConfigMgr->GetOption<int32>("AiShadow.RandomBotAllianceRatio", 50);
    randomBotHordeRatio = sConfigMgr->GetOption<int32>("AiShadow.RandomBotHordeRatio", 50);
    disableDeathKnightLogin = sConfigMgr->GetOption<bool>("AiShadow.DisableDeathKnightLogin", 0);
    limitTalentsExpansion = sConfigMgr->GetOption<bool>("AiShadow.LimitTalentsExpansion", 0);
    botActiveAlone = sConfigMgr->GetOption<int32>("AiShadow.BotActiveAlone", 100);
    BotActiveAloneForceWhenInRadius = sConfigMgr->GetOption<uint32>("AiShadow.BotActiveAloneForceWhenInRadius", 150);
    BotActiveAloneForceWhenInZone = sConfigMgr->GetOption<bool>("AiShadow.BotActiveAloneForceWhenInZone", 1);
    BotActiveAloneForceWhenInMap = sConfigMgr->GetOption<bool>("AiShadow.BotActiveAloneForceWhenInMap", 0);
    BotActiveAloneForceWhenIsFriend = sConfigMgr->GetOption<bool>("AiShadow.BotActiveAloneForceWhenIsFriend", 1);
    BotActiveAloneForceWhenInGuild = sConfigMgr->GetOption<bool>("AiShadow.BotActiveAloneForceWhenInGuild", 1);
    botActiveAloneSmartScale = sConfigMgr->GetOption<bool>("AiShadow.botActiveAloneSmartScale", 1);
    botActiveAloneSmartScaleDiffLimitfloor = sConfigMgr->GetOption<uint32>("AiShadow.botActiveAloneSmartScaleDiffLimitfloor", 50);
    botActiveAloneSmartScaleDiffLimitCeiling = sConfigMgr->GetOption<uint32>("AiShadow.botActiveAloneSmartScaleDiffLimitCeiling", 200);
    botActiveAloneSmartScaleWhenMinLevel = sConfigMgr->GetOption<uint32>("AiShadow.botActiveAloneSmartScaleWhenMinLevel", 1);
    botActiveAloneSmartScaleWhenMaxLevel = sConfigMgr->GetOption<uint32>("AiShadow.botActiveAloneSmartScaleWhenMaxLevel", 80);

    randombotsWalkingRPG = sConfigMgr->GetOption<bool>("AiShadow.RandombotsWalkingRPG", false);
    randombotsWalkingRPGInDoors = sConfigMgr->GetOption<bool>("AiShadow.RandombotsWalkingRPG.InDoors", false);
    minEnchantingBotLevel = sConfigMgr->GetOption<int32>("AiShadow.MinEnchantingBotLevel", 60);
    limitEnchantExpansion = sConfigMgr->GetOption<int32>("AiShadow.LimitEnchantExpansion", 1);
    limitGearExpansion = sConfigMgr->GetOption<int32>("AiShadow.LimitGearExpansion", 1);
    randombotStartingLevel = sConfigMgr->GetOption<int32>("AiShadow.RandombotStartingLevel", 1);
    enablePeriodicOnlineOffline = sConfigMgr->GetOption<bool>("AiShadow.EnablePeriodicOnlineOffline", false);
    enableRandomBotTrading = sConfigMgr->GetOption<int32>("AiShadow.EnableRandomBotTrading", 1);
    periodicOnlineOfflineRatio = sConfigMgr->GetOption<float>("AiShadow.PeriodicOnlineOfflineRatio", 2.0);
    gearscorecheck = sConfigMgr->GetOption<bool>("AiShadow.GearScoreCheck", false);
    randomBotPreQuests = sConfigMgr->GetOption<bool>("AiShadow.PreQuests", false);

    // SPP automation
    freeMethodLoot = sConfigMgr->GetOption<bool>("AiShadow.FreeMethodLoot", false);
    lootRollLevel = sConfigMgr->GetOption<int32>("AiShadow.LootRollLevel", 1);
    autoPickReward = sConfigMgr->GetOption<std::string>("AiShadow.AutoPickReward", "yes");
    autoEquipUpgradeLoot = sConfigMgr->GetOption<bool>("AiShadow.AutoEquipUpgradeLoot", true);
    equipUpgradeThreshold = sConfigMgr->GetOption<float>("AiShadow.EquipUpgradeThreshold", 1.1f);
    twoRoundsGearInit = sConfigMgr->GetOption<bool>("AiShadow.TwoRoundsGearInit", false);
    syncQuestWithPlayer = sConfigMgr->GetOption<bool>("AiShadow.SyncQuestWithPlayer", true);
    syncQuestForPlayer = sConfigMgr->GetOption<bool>("AiShadow.SyncQuestForPlayer", false);
    dropObsoleteQuests = sConfigMgr->GetOption<bool>("AiShadow.DropObsoleteQuests", true);
    autoTrainSpells = sConfigMgr->GetOption<std::string>("AiShadow.AutoTrainSpells", "yes");
    autoPickTalents = sConfigMgr->GetOption<bool>("AiShadow.AutoPickTalents", true);
    autoUpgradeEquip = sConfigMgr->GetOption<bool>("AiShadow.AutoUpgradeEquip", false);
    hunterWolfPet = sConfigMgr->GetOption<int32>("AiShadow.HunterWolfPet", 0);
    defaultPetStance = sConfigMgr->GetOption<int32>("AiShadow.DefaultPetStance", 1);
    petChatCommandDebug = sConfigMgr->GetOption<bool>("AiShadow.PetChatCommandDebug", 0);
    autoLearnTrainerSpells = sConfigMgr->GetOption<bool>("AiShadow.AutoLearnTrainerSpells", true);
    autoLearnQuestSpells = sConfigMgr->GetOption<bool>("AiShadow.AutoLearnQuestSpells", false);
    autoTeleportForLevel = sConfigMgr->GetOption<bool>("AiShadow.AutoTeleportForLevel", false);
    autoDoQuests = sConfigMgr->GetOption<bool>("AiShadow.AutoDoQuests", true);
    enableNewRpgStrategy = sConfigMgr->GetOption<bool>("AiShadow.EnableNewRpgStrategy", true);

    RpgStatusProbWeight[RPG_WANDER_RANDOM] = sConfigMgr->GetOption<int32>("AiShadow.RpgStatusProbWeight.WanderRandom", 15);
    RpgStatusProbWeight[RPG_WANDER_NPC] = sConfigMgr->GetOption<int32>("AiShadow.RpgStatusProbWeight.WanderNpc", 20);
    RpgStatusProbWeight[RPG_GO_GRIND] = sConfigMgr->GetOption<int32>("AiShadow.RpgStatusProbWeight.GoGrind", 15);
    RpgStatusProbWeight[RPG_GO_CAMP] = sConfigMgr->GetOption<int32>("AiShadow.RpgStatusProbWeight.GoCamp", 10);
    RpgStatusProbWeight[RPG_DO_QUEST] = sConfigMgr->GetOption<int32>("AiShadow.RpgStatusProbWeight.DoQuest", 60);
    RpgStatusProbWeight[RPG_TRAVEL_FLIGHT] = sConfigMgr->GetOption<int32>("AiShadow.RpgStatusProbWeight.TravelFlight", 15);
    RpgStatusProbWeight[RPG_REST] = sConfigMgr->GetOption<int32>("AiShadow.RpgStatusProbWeight.Rest", 5);

    syncLevelWithPlayers = sConfigMgr->GetOption<bool>("AiShadow.SyncLevelWithPlayers", false);
    randomBotGroupNearby = sConfigMgr->GetOption<bool>("AiShadow.RandomBotGroupNearby", false);

    // arena
    randomBotArenaTeam2v2Count = sConfigMgr->GetOption<int32>("AiShadow.RandomBotArenaTeam2v2Count", 10);
    randomBotArenaTeam3v3Count = sConfigMgr->GetOption<int32>("AiShadow.RandomBotArenaTeam3v3Count", 10);
    randomBotArenaTeam5v5Count = sConfigMgr->GetOption<int32>("AiShadow.RandomBotArenaTeam5v5Count", 5);
    deleteRandomBotArenaTeams = sConfigMgr->GetOption<bool>("AiShadow.DeleteRandomBotArenaTeams", false);
    randomBotArenaTeamMaxRating = sConfigMgr->GetOption<int32>("AiShadow.RandomBotArenaTeamMaxRating", 2000);
    randomBotArenaTeamMinRating = sConfigMgr->GetOption<int32>("AiShadow.RandomBotArenaTeamMinRating", 1000);

    selfBotLevel = sConfigMgr->GetOption<int32>("AiShadow.SelfBotLevel", 1);

    RandomShadowFactory::CreateRandomBots();
    if (World::IsStopped())
    {
        return true;
    }

    // Assign account types after accounts are created
    sRandomShadowMgr->AssignAccountTypes();

    if (sShadowAIConfig->enabled)
    {
        sRandomShadowMgr->Init();
    }

    sRandomItemMgr->Init();
    sRandomItemMgr->InitAfterAhBot();
    sShadowTextMgr->LoadBotTexts();
    sShadowTextMgr->LoadBotTextChance();
    ShadowFactory::Init();

    AiObjectContext::BuildAllSharedContexts();

    if (sShadowAIConfig->randomBotSuggestDungeons)
    {
        sShadowDungeonSuggestionMgr->LoadDungeonSuggestions();
    }

    excludedHunterPetFamilies.clear();
    LoadList<std::vector<uint32>>(sConfigMgr->GetOption<std::string>("AiShadow.ExcludedHunterPetFamilies", ""), excludedHunterPetFamilies);

    LOG_INFO("server.loading", "---------------------------------------");
    LOG_INFO("server.loading", "       mod-shadows initialized      ");
    LOG_INFO("server.loading", "---------------------------------------");

    return true;
}

bool ShadowAIConfig::IsInRandomAccountList(uint32 id)
{
    return find(randomBotAccounts.begin(), randomBotAccounts.end(), id) != randomBotAccounts.end();
}

bool ShadowAIConfig::IsInRandomQuestItemList(uint32 id)
{
    return find(randomBotQuestItems.begin(), randomBotQuestItems.end(), id) != randomBotQuestItems.end();
}

bool ShadowAIConfig::IsPvpProhibited(uint32 zoneId, uint32 areaId)
{
    return IsInPvpProhibitedZone(zoneId) || IsInPvpProhibitedArea(areaId) || IsInPvpProhibitedZone(areaId);
}

bool ShadowAIConfig::IsInPvpProhibitedZone(uint32 id)
{
    return find(pvpProhibitedZoneIds.begin(), pvpProhibitedZoneIds.end(), id) != pvpProhibitedZoneIds.end();
}

bool ShadowAIConfig::IsInPvpProhibitedArea(uint32 id)
{
    return find(pvpProhibitedAreaIds.begin(), pvpProhibitedAreaIds.end(), id) != pvpProhibitedAreaIds.end();
}

bool ShadowAIConfig::IsRestrictedHealerDPSMap(uint32 mapId) const
{
    return restrictHealerDPS &&
            std::find(restrictedHealerDPSMaps.begin(), restrictedHealerDPSMaps.end(), mapId) != restrictedHealerDPSMaps.end();
}

std::string const ShadowAIConfig::GetTimestampStr()
{
    time_t t = time(nullptr);
    tm* aTm = localtime(&t);
    //       YYYY   year
    //       MM     month (2 digits 01-12)
    //       DD     day (2 digits 01-31)
    //       HH     hour (2 digits 00-23)
    //       MM     minutes (2 digits 00-59)
    //       SS     seconds (2 digits 00-59)
    char buf[20];
    snprintf(buf, 20, "%04d-%02d-%02d %02d-%02d-%02d", aTm->tm_year + 1900, aTm->tm_mon + 1, aTm->tm_mday, aTm->tm_hour,
             aTm->tm_min, aTm->tm_sec);
    return std::string(buf);
}

bool ShadowAIConfig::openLog(std::string const fileName, char const* mode)
{
    if (!hasLog(fileName))
        return false;

    auto logFileIt = logFiles.find(fileName);
    if (logFileIt == logFiles.end())
    {
        logFiles.insert(std::make_pair(fileName, std::make_pair(nullptr, false)));
        logFileIt = logFiles.find(fileName);
    }

    FILE* file = logFileIt->second.first;
    bool fileOpen = logFileIt->second.second;

    if (fileOpen)  // close log file
        fclose(file);

    std::string m_logsDir = sConfigMgr->GetOption<std::string>("LogsDir", "", false);
    if (!m_logsDir.empty())
    {
        if ((m_logsDir.at(m_logsDir.length() - 1) != '/') && (m_logsDir.at(m_logsDir.length() - 1) != '\\'))
            m_logsDir.append("/");
    }

    file = fopen((m_logsDir + fileName).c_str(), mode);
    fileOpen = true;

    logFileIt->second.first = file;
    logFileIt->second.second = fileOpen;

    return true;
}

void ShadowAIConfig::log(std::string const fileName, char const* str, ...)
{
    if (!str)
        return;

    std::lock_guard<std::mutex> guard(m_logMtx);

    if (!isLogOpen(fileName) && !openLog(fileName, "a"))
        return;

    FILE* file = logFiles.find(fileName)->second.first;

    va_list ap;
    va_start(ap, str);
    vfprintf(file, str, ap);
    fprintf(file, "\n");
    va_end(ap);
    fflush(file);

    fflush(stdout);
}

void ShadowAIConfig::loadWorldBuff()
{
    std::string matrix = sConfigMgr->GetOption<std::string>("AiShadow.WorldBuffMatrix", "", true);
    if (matrix.empty())
        return;

    std::istringstream entryStream(matrix);
    std::string entry;

    while (std::getline(entryStream, entry, ';'))
    {

        entry.erase(0, entry.find_first_not_of(" \t\r\n"));
        entry.erase(entry.find_last_not_of(" \t\r\n") + 1);

        size_t firstColon = entry.find(':');
        size_t secondColon = entry.find(':', firstColon + 1);

        if (firstColon == std::string::npos || secondColon == std::string::npos)
        {
            LOG_ERROR("shadows", "Malformed entry: [{}]", entry);
            continue;
        }

        std::string metaPart = entry.substr(firstColon + 1, secondColon - firstColon - 1);
        std::string spellPart = entry.substr(secondColon + 1);

        std::vector<uint32> ids;
        std::istringstream metaStream(metaPart);
        std::string token;
        while (std::getline(metaStream, token, ','))
        {
            try {
                ids.push_back(static_cast<uint32>(std::stoi(token)));
            } catch (...) {
                LOG_ERROR("shadows", "Invalid meta token in [{}]", entry);
                break;
            }
        }

        if (ids.size() != 5)
        {
            LOG_ERROR("shadows", "Entry [{}] has incomplete meta block", entry);
            continue;
        }

        std::istringstream spellStream(spellPart);
        while (std::getline(spellStream, token, ','))
        {
            try {
                uint32 spellId = static_cast<uint32>(std::stoi(token));
                worldBuff wb = { spellId, ids[0], ids[1], ids[2], ids[3], ids[4] };
                worldBuffs.push_back(wb);
            } catch (...) {
                LOG_ERROR("shadows", "Invalid spell ID in [{}]", entry);
            }
        }
    }
}

static std::vector<std::string> split(const std::string& str, const std::string& pattern)
{
    std::vector<std::string> res;
    if (str == "")
        return res;
    // Also add separators to string connections to facilitate intercepting the last paragraph.
    std::string strs = str + pattern;
    size_t pos = strs.find(pattern);

    while (pos != strs.npos)
    {
        std::string temp = strs.substr(0, pos);
        res.push_back(temp);
        // Remove the split string and split the remaining string
        strs = strs.substr(pos + 1, strs.size());
        pos = strs.find(pattern);
    }

    return res;
}

std::vector<std::vector<uint32>> ShadowAIConfig::ParseTempTalentsOrder(uint32 cls, std::string tab_link)
{
    // check bad link
    uint32 classMask = 1 << (cls - 1);
    std::vector<std::vector<uint32>> res;
    std::vector<std::string> tab_links = split(tab_link, "-");
    std::map<uint32, std::vector<TalentEntry const*>> spells;
    std::vector<std::vector<std::vector<uint32>>> orders(3);
    for (uint32 i = 0; i < sTalentStore.GetNumRows(); ++i)
    {
        TalentEntry const* talentInfo = sTalentStore.LookupEntry(i);
        if (!talentInfo)
            continue;

        TalentTabEntry const* talentTabInfo = sTalentTabStore.LookupEntry(talentInfo->TalentTab);
        if (!talentTabInfo)
            continue;

        if ((classMask & talentTabInfo->ClassMask) == 0)
            continue;

        spells[talentTabInfo->tabpage].push_back(talentInfo);
    }
    for (int tab = 0; tab < 3; tab++)
    {
        if (tab_links.size() <= tab)
        {
            break;
        }
        std::sort(spells[tab].begin(), spells[tab].end(),
                  [&](TalentEntry const* lhs, TalentEntry const* rhs)
                  { return lhs->Row != rhs->Row ? lhs->Row < rhs->Row : lhs->Col < rhs->Col; });
        for (int i = 0; i < tab_links[tab].size(); i++)
        {
            if (i >= spells[tab].size())
            {
                break;
            }
            int lvl = tab_links[tab][i] - '0';
            if (lvl == 0)
                continue;
            orders[tab].push_back({(uint32)tab, spells[tab][i]->Row, spells[tab][i]->Col, (uint32)lvl});
        }
    }
    // sort by talent tab size
    std::sort(orders.begin(), orders.end(), [&](auto& lhs, auto& rhs) { return lhs.size() > rhs.size(); });
    for (auto& order : orders)
    {
        res.insert(res.end(), order.begin(), order.end());
    }
    return res;
}

std::vector<std::vector<uint32>> ShadowAIConfig::ParseTempPetTalentsOrder(uint32 spec, std::string tab_link)
{
    // check bad link
    // uint32 classMask = 1 << (cls - 1);
    std::vector<TalentEntry const*> spells;
    std::vector<std::vector<uint32>> orders;
    for (uint32 i = 0; i < sTalentStore.GetNumRows(); ++i)
    {
        TalentEntry const* talentInfo = sTalentStore.LookupEntry(i);
        if (!talentInfo)
            continue;

        TalentTabEntry const* talentTabInfo = sTalentTabStore.LookupEntry(talentInfo->TalentTab);
        if (!talentTabInfo)
            continue;

        if (!((1 << spec) & talentTabInfo->petTalentMask))
            continue;
        // skip some duplicate spells like dash/dive
        if (talentInfo->TalentID == 2201 || talentInfo->TalentID == 2208 || talentInfo->TalentID == 2219 ||
            talentInfo->TalentID == 2203)
            continue;

        spells.push_back(talentInfo);
    }
    std::sort(spells.begin(), spells.end(),
              [&](TalentEntry const* lhs, TalentEntry const* rhs)
              { return lhs->Row != rhs->Row ? lhs->Row < rhs->Row : lhs->Col < rhs->Col; });
    for (int i = 0; i < tab_link.size(); i++)
    {
        if (i >= spells.size())
        {
            break;
        }
        int lvl = tab_link[i] - '0';
        if (lvl == 0)
            continue;
        orders.push_back({spells[i]->Row, spells[i]->Col, (uint32)lvl});
    }
    // sort by talent tab size
    std::sort(orders.begin(), orders.end(), [&](auto& lhs, auto& rhs) { return lhs.size() > rhs.size(); });

    return orders;
}
