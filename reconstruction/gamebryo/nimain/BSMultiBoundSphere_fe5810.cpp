// Source exposure: binary-analysis.
// Code origin: original reconstruction from pinned-image observations.
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/o2-fpfast.json
// BSMultiBoundSphere: STANDIN CRASHLOGGER_PDB(59818@2026.10.24)
// BSMultiBoundSphere::Functionfe5810: GUESS(low)
// 0xfe5810 BSMultiBoundSphere::Functionfe5810
#include "BSMultiBoundSphere_fe5810.h"

// Test whether the bounding sphere lies entirely on the positive side of all active frustum planes.
bool BSMultiBoundSphere::Functionfe5810(const NiFrustumPlanes& a_planes) const
{
    const float cx = center.x;
    const float cy = center.y;
    const float cz = center.z;
    const float r = radius;
    for (std::uint32_t i = 0; i < 6; ++i) {
        if ((a_planes.activePlanes & (1u << i)) != 0) {
            if (WhichSide(a_planes.planes[i], cx, cy, cz, r) != PlaneSide::kPositiveSide) {
                return false;
            }
        }
    }
    return true;
}
