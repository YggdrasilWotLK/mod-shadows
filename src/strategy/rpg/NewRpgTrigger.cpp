#include "NewRpgTriggers.h"
#include "ShadowAI.h"

bool NewRpgStatusTrigger::IsActive() { return status == botAI->rpgInfo.status; }