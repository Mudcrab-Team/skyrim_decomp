// Source exposure: mixed (local binary analysis and published declarations).
// Code origin: original reconstruction from the pinned image and labelled layout information.
// Code shape adapted from the project reconstruction of BSOcclusionPlane::AreVerticesInsideActivePlanes.
// BSOcclusionBox, AreCornersInsidePlanes: CRASHLOGGER_PDB(59818@2026.10.24)
// Recipe: reconstruction/recipes/o2-fpfast-root-includes.json
// 0xfe7790 BSOcclusionBox::AreCornersInsidePlanes
#include "BSOcclusionBox_fe7790.h"

bool BSOcclusionBox::AreCornersInsidePlanes(const NiFrustumPlanes& frustum) const
{
    const auto active = frustum.activePlanes;
    for (int index = 0; index < 6; ++index) {
        if (active & (1u << index)) {
            const auto& plane = frustum.cullingPlanes[index];
            for (long long vertex = 0; vertex < 8; ++vertex) {
                const auto& corner = corners[vertex];
                const float distance = plane.normal.x * corner.x + plane.normal.y * corner.y
                    + plane.normal.z * corner.z - plane.constant;
                if (!(distance >= 0.0f)) {
                    return false;
                }
            }
        }
    }
    return true;
}
