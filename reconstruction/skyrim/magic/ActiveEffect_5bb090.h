// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: the partial active effect and base-effect records follow the cited public layouts.
// ActiveEffect, MagicItem, MagicTarget, Effect, Effect::baseEffect, target, spell, duration, elapsedSeconds, flags, ClearTargetImpl, CanFinish, GetBaseObject: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// TESDataHandler, EffectSetting: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// Function declarations, FunctionSlot declarations, padding, effectFlags: STANDIN GUESS(low)
#pragma once

#include <cstdint>

class MagicTarget;

class TESDataHandler
{
public:
    bool Function1c2280() const;
};

class MagicItem
{
public:
    bool IsValid() const;
};

struct EffectSetting
{
    std::uint8_t padding00[0x68];
    std::uint32_t effectFlags;
};

struct Effect
{
    std::uint8_t padding00[0x10];
    EffectSetting* baseEffect;
};

class ActiveEffect
{
public:
    virtual void FunctionSlot00();
    virtual void FunctionSlot01();
    virtual void FunctionSlot02();
    virtual void FunctionSlot03();
    virtual void FunctionSlot04();
    virtual void FunctionSlot05();
    virtual void FunctionSlot06();
    virtual void FunctionSlot07();
    virtual void FunctionSlot08();
    virtual void FunctionSlot09();
    virtual void FunctionSlot0A();
    virtual void FunctionSlot0B();
    virtual void FunctionSlot0C();
    virtual void FunctionSlot0D();
    virtual void FunctionSlot0E();
    virtual void FunctionSlot0F();
    virtual void FunctionSlot10();
    virtual void FunctionSlot11();
    virtual void ClearTargetImpl();
    const EffectSetting* GetBaseObject() const noexcept;
    bool Function5bb910() const;
    void Function5bb950(bool enabled);
    void Function5bcbc0();
    bool CanFinish() const;

private:
    void Function5bac30();

    std::uint8_t padding08[0x38];
    MagicItem* spell;
    Effect* effect;
    MagicTarget* target;
    std::uint8_t padding58[0x18];
    float elapsedSeconds;
    float duration;
    float magnitude;
    std::uint32_t flags;
};
