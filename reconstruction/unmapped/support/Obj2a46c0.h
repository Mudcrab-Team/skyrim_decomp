// Source exposure: binary-analysis
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Obj2a46c0, Obj2a46c0::Function2a46c0, g_currentTime2a46c0: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

extern float g_currentTime2a46c0;

class Obj2a46c0
{
public:
    bool Function2a46c0() const;

    std::uint8_t unk00[0x20];  // 0x00
    float startTime;           // 0x20
    std::uint32_t unk24;       // 0x24
    float duration;            // 0x28
};

static_assert(offsetof(Obj2a46c0, startTime) == 0x20, "startTime offset");
static_assert(offsetof(Obj2a46c0, duration) == 0x28, "duration offset");
