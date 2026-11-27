// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Code origin: original reconstruction from the pinned image listing
// 0x1538860 ResetCalculatedShadowCasterLights
// CI hash: 0x1538860 ?ResetCalculatedShadowCasterLights@@YAXXZ
// Adapted bodies: none
#include "ShadowSceneNode_R5B2CasterReset.h"

// ResetCalculatedShadowCasterLights: CRASHLOGGER_PDB(59818@2026.10.24)
// The globals: GUESS(low); the per-frame caster bookkeeping the engine keeps beside the scene node
extern ShadowSceneNode* g_shadowSceneNode;
extern ShadowRenderState* g_shadowRenderState;
extern bool g_focusShadowsEnabled;
extern std::int32_t g_focusLightCount;

struct CasterState
{
    std::uint32_t start;
    std::uint32_t count;
    std::uint32_t mask;
    std::uint8_t unknown0C;
    bool lightsFrozen;
    bool focusPassQueued;
};

extern CasterState g_casterState;
extern BSCullingProcess** g_cullingProcesses;
extern CullInput g_dirCullInput;

void ResetCalculatedShadowCasterLights()
{
    ShadowSceneNode* sceneNode = g_shadowSceneNode;
    NiCamera* camera = g_shadowRenderState->camera;
    g_casterState.start = 0;
    g_casterState.count = 0;
    g_casterState.mask = 0;
    sceneNode->ClearShadowCasterArray();
    bool focus = g_focusShadowsEnabled && g_focusLightCount != 0;
    g_casterState.focusPassQueued = false;
    if (!g_casterState.lightsFrozen) {
        BSShadowDirectionalLight* light = g_shadowSceneNode->shadowDirLight;
        light->tail.focusEnabled = focus;
        light->Unk_10(camera);
        if (focus) {
            light->Function155ca00(camera);
            g_casterState.focusPassQueued = true;
        }
        sceneNode->ReplaceShadowCasters(light, g_casterState.start, light->shadowMapCount);
        std::uint32_t index = g_casterState.count;
        g_casterState.count = index + 1;
        light->shadowmapIndex = index;
        g_casterState.mask |= 1 << g_casterState.start;
        light->DirShadowLightCulling(&g_dirCullInput, g_cullingProcesses[0]->unk30190->frustum->bounds);
    } else if (g_shadowSceneNode->shadowDirLight) {
        g_shadowSceneNode->shadowDirLight->Unk_0C();
    }
}
