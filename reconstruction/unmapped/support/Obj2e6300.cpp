// Source exposure: mixed (pinned image listing; sibling source).
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: IsKindOf, treated as adapted: shaped like NiRTTI::IsKindOf in the sibling source cited below (CC0-1.0).
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/f3staging/f3blk_00560000_o2.cpp:19104
// SPDX-License-Identifier: CC0-1.0
// 0x2e6300 Obj2e6300::HasNonEmptyTarget
#include "Obj2e6300.h"

namespace
{
bool IsKindOf(const Obj2e6300* a_obj, const RTTI2e6300* a_target)
{
    for (const RTTI2e6300* rtti = a_obj->GetRTTI(); rtti != nullptr; rtti = rtti->m_parent)
    {
        if (rtti == a_target)
        {
            return true;
        }
    }
    return false;
}
}

// Guess: recursively check whether this node or any child node matches the target RTTI with non-zero count.
bool Obj2e6300::HasNonEmptyTarget(Obj2e6300* a_node)
{
    if (!a_node)
    {
        return false;
    }
    if (IsKindOf(a_node, &gRTTI2e6300) && a_node->m_count != 0)
    {
        return true;
    }
    for (std::uint32_t i = 0; i < a_node->m_capacity; ++i)
    {
        Obj2e6300* child = a_node->m_children[i];
        if (child)
        {
            Obj2e6300* childNode = child->AsNode();
            if (childNode && HasNonEmptyTarget(childNode))
            {
                return true;
            }
        }
    }
    return false;
}
