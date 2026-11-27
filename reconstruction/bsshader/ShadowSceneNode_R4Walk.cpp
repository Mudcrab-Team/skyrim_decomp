// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Code origin: original reconstruction from the pinned image listing; the IsKindOf helper matches a CC0 sibling body
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_007c0000_o2.cpp:13697
// 0x150cd30 ShadowSceneNode::AddLightsBelow
// Adapted bodies: IsKindOf
#include "ShadowSceneNode_R4Walk.h"

// IsKindOf: GUESS(low); the walk up the run-time type chain
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

// AddLightsBelow: GUESS(low); adds every light under a node and returns how many it found
std::uint32_t ShadowSceneNode::AddLightsBelow(NiNode* a_node, float a_radius)
{
    std::uint32_t count = 0;
    NiNodeChildren& kids = static_cast<NiNodeView*>(static_cast<NiAVObject*>(a_node))->children;
    for (std::uint32_t i = 0; i < kids.emptyRunStart; ++i) {
        NiAVObject* child = kids.data[i];
        if (!child) {
            continue;
        }
        NiNode* node = child->AsNode();
        if (node) {
            count += AddLightsBelow(node, a_radius);
            continue;
        }
        NiAVObject* object = IsKindOf(reinterpret_cast<const NiRTTIView*>(child->GetRTTI()), &g_niLightRTTI) ? child : nullptr;
        if (!object) {
            continue;
        }
        NiLight* light = reinterpret_cast<NiLight*>(object);
        LIGHT_CREATE_PARAMS params;
        params.unk00 = 1;
        AddLight(light, &params);
        UpdateTimeFlags data{};
        light->UpdateObjectUpwards(&data);
        LightRadiusView* view = IsKindOf(reinterpret_cast<const NiRTTIView*>(object->GetRTTI()), &g_lightRadiusRTTI)
            ? reinterpret_cast<LightRadiusView*>(object)
            : nullptr;
        if (view) {
            view->radius = FocusPoint(a_radius, 0.0f, 0.0f);
        }
        ++count;
    }
    return count;
}
