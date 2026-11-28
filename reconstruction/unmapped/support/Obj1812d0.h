// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// StartingTransform1812d0, Obj1812d0, IsNotEqual: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct StartingTransform1812d0
{
    float pos[3];  // 00
    float rot[3];  // 0C
};

struct Obj1812d0
{
    bool IsNotEqual(const Obj1812d0* a_rhs) const;  // compared: 0x1812d0

    std::uint8_t unk00[0x10];             // 00
    StartingTransform1812d0 transform10;  // 10
    std::uint64_t location28;             // 28
};
