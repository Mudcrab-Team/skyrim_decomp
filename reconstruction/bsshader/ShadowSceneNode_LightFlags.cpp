// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Code origin: original reconstruction from the pinned image listing; the type-chain walk is adapted from the sibling
// Adapted bodies: IsKindOf (momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_007c0000_o2.cpp:13697, CC0-1.0)
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_007c0000_o2.cpp:13697 (run-time type walk)
// 0x15120a0 ShadowSceneNode::SetLightNodeFlags
// CI hash: 0x15120a0 ?SetLightNodeFlags@ShadowSceneNode@@QEAAXPEAVNiNode@@_N1@Z
#include "ShadowSceneNode_LightFlags.h"

// IsKindOf: GUESS(low); the walk up the run-time type chain, shaped after the sibling body named above
static bool IsKindOf(const NiRTTIView* a_type, const NiRTTIView* a_base)
{
    while (a_type) {
        if (a_type == a_base) {
            return true;
        }
        a_type = a_type->base;
    }
    return false;
}

// SetLightNodeFlags: GUESS(low); no public name
void ShadowSceneNode::SetLightNodeFlags(NiNode* a_node, bool a_set, bool a_remove)
{
    NiNodeChildren& kids = static_cast<NiNodeView*>(static_cast<NiAVObject*>(a_node))->children;
    std::uint16_t count = kids.emptyRunStart;
    for (std::uint16_t i = 0; i < count; ++i) {
        NiAVObject* child = kids.data[i];
        if (child) {
            if (IsKindOf(reinterpret_cast<const NiRTTIView*>(child->GetRTTI()), &g_niLightRTTI)) {
                ObjectFlagsView* view = reinterpret_cast<ObjectFlagsView*>(child);
                if (a_set) {
                    view->flags |= 1;
                } else {
                    view->flags &= ~1u;
                }
                if (a_remove) {
                    RemoveLightByNode(reinterpret_cast<NiLight*>(child));
                }
            } else if (child->AsNode()) {
                SetLightNodeFlags(static_cast<NiNode*>(child), a_set, a_remove);
            }
        }
    }
}
