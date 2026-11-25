// Source exposure: mixed (community declarations; pinned-image observations; permitted sibling game code).
// SPDX-License-Identifier: CC0-1.0
// Code origin: original declarations from observed offsets
// TESObjectCELL, TESObjectCELL::GetGroupBlockKey: CRASHLOGGER_PDB(59818@2026.10.24)
// CellCoordinates, formID, cellFlags, cellData: STANDIN OBSERVED
#pragma once
#include <cstdint>

struct CellCoordinates
{
    std::int32_t x;
    std::int32_t y;
};

class TESObjectCELL
{
public:
    std::uint32_t GetGroupBlockKey();
    std::uint8_t prefix00[0x14];
    std::uint32_t formID;
    std::uint8_t prefix18[0x28];
    std::uint16_t cellFlags;
    std::uint8_t prefix42[0x26];
    CellCoordinates* cellData;
};
