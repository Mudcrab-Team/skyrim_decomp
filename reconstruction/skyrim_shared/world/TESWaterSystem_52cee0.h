// Source exposure: binary-analysis (pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// TESWaterSystem, WaterItem, items, count, flags, Function52cee0: GUESS(low)
// TESWaterSystem::Function52cee0: CRASHLOGGER_PDB(59818@2026.10.24); size only
#pragma once

#include <cstdint>
#include <cstddef>

struct WaterItem
{
    std::uint8_t pad00[0x10];
    std::uint16_t flags;  // 0x10
};

class TESWaterSystem
{
public:
    WaterItem* Function52cee0();  // compared: 0x52cee0

    std::uint8_t pad00[0x38];
    WaterItem** items;  // 0x38
    std::uint8_t pad40[0x8];
    std::uint32_t count;  // 0x48
};
