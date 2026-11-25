// Near miss: 11.75 alignment distance | control-flow
// Exposure detail: (pinned-image observations; community declarations).
// Source exposure: mixed
// Code origin: original; handwritten reconstruction from target observations
// SPDX-License-Identifier: CC0-1.0
// Adapted bodies: none
// 0xee0fb0 NiAVObject::SavePreviousWorldTransformRecursive

#include "include/ee0fb0/NiAVObject_ee0fb0.h"

void NiAVObject::SavePreviousWorldTransformRecursive()
{
    flags02 |= 0x40;
    previousWorld = world;
    NiNode* node = AsNode();
    if (node) {
        { std::ptrdiff_t i = 0; while (node->children.freeIdx > i) {
            NiAVObject* child;
            child = node->children.data[i];
            if (child != 0) {
                child->SavePreviousWorldTransformRecursive();
            } ++i;
        } }
    }
}
