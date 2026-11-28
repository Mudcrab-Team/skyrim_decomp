// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Function151420: GUESS(low)
// EffectTarget151420: GUESS(low)
// EffectEntry151420: GUESS(low)
// EffectOwner151420: GUESS(low)
#pragma once

#include <cstdint>

struct EffectTarget151420
{
    std::uint8_t unk00[0x6B];
    std::uint8_t flags6B;
};

struct EffectEntry151420
{
    std::uint64_t unk00[2];
    EffectTarget151420* target;
};

struct EffectOwner151420
{
    std::uint8_t unk00[0x58];
    EffectEntry151420** entries;
    std::uint64_t unk60;
    std::uint32_t count;
};

bool Function151420(const EffectOwner151420* owner, const EffectTarget151420* target);
