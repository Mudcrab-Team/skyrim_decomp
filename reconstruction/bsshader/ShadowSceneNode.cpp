// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Code origin: original; the listing and community declarations, BSTArray and NiPointer shapes after the sibling
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
#include <intrin.h>
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
