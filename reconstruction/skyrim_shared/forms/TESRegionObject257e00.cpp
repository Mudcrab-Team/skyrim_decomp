// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x257e00 TESRegionObject257e00::SetParentRadius
// Adapted bodies: none
#include "TESRegionObject257e00.h"

// Update the parent radius when not below the near-generation radius and refresh children.
bool TESRegionObject257e00::SetParentRadius(std::uint16_t value)
{
    if (value < generateNearRadius || value == parentRadius)
    {
        return false;
    }
    parentRadius = value;
    UpdateChildren();
    return true;
}
