// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// 0x1570240 BSOrderedNode::CopyMembers
// Adapted bodies: none
#include "BSOrderedNode_1570240.h"

void BSOrderedNode::CopyMembers(BSOrderedNode* a_dest, NiCloningProcess& a_cloning)
{
    NiNode::CopyMembers(a_dest, a_cloning);
    const float radius = orderedBound.radius;
    NiPoint3& destCenter = a_dest->orderedBound.center;
    const NiPoint3& center = orderedBound.center;
    destCenter.x = center.x;
    destCenter.y = center.y;
    destCenter.z = center.z;
    a_dest->orderedBound.radius = radius;
    a_dest->useStaticBound = useStaticBound;
}
