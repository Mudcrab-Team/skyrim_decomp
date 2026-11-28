// Source exposure: binary-analysis
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Obj283190, Obj283190::Function283190: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class Obj283190
{
public:
    void Function283190(bool a_enable);

    std::uint8_t unk00[0xB0];  // 0x00
    std::uint8_t flagsB0;      // 0xB0
};

static_assert(offsetof(Obj283190, flagsB0) == 0xB0, "flagsB0 offset");
