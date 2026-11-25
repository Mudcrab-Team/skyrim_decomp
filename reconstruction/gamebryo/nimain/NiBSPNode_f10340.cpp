// Source exposure: mixed (community names; pinned-image observations).
// Code origin: original; pinned-image observations and labelled naming sources
// SPDX-License-Identifier: CC0-1.0
// 0xf10340 NiBSPNode::IsEqual
// Adapted bodies: none
// Recipe: reconstruction/recipes/o2-fpfast.json
#include "NiBSPNode_f10340.h"
bool NiBSPNode::IsEqual(NiObject* other)
{
    if (!NiNode::IsEqual(other))
        return false;
    const auto* node = reinterpret_cast<const NiBSPNode*>(other);
    if (modelPlane[0] != node->modelPlane[0] ||
        modelPlane[1] != node->modelPlane[1] ||
        modelPlane[2] != node->modelPlane[2] ||
        modelPlane[3] != node->modelPlane[3])
        return false;
    return true;
}
