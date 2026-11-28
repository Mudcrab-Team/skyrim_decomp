// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x257e30 TESRegionObject257e30::SetGenerateNearRadius
// Adapted bodies: none
#include "TESRegionObject257e30.h"

// Update the near-generation radius and refresh children when changed.
bool TESRegionObject257e30::SetGenerateNearRadius(std::uint16_t value)
{
    if (value != generateNearRadius)
    {
        generateNearRadius = value;
        UpdateChildren();
        return true;
    }
    return false;
}
