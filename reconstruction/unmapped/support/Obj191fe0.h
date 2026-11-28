// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// Obj191fe0, IsNotEqual: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct Obj191fe0
{
    bool IsNotEqual(const Obj191fe0* a_other) const;  // compared: 0x191fe0

    std::uint32_t handle;  // 00
    float unk04;           // 04
    float unk08;           // 08
    float unk0C;           // 0C
    float unk10;           // 10
    float unk14;           // 14
    float unk18;           // 18
    std::uint8_t unk1C;    // 1C
};
