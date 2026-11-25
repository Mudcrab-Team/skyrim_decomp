// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/Shared/Regions/TESRegionDataWeather.cpp:5
// TESRegionDataWeather, TESRegionDataWeather::~TESRegionDataWeather: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) SIBLING(fo4-private@1b765c70, author-permission)
// TESRegionData, TESRegionData::~TESRegionData: STANDIN COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// WeatherList: STANDIN GUESS(low); the weather type list member, whose destructor is an out-of-line call
// TESRegionDataWeather::weatherTypes: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// unk08: GUESS(low)
#pragma once

#include <cstdint>

class TESRegionData
{
public:
    virtual ~TESRegionData();

    std::uint8_t unk08[8];
};

class WeatherList
{
public:
    ~WeatherList();

    void* unk00;
    void* unk08;
};

class TESRegionDataWeather : public TESRegionData
{
public:
    TESRegionDataWeather();
    ~TESRegionDataWeather() override;

    WeatherList weatherTypes;  // 10
};
static_assert(sizeof(TESRegionDataWeather) == 0x20, "TESRegionDataWeather size");
