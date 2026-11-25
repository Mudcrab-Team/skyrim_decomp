// Source exposure: mixed (pinned image and cited public declarations).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: partial caster and reference prefixes follow the cited class and virtual slot declarations. Stamped as a twin of matched 0x5cd2d0 (skyrim/magic/MagicCaster_5cd1b0): source copied, names replaced by placeholders.
// TESObjectREFR, MagicItem, Actor: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SoundID, State: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// CastingSounds: STANDIN GUESS(low)
// Function1599430, Owner1599430: GUESS(low) STANDIN
// currentSpell, desiredTarget, sounds, state, castingTimer, nextTargetUpdate, projectileTimer, StartChargeImpl, StartCastImpl, SelectSpellImpl, PrepareSound, AdjustActiveEffect, kUnk02, kUnk04: GUESS(low) STANDIN
#pragma once
#include "MagicCaster_5cd1b0.h"

class Owner1599430
{
public:
    enum class State : std::uint32_t { kUnk02 = 2, kUnk04 = 4 };
    virtual ~Owner1599430();
    virtual void FunctionSlot01();
    virtual void FunctionSlot02();
    virtual void FunctionSlot03();
    virtual bool StartChargeImpl();
    virtual void FunctionSlot05();
    virtual void StartCastImpl();
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
    virtual void SelectSpellImpl();
    virtual void FunctionSlot12();
    virtual void FunctionSlot13();
    virtual void FunctionSlot14();
    virtual void FunctionSlot15();
    virtual void FunctionSlot16();
    virtual void FunctionSlot17();
    virtual void FunctionSlot18();
    virtual void FunctionSlot19();
    virtual void FunctionSlot1A();
    virtual void PrepareSound(MagicSystem::SoundID sound, MagicItem* spell);
    static Owner1599430* Function5cd1b0(std::uint32_t formID);
    void Function1599430();
    virtual void AdjustActiveEffect(ActiveEffect* effect, float power, bool option);
    void Function5d06a0();
    bool Function5d07a0();
    void Function5d07f0();

protected:
    void Function5cda50(MagicSystem::SoundID sound);
    bool Function5ca880(TESObjectREFR* target, bool option);
    void Function5cd380();

    CastingSounds sounds;
    BSPointerHandle<Actor> desiredTarget;
    std::uint32_t padding24;
    MagicItem* currentSpell;
    State state;
    float castingTimer;
    std::uint8_t padding38[8];
    float nextTargetUpdate;
    float projectileTimer;
};
static_assert(sizeof(Owner1599430) == 0x48, "magic caster prefix size");
