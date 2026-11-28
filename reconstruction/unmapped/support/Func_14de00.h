// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// FormBase14de00: GUESS(low)
// FormDerived14de00: GUESS(low)
// EffectTableEntry14de00: GUESS(low)
// Effect14de00: GUESS(low)
// TargetWrapper14de00: GUESS(low)
// Func_14de00: GUESS(low)
#pragma once

#include <cstdint>

struct FormBase14de00
{
    virtual ~FormBase14de00() {}

    std::uint8_t unk08[0x12];
    std::uint8_t formType;
    std::uint8_t unk1B[0x182];
    std::uint8_t byte19D;
};

struct FormDerived14de00 : FormBase14de00
{
    ~FormDerived14de00() override {}
};

struct EffectTableEntry14de00
{
    std::uint32_t kind;
    std::uint8_t unk04[0x14];
};

static_assert(sizeof(EffectTableEntry14de00) == 0x18, "EffectTableEntry14de00 size mismatch");

extern EffectTableEntry14de00 g_effectTable14de00[];

struct Effect14de00
{
    std::uint8_t unk00[0x68];
    std::uint32_t flags68;
    std::uint8_t unk6C[0x54];
    std::int32_t archetype;
    std::uint8_t unkC4[0x18];
    std::int32_t delivery;
};

extern bool CheckActor14de00(void* actor);

struct TargetWrapper14de00
{
    FormBase14de00* form;
    void** actorSlot;
};

struct Func_14de00
{
    static bool CanApplyWrapper(TargetWrapper14de00* wrapper, Effect14de00* effect);
};
