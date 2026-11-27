// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: original reconstruction from the pinned image listing; community names and offsets as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sky, Sky::ResetWeather, Sky::currentWeather, Sky::lastWeather, Sky::defaultWeather, Sky::overrideWeather, Sky::region, Sky::clouds, Sky::precip, Sky::lastMoonPhaseUpdate, Sky::flags: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG's layout, ResetWeather is the name in NG and in the CrashLogger map
// TESWeather, TESRegion, Clouds, Precipitation: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); declared only
// Sky::Function415660, Sky::Function418580, Sky::Function418e10, Clouds::Function40cce0, Precipitation::Function40f3c0: GUESS(low); names made up for the callees at those RVAs, bodies not compared here
// unk00, unk70, unk90, unk1E0: GUESS(low); unread ranges
#pragma once

#include <cstdint>
#include <cstddef>

class TESWeather;
class TESRegion;

class Clouds
{
public:
    void Function40cce0();  // callee at 0x40cce0, not compared
};

class Precipitation
{
public:
    void Function40f3c0();  // callee at 0x40f3c0, not compared
};

class Sky
{
public:
    void ResetWeather();  // compared: 0x4154c0
    void Function415660();  // callee at 0x415660, not compared
    void Function418580();  // callee at 0x418580, not compared
    void Function418e10(int a_value);  // callee at 0x418e10, not compared

    std::uint8_t unk00[0x48];
    TESWeather* currentWeather;   // 48
    TESWeather* lastWeather;      // 50
    TESWeather* defaultWeather;   // 58
    TESWeather* overrideWeather;  // 60
    TESRegion* region;            // 68
    std::uint8_t unk70[0x18];
    Clouds* clouds;               // 88
    std::uint8_t unk90[0x10];
    Precipitation* precip;        // A0
    std::uint8_t unkA8[0x1d8 - 0xa8];
    std::uint32_t lastMoonPhaseUpdate;  // 1D8
    std::uint32_t flags;                // 1DC
};
static_assert(offsetof(Sky, flags) == 0x1dc, "layout");
