// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// 0x253ce0 compared function
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESRegionDataWeather: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// TESRegionDataWeather::IsLoaded: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// field10, field18: GUESS(low)
#pragma once

#include <cstdint>
#include "TESRegionData.h"

// WeatherResult, Unk_04, Unk_05, WeatherResult::Apply: GUESS(low) STANDIN
class WeatherResult
{
public:
    virtual ~WeatherResult();
    virtual void Unk_01();
    virtual void Unk_02();
    virtual void Unk_03();
    virtual void Unk_04();
    virtual void Unk_05();
    virtual void Apply(void* a_arg, int a_count);  // vtable slot 06
};

class TESRegionDataWeather : public TESRegionData
{
public:
    virtual bool IsLoaded() const;              // compared: 0x253ea0
    virtual WeatherResult* Unk_04(void* a_arg);  // vtable slot 04
    virtual WeatherResult* Unk_05(void* a_arg);  // compared: 0x253ce0; vtable slot 05

    void* field10;  // 10
    void* field18;  // 18
};
static_assert(sizeof(TESRegionDataWeather) == 0x20, "TESRegionDataWeather size");
