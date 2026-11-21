// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original implementation using the observed cleanup and partial layouts.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// TESRegionDataManager: EXE_RTTI
#pragma once

#include <cstdint>

class TESRegionDataManager
{
public:
    TESRegionDataManager();
    virtual ~TESRegionDataManager();

private:
    std::uint8_t padding08[0x8];
};
static_assert(sizeof(TESRegionDataManager) == 0x10, "observed allocation size");
