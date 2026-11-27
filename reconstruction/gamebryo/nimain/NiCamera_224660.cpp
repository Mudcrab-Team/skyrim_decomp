// Source exposure: mixed (local pinned-image analysis and labelled declarations).
// Code origin: original reconstruction from the local listing and labelled declarations.
// Adapted bodies: none.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// NiCamera, NiPlane, NiFrustumPlanes, BoundInFrustum: CRASHLOGGER_PDB(59818@2026.10.24)
// NiBound, center, radius: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
// SetFromCamera, g_frameCounter: GUESS(low)
// 0x224660 NiCamera::BoundInFrustum
#include "NiCamera_224660.h"

// Tests whether a bounding sphere intersects or lies inside the camera's six frustum planes.
bool NiCamera::BoundInFrustum(const NiBound& bound, NiCamera* camera)
{
    if (!camera) {
        return false;
    }

    static NiFrustumPlanes frustumPlanes;
    static NiCamera* lastCamera = nullptr;
    static std::uint32_t lastFrame = 0;

    if (lastCamera != camera || lastFrame != g_frameCounter) {
        frustumPlanes.SetFromCamera(*camera);
        lastFrame = g_frameCounter;
        lastCamera = camera;
    }

    for (std::uint32_t i = 0; i < 6; ++i) {
        const NiPlane& plane = frustumPlanes.cullingPlanes[i];
        float dist = bound.center.x * plane.normal.x +
                     bound.center.y * plane.normal.y +
                     bound.center.z * plane.normal.z - plane.constant;
        if (!(dist > -bound.radius)) {
            return false;
        }
    }

    return true;
}
