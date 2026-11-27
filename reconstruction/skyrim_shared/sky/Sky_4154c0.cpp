// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: original reconstruction from the pinned image listing; community names as labelled in the header
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x4154c0 Sky::ResetWeather
#include "Sky_4154c0.h"

void Sky::ResetWeather()
{
    flags &= ~0x8u;
    currentWeather = lastWeather = defaultWeather = overrideWeather = nullptr;
    region = nullptr;
    lastMoonPhaseUpdate = 0;
    if (clouds)
    {
        clouds->Function40cce0();
    }
    if (precip)
    {
        precip->Function40f3c0();
    }
    Function415660();
    Function418580();
    Function418e10(0);
    flags &= ~0x400000u;
}
