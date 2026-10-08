/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#include "ShadowAIBase.h"

#include "Shadows.h"

ShadowAIBase::ShadowAIBase(bool isBotAI) : nextAICheckDelay(0), _isBotAI(isBotAI) {}

void ShadowAIBase::UpdateAI(uint32 elapsed, bool minimal)
{
    if (totalPmo)
        totalPmo->finish();

    totalPmo = sPerformanceMonitor->start(PERF_MON_TOTAL, "ShadowAIBase::FullTick");

    if (nextAICheckDelay > elapsed)
        nextAICheckDelay -= elapsed;
    else
        nextAICheckDelay = 0;

    if (!CanUpdateAI())
        return;

    UpdateAIInternal(elapsed, minimal);
    YieldThread();
}

void ShadowAIBase::SetNextCheckDelay(uint32 const delay)
{
    // if (nextAICheckDelay < delay)
    // LOG_DEBUG("shadows", "Setting lesser delay {} -> {}", nextAICheckDelay, delay);

    nextAICheckDelay = delay;

    // if (nextAICheckDelay > sShadowAIConfig->globalCoolDown)
    // LOG_DEBUG("shadows",  "std::set next check delay: {}", nextAICheckDelay);
}

void ShadowAIBase::IncreaseNextCheckDelay(uint32 delay)
{
    nextAICheckDelay += delay;

    // if (nextAICheckDelay > sShadowAIConfig->globalCoolDown)
    //     LOG_DEBUG("shadows",  "increase next check delay: {}", nextAICheckDelay);
}

bool ShadowAIBase::CanUpdateAI() { return nextAICheckDelay == 0; }

void ShadowAIBase::YieldThread(uint32 delay)
{
    if (nextAICheckDelay < delay)
        nextAICheckDelay = delay;
}

bool ShadowAIBase::IsActive() { return nextAICheckDelay < sShadowAIConfig->maxWaitForMove; }

bool ShadowAIBase::IsBotAI() const { return _isBotAI; }
