// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0xff33c0 BSMultiBoundNode::FindAncestorOfType
// Adapted bodies: none
#include "BSMultiBoundNode_ff33c0.h"

static bool IsOfType(const NiAVObjectStandIn* a_object)
{
    return a_object && a_object->GetRTTI() == &kRTTI;
}

NiAVObjectStandIn* BSMultiBoundNode::FindAncestorOfType(NiAVObjectStandIn* a_object)
{
    NiAVObjectStandIn* node = a_object;
    while (node && !IsOfType(node)) {
        node = node->parent;
    }
    if (IsOfType(node)) {
        return node;
    }
    return nullptr;
}
