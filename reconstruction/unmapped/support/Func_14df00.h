// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// FormBase14df00: GUESS(low)
// FormDerived14df00: GUESS(low)
// EffectTableEntry14df00: GUESS(low)
// Effect14df00: GUESS(low)
// Func_14df00: GUESS(low)
#pragma once

#include <cstdint>

struct FormBase14df00
{
    virtual ~FormBase14df00() {}

    std::uint8_t unk08[0x12];
    std::uint8_t formType;
    std::uint8_t unk1B[0x182];
    std::uint8_t byte19D;
};

struct FormDerived14df00 : FormBase14df00
{
    ~FormDerived14df00() override {}
};

struct EffectTableEntry14df00
{
    std::uint32_t kind;
    std::uint8_t unk04[0x14];
};

static_assert(sizeof(EffectTableEntry14df00) == 0x18, "EffectTableEntry14df00 size mismatch");

extern EffectTableEntry14df00 g_effectTable14df00[];

struct Effect14df00
{
    std::uint8_t unk00[0x68];
    std::uint32_t flags68;
    std::uint8_t unk6C[0x54];
    std::int32_t archetype;
    std::uint8_t unkC4[0x18];
    std::int32_t delivery;
};

extern bool CheckActor14df00(void* actor);

struct Func_14df00
{
    static bool CanApply(FormBase14df00* form, void* actor, Effect14df00* effect);
};
