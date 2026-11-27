// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Code origin: original reconstruction from the pinned image listing
// 0x1539a70 RenderShadowmasks
// CI hash: 0x1539a70 ?RenderShadowmasks@@YAX_N@Z
// Adapted bodies: none
#include "ShadowSceneNode_R5BMasks.h"

// RenderShadowmasks: CRASHLOGGER_PDB(59818@2026.10.24)
extern ShadowRenderState* g_shadowRenderState;
extern bool g_shadowmasksForced;
extern std::int32_t g_shadowmaskCount;
extern bool g_shadowmaskDebug;
extern BSGraphics::Renderer g_renderer;
extern BSGraphics::State g_graphicsState;
extern NiCamera* g_currentShadowCamera;
void RenderParabolicShadowmaps();

void RenderShadowmasks(bool a_flag)
{
    NiCamera* camera = g_shadowRenderState->camera;
    if (!g_shadowmasksForced && g_shadowmaskCount <= 0) {
        return;
    }
    float red = !g_shadowmaskDebug ? 1.0f : 0.0f;
    g_renderer.SetClearColor(red, 0.0f, 0.0f, 0.0f);
    g_graphicsState.SetCameraData(camera, a_flag);
    g_currentShadowCamera = camera;
    if (g_shadowmasksForced) {
        RenderParabolicShadowmaps();
    }
    g_renderer.SetClearColorFromArray();
}
