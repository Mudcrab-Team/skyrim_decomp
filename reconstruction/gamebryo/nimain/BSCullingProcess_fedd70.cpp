// Source exposure: mixed (local pinned-image analysis and community PDB facts).
// Code origin: original reconstruction from the contributor-owned image.
// Adapted bodies: none
// 0xfedd70 BSCullingProcess::Process2
#include "BSCullingProcess_fedd70.h"

void BSCullingProcess::Process2(NiCamera* camera, NiAVObject* scene, NiVisibleArray* visibleSet)
{
    if (!camera || !scene) {
        return;
    }

    this->camera = camera;
    const bool recurse = recurseToGeometry;
    SetFrustum(camera->viewFrustum);

    if (doCustomCullPlanes) {
        planes = customCullPlanes;
    }

    NiVisibleArray* savedVisibleSet = nullptr;
    if (visibleSet) {
        savedVisibleSet = this->visibleSet;
        this->visibleSet = visibleSet;
    }

    if (!recurse) {
        Process1(scene, 0xFFFFFFFFu);
    } else {
        scene->CullGeometry(this, 0xFFFFFFFFu);
    }

    if (visibleSet) {
        this->visibleSet = savedVisibleSet;
    }
}
