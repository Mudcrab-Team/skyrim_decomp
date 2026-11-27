// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: original reconstruction from the pinned image listing; community names as labelled in the header
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x40d370 Sky::Function40d370
#include "Sky_40d370.h"

Calendar* g_calendar;
std::uint32_t g_moonPhase;

bool Sky::Function40d370()
{
    TESClimate* climate = currentClimate;
    if (climate && (climate->moonPhaseLength & 0x3F))
    {
        std::uint32_t length = climate->moonPhaseLength & 0x3F;
        std::uint32_t day = g_calendar->Function646000();
        std::uint32_t phase = (day % (length * 8)) / length;
        if (phase != g_moonPhase)
        {
            g_moonPhase = phase;
            return true;
        }
    }
    return false;
}
