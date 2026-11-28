// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// TESRegionObject257c30, TESRegionObject257c30::SetDensity: CRASHLOGGER_PDB(59818@2026.10.24)
// UpdateChildren, density: GUESS(low)
#pragma once

#include <cstdint>

class TESRegionObject257c30
{
public:
    void UpdateChildren();
    bool SetDensity(float value);

    std::uint8_t unk00[0x10];  // 00
    float density;             // 10
};
