// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Function1516b0: GUESS(low)
// TableRecord1516b0: GUESS(low)
// EffectData1516b0: GUESS(low)
// EffectEntry1516b0: GUESS(low)
// EffectOwner1516b0: GUESS(low)
// gEffectTable1516b0: GUESS(low)
#pragma once

#include <cstdint>

struct TableRecord1516b0
{
    std::uint32_t kind;
    std::uint32_t unk04;
    std::uint64_t unk08;
    std::uint64_t unk10;
};

static_assert(sizeof(TableRecord1516b0) == 0x18, "TableRecord1516b0 size");

extern TableRecord1516b0 gEffectTable1516b0[];

struct EffectData1516b0
{
    std::uint8_t unk00[0xC0];
    std::int32_t tableIndex;
};

struct EffectEntry1516b0
{
    std::uint64_t unk00[2];
    EffectData1516b0* effect;
};

struct EffectOwner1516b0
{
    std::uint8_t unk00[0x58];
    EffectEntry1516b0** entries;
    std::uint64_t unk60;
    std::uint32_t count;
};

bool Function1516b0(const EffectOwner1516b0* owner);
