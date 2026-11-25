// Source exposure: mixed (local pinned-image analysis and community PDB facts).
// Code origin: original reconstruction from the contributor-owned image.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Adapted bodies: none
// 0x73c720 HighActorCuller::Update
#include "HighActorCuller_73c720.h"

void HighActorCuller::Update(NiCamera* camera)
{
    if (!multiBoundSphere) {
        InitializeBounds(camera);
    } else {
        culler.camera = camera;
        culler.SetFrustum(camera->viewFrustum);
    }
    actorManager->Visit(this);
}
