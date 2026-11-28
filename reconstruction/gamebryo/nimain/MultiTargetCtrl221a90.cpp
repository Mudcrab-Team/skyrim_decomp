// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: MultiTargetCtrl221a90::ClearTargetsRecursive, treated as adapted: shaped like a recursive scene node walk in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00480000_o2.cpp:4668
// SPDX-License-Identifier: CC0-1.0
// 0x221a90 MultiTargetCtrl221a90::ClearTargetsRecursive
#include "MultiTargetCtrl221a90.h"

// Remove matching target pointers for a node and recursively process its children.
void MultiTargetCtrl221a90::ClearTargetsRecursive(NiAVObject221a90* obj)
{
    std::uint16_t index = GetTargetIndex(obj);
    if (index != kInvalidIndex221a90)
    {
        targets[index] = nullptr;
    }
    NiNode221a90* node = obj->AsNode();
    if (node)
    {
        for (std::uint32_t i = 0; i < node->childCount; ++i)
        {
            ClearTargetsRecursive(node->children[i]);
        }
    }
}
