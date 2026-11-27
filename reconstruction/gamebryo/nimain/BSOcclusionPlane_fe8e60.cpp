// Source exposure: mixed (local pinned-image analysis and community-generated names and layouts).
// Code origin: original reconstruction from local observations.
// Adapted bodies: none.
// SPDX-License-Identifier: CC0-1.0
// BSOcclusionPlane, IntersectsPlanes, UpdateCorners, QuadIntersectsPlanes, NiFrustumPlanes, NiPoint3, translation, rotation, size, corners, edgeFlags: CRASHLOGGER_PDB(59818@2026.10.24)
// Recipe: reconstruction/recipes/o2-fpfast-root-includes.json
// 0xfe8e60 BSOcclusionPlane::IntersectsPlanes
#include "BSOcclusionPlane_fe8e60.h"

#include <cmath>
#include <cstring>

bool BSOcclusionPlane::IntersectsPlanes(const NiFrustumPlanes* frustum, bool testOrigin, const NiPoint3& origin)
{
    UpdateCorners();
    NiPoint3 quad[4];
    memcpy_s(quad, sizeof(quad), corners, sizeof(quad));

    const bool intersects = frustum->QuadIntersectsPlanes(quad, edgeFlags);
    if (!intersects && testOrigin) {
        const NiPoint3 vertical = rotation.GetRow(2);
        const NiPoint3 delta = origin - translation;
        const NiPoint3 horizontal = rotation.GetRow(1);
        if (std::fabs(delta.Dot(horizontal)) > size.x) {
            return false;
        }
        if (std::fabs(delta.Dot(vertical)) > size.y) {
            return false;
        }
        return true;
    }
    return intersects;
}
