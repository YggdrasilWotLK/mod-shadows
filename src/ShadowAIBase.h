/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_SHADOWAIBASE_H
#define _SHADOW_SHADOWAIBASE_H

#include "Define.h"
#include "ShadowAIConfig.h"

#include <atomic>

class ShadowAIBase
{
public:
    ShadowAIBase(bool isBotAI);
    virtual ~ShadowAIBase() = default;

    bool CanUpdateAI();
    void SetNextCheckDelay(uint32 const delay);
    void IncreaseNextCheckDelay(uint32 delay);
    void YieldThread(uint32 delay = sShadowAIConfig->reactDelay);
    virtual void UpdateAI(uint32 elapsed, bool minimal = false);
    virtual void UpdateAIInternal(uint32 elapsed, bool minimal = false) = 0;
    bool IsActive();
    bool IsBotAI() const;
    // Lifetime flag: set to false before the object is erased/deleted so
    // concurrent map readers (no lock held across use) can skip a dying entry.
    bool IsAlive() const { return _alive.load(std::memory_order_acquire); }
    void Invalidate() { _alive.store(false, std::memory_order_release); }

protected:
    uint32 nextAICheckDelay;
    class PerformanceMonitorOperation* totalPmo = nullptr;

private:
    bool _isBotAI;
    std::atomic<bool> _alive{true};
};

#endif
