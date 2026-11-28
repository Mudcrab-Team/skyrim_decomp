// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x223ed0 CountMatchingNodes223ed0
// Adapted bodies: none
#include "FreeFunction_223ed0.h"

// Count objects in a subtree, optionally excluding unnamed or prefix-matching nodes.
std::uint32_t CountMatchingNodes223ed0(NiAVObject223ed0* obj, bool filterPrefix)
{
    std::uint32_t count = 0;
    if (obj)
    {
        if (!filterPrefix || (obj->name && _strnicmp(obj->name, gPrefix223ed0, 5) != 0))
        {
            count = 1;
        }
        NiNode223ed0* node = obj->AsNode();
        if (node)
        {
            for (std::uint32_t i = 0; i < node->childCount; ++i)
            {
                count += CountMatchingNodes223ed0(node->children[i], filterPrefix);
            }
        }
    }
    return count;
}
