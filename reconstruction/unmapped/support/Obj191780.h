// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// Handle191780, Obj191780, gInvalidHandle191780: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

extern std::uint32_t gInvalidHandle191780;

struct Handle191780
{
    Handle191780() : value(gInvalidHandle191780) {}
    std::uint32_t value;  // 00
};

struct Obj191780
{
    Obj191780();  // compared: 0x191780

    Handle191780 handle;  // 00
    float unk04;          // 04
    float unk08;          // 08
    float unk0C;          // 0C
    float unk10;          // 10
    float unk14;          // 14
    float unk18;          // 18
    std::uint8_t unk1C;   // 1C
};
