// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Code origin: original; the listing and community declarations
// Sibling source: momusdigital/fnv_decomp@2b07cb3e src/bsshader/shadowscenenode.cpp:4516 (the light type validation and the queued add)
// 0x150c810 ShadowSceneNode::AddLight(NiLight*, LIGHT_CREATE_PARAMS*)
#include "ShadowSceneNode_R5D1.h"
#include <intrin.h>

// Adapted bodies: BSSpinLock::Unlock (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/B/BSAtomic.cpp, MIT) inlined
// The lock release is inlined into every guard, as the engine does.
void BSSpinLock::Unlock()
{
    _mm_lfence();  // ordering: serialise earlier loads before reading the owner
    std::uint32_t myThreadID = GetCurrentThreadId();

    if (owningThread == myThreadID) {
        if (lockCount == 1) {
            owningThread = 0;
            _mm_mfence();  // ordering: publish the cleared owner before releasing the count
            // atomic release: other threads spin on this count
            _InterlockedCompareExchange(reinterpret_cast<volatile long*>(&lockCount), 0, 1);
        } else {
            // atomic release: other threads spin on this count
            _InterlockedDecrement(reinterpret_cast<volatile long*>(&lockCount));
        }
    }
}

// AddLight: CRASHLOGGER_PDB(59818@2026.10.24)
BSLight* ShadowSceneNode::AddLight(NiLight* a_light, LIGHT_CREATE_PARAMS* a_params)
{
    MemoryContextScope scope(0x1D);
    if (!a_light) {
        return nullptr;
    }
    if (a_light->GetRTTI() != &g_niDirectionalLightRTTI && a_light->GetRTTI() != &g_niPointLightRTTI) {
        return nullptr;
    }

    BSAutoLock lock(&lightQueueLock);
    BSLight* light;
    if (a_params->shadowLight) {
        MemoryContextScope shadowScope(0x1D);
        BSShadowLight* shadowLight;
        // negated >= : a NaN field of view stays on the plain frustum light
        if (!(a_params->fov >= 3.14159265f)) {
            shadowLight = new BSShadowFrustumLight(a_params->fov, a_params->falloff, a_params->nearDistance, 0.0f);
        } else if (!(a_params->fov >= 6.28318531f)) {
            shadowLight = new BSShadowParabolicLight(false);
        } else {
            shadowLight = new BSShadowParabolicLight(true);
        }
        float bias = a_params->depthBias;
        shadowLight->tail.shadowBiasScale = bias;
        shadowLight->tail.sceneGraphIndex = a_params->sceneGraphIndex;
        light = shadowLight;
    } else {
        light = new BSLight;
    }

    light->Unk_02(a_light);
    light->dynamic = a_params->dynamic;
    light->portalStrict = a_params->portalStrict;
    light->affectLand = a_params->affectLand;
    light->affectWater = a_params->affectWater;
    light->objectNode = a_params->objectNode;
    light->lodFade = a_params->neverFades;
    light->lensFlareData = a_params->lensFlareData;
    if (BSLensFlareRenderData* flare = a_params->lensFlareData) {
        for (auto it = flare->sprites.begin(); it != flare->sprites.end(); ++it) {
            (*it)->Unk_02();
        }
    }
    queuedAdd.Append(light);
    light->portalGraph = portalGraph;
    return light;
}
