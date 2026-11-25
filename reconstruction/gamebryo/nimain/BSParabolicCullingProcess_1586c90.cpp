// Source exposure: mixed (local pinned-image analysis and community-generated names).
// Code origin: original reconstruction from the contributor-owned image.
// Adapted bodies: none
// 0x1586c90 BSParabolicCullingProcess::UpdateLightPlanes
// CI hash: 0x1586c90 ?UpdateLightPlanes@BSParabolicCullingProcess@@QEAAXPEAUNiCamera@@M_N@Z
#include "BSParabolicCullingProcess_1586c90.h"

#include <intrin.h>

void BSParabolicCullingProcess::UpdateLightPlanes(NiCamera* newCamera, float radius, bool rememberCamera)
{
    camera = newCamera;
    if (rememberCamera && !lightCamera && newCamera) {
        // Retain the camera when its reference is first stored.
        _InterlockedIncrement(&newCamera->refCount);
        lightCamera = newCamera;
    }
    equatorialPlane = NiPlane({newCamera->worldRotation[0][0], newCamera->worldRotation[1][0],
                               newCamera->worldRotation[2][0]}, newCamera->worldTranslation);
    lightPosition = newCamera->worldTranslation;
    lightRadius = radius;
    unk301F8 = radius;
    activePlanes = 0;
}
