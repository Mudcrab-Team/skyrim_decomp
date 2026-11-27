// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// BSMultiBoundSphere: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSMultiBoundSphere::WithinFrustum: CRASHLOGGER_PDB(59818@2026.10.24)
// 0xfe5770 BSMultiBoundSphere::WithinFrustum
#include "BSMultiBoundSphere_fe5770.h"

// Test whether the bounding sphere intersects all active frustum planes.
bool BSMultiBoundSphere::WithinFrustum(const NiFrustumPlanes& a_planes) const
{
    const float cx = center.x;
    const float cy = center.y;
    const float cz = center.z;
    const float r = radius;
    for (std::uint32_t i = 0; i < 6; ++i) {
        if ((a_planes.activePlanes & (1u << i)) != 0) {
            const NiPlane& plane = a_planes.planes[i];
            const float dist = cx * plane.normal.x + cy * plane.normal.y + cz * plane.normal.z - plane.constant;
            if (dist <= -r) {
                return false;
            }
        }
    }
    return true;
}
