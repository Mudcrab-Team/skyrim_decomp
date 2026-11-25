// Source exposure: mixed (pinned image and labelled declarations).
// Code origin: reconstructed from the local image using the declarations below.
// Adapted bodies: none
// 0xef76f0 NiFrustumPlanes::Set
#include "NiFrustumPlanes_ef76f0.h"

void NiFrustumPlanes::Set(const NiCamera& camera)
{
    Set(camera.viewFrustum, camera.world);
}
