// Source exposure: mixed (pinned image and labelled declarations).
// Code origin: reconstructed from the local image using the declarations below.
// NiFrustumPlanes, Set, NiCamera, NiFrustum, NiTransform, world, viewFrustum, cullingPlanes, activePlanes, rotate, translate, scale, NiPoint3, NiMatrix3: CRASHLOGGER_PDB(59818@2026.10.24)
// NiFrustumPlanes::Set: GUESS(low); the camera overload is named for the frustum-and-transform method it delegates to.
#pragma once

#include "NiCamera_2247e0.h"

class NiFrustumPlanes
{
public:
    void Set(const NiCamera& camera);
    void Set(const NiFrustum& frustum, const NiTransform& transform);

    float cullingPlanes[6][4];
    unsigned activePlanes;
};
