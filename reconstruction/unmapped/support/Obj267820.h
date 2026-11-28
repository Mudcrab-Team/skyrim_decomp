// Source exposure: binary-analysis
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Obj267820: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class Obj267820
{
public:
    Obj267820();

    std::uint8_t unk00;     // 0x00
    void* unk08;            // 0x08
    std::uint8_t unk10;     // 0x10
    std::uint32_t unk14;    // 0x14
    std::uint32_t unk18;    // 0x18
    void* unk20;            // 0x20
    void* unk28;            // 0x28
    void* unk30;            // 0x30
    std::int32_t unk38;     // 0x38
    void* unk40;            // 0x40
};

static_assert(offsetof(Obj267820, unk08) == 0x08, "unk08 offset");
static_assert(offsetof(Obj267820, unk10) == 0x10, "unk10 offset");
static_assert(offsetof(Obj267820, unk14) == 0x14, "unk14 offset");
static_assert(offsetof(Obj267820, unk20) == 0x20, "unk20 offset");
static_assert(offsetof(Obj267820, unk38) == 0x38, "unk38 offset");
static_assert(offsetof(Obj267820, unk40) == 0x40, "unk40 offset");
