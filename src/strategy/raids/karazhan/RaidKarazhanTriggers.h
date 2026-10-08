#ifndef _SHADOW_RAIDKARAZHANTRIGGERS_H
#define _SHADOW_RAIDKARAZHANTRIGGERS_H

#include "Trigger.h"

class KarazhanAttumenTheHuntsmanTrigger : public Trigger
{
public:
    KarazhanAttumenTheHuntsmanTrigger(ShadowAI* botAI) : Trigger(botAI, "karazhan attumen the huntsman") {}
    bool IsActive() override;
};

class KarazhanMoroesTrigger : public Trigger
{
public:
    KarazhanMoroesTrigger(ShadowAI* botAI) : Trigger(botAI, "karazhan moroes") {}
    bool IsActive() override;
};

class KarazhanMaidenOfVirtueTrigger : public Trigger
{
public:
    KarazhanMaidenOfVirtueTrigger(ShadowAI* botAI) : Trigger(botAI, "karazhan maiden of virtue") {}
    bool IsActive() override;
};

class KarazhanBigBadWolfTrigger : public Trigger
{
public:
    KarazhanBigBadWolfTrigger(ShadowAI* botAI) : Trigger(botAI, "karazhan big bad wolf") {}
    bool IsActive() override;
};

class KarazhanRomuloAndJulianneTrigger : public Trigger
{
public:
    KarazhanRomuloAndJulianneTrigger(ShadowAI* botAI) : Trigger(botAI, "karazhan romulo and julianne") {}
    bool IsActive() override;
};

class KarazhanWizardOfOzTrigger : public Trigger
{
public:
    KarazhanWizardOfOzTrigger(ShadowAI* botAI) : Trigger(botAI, "karazhan wizard of oz") {}
    bool IsActive() override;
};

class KarazhanTheCuratorTrigger : public Trigger
{
public:
    KarazhanTheCuratorTrigger(ShadowAI* botAI) : Trigger(botAI, "karazhan the curator") {}
    bool IsActive() override;
};

class KarazhanTerestianIllhoofTrigger : public Trigger
{
public:
    KarazhanTerestianIllhoofTrigger(ShadowAI* botAI) : Trigger(botAI, "karazhan terestian illhoof") {}
    bool IsActive() override;
};

class KarazhanShadeOfAranTrigger : public Trigger
{
public:
    KarazhanShadeOfAranTrigger(ShadowAI* botAI) : Trigger(botAI, "karazhan shade of aran") {}
    bool IsActive() override;
};

class KarazhanNetherspiteTrigger : public Trigger
{
public:
    KarazhanNetherspiteTrigger(ShadowAI* botAI) : Trigger(botAI, "karazhan netherspite") {}
    bool IsActive() override;
};

class KarazhanPrinceMalchezaarTrigger : public Trigger
{
public:
    KarazhanPrinceMalchezaarTrigger(ShadowAI* botAI) : Trigger(botAI, "karazhan prince malchezaar") {}
    bool IsActive() override;
};

#endif
