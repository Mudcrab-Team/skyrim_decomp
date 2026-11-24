// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x14e70b0 NiNode::AsBSFadeNode
// Adapted bodies: none
#include "NiNode_14e70b0.h"

BSFadeNode* NiNode::AsBSFadeNode(NiNode* start)
{
    BSFadeNode* result = nullptr;
    for (NiNode* node = start; node; node = result ? nullptr : node->ParentNode()) {
        result = node->AsFadeNode();
    }
    return result;
}
