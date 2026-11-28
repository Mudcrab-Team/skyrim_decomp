// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// TESRegionObject257e00, TESRegionObject257e00::SetParentRadius: CRASHLOGGER_PDB(59818@2026.10.24)
// UpdateChildren, parentRadius, generateNearRadius: GUESS(low)
#pragma once

#include <cstdint>

class TESRegionObject257e00
{
public:
    void UpdateChildren();
    bool SetParentRadius(std::uint16_t value);

    std::uint8_t unk00[0x18];          // 00
    std::uint16_t parentRadius;        // 18
    std::uint16_t generateNearRadius;  // 1A
};
