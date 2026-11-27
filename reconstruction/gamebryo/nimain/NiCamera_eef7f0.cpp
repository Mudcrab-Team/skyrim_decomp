// Source exposure: mixed (local pinned-image analysis and labelled declarations).
// Code origin: reconstructed from the local listing and the sources named below.
// Adapted bodies: none.
// NiCamera, NiObject, NiAVObject, IsEqual, worldToCam, viewFrustum, minNearPlaneDist, maxFarNearRatio, port, lodAdjust, NiFrustum: CRASHLOGGER_PDB(59818@2026.10.24)
// ViewPort: GUESS(low)
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0xeef7f0 NiCamera::IsEqual
// CI hash: 0xeef7f0 ?IsEqual@NiCamera@@QEAA_NPEAVNiObject@@@Z
#include "NiCamera_eef7f0.h"

bool NiCamera::IsEqual(NiObject* other)
{
    if (!NiAVObject::IsEqual(other)) {
        return false;
    }
    const NiCamera* camera = static_cast<NiCamera*>(other);
    return viewFrustum.fLeft == camera->viewFrustum.fLeft &&
           viewFrustum.fRight == camera->viewFrustum.fRight &&
           viewFrustum.fTop == camera->viewFrustum.fTop &&
           viewFrustum.fBottom == camera->viewFrustum.fBottom &&
           viewFrustum.fNear == camera->viewFrustum.fNear &&
           viewFrustum.fFar == camera->viewFrustum.fFar &&
           port.left == camera->port.left && port.right == camera->port.right &&
           port.top == camera->port.top && port.bottom == camera->port.bottom &&
           lodAdjust == camera->lodAdjust;
}
