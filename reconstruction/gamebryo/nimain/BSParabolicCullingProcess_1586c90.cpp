// Source exposure: mixed (local pinned-image analysis and community-generated names).
// Code origin: original reconstruction from the contributor-owned image.
// Uses the project NiAVObject.h definitions of NiPoint3 assignment and NiPointer assignment.
// 0x1586c90 BSParabolicCullingProcess::UpdateLightPlanes
// CI hash: 0x1586c90 ?UpdateLightPlanes@BSParabolicCullingProcess@@QEAAXPEAUNiCamera@@M_N@Z
#include "BSParabolicCullingProcess_1586c90.h"

void BSParabolicCullingProcess::UpdateLightPlanes(NiCamera* newCamera, float radius, bool rememberCamera)
{
    camera = newCamera;
    if (rememberCamera && !lightCamera.pointer)
        lightCamera = newCamera;

    const NiTransform& world = newCamera->world;
    equatorialPlane = NiPlane({world.rotate.entry[0][0], world.rotate.entry[1][0],
                               world.rotate.entry[2][0]}, world.translate);
    lightPosition = world.translate;
    lightRadius = radius;
    unk301F8 = radius;
    activePlanes = 0;
}
