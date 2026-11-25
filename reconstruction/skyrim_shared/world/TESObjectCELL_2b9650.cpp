// Source exposure: mixed (community declarations; pinned-image observations; permitted sibling game code).
// Code origin: adapted sibling group selection, with locally observed coordinate arithmetic
// SPDX-License-Identifier: CC0-1.0
// 0x2b9650 TESObjectCELL::GetGroupBlockKey
// Adapted bodies: TESObjectCELL::GetGroupBlockKey, momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesobjectcell.cpp:5436 (CC0-1.0)
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesobjectcell.cpp:5436
// TESObjectCELL::GetGroupBlockKey: SIBLING(momusdigital/fnv_decomp@2b07cb3e, CC0-1.0)
#include "TESObjectCELL_2b9650.h"

std::uint32_t TESObjectCELL::GetGroupBlockKey()
{
    if (!(cellFlags & 1)) {
        std::int32_t x;
        std::int32_t y;
        if (cellData) {
            x = cellData->x;
            y = cellData->y;
        } else {
            x = 0;
            y = 0;
        }
        return (static_cast<std::int16_t>(x >> 5) << 16) |
               static_cast<std::uint16_t>(y >> 5);
    }
    return (formID & 0xFFFFFF) % 10;
}
