// Source exposure: mixed (pinned image listing; CrashLogger PDB names).
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x257c30 TESRegionObject257c30::SetDensity
// Adapted bodies: none
#include "TESRegionObject257c30.h"

// Update the region object density within [0.0, 100.0] and refresh children.
bool TESRegionObject257c30::SetDensity(float value)
{
    if (value < 0.0f || value > 100.0f || value == density)
    {
        return false;
    }
    density = value;
    UpdateChildren();
    return true;
}
