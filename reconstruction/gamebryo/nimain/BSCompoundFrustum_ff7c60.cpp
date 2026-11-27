// Source exposure: mixed (local binary analysis and published declarations).
// Code origin: original reconstruction from the pinned image and labelled layout information.
// BSCompoundFrustum, SetCamera: CRASHLOGGER_PDB(59818@2026.10.24)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xff7c60 BSCompoundFrustum::SetCamera
#include "BSCompoundFrustum_ff7c60.h"

void BSCompoundFrustum::SetCamera(NiCamera* newCamera)
{
    if (newCamera) {
        viewFrustum.Set(newCamera->viewFrustum, newCamera->world);
        viewPosition.x = newCamera->world.translate.x;
        viewPosition.y = newCamera->world.translate.y;
        viewPosition.z = newCamera->world.translate.z;
    }
    camera = newCamera;
    freePlane = 0;
    freeOp = 0;
    skipViewFrustum = false;
    prethreaded = false;
    firstOp = 0;
}
