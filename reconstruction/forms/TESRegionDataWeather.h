// Source exposure: mixed (names and declarations from community headers; base classes, sizes and
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// the compared functions from the pinned image).
// TESRegionDataWeather: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT) EXE_RTTI
// TESRegionDataWeather::IsLoaded: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// field10, field18: GUESS(low)
#pragma once

#include <cstdint>
#include "../forms/TESRegionData.h"

class TESRegionDataWeather : public TESRegionData
{
public:
    virtual bool IsLoaded() const;  // compared: 0x253ea0

    void* field10;  // 10
    void* field18;  // 18
};
static_assert(sizeof(TESRegionDataWeather) == 0x20, "TESRegionDataWeather size");
