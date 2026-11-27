// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Code origin: original reconstruction from the pinned image listing
// 0x1510b60 ShadowSceneNode::UpdateOcclusionPlaneVisibility
// Adapted bodies: none
#include "ShadowSceneNode_R4Planes.h"

// UpdateOcclusionPlaneVisibility: GUESS(low); the public name is a placeholder
void ShadowSceneNode::UpdateOcclusionPlaneVisibility(NiCamera* a_camera)
{
    if (!portalGraph) {
        return;
    }
    NiCullingProcess culler(nullptr);
    culler.camera = a_camera;
    culler.SetFrustum(a_camera->frustum);
    NiTPointerList<BSOcclusionShape*>& shapes = portalGraph->occlusionShapes;
    NiTListItem<BSOcclusionShape*>* pos = shapes.GetHeadPos();
    NiFrustumPlanes planes;
    while (pos) {
        BSOcclusionShape* shape = shapes.GetNext(pos);
        if (shape && shape->IsOcclusionPlane()) {
            BSOcclusionPlane* plane = static_cast<BSOcclusionPlane*>(shape);
            const bool inside = plane->InsidePlanes(culler.camera->worldPosition);
            const bool front = plane->IsInFront(a_camera->worldPosition);
            plane->visibilityState = (inside & front) ? 1 : 2;
        }
    }
}
