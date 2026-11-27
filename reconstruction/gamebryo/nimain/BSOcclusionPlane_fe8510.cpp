// Source exposure: mixed (local pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// BSOcclusionPlane, BSOcclusionShape, NiPoint3, NiMatrix3, translation, rotation, visibilityState, size, twoSided, unkF8: CRASHLOGGER_PDB(59818@2026.10.24)
// kZeroPoint, kIdentityMatrix: GUESS(low)
// 0xfe8510 BSOcclusionPlane::BSOcclusionPlane
#include "BSOcclusionPlane_fe8510.h"

BSOcclusionPlane::BSOcclusionPlane()
{
    translation = NiPoint3::kZeroPoint;
    size.x = 50.0f;
    size.y = 50.0f;
    rotation = NiMatrix3::kIdentityMatrix;
    visibilityState = 0;
    twoSided = true;
    unkF8[0] = 0;
    unkF8[1] = 0;
    unkF8[2] = 0;
    unkF8[3] = 0;
}
