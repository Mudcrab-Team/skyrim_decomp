// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xfddba0 NiAVObject::SetSelectiveUpdateTransformsRecursive
// Adapted bodies: none
#include "NiAVObject_fddba0.h"

void NiAVObject::SetSelectiveUpdateTransformsRecursive(NiAVObject* a_object)
{
    if (!a_object) {
        return;
    }
    a_object->flags = (a_object->flags & ~0x10u) | 0x6u;
    NiNode* node = a_object->AsNode();
    if (node) {
        for (std::uint32_t i = 0; i < node->childrenCount; ++i) {
            SetSelectiveUpdateTransformsRecursive(node->children[i]);
        }
    }
}
