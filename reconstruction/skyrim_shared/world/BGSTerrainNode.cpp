// Source exposure: mixed (community headers; the pinned image listing).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// SPDX-License-Identifier: GPL-3.0-or-later (powerof3/CommonLibSSE declarations; full text: licenses/CommonLibSSE-GPL-3.0.txt)
// Code origin: original reconstruction from the pinned image listing; class names and member
// layout from the pinned community headers, marked with labels below. No game bytes are stored here.
// 0x5188b0 BGSTerrainNode::UnloadDataRecurse
// 0x519dd0 BGSTerrainNode::IsWithinObjectLevel0Distance
// 0x519e00 BGSTerrainNode::IsWithinObjectLevel1Distance
// IsWithinObjectLevel0Distance, IsWithinObjectLevel1Distance, UnloadDataRecurse, UnloadData,
// objectLevel0Distance, objectLevel1Distance: GUESS(low)
// Adapted bodies: none; every body was derived from its own listing.
#include "BGSTerrainNode.h"

// Unload this node's data, then recurse into each of the four child nodes.
void BGSTerrainNode::UnloadDataRecurse(std::uint32_t flags)
{
    if ((nodeState & 0x1) == 0) {
        UnloadData(flags);
    }

    if ((flags & 0x2) != 0) {
        nodeState = (nodeState & 0xFFFFFE3F) | 0x20;
    }

    if ((flags & 0x4) != 0) {
        nodeState = (nodeState & 0xFFFFF3FF) | 0x200;
    }

    // The listing compares the child index with a signed less-than, so the bound is signed.
    for (std::uint32_t i = 0; static_cast<std::int32_t>(i) < 4; ++i) {
        if (children != nullptr) {
            BGSTerrainNode* child = &children[i];
            if (child != nullptr) {
                child->UnloadDataRecurse(flags);
            }
        }
    }
}

// True when the object level-0 distance reported by the callee is below the global threshold.
bool BGSTerrainNode::IsWithinObjectLevel0Distance() const
{
    return Function51a6e0() < objectLevel0Distance;
}

// True when the object level-1 distance reported by the callee is below the level-1 global threshold.
bool BGSTerrainNode::IsWithinObjectLevel1Distance() const
{
    return Function51a6e0() < objectLevel1Distance;
}
