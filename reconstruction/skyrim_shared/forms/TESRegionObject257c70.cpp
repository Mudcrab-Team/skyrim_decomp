// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x257c70 TESRegionObject257c70::SetCluster
// Adapted bodies: none
#include "TESRegionObject257c70.h"

// Update the cluster count when within [0, 100] and refresh children.
bool TESRegionObject257c70::SetCluster(std::uint8_t value)
{
    if (value > 100 || value == cluster)
    {
        return false;
    }
    cluster = value;
    UpdateChildren();
    return true;
}
