// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original implementation from the observed aperture and origin projection tests.
// Declarations informed by powerof3/CommonLibSSE, GPL-3.0.
// Recipe: reconstruction/recipes/o2-fpfast-root-includes.json
// 0xfe8e60 BSOcclusionPlane::IntersectsFrustum
#include "BSOcclusionPlane_fe8e60.h"

#include <cmath>
#include <cstring>

bool BSOcclusionPlane::IntersectsFrustum(const NiFrustumPlanes* frustum, bool testOrigin, const NiPoint3& origin)
{
    Refresh();
    NiPoint3 quad[4];
    memcpy_s(quad, sizeof(quad), corners, sizeof(quad));

    const bool intersects = frustum->IntersectsQuad(quad, edgeFlags);
    if (!intersects && testOrigin) {
        const float x = origin.x - translation.x;
        const float y = origin.y - translation.y;
        const float z = origin.z - translation.z;
        const volatile NiPoint3& verticalAxis = vertical;
        const float verticalX = verticalAxis.x;
        const float verticalY = verticalAxis.y;
        const float verticalZ = verticalAxis.z;
        const float horizontalDistance = (y * horizontal.y + x * horizontal.x) + z * horizontal.z;
        if (std::fabs(horizontalDistance) > halfWidth) {
            return false;
        }
        const float verticalDistance = (y * verticalY + x * verticalX) + z * verticalZ;
        if (std::fabs(verticalDistance) > halfHeight) {
            return false;
        }
        return true;
    }
    return intersects;
}
