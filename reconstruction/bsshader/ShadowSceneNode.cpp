// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Code origin: original; the listing and community declarations, BSTArray and NiPointer shapes after the sibling; the added functions are original from the listing
// Adapted bodies: BSSpinLock::Unlock (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/B/BSAtomic.cpp, MIT) inlined
// 0x150ff00 ShadowSceneNode::ClearShadowCasterArray
// 0x150fee0 ShadowSceneNode::GetShadowCasterLightArrayEntry
// 0x150f830 ShadowSceneNode::GetActiveLightAt
// 0x150f8b0 ShadowSceneNode::GetShadowCasterLightByIndex
// 0x150f710 ShadowSceneNode::FindActiveLight
// 0x150f7b0 ShadowSceneNode::FindQueuedAddLight
// 0x150fe20 ShadowSceneNode::CountLitShadowLights
// 0x150c7b0 ShadowSceneNode::AddLight(NiLight*, bool)
// 0x150f340 ShadowSceneNode::ClearLights_Flagged
// 0x150e300 ShadowSceneNode::TryQueueLightRemove
// 0x1511f00 ShadowSceneNode::ClearShadowLightShadowmaps
// 0x1511f80 ShadowSceneNode::UnlinkLightFromPortalGraph
// 0x1511ff0 ShadowSceneNode::UnlinkChildLights
// 0x150cb10 ShadowSceneNode::AddLight(BSLight*)
// 0x150cff0 ShadowSceneNode::RemoveLightByNode
// 0x1516b90 ShadowSceneNode::CollectLightingShaderGeometry
// 0x1516f50 ShadowSceneNode::CollectLitGeometry
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
#include "ShadowSceneNode.h"

// GeometryVisit, VisitGeometry, CollectLitGeometryCallback: GUESS(low); the traversal helpers the two collectors forward to
struct GeometryVisit
{
    void* visitor;
    bool includeShaders;
    bool includeLit;
};
void VisitGeometry(ShadowSceneNode* a_node, GeometryVisit* a_visit);
void VisitGeometryWithCallback(ShadowSceneNode* a_node, void (*a_callback)());
void CollectLitGeometryCallback();

// ShadowSceneNode::ClearShadowCasterArray, GetShadowCasterLightArrayEntry, GetActiveLightAt, GetShadowCasterLightByIndex, FindActiveLight: CRASHLOGGER_PDB(59818@2026.10.24)
// FindQueuedAddLight, CountLitShadowLights: GUESS(low); no public name
void ShadowSceneNode::ClearShadowCasterArray()
{
    for (std::uint32_t i = 0; i < shadowCasterLights.iSize; ++i) {
        BSShadowLight* light = shadowCasterLights[i];
        if (light) {
            light->shadowmapIndex = 0xFF;
            shadowCasterLights[i] = nullptr;
        }
    }
}

BSShadowLight* ShadowSceneNode::GetShadowCasterLightArrayEntry(std::uint32_t a_index)
{
    return shadowCasterLights[a_index];
}

BSLight* ShadowSceneNode::GetActiveLightAt(std::uint32_t a_index)
{
    BSLight* result = nullptr;
    std::uint32_t i = 0;
    for (auto it = activeLights.begin(); it != activeLights.end() && !result; ++it) {
        if (a_index == i++) {
            result = *it;
        }
    }
    return result;
}

BSLight* ShadowSceneNode::GetShadowCasterLightByIndex(std::uint32_t a_index)
{
    BSLight* result = nullptr;
    std::uint32_t i = 0;
    for (auto it = shadowLights.begin(); it != shadowLights.end() && !result; ++it) {
        if (a_index == i++) {
            result = *it;
        }
    }
    return result;
}

BSLight* ShadowSceneNode::FindActiveLight(NiLight* a_light)
{
    for (auto it = activeLights.begin(); it != activeLights.end(); ++it) {
        BSLight* entry = *it;
        if (entry && entry->light == a_light) {
            return entry;
        }
    }
    for (auto it = shadowLights.begin(); it != shadowLights.end(); ++it) {
        BSLight* entry = *it;
        if (entry && entry->light == a_light) {
            return entry;
        }
    }
    return nullptr;
}

BSLight* ShadowSceneNode::FindQueuedAddLight(NiLight* a_light)
{
    BSLight* result = nullptr;
    for (auto it = queuedAdd.begin(); it != queuedAdd.end() && !result; ++it) {
        BSLight* entry = *it;
        if (entry && entry->light == a_light) {
            result = entry;
        }
    }
    return result;
}

std::uint16_t ShadowSceneNode::CountLitShadowLights()
{
    std::uint16_t count = 0;
    for (auto it = activeLights.begin(); it != activeLights.end(); ++it) {
        BSLight* entry = *it;
        if (entry && entry->frustumCull != 0xFF) {
            ++count;
        }
    }
    return count;
}

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

BSLight* ShadowSceneNode::AddLight(NiLight* a_light, bool a_flag)
{
    LIGHT_CREATE_PARAMS params;
    params.unk00 = a_flag;
    return AddLight(a_light, &params);
}

