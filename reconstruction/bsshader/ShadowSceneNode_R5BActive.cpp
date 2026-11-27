// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Code origin: original reconstruction from the pinned image listing
// 0x1538f00 RenderActiveShadowCasterLights
// CI hash: 0x1538f00 ?RenderActiveShadowCasterLights@@YAXXZ
// Adapted bodies: none
#include "ShadowSceneNode_R5BActive.h"

// RenderActiveShadowCasterLights: CRASHLOGGER_PDB(59818@2026.10.24)
// g_shadowSceneNode: GUESS(low); the scene node whose caster array is walked
extern ShadowSceneNode* g_shadowSceneNode;

void RenderActiveShadowCasterLights()
{
    ShadowSceneNode* sceneNode = g_shadowSceneNode;
    MemoryContextScope scope(0x1D);
    std::uint32_t index = 0;
    for (BSShadowLight* light = sceneNode->GetShadowCasterLightArrayEntry(0); light; light = sceneNode->GetShadowCasterLightArrayEntry(index)) {
        light->Unk_0A(&index);
    }
}
