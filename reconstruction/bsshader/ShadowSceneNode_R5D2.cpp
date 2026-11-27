// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Code origin: original; the listing and community declarations
// Adapted bodies: none
// 0x150c280 ShadowSceneNode::OnVisible
#include "ShadowSceneNode_R5D2.h"
#include <cstring>

// OnVisible: CRASHLOGGER_PDB(59818@2026.10.24)
void ShadowSceneNode::OnVisible(BSCullingProcess& a_process, std::uint32_t a_flags)
{
    a_process.Prepare();
    NiCamera* camera = a_process.camera;
    g_cullSceneGraphIndex = sceneGraphIndex;
    g_cullCamera = camera;
    g_cullBlendValue = (g_cullBlendEnd - g_cullBlendStart) * g_cullBlendScale + g_cullBlendStart;
    if (portalGraph) {
        if (g_memoryManagerGuard != 2) {
            InitMemoryManager(&g_memoryManager, &g_memoryManagerGuard);
        }
        ScrapHeap* heap = g_memoryManager.GetThreadScrapHeap(0);
        std::uint8_t* wasCulled = nullptr;
        if (portalGraph->GetAlwaysRenderCount()) {
            wasCulled = static_cast<std::uint8_t*>(heap->Allocate(portalGraph->GetAlwaysRenderCount(), 8));
            std::memset(wasCulled, 0, portalGraph->GetAlwaysRenderCount());
            for (std::uint32_t i = 0; i < portalGraph->GetAlwaysRenderCount(); ++i) {
                CullableObject* object = portalGraph->GetAlwaysRenderAt(i);
                if (object) {
                    wasCulled[i] = object->flags & 1;
                    object->flags |= 1;
                }
            }
        }
        if (CullableObject* root = portalGraph->unk70) {
            root->flags |= 1;
        }

        BSCompoundFrustumCache* cache = a_process.unk30190;
        if ((cache && cache->openAllowed) || a_process.cullMode == 1 || a_process.cullMode == 3) {
            BaseOnVisible(a_process, a_flags);
            BSTArray<BSMultiBoundRoom*>* rooms = &a_process.unk30190->rooms;
            if (a_process.cullMode == 1 || a_process.cullMode == 3) {
                rooms = &portalGraph->rooms;
            }
            auto it = rooms->begin();
            // built and destroyed around the walk; nothing reads it
            BSCompoundFrustum frustum;
            while (it != rooms->end()) {
                BSMultiBoundRoom* room = *it;
                ++it;
                NiTPointerList<BSPortal*>* portals = room ? &room->portals : &portalGraph->unk28;
                if (portals->count) {
                    NiTListItem<BSPortal*>* pos = portals->head;
                    while (pos) {
                        BSPortal* portal = portals->GetNext(pos);
                        if (portal && a_process.TestSharedNode(portal->portalSharedNode)) {
                            portal->portalSharedNode->OnVisible(a_process, 0xFFFFFFFF);
                        }
                    }
                }
                a_process.unk301A0 = nullptr;
            }
        } else {
            for (auto it = cache->rooms.begin(); it != a_process.unk30190->rooms.end();) {
                BSMultiBoundRoom* room = *it;
                ++it;
                if (!room) {
                    continue;
                }
                room->OnVisible(a_process, 0xFFFFFFFF);
                if (room->portals.count) {
                    NiTListItem<BSPortal*>* pos = room->portals.head;
                    while (pos) {
                        BSPortal* portal = room->portals.GetNext(pos);
                        if (portal && a_process.TestSharedNode(portal->portalSharedNode)) {
                            BSCompoundFrustum* shared = BuildSharedCompoundFrustum(&a_process, portal);
                            if (shared) {
                                a_process.unk30190->Insert(portal->portalSharedNode, shared);
                            }
                            portal->portalSharedNode->OnVisible(a_process, 0xFFFFFFFF);
                        }
                    }
                }
                a_process.unk301A0 = nullptr;
            }
            NiNodeChildren& kids = static_cast<NiNodeView*>(static_cast<NiAVObject*>(this))->children;
            for (std::uint32_t i = 4; i < kids.emptyRunStart; ++i) {
                CullableObject* child = reinterpret_cast<CullableObject*>(kids.data[i]);
                if (child) {
                    child->Cull(a_process, 0xFFFFFFFF);
                }
            }
        }

        for (std::uint32_t i = 0; i < portalGraph->GetAlwaysRenderCount(); ++i) {
            CullableObject* object = portalGraph->GetAlwaysRenderAt(i);
            if (object && !wasCulled[i]) {
                object->flags &= ~1u;
                object->Cull(a_process, 0xFFFFFFFF);
            }
        }
        if (CullableObject* root = portalGraph->unk70) {
            root->flags &= ~1u;
        }
        heap->Deallocate(wasCulled);
    } else {
        BaseOnVisible(a_process, a_flags);
    }
}
