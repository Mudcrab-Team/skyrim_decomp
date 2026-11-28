// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x2263c0 FindGeomAtIndex2263c0
// Adapted bodies: none
#include "FreeFunction_2263c0.h"

// Return the matching geometry node at the given pre-order index in a subtree.
NiAVObject2263c0* FindGeomAtIndex2263c0(NiAVObject2263c0* obj, std::uint32_t& remaining, bool excludePrefixA, bool requirePrefixB)
{
    if (!obj)
    {
        return nullptr;
    }
    if (obj->AsGeometry())
    {
        if ((!excludePrefixA || (obj->name && _strnicmp(obj->name, gPrefixA2263c0, 5) != 0)) &&
            (!requirePrefixB || _strnicmp(obj->name, gPrefixB2263c0, 7) == 0))
        {
            if (remaining == 0)
            {
                return obj;
            }
            --remaining;
        }
    }
    NiNode2263c0* node = obj->AsNode();
    if (node)
    {
        for (std::uint32_t i = 0; i < node->childCount; ++i)
        {
            NiAVObject2263c0* child = node->children[i];
            NiAVObject2263c0* found = FindGeomAtIndex2263c0(child, remaining, excludePrefixA, requirePrefixB);
            if (found)
            {
                return found;
            }
        }
    }
    return nullptr;
}
