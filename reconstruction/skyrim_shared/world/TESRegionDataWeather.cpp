// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: bodies written from the pinned image listing; names and declarations from community headers
// 0x253ce0 TESRegionDataWeather::Unk_05
// Adapted bodies: none
// Source exposure: mixed (names and declarations from community headers; the listing of the pinned
// image).
// Adapted bodies: none
#include "TESRegionDataWeather.h"

bool TESRegionDataWeather::IsLoaded() const
{
    if (field18 != nullptr) {
        return true;
    }
    if (field10 != nullptr) {
        return true;
    }
    return false;
}

WeatherResult* TESRegionDataWeather::Unk_05(void* a_arg)
{
    WeatherResult* result = Unk_04(a_arg);
    result->Apply(a_arg, 2);
    return result;
}
