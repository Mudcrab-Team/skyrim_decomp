// Near miss: 13.0 alignment distance | control-flow
// Exposure detail: (community declarations; community-generated layouts; pinned-image observations).
// Source exposure: mixed
// Code origin: original; pinned-image observations and labelled declarations
// SPDX-License-Identifier: CC0-1.0
// NiNode, NiNode::FindAddonAttachPoint: CRASHLOGGER_PDB(59818@2026.10.24)
// Adapted bodies: none
// 0x2e6190 NiNode::FindAddonAttachPoint

#include "include/2e6190/NiNode_2e6190.h"

void NiNode::FindAddonAttachPoint(NiNode* root)
{
    if (!root)
        return;
    for (std::uint16_t index = 0; index < root->freeIndex; ++index) {
        NiAVObjectPrefix* child = root->children[index];
        if (!child)
            continue;
        NiNode* node = child->vtable->asNode(child);
        if (!node)
            continue;
        const NiRTTI* type = node->vtable->getRTTI(node);
        while (type && type != &addonType)
            type = type->baseRTTI;
        if (type)
            root->vtable->detachChildAt(root, index);
        else
            FindAddonAttachPoint(node);
    }
}
