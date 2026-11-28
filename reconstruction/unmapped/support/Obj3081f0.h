// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: Obj3081f0::GetColor, treated as adapted: shaped like TESWeather::GetCloudColor in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/sky/sky.cpp:1283
// SPDX-License-Identifier: CC0-1.0
// Obj3081f0, Obj3081f0::GetColor: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

class Obj3081f0
{
public:
    std::uint32_t GetColor(std::int32_t a_row, std::int32_t a_col) const;

    std::uint64_t unk00[76];          // 0x000
    std::uint32_t m_colors[87][4];    // 0x260
    std::int32_t m_rowCount;          // 0x7D0
};
static_assert(offsetof(Obj3081f0, m_colors) == 0x260, "m_colors offset");
static_assert(offsetof(Obj3081f0, m_rowCount) == 0x7D0, "m_rowCount offset");
