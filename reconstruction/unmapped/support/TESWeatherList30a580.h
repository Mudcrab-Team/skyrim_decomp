// Source exposure: mixed (pinned image listing; CrashLogger PDB names; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: TESWeatherList30a580::UsesWeather, treated as adapted: shaped like the chance reading of TESWeatherList::GetRandomWeather in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesweatherlist.cpp:117
// SPDX-License-Identifier: CC0-1.0
// TESWeatherList30a580, TESWeatherList30a580::UsesWeather: CRASHLOGGER_PDB(59818@2026.10.24)
// Global30a580, Entry30a580: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct Global30a580
{
    std::uint64_t unk00[6];  // 0x00
    std::uint32_t unk30;     // 0x30
    float m_value;           // 0x34
};
static_assert(offsetof(Global30a580, m_value) == 0x34, "m_value offset");

struct Entry30a580
{
    void* m_weather;         // 0x00
    std::uint32_t m_chance;  // 0x08
    Global30a580* m_global;  // 0x10
};
static_assert(offsetof(Entry30a580, m_chance) == 0x08, "m_chance offset");
static_assert(offsetof(Entry30a580, m_global) == 0x10, "m_global offset");

class TESWeatherList30a580
{
public:
    bool UsesWeather(void* a_weather) const;

    Entry30a580* m_item;  // 0x00
    TESWeatherList30a580* m_next;    // 0x08
};
