// Source exposure: binary-analysis
// Code origin: original; written from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Obj2a7630, Obj2a7630::Function2a7630, g_currentTime2a7630: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

extern float g_currentTime2a7630;

class Obj2a7630
{
public:
    bool Function2a7630(float a_startTime) const;

    std::uint8_t unk00[0x20];  // 0x00
    bool active;               // 0x20
    std::uint8_t unk21[0x03];  // 0x21
    float duration;            // 0x24
};

static_assert(offsetof(Obj2a7630, active) == 0x20, "active offset");
static_assert(offsetof(Obj2a7630, duration) == 0x24, "duration offset");
