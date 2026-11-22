// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original; the listing and community declarations only
// NiPSysEmitterCtlr: EXE_RTTI
// GetInterpolator: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// interpolator0, interpolator1: GUESS(low); members at the offsets the compared body reads
#pragma once

#include <cstdint>

class NiPSysEmitterCtlr
{
public:
    virtual std::uint32_t GetInterpolatorCount() const;
    void* GetInterpolator(std::uint16_t a_index) const;

    std::uint8_t pad08[0x40];  // 08
    void*        interpolator0;  // 48
    std::uint8_t pad50[0x10];  // 50
    void*        interpolator1;  // 60
};
