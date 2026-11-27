// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Code origin: original reconstruction from the pinned image listing
// 0x15121a0 ShadowSceneNode::UpdateLightList
// Adapted bodies: none
#include "ShadowSceneNode_R4LightList.h"

// UpdateLightList: GUESS(low); no public name
void ShadowSceneNode::UpdateLightList(BSTArray<NiPointer<BSLight>>* a_lights, NiCamera* a_camera)
{
    auto it = a_lights->begin();
    while (it != a_lights->end()) {
        BSLight* light = *it;
        if (light) {
            NiLight* node = light->light;
            if (!node || node->GetRefCount() == 1) {
                if (light->portalGraph == portalGraph) {
                    light->ReleasePortalGraph();
                }
                it = a_lights->erase(it);
            } else {
                if (light->unk46 && light->unk44) {
                    if (node->flags & 1) {
                        light->ClearGeometryList();
                    } else if (light->frustumCull != 0xFF) {
                        const NiPoint3& centre = node->boundCenter;
                        light->position = NiPoint3(centre.x, centre.y, centre.z);
                        EnableLight(light);
                        if (a_camera) {
                            light->UpdateLODFadeAndCull(a_camera);
                        }
                        ++it;
                        continue;
                    }
                }
                if (a_camera) {
                    light->UpdateLODFadeAndCull(a_camera);
                }
                ++it;
            }
        }
    }
}