// ClearLights_Flagged: CRASHLOGGER_PDB(59818@2026.10.24)
void ShadowSceneNode::ClearLights_Flagged(bool a_clear, bool a_keepArrays)
{
    if (a_clear) {
        for (auto it = activeLights.begin(); it != activeLights.end(); ++it) {
            BSLight* entry = *it;
            if (entry) {
                QueueLightRemove(entry);
            }
        }
        if (!a_keepArrays) {
            ClearLightArrays();
        }
    }
}

// QueueLightRemove, QueueLightAdd, AttachObject: not compared here; each reads the thread-local memory context, whose
// relocation the published target layout cannot express
// QueueLightRemove: CRASHLOGGER_PDB(59818@2026.10.24)
void ShadowSceneNode::QueueLightRemove(BSLight* a_light)
{
    if (a_light) {
        BSAutoLock lock(&lightQueueLock);
        MemoryContextScope scope(0x41);
        lightQueueRemove.Append(a_light);
    }
}

// TryQueueLightRemove: CRASHLOGGER_PDB(59818@2026.10.24)
void ShadowSceneNode::TryQueueLightRemove(NiLight* a_light)
{
    BSLight* light = FindActiveLight(a_light);
    if (light) {
        QueueLightRemove(light);
    }
}

// AttachObject: CRASHLOGGER_PDB(59818@2026.10.24)
void ShadowSceneNode::AttachObject(NiAVObject* a_object)
{
    if (a_object) {
        // NiAVObject::flags at 0xF4: COMMUNITY(CharmedBaryon/CommonLibSSE-NG@b93280e, MIT)
        if (!(a_object->unknown30[0xF4 - 0x30] & 1)) {
            BSAutoLock lock(&objectListLock);
            MemoryContextScope scope(0x20);
            particleNodes.Append(a_object);
        }
    }
}

void ShadowSceneNode::ClearShadowLightShadowmaps()
{
    if (shadowDirLight) {
        shadowDirLight->Unk_0C();
    }
    for (auto it = shadowLights.begin(); it != shadowLights.end(); ++it) {
        BSLight* entry = *it;
        if (entry) {
            static_cast<BSShadowLight*>(entry)->Unk_0C();
        }
    }
}

// UnlinkLightFromPortalGraph: CRASHLOGGER_PDB(59818@2026.10.24)
void ShadowSceneNode::UnlinkLightFromPortalGraph(NiAVObject* a_object)
{
    if (a_object->AsGeometry()) {
        ShaderPropertyView* property = static_cast<GeometryView*>(a_object)->shaderProperty;
        if (property && property->lightData) {
            property->lightData->RemoveGeometryFromLights(a_object);
        }
    } else {
        NiNode* node = a_object->AsNode();
        if (node) {
            UnlinkChildLights(node);
        }
    }
}

// UnlinkChildLights: CRASHLOGGER_PDB(59818@2026.10.24)
void ShadowSceneNode::UnlinkChildLights(NiNode* a_node)
{
    NiNodeChildren& kids = static_cast<NiNodeView*>(static_cast<NiAVObject*>(a_node))->children;
    for (std::uint32_t i = 0; i < kids.emptyRunStart; ++i) {
        NiAVObject* child = kids.data[i];
        if (child) {
            if (child->AsGeometry()) {
                ShaderPropertyView* property = static_cast<GeometryView*>(child)->shaderProperty;
                if (property && property->lightData) {
                    property->lightData->RemoveGeometryFromLights(child);
                }
            } else {
                NiNode* node = child->AsNode();
                if (node) {
                    UnlinkChildLights(node);
                }
            }
        }
    }
}

// RemoveLightByNode: GUESS(low); the CrashLogger name for this address is AddLight
void ShadowSceneNode::RemoveLightByNode(NiLight* a_light)
{
    if (a_light && allowLightRemoveQueues) {
        for (auto it = activeLights.begin(); it != activeLights.end(); ++it) {
            BSLight* entry = *it;
            if (entry && entry->light == a_light) {
                QueueLightAdd(entry);
                return;
            }
        }
        for (auto it = shadowLights.begin(); it != shadowLights.end(); ++it) {
            BSLight* entry = *it;
            if (entry && entry->light == a_light) {
                QueueLightAdd(entry);
                return;
            }
        }
    }
}

// QueueLightAdd: CRASHLOGGER_PDB(59818@2026.10.24)
void ShadowSceneNode::QueueLightAdd(const NiPointer<BSLight>& a_light)
{
    if (a_light.m_pObject && allowLightRemoveQueues) {
        BSAutoLock lock(&lightQueueLock);
        MemoryContextScope scope(0x1D);
        queuedRemove.Add(a_light);
    }
}

// AddLight: CRASHLOGGER_PDB(59818@2026.10.24)
void ShadowSceneNode::AddLight(BSLight* a_light)
{
    BSAutoLock lock(&lightQueueLock);
    queuedAdd.Add(a_light);
    a_light->portalGraph = portalGraph;
}

// CollectLightingShaderGeometry: CRASHLOGGER_PDB(59818@2026.10.24)
void ShadowSceneNode::CollectLightingShaderGeometry(void* a_visitor)
{
    GeometryVisit visit;
    visit.visitor = a_visitor;
    visit.includeShaders = true;
    visit.includeLit = true;
    VisitGeometry(this, &visit);
}

// CollectLitGeometry: GUESS(low); no public name
void ShadowSceneNode::CollectLitGeometry()
{
    VisitGeometryWithCallback(this, &CollectLitGeometryCallback);
}

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
