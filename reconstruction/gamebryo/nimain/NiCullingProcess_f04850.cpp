// Source exposure: mixed (pinned image and labelled declarations).
// Code origin: reconstructed from the local image using the declarations below.
// Adapted bodies: none
// 0xf04850 NiCullingProcess::SetFrustum
#include "NiCullingProcess_f04850.h"

void NiCullingProcess::SetFrustum(const NiFrustum& view)
{
    if (camera) {
        frustum = view;
        planes.Set(frustum, camera->world);
        constexpr unsigned allSixPlanes = (1u << 6) - 1;
        planes.activePlanes = allSixPlanes;
    }
}
