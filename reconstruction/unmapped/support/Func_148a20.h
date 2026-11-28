// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// TableRecord148a20: GUESS(low)
// Target148a20: GUESS(low)
// EffectData148a20: GUESS(low)
// gEffectTable148a20: GUESS(low)
// Func_148a20: GUESS(low)
#pragma once

#include <cstdint>

struct TableRecord148a20
{
    std::uint32_t kind;
    std::uint32_t unk04;
    std::uint64_t unk08;
    std::uint64_t unk10;
};

static_assert(sizeof(TableRecord148a20) == 0x18, "TableRecord148a20 size");

extern TableRecord148a20 gEffectTable148a20[];

struct Target148a20
{
    std::uint8_t unk00[0x1A];
    std::uint8_t formType;
};

struct EffectData148a20
{
    std::uint8_t unk00[0x70];
    const Target148a20* target;
    std::uint8_t unk78[0x48];
    std::int32_t tableIndex;
};

struct Func_148a20
{
    const Target148a20* GetMatchingTarget() const;

    std::uint64_t unk00[2];
    const EffectData148a20* effect;
};
