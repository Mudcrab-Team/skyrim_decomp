// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Code origin: original; the listing and community declarations, BSTArray and NiPointer shapes after the sibling
// Adapted bodies: BSSpinLock::Unlock (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/B/BSAtomic.cpp, MIT) inlined
// 0x150c780 ShadowSceneNode::FillShadowScratch
// 0x150c710 ShadowSceneNode::BeginShadowFrame
// 0x15122e0 BSTArray<NiPointer<BSLight>, BSTArrayHeapAllocator>::Add<BSLight*>
// 0x150e090 ShadowSceneNode::ClearLightArrays
// 0x150fff0 ShadowSceneNode::UpdateActiveLightsLODFadeAndCull
// 0x150e680 ShadowSceneNode::QueueLightRemoveUnscoped
// 0x150e5e0 ShadowSceneNode::QueueLightRemoveByNode
// 0x150e400 ShadowSceneNode::EnableLight
// CI hash: 0x150c710 ?BeginShadowFrame@ShadowSceneNode@@QEAAXPEAUShadowFrameSource@@@Z
// CI hash: 0x150c780 ?FillShadowScratch@ShadowSceneNode@@QEAAPEAXH@Z
// CI hash: 0x150e090 ?ClearLightArrays@ShadowSceneNode@@QEAAXXZ
// CI hash: 0x150e400 ?EnableLight@ShadowSceneNode@@QEAAXPEAVBSLight@@@Z
// CI hash: 0x150e5e0 ?QueueLightRemoveByNode@ShadowSceneNode@@QEAAXPEAVNiLight@@@Z
// CI hash: 0x150e680 ?QueueLightRemoveUnscoped@ShadowSceneNode@@QEAAXPEAVBSLight@@@Z
// CI hash: 0x150fff0 ?UpdateActiveLightsLODFadeAndCull@ShadowSceneNode@@QEAAXPEAVNiCamera@@@Z
// CI hash: 0x15122e0 ??$Add@PEAVBSLight@@@?$BSTArray@V?$NiPointer@VBSLight@@@@VBSTArrayHeapAllocator@@@@QEAAXPEAVBSLight@@@Z
#include <intrin.h>
#include <string.h>
#include "ShadowSceneNode_Pool.h"

// BeginShadowFrame: CRASHLOGGER_PDB(59818@2026.10.24)
// g_shadowFrameSceneGraphIndex, g_shadowFrameView, g_shadowBlend*, g_shadowBlendFactor: GUESS(low); frame globals the function refreshes
extern std::uint8_t g_shadowFrameSceneGraphIndex;
extern void* g_shadowFrameView;
extern float g_shadowBlendStart;
extern float g_shadowBlendEnd;
extern float g_shadowBlendResult;
extern const float g_shadowBlendFactor;

void ShadowSceneNode::BeginShadowFrame(ShadowFrameSource* a_source)
{
    a_source->Prepare();
    void* view = a_source->view;
    g_shadowFrameSceneGraphIndex = sceneGraphIndex;
    g_shadowFrameView = view;
    g_shadowBlendResult = (g_shadowBlendEnd - g_shadowBlendStart) * g_shadowBlendFactor + g_shadowBlendStart;
}

// FillShadowScratch: GUESS(low); a scratch buffer filled with the caller's byte and handed back
struct ShadowScratch
{
    std::uint8_t bytes[0x301F8];
};
static_assert(sizeof(ShadowScratch) == 0x301F8, "ShadowScratch size");

void* ShadowSceneNode::FillShadowScratch(int a_value)
{
    ShadowScratch scratch;
    return memset(&scratch, a_value, sizeof(scratch));
}

// UpdateLODFadeAndCull: CRASHLOGGER_PDB(59818@2026.10.24)
// UpdateActiveLightsLODFadeAndCull: GUESS(low); the loop over the active lights has no public name
void ShadowSceneNode::UpdateActiveLightsLODFadeAndCull(NiCamera* a_camera)
{
    for (auto it = activeLights.begin(); it != activeLights.end(); ++it) {
        BSLight* entry = *it;
        if (entry) {
            entry->UpdateLODFadeAndCull(a_camera);
        }
    }
}

// ClearLightArrays: CRASHLOGGER_PDB(59818@2026.10.24)
void ShadowSceneNode::ClearLightArrays()
{
    for (auto it = activeLights.begin(); it != activeLights.end(); ++it) {
        BSLight* entry = *it;
        if (entry) {
            NiPointer<BSLight> light(entry);
            QueueLightAdd(light);
        }
    }
    for (auto it = shadowLights.begin(); it != shadowLights.end(); ++it) {
        BSLight* entry = *it;
        if (entry) {
            NiPointer<BSLight> light(entry);
            QueueLightAdd(light);
        }
    }
    for (std::uint32_t i = 0; i < shadowCasterLights.iSize; ++i) {
        BSShadowLight* light = shadowCasterLights[i];
        if (light) {
            light->shadowmapIndex = 0xFF;
            shadowCasterLights[i] = nullptr;
        }
    }
}

// the out-of-line append of a light reference to a light array
template void BSTArray<NiPointer<BSLight>, BSTArrayHeapAllocator>::Add<BSLight*>(BSLight*);

// QueueLightRemoveByNode, QueueLightRemoveUnscoped: GUESS(low); no public name
void ShadowSceneNode::QueueLightRemoveByNode(NiLight* a_light)
{
    BSLight* light = FindActiveLight(a_light);
    if (light) {
        BSAutoLock lock(&lightQueueLock);
        lightQueueRemove.Append(light);
    }
}

void ShadowSceneNode::QueueLightRemoveUnscoped(BSLight* a_light)
{
    if (a_light) {
        BSAutoLock lock(&lightQueueLock);
        lightQueueRemove.Append(a_light);
    }
}

// EnableLight: CRASHLOGGER_PDB(59818@2026.10.24)
// g_minLightRadius, g_mainShadowSceneNode: GUESS(low); the smallest radius a light may have and the scene node that owns the focus
extern const float g_minLightRadius;
extern ShadowSceneNode* g_mainShadowSceneNode;

void ShadowSceneNode::EnableLight(BSLight* a_light)
{
    if (a_light->Unk_03()) {
        if (!portalGraph || !portalGraph->unk50) {
            return;
        }
    }
    NiLight* node = a_light->light;
    if ((node->flags & 1) || node->radius < g_minLightRadius) {
        a_light->ClearGeometryList();
        return;
    }
    a_light->portalGraph = portalGraph;
    bool focus = a_light->unk46 && this == g_mainShadowSceneNode;
    if (a_light->Unk_03()) {
        ShadowLightTail* tail = &static_cast<BSShadowLight*>(a_light)->tail;
        if (tail) {
            AttachShadowLight(a_light, tail, focus);
            return;
        }
    }
    AccumulateLights(a_light, 0, focus);
}
