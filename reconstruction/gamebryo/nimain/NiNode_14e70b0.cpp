// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0x14e70b0 NiNode::AsBSFadeNode
// Adapted bodies: none
#include "NiNode_14e70b0.h"

BSFadeNode* NiNode::AsBSFadeNode()
{
    BSFadeNode* result = nullptr;
    for (NiNode* node = this; node; node = result ? nullptr : node->GetParent()) {
        result = node->AsFadeNode();
    }
    return result;
}
