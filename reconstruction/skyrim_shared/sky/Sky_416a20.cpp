// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: original reconstruction from the pinned image listing; community names as labelled in the header
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x416a20 Sky::Function416a20
#include "Sky_416a20.h"

void Sky::Function416a20(WeatherColorPairs& a_out, const TESWeather* a_current, const TESWeather* a_last,
    std::int32_t a_type, const std::int32_t& a_fromTime, const std::int32_t& a_toTime)
{
    if (!a_current)
    {
        return;
    }
    a_out.from = a_current->colorData[a_type][a_fromTime];
    a_out.to = a_current->colorData[a_type][a_toTime];
    if (a_last)
    {
        a_out.lastFrom = a_last->colorData[a_type][a_fromTime];
        a_out.lastTo = a_last->colorData[a_type][a_toTime];
    }
    else
    {
        a_out.lastFrom = Color{};
        a_out.lastTo = Color{};
    }
}
