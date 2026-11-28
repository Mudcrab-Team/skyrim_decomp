// Source exposure: mixed (pinned image listing; CrashLogger PDB names; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: TESWeatherList30a500::FindMinChance, treated as adapted: shaped like the chance reading of TESWeatherList::GetRandomWeather in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesweatherlist.cpp:117
// SPDX-License-Identifier: CC0-1.0
// TESWeatherList30a500, Global30a500, Weather30a500, Entry30a500, TESWeatherList30a500::FindMinChance: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct Global30a500
{
    std::uint64_t unk00[6];  // 0x00
    std::uint32_t unk30;     // 0x30
    float m_value;           // 0x34
};
static_assert(offsetof(Global30a500, m_value) == 0x34, "m_value offset");

struct Weather30a500
{
    std::uint64_t unk00[205];  // 0x000
    std::uint8_t unk668[7];    // 0x668
    std::uint8_t m_flags;      // 0x66F
};
static_assert(offsetof(Weather30a500, m_flags) == 0x66F, "m_flags offset");

struct Entry30a500
{
    Weather30a500* m_weather;  // 0x00
    std::uint32_t m_chance;    // 0x08
    Global30a500* m_global;    // 0x10
};

class TESWeatherList30a500
{
public:
    Weather30a500* FindMinChance(std::uint32_t a_flagBit) const;

    Entry30a500* m_item;  // 0x00
    TESWeatherList30a500* m_next;    // 0x08
};
