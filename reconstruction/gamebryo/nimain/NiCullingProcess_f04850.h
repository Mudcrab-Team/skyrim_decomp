// Source exposure: mixed (pinned image and labelled declarations).
// Code origin: reconstructed from the local image using the declarations below.
// NiCullingProcess, SetFrustum, NiCamera, NiTransform, NiFrustum, NiFrustumPlanes, Set, world, frustum, planes, camera, activePlanes: CRASHLOGGER_PDB(59818@2026.10.24)
#pragma once

#include "NiFrustumPlanes_ef76f0.h"

class NiCullingProcess
{
public:
    void SetFrustum(const NiFrustum& view);

    char unknown00[0x18];
    NiCamera* camera;
    NiFrustum frustum;
    NiFrustumPlanes planes;
};
