// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// TESRegionObject257c70, TESRegionObject257c70::SetCluster: CRASHLOGGER_PDB(59818@2026.10.24)
// UpdateChildren, cluster: GUESS(low)
#pragma once

#include <cstdint>

class TESRegionObject257c70
{
public:
    void UpdateChildren();
    bool SetCluster(std::uint8_t value);

    std::uint8_t unk00[0x14];  // 00
    std::uint8_t cluster;      // 14
};
