// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; pinned-image observations and labelled naming sources
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// 0x2b96b0 TESObjectCELL::GetGroupSubBlockKey
// Adapted bodies: none
#include "TESObjectCELL_2b96b0.h"

std::uint32_t TESObjectCELL::GetGroupSubBlockKey()
{
    if (!(flags & 1)) {
        std::int32_t x = GetExteriorX();
        std::int32_t y = GetExteriorY();
        // The block x index is a signed 16-bit coordinate; the y index is unsigned.
        return (static_cast<std::int16_t>(x >> 3) << 16) |
            static_cast<std::uint16_t>(y >> 3);
    }
    return ((formID & 0x00ffffff) % 100) / 10;
}
