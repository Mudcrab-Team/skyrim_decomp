// Source exposure: mixed (pinned image and labelled declarations).
// Code origin: reconstructed from the local image using the declarations below.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Adapted bodies: NiCamera::PointInFrustum from CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/N/NiCamera.cpp (MIT).
// 0x2247e0 NiCamera::PointInFrustum
#include "NiCamera_2247e0.h"

bool NiCamera::PointInFrustum(const NiPoint3& point, NiCamera* camera, float radius)
{
    if (!camera) {
        return false;
    }
    const NiBound bound{{point.x, point.y, point.z}, radius};
    return BoundInFrustum(bound, camera);
}
