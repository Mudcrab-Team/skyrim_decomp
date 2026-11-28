// Source exposure: mixed (pinned image listing; CrashLogger PDB names; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: TESWeatherList30a500::FindMinChance, treated as adapted: shaped like the chance reading of TESWeatherList::GetRandomWeather in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesweatherlist.cpp:117
// SPDX-License-Identifier: CC0-1.0
// 0x30a500 TESWeatherList30a500::FindMinChance
#include "TESWeatherList30a500.h"

// Guess: find the matching-flag weather entry with the smallest chance value.
Weather30a500* TESWeatherList30a500::FindMinChance(std::uint32_t a_flagBit) const
{
    Weather30a500* best = nullptr;
    std::uint32_t bestChance = 0xFFFFFFFFu;
    for (const TESWeatherList30a500* node = this; node && node->m_item; node = node->m_next)
    {
        const Entry30a500* entry = node->m_item;
        Weather30a500* weather = entry->m_weather;
        const std::uint32_t chance = entry->m_global
            ? static_cast<std::uint32_t>(entry->m_global->m_value)
            : entry->m_chance;
        if (weather && (weather->m_flags & (1u << a_flagBit)) != 0 && chance < bestChance)
        {
            best = weather;
            bestChance = chance;
        }
    }
    return best;
}
