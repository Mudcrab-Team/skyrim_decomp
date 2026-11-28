// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x257e90 TESRegionObject257e90::SetMaximumZ
// Adapted bodies: none
#include "TESRegionObject257e90.h"

// Update the maximum Z bound when not below minimum Z and refresh children.
bool TESRegionObject257e90::SetMaximumZ(float value)
{
    if (value == maxZ || value < minZ)
    {
        return false;
    }
    maxZ = value;
    UpdateChildren();
    return true;
}
