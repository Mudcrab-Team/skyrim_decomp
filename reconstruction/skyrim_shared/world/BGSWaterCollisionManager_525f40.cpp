// Source exposure: mixed (CrashLogger layouts; pinned-image observations).
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// BGSWaterCollisionManager, bhkPlaceableWater: CRASHLOGGER_PDB(59818@2026.10.24)
// GetTransformHeight: GUESS(low)
// 0x525f40 BGSWaterCollisionManager::bhkPlaceableWater::GetTransformHeight
#include "BGSWaterCollisionManager_525f40.h"

// Queries the water physics body transform and returns its Z translation component.
// The CrashLogger name is GetTransform; the name used here is a guess from what the body does.
// Parameter count or return type differs from the CrashLogger prototype: the signature here is
// inferred from the body and is a guess.
float BGSWaterCollisionManager::bhkPlaceableWater::GetTransformHeight()
{
    WaterTransform525f40 transform;
    body->QueryTransform(&transform);
    return transform.values[14];
}
