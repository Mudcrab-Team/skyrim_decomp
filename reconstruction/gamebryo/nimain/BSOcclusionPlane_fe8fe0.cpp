// Source exposure: mixed (local pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// BSOcclusionPlane, InsidePlanes, UpdateCorners, QuadIntersectsPlanes, NiPoint3, corners, edgeFlags: CRASHLOGGER_PDB(59818@2026.10.24)
// g_frustumPlanes: GUESS(low)
// Recipe: reconstruction/recipes/o2-fpfast-root-includes.json
// 0xfe8fe0 BSOcclusionPlane::InsidePlanes
#include "BSOcclusionPlane_fe8fe0.h"

bool BSOcclusionPlane::InsidePlanes(const NiPoint3& origin)
{
    NiPoint3 relativeCorners[4];
    UpdateCorners();
    for (int i = 0; i < 4; ++i) {
        relativeCorners[i] = corners[i] - origin;
    }
    return g_frustumPlanes.QuadIntersectsPlanes(relativeCorners, edgeFlags);
}
