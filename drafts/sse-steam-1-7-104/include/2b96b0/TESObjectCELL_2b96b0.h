// Exposure detail: (pinned-image observations and community symbol declarations).
// Source exposure: mixed
// Code origin: original; partial declarations from labelled naming sources
// SPDX-License-Identifier: CC0-1.0
// TESObjectCELL, TESObjectCELL::GetGroupSubBlockKey: CRASHLOGGER_PDB(59818@2026.10.24)
// TESObjectCELL::GetGroupSubBlockKey: SYMBOLS(fo4-pdb)
// ExteriorData, x, y, flags, formID, exteriorData: STANDIN GUESS(low); descriptive names for observed fields

#pragma once

#include <cstdint>
#include <cstddef>

class TESObjectCELL
{
public:
    struct ExteriorData { std::int32_t x; std::int32_t y; };
    std::uint32_t GetGroupSubBlockKey();
    std::uint8_t unknown00[0x14];
    std::uint32_t formID;
    std::uint8_t unknown18[0x28];
    std::uint16_t flags;
    std::uint8_t unknown42[0x26];
    ExteriorData* exteriorData;
};
static_assert(offsetof(TESObjectCELL, flags) == 0x40, "Observed flags offset");
static_assert(offsetof(TESObjectCELL, exteriorData) == 0x68, "Observed exterior data offset");
