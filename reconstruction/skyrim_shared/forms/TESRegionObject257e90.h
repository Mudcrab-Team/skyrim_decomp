// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// TESRegionObject257e90, TESRegionObject257e90::SetMaximumZ: CRASHLOGGER_PDB(59818@2026.10.24)
// UpdateChildren, minZ, maxZ: GUESS(low)
#pragma once

#include <cstdint>

class TESRegionObject257e90
{
public:
    void UpdateChildren();
    bool SetMaximumZ(float value);

    std::uint8_t unk00[0x1C];  // 00
    float minZ;                // 1C
    float maxZ;                // 20
};
