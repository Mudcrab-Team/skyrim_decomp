// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: UpdateControllersRecursive2238b0, treated as adapted: shaped like a recursive scene node walk in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/unmapped/bhkrigidbody.cpp:2118
// SPDX-License-Identifier: CC0-1.0
// 0x2238b0 UpdateControllersRecursive2238b0
#include "FreeFunction_2238b0.h"

// Invoke slot 44 on each attached controller and recurse into child nodes.
void UpdateControllersRecursive2238b0(NiAVObject2238b0* obj)
{
    if (!obj)
    {
        return;
    }
    for (NiTimeController2238b0* ctrl = obj->controllers; ctrl; ctrl = ctrl->next)
    {
        ctrl->UpdateController();
    }
    NiNode2238b0* node = obj->AsNode();
    if (node)
    {
        for (std::uint32_t i = 0; i < node->childCount; ++i)
        {
            UpdateControllersRecursive2238b0(node->children[i]);
        }
    }
}
