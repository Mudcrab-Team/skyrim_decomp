// Source exposure: mixed (pinned image listing; CrashLogger PDB names; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: TESWeatherList30a580::UsesWeather, treated as adapted: shaped like the chance reading of TESWeatherList::GetRandomWeather in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesweatherlist.cpp:117
// SPDX-License-Identifier: CC0-1.0
// 0x30a580 TESWeatherList30a580::UsesWeather
#include "TESWeatherList30a580.h"

namespace
{
std::uint32_t GetChance(const Entry30a580* a_entry)
{
    if (a_entry->m_global)
    {
        return static_cast<std::uint32_t>(a_entry->m_global->m_value);
    }
    return a_entry->m_chance;
}
}

// Guess: check whether any linked weather entry matches the weather with a non-zero chance.
bool TESWeatherList30a580::UsesWeather(void* a_weather) const
{
    bool found = false;
    for (const TESWeatherList30a580* node = this; !found && node && node->m_item; node = node->m_next)
    {
        const Entry30a580* entry = node->m_item;
        found = (entry->m_weather == a_weather) && (GetChance(entry) != 0);
    }
    return found;
}
