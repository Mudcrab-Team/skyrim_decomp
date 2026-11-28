// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// TESRegionObject257e30, TESRegionObject257e30::SetGenerateNearRadius: CRASHLOGGER_PDB(59818@2026.10.24)
// UpdateChildren, generateNearRadius: GUESS(low)
#pragma once

#include <cstdint>

class TESRegionObject257e30
{
public:
    void UpdateChildren();
    bool SetGenerateNearRadius(std::uint16_t value);

    std::uint8_t unk00[0x1A];          // 00
    std::uint16_t generateNearRadius;  // 1A
};
