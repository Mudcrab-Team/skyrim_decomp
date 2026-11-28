// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// TESFurniture, TESFurniture::sub_1402198E0: CRASHLOGGER_PDB(59818@2026.10.24)
// enabledMarkers: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

class TESFurniture
{
public:
    bool sub_1402198E0(std::uint32_t a_index) const;  // compared: 0x26e720

    std::uint8_t  unk00[0xE4];     // 00
    std::uint32_t enabledMarkers;  // E4
};
static_assert(offsetof(TESFurniture, enabledMarkers) == 0xE4, "enabledMarkers offset");
