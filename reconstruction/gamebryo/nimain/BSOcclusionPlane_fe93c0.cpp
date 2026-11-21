// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original implementation from the observed active-plane containment test.
// Declarations informed by powerof3/CommonLibSSE, GPL-3.0.
// Recipe: reconstruction/recipes/o2-fpfast-root-includes.json
// 0xfe93c0 BSOcclusionPlane::AreVerticesInsideActivePlanes
#include "BSOcclusionPlane_fe93c0.h"

#include <cstring>

bool BSOcclusionPlane::AreVerticesInsideActivePlanes(const NiFrustumPlanes* frustum)
{
    Refresh();
    PortalVertex corners[4];
    memcpy_s(corners, sizeof(corners), vertices, sizeof(corners));

    const auto active = frustum->activePlanes;
    for (int index = 0; index < 6; ++index) {
        if ((active & (1u << index)) != 0) {
            const auto& plane = frustum->planes[index];
            for (std::int64_t vertex = 0; vertex < 4; ++vertex) {
                const auto& corner = corners[vertex];
                const float distance = (plane.normal.y * corner.y + plane.normal.x * corner.x)
                    + plane.normal.z * corner.z - plane.constant;
                if (!(distance >= 0.0f)) {
                    return false;
                }
            }
        }
    }
    return true;
}
