// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x257e60 TESRegionObject257e60::SetMinimumZ
// Adapted bodies: none
#include "TESRegionObject257e60.h"

// Update the minimum Z bound when not exceeding maximum Z and refresh children.
bool TESRegionObject257e60::SetMinimumZ(float value)
{
    if (value == minZ || value > maxZ)
    {
        return false;
    }
    minZ = value;
    UpdateChildren();
    return true;
}
