// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Elem13adb0: GUESS(low)
#pragma once

#include <cstdint>
#include <vector>

struct Elem13adb0
{
    virtual ~Elem13adb0() {}
    std::uint8_t unk08[0xE0];
};

static_assert(sizeof(Elem13adb0) == 0xE8, "Elem13adb0 size mismatch");

