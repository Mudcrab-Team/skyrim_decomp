// Source exposure: binary-analysis
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Obj2661b0, Obj2661b0::Function2661b0: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class Obj2661b0
{
public:
    std::uint32_t Function2661b0() const;

    std::uint8_t unk00[0x80];  // 0x00
    std::uint32_t flags80;     // 0x80
};

static_assert(offsetof(Obj2661b0, flags80) == 0x80, "flags80 offset");
