/*
 * Copyright (C) 2016+ AzerothCore <www.azerothcore.org>, released under GNU GPL v2 license, you may redistribute it
 * and/or modify it under version 2 of the License, or (at your option), any later version.
 */

#ifndef _SHADOW_GENERICWARLOCKNONCOMBATSTRATEGY_H
#define _SHADOW_GENERICWARLOCKNONCOMBATSTRATEGY_H

#include "NonCombatStrategy.h"

class ShadowAI;

class GenericWarlockNonCombatStrategy : public NonCombatStrategy
{
public:
    GenericWarlockNonCombatStrategy(ShadowAI* botAI);

    std::string const getName() override { return "nc"; }
    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
};

class SummonImpStrategy : public NonCombatStrategy
{
public:
    SummonImpStrategy(ShadowAI* ai);
    virtual std::string const getName() override { return "imp"; }

public:
    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
};

class SummonVoidwalkerStrategy : public NonCombatStrategy
{
public:
    SummonVoidwalkerStrategy(ShadowAI* ai);
    virtual std::string const getName() override { return "voidwalker"; }

public:
    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
};

class SummonSuccubusStrategy : public NonCombatStrategy
{
public:
    SummonSuccubusStrategy(ShadowAI* ai);
    virtual std::string const getName() override { return "succubus"; }

public:
    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
};

class SummonFelhunterStrategy : public NonCombatStrategy
{
public:
    SummonFelhunterStrategy(ShadowAI* ai);
    virtual std::string const getName() override { return "felhunter"; }

public:
    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
};

class SummonFelguardStrategy : public NonCombatStrategy
{
public:
    SummonFelguardStrategy(ShadowAI* ai);
    virtual std::string const getName() override { return "felguard"; }

public:
    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
};

class SoulstoneSelfStrategy : public NonCombatStrategy
{
public:
    SoulstoneSelfStrategy(ShadowAI* ai);
    virtual std::string const getName() override { return "ss self"; }

public:
    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
};

class SoulstoneMasterStrategy : public NonCombatStrategy
{
public:
    SoulstoneMasterStrategy(ShadowAI* ai);
    virtual std::string const getName() override { return "ss master"; }

public:
    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
};

class SoulstoneTankStrategy : public NonCombatStrategy
{
public:
    SoulstoneTankStrategy(ShadowAI* ai);
    virtual std::string const getName() override { return "ss tank"; }

public:
    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
};

class SoulstoneHealerStrategy : public NonCombatStrategy
{
public:
    SoulstoneHealerStrategy(ShadowAI* ai);
    virtual std::string const getName() override { return "ss healer"; }

public:
    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
};

class UseSpellstoneStrategy : public NonCombatStrategy
{
public:
    UseSpellstoneStrategy(ShadowAI* ai);
    virtual std::string const getName() override { return "spellstone"; }

public:
    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
};

class UseFirestoneStrategy : public NonCombatStrategy
{
public:
    UseFirestoneStrategy(ShadowAI* ai);
    virtual std::string const getName() override { return "firestone"; }

public:
    void InitTriggers(std::vector<TriggerNode*>& triggers) override;
};

#endif
