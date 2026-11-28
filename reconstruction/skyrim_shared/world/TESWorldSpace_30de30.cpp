// Source exposure: mixed (pinned image, cited public declarations and the FNV sibling).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Code origin: original reconstruction from the pinned game build, shaped after the cited sibling.
// Adapted bodies: GetWorldTerrainManager, GetParentWorld and GetParentUseFlag follow momusdigital/fnv_decomp@2b07cb3e and momusdigital/f3_decomp@f5bac1b5 src/fallout_shared/tesworldspace.cpp (CC0-1.0); GetDefaultLandHeight follows the same shape.
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesworldspace.cpp:69
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/fallout_shared/tesworldspace.cpp:80
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/fallout_shared/tesworldspace.cpp:20
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/fallout_shared/tesworldspace.cpp:28
// 0x30db20 TESWorldSpace::GetWorldTerrainManager
// 0x30de30 TESWorldSpace::GetDefaultLandHeight
#include "TESWorldSpace_30de30.h"

// The terrain manager of the parent world when LOD data is inherited, else this world's own.
// The PDB records a void return; the compared code returns the pointer.
BGSTerrainManager* TESWorldSpace::GetWorldTerrainManager()
{
    if (GetParentWorld(PU_LOD)) {
        return GetParentWorld(PU_LOD)->GetWorldTerrainManager();
    }
    return terrainManager;
}

// The parent world's default land height when land data is inherited, else this world's own.
// The PDB records a void return; the compared code returns the float.
float TESWorldSpace::GetDefaultLandHeight()
{
    if (GetParentWorld(PU_LAND)) {
        return GetParentWorld(PU_LAND)->GetDefaultLandHeight();
    }
    return defaultLandHeight;
}
