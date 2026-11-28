// Source exposure: binary-analysis (the pinned image listing).
// Code origin: original reconstruction written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// Obj1caf60, HasActiveTarget, g_flag1caf60: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

extern std::uint8_t g_flag1caf60;

struct Obj1caf60
{
    bool HasActiveTarget() const;  // compared: 0x1caf60

    std::uint8_t unk00[0x18];  // 00
    void* ptr18;               // 18
    std::uint8_t unk20[0x09];  // 20
    std::uint8_t flag29;       // 29
    std::uint8_t unk2A[0x0E];  // 2A
    void* ptr38;               // 38
};
