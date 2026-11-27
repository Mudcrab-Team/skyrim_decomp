// Source exposure: mixed (binary-analysis of the pinned image, community-headers).
// Code origin: original reconstruction from the pinned image listing; community names and offsets as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESWeather, TESWeather::colorData, Color: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) OBSERVED; NG's colour table of 17 types by 4 times at 698
// Sky: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT); declared only
// Sky::Function416a20, WeatherColorPairs, WeatherColorPairs::from, WeatherColorPairs::to, WeatherColorPairs::lastFrom, WeatherColorPairs::lastTo: GUESS(low); the name comes from the inventory address, the result block is made up from the stores
#pragma once

#include <cstdint>
#include <cstddef>

struct Color
{
    std::uint8_t red;
    std::uint8_t green;
    std::uint8_t blue;
    std::uint8_t alpha;
};

class TESWeather
{
public:
    std::uint8_t unk000[0x698];
    Color colorData[17][4];  // 698
};

struct WeatherColorPairs
{
    Color from;      // 00
    Color to;        // 04
    Color lastFrom;  // 08
    Color lastTo;    // 0C
};

class Sky
{
public:
    void Function416a20(WeatherColorPairs& a_out, const TESWeather* a_current, const TESWeather* a_last,
        std::int32_t a_type, const std::int32_t& a_fromTime, const std::int32_t& a_toTime);  // compared: 0x416a20
};
