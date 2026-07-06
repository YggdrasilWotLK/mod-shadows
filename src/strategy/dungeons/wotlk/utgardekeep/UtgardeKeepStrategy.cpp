#include "UtgardeKeepStrategy.h"
#include "UtgardeKeepMultipliers.h"


void WotlkDungeonUKStrategy::InitTriggers(std::vector<TriggerNode*> &triggers)
{
    // Prince Keleseth
    triggers.push_back(new TriggerNode("keleseth frost tomb",
             NextAction::array(0, new NextAction("attack frost tomb", ACTION_RAID + 1), nullptr)));

    // Skarvald the Constructor & Dalronn the Controller
    triggers.push_back(new TriggerNode("dalronn priority",
             NextAction::array(0, new NextAction("attack dalronn", ACTION_RAID + 1), nullptr)));

}

void WotlkDungeonUKStrategy::InitMultipliers(std::vector<Multiplier*> &multipliers)
{
    multipliers.push_back(new PrinceKelesethMultiplier(botAI));
    multipliers.push_back(new SkarvaldAndDalronnMultiplier(botAI));
}