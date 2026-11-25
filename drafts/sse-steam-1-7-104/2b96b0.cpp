// Near miss: 87.34% | inline-set
// Exposure detail: (community headers; the pinned image listing).
// Source exposure: mixed
// Code origin: original; pinned-image observations and labelled naming sources
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0x2b96b0 TESObjectCELL::GetGroupSubBlockKey

#include "include/2b96b0/TESObjectCELL_2b96b0.h"

std::uint32_t TESObjectCELL::GetGroupSubBlockKey()
{
    if (!(flags & 1)) {
        ExteriorData* data = exteriorData;
        std::int32_t x;
        std::int32_t y;
        if (data) {
            x = data->x;
            y = data->y;
        } else {
            x = 0;
            y = 0;
        }
        return (static_cast<std::uint32_t>(x >> 3) << 16) |
            static_cast<std::uint16_t>(y >> 3);
    }
    return ((formID & 0x00ffffff) % 100) / 10;
}
