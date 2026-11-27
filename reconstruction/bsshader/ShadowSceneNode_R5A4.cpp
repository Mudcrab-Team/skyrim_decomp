// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Code origin: original; the listing and community declarations
// 0x150cbf0 ShadowSceneNode::AddOrUpdateActiveLight
// 0x150d240 ShadowSceneNode::UnlinkLight
#include "ShadowSceneNode_R5A4.h"

// AddOrUpdateActiveLight, UnlinkLight: CRASHLOGGER_PDB(59818@2026.10.24)
BSLight* ShadowSceneNode::AddOrUpdateActiveLight(BSLight* a_light)
{
    MemoryContextScope scope(0x1D);
    BSTArray<NiPointer<BSLight>>* lights = &activeLights;
    if (a_light->Unk_03()) {
        lights = &shadowLights;
    }
    for (auto it = lights->begin(); it != lights->end(); ++it) {
        BSLight* entry = *it;
        if (entry) {
            NiLight* node = entry->light;
            if (node == a_light->light) {
                entry->unk46 = a_light->unk46;
                EnableLight(entry);
                return entry;
            }
        }
    }
    lights->Add(a_light);
    EnableLight(a_light);
    return nullptr;
}

void ShadowSceneNode::UnlinkLight(const NiPointer<BSLight>& a_light)
{
    BSTArray<NiPointer<BSLight>>* lights = &activeLights;
    if (a_light->Unk_03()) {
        lights = &shadowLights;
        for (std::uint32_t i = 0; i < shadowCasterLights.iSize; ++i) {
            if (shadowCasterLights[i] == static_cast<BSShadowLight*>(a_light.m_pObject)) {
                shadowCasterLights[i] = nullptr;
            }
        }
    }
    if (!a_light->objectNode && a_light->portalGraph == portalGraph && portalGraph) {
        a_light->ReleasePortalGraph();
    }
    BSLensFlareRenderData* flare = a_light->lensFlareData;
    if (flare) {
        for (auto it = flare->sprites.begin(); it != flare->sprites.end(); ++it) {
            BSLensFlareSpriteRenderData* sprite = *it;
            sprite->texture = nullptr;
        }
    }
    std::uint32_t index = 0xFFFFFFFF;
    for (std::uint32_t i = 0; i < lights->iSize && index == 0xFFFFFFFF; ++i) {
        if ((*lights)[i] == a_light) {
            index = i;
        }
    }
    if (index < lights->iSize) {
        lights->Remove(index, 1);
    }
}
