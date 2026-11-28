// Source exposure: binary-analysis (pinned image listing).
// Code origin: original; written from the pinned image listing.
// SPDX-License-Identifier: CC0-1.0
// PointerArray1e2110, Unit1e2110, g_entries1e2110, FindIndex1e2110, data, capacity, unk0C, count: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct PointerArray1e2110
{
    void** data;             // 00
    std::uint32_t capacity;  // 08
    std::uint32_t unk0C;     // 0C
    std::uint32_t count;     // 10
};
static_assert(offsetof(PointerArray1e2110, count) == 0x10, "PointerArray1e2110::count offset");

extern PointerArray1e2110 g_entries1e2110;

struct Unit1e2110
{
    static std::uint8_t FindIndex1e2110(const void* a_target);  // compared: 0x1e2110
};
