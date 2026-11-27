// Source exposure: mixed (local pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// BSOcclusionPlane, GetCornersRelativeTo, UpdateCorners, NiPoint3, corners: CRASHLOGGER_PDB(59818@2026.10.24)
// Recipe: reconstruction/recipes/o2-fpfast-root-includes.json
// 0xfe8950 BSOcclusionPlane::GetCornersRelativeTo
#include "BSOcclusionPlane_fe8950.h"

void BSOcclusionPlane::GetCornersRelativeTo(NiPoint3* destination, const NiPoint3& origin)
{
    UpdateCorners();
    for (int i = 0; i < 4; ++i) {
        destination[i] = corners[i] - origin;
    }
}
