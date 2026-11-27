// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Code origin: original reconstruction from the pinned image listing
// 0x1510db0 ShadowSceneNode::TestCachedAABBVisibility
// 0x1510c90 ShadowSceneNode::TestGeometryVisibility
// CI hash: 0x1510c90 ?TestGeometryVisibility@ShadowSceneNode@@QEAAXPEAUCullGeometryView@@PEBXPEAUPortalCullContext@@@Z
// CI hash: 0x1510db0 ?TestCachedAABBVisibility@ShadowSceneNode@@QEAAXPEAVCullBound@@PEBXPEAUPortalCullContext@@@Z
#include "ShadowSceneNode_Visibility.h"

// g_visibilityStamp: GUESS(low); the stamp the geometry visibility test leaves on an object
extern std::uint32_t g_visibilityStamp;

// TestCachedAABBVisibility: CRASHLOGGER_PDB(59818@2026.10.24)
// The cached bound state is 0 (unknown), 1 (visible) or 2 (hidden). A bound that sits inside the portal volumes is visible only while
// every room of the active portal graph that shares its kind also overlaps it.
void ShadowSceneNode::TestCachedAABBVisibility(CullBound* a_bound, const void* a_box, PortalCullContext* a_context)
{
    std::uint32_t state = a_bound->visibility;
    if (((a_context->mode - 1) & ~2u) == 0) {
        state = 1;
    } else if (state == 0) {
        std::uint32_t saved = a_context->savedState;
        bool inside = a_bound->Contains(a_context->bounds);
        a_bound->visibility = inside ? 1 : 2;
        if (inside && portalGraph) {
            PortalNode* node = portalGraph->rooms;
            state = 1;
            while (node) {
                PortalRoom* const& room = node->room;
                node = node->next;
                if (room && room->kind == state) {
                    if (!a_bound->Overlaps(a_box, a_context, room)) {
                        state = 2;
                        break;
                    }
                }
            }
        }
        a_context->savedState = saved;
    }
    a_bound->visibility = state;
}

// TestGeometryVisibility: GUESS(low); the geometry flavour of the cached bound test, which also leaves the stamp on the object
void ShadowSceneNode::TestGeometryVisibility(CullGeometryView* a_object, const void* a_box, PortalCullContext* a_context)
{
    CullBound* bound = a_object->shaderProperty->bound;
    std::uint32_t state = bound->visibility;
    if (((a_context->mode - 1) & ~2u) == 0) {
        state = 1;
    } else if (state == 0) {
        std::uint32_t saved = a_context->savedState;
        bool inside = bound->Contains(a_context->bounds);
        bound->visibility = inside ? 1 : 2;
        if (inside && portalGraph) {
            PortalNode* node = portalGraph->rooms;
            state = 1;
            while (node) {
                PortalRoom* const& room = node->room;
                node = node->next;
                if (room && room->kind == state) {
                    if (!bound->Overlaps(a_box, a_context, room)) {
                        state = 2;
                        break;
                    }
                }
            }
        }
        a_context->savedState = saved;
    }
    bound->visibility = state;
    a_object->visibilityStamp = g_visibilityStamp;
}
