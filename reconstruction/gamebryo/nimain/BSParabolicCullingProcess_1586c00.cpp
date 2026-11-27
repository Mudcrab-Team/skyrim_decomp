// Source exposure: mixed (local pinned-image analysis and community PDB facts).
// Code origin: original reconstruction from the contributor-owned image.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Adapted bodies: none
// 0x1586c00 BSParabolicCullingProcess::Process2
#include "BSParabolicCullingProcess_1586c00.h"

void BSParabolicCullingProcess::Process2(NiCamera* newCamera, NiAVObject* scene, NiVisibleArray* visible)
{
    if (!newCamera || !scene)
        return;
    camera = newCamera;
    SetFrustum(newCamera->viewFrustum);
    planes.activePlanes = static_cast<ActivePlane>(0);
    NiVisibleArray* saved = nullptr;
    if (visible) {
        saved = visibleSet;
        visibleSet = visible;
    }
    scene->Cull(this, static_cast<unsigned int>(-1));
    if (visible)
        visibleSet = saved;
}
