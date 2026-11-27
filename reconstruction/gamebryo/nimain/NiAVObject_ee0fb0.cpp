// Source exposure: mixed (pinned-image observations; community declarations).
// Code origin: original; handwritten reconstruction from target observations
// SPDX-License-Identifier: CC0-1.0
// 0xee0fb0 NiAVObject::SavePreviousWorldTransformRecursive
// Adapted bodies: none
#include "NiAVObject_ee0fb0.h"

void NiAVObject::SavePreviousWorldTransformRecursive()
{
    flags02 |= 0x40;
    previousWorld = world;
    NiNode* node = AsNode();
    if (node) {
        // The child count is cached; it is not re-read on each iteration.
        const std::ptrdiff_t count = node->children.freeIdx;
        if (count > 0) {
            std::ptrdiff_t i = 0;
            do {
                NiAVObject* child = node->children.data[i];
                if (child) {
                    child->SavePreviousWorldTransformRecursive();
                }
                ++i;
            } while (i < count);
        }
    }
}
