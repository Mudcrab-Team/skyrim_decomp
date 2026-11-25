// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Adapted bodies: none
// 0x157ead0 BSShadowDirectionalLight::Accumulate
// 0x157ebb0 BSShadowDirectionalLight::Render
// CI hash: 0x157ead0 ?Accumulate@BSShadowDirectionalLight@@QEAAXPEBI@Z
// CI hash: 0x157ebb0 ?Render@BSShadowDirectionalLight@@QEAAXPEAI@Z
#include "BSShadowDirectionalLight_Pool.h"

// Accumulate: CRASHLOGGER_PDB(59818@2026.10.24)
void BSShadowDirectionalLight::Accumulate(const std::uint32_t* a_cascade)
{
    for (std::uint32_t i = 0; i < shadowMapCount; ++i) {
        BSShaderAccumulator* accumulator = shadowmapDescriptors[i].shaderAccumulator;
        std::uint32_t cascade = *a_cascade;
        accumulator->passIndex = cascade + 1;
        std::uint32_t mask;
        if (cascade <= 30) {
            mask = 1 << cascade;
        } else {
            mask = 0;
        }
        accumulator->passMask = mask;
        shadowmapDescriptors[i].shaderAccumulator->unk168 = i;
        shadowmapDescriptors[i].shaderAccumulator->unk12E = true;
        AccumulateShadow(&shadowmapDescriptors[i], a_cascade, &cullingProcesses, i + 11);
    }
}

// g_shadowRenderMode, g_focusShadowmapCount, g_focusShadowmapBase: GUESS(low); the render mode switch, the number of focus descriptors and the first slot they use
extern std::uint32_t g_shadowRenderMode;
extern std::uint32_t g_focusShadowmapCount;
extern std::uint32_t g_focusShadowmapBase;

// Render: CRASHLOGGER_PDB(59818@2026.10.24)
void BSShadowDirectionalLight::Render(std::uint32_t* a_arg)
{
    if (g_shadowRenderMode == 2) {
        for (std::uint32_t i = 0; i < shadowMapCount; ++i) {
            shadowmapDescriptors[i].renderTarget = 3;
            shadowmapDescriptors[i].shadowmapIndex = i;
            std::uint32_t unused = 0;
            RenderShadowmap(&shadowmapDescriptors[i], &unused, 0x100);
        }
    }
    for (std::uint32_t i = 0; i < shadowMapCount; ++i) {
        shadowmapDescriptors[i].renderTarget = 2;
        shadowmapDescriptors[i].shadowmapIndex = i;
        RenderShadowmap(&shadowmapDescriptors[i], a_arg, 0);
    }
    if (tail.focusEnabled) {
        for (std::uint32_t i = 0; i < g_focusShadowmapCount; ++i) {
            ShadowmapDescriptor* descriptor = &focusShadowmapDescriptors[i];
            std::uint32_t unused = 0;
            descriptor->renderTarget = 4;
            std::uint32_t slot = g_focusShadowmapBase + i;
            descriptor->unkE8 = 1;
            descriptor->shadowmapIndex = slot;
            RenderShadowmap(descriptor, &unused, 0);
        }
    }
}
