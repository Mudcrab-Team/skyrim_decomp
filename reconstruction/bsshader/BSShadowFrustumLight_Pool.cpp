// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Adapted bodies: none
// 0x15879d0 BSShadowFrustumLight::Accumulate
// 0x1587a30 BSShadowFrustumLight::Render
// 0x1587ae0 BSShadowFrustumLight::SetLight
// 0x1587ef0 BSShadowFrustumLight::`scalar deleting destructor'
// CI hash: 0x15879d0 ?Accumulate@BSShadowFrustumLight@@QEAAXPEBII@Z
// CI hash: 0x1587a30 ?Render@BSShadowFrustumLight@@QEAAXPEAI@Z
// CI hash: 0x1587ae0 ?SetLight@BSShadowFrustumLight@@QEAAXPEAVNiLight@@@Z
// CI hash: 0x1587ef0 ??_GBSShadowFrustumLight@@UEAAPEAXI@Z
#include "BSShadowFrustumLight_Pool.h"

// g_focusShadowmapCount, g_focusShadowmapBase: GUESS(low); how many focus descriptors render and the first shadowmap slot they use
extern std::uint32_t g_focusShadowmapCount;
extern std::uint32_t g_focusShadowmapBase;

// Accumulate, Render, ~BSShadowFrustumLight: CRASHLOGGER_PDB(59818@2026.10.24)
void BSShadowFrustumLight::Accumulate(const std::uint32_t* a_cascade, std::uint32_t a_count)
{
    BSShaderAccumulator* accumulator = shadowmapDescriptors[0].shaderAccumulator;
    std::uint32_t cascade = *a_cascade;
    accumulator->passIndex = cascade + 1;
    std::uint32_t mask;
    if (cascade <= 30) {
        mask = 1 << cascade;
    } else {
        mask = 0;
    }
    accumulator->passMask = mask;
    AccumulateShadow(&shadowmapDescriptors[0], a_cascade, nullptr, a_count + 13);
}

void BSShadowFrustumLight::Render(std::uint32_t* a_arg)
{
    RenderShadowmap(&shadowmapDescriptors[0], a_arg, 0);
    if (tail.focusEnabled) {
        for (std::uint32_t i = 0; i < g_focusShadowmapCount; ++i) {
            ShadowmapDescriptor* descriptor = &focusShadowmapDescriptors[i];
            descriptor->renderTarget = 4;
            if (descriptor->shaderAccumulator) {
                std::uint32_t slot = g_focusShadowmapBase + i;
                descriptor->unkE8 = 1;
                descriptor->unkE9 = 1;
                descriptor->shadowmapIndex = slot;
                std::uint32_t unused = 0;
                RenderShadowmap(descriptor, &unused, 0);
            }
        }
    }
}

// SetLight: GUESS(low); the CrashLogger name of this address is Func2_14132D0F0, an override of the light's slot 2
void BSShadowFrustumLight::SetLight(NiLight* a_light)
{
    BSLight::SetLight(a_light);
    NiCamera* camera = shadowmapDescriptors[0].camera;
    NiFrustum frustum = camera->frustum;
    frustum.farPlane = a_light->unknown128;
    frustum.nearPlane = unk56C;
    camera->SetFrustum(frustum);
    camera->worldTranslate = light->worldTranslate;
    camera->worldRotate = light->worldRotate;
    UpdateTimeFlags update;
    update.time = 0.0f;
    update.flags = 0;
    camera->UpdateObjectUpwards(&update);
}

BSShadowFrustumLight::~BSShadowFrustumLight()
{
    shadowmapDescriptors[0].camera = nullptr;
}
