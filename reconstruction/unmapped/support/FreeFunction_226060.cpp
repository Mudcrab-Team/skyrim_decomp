// Source exposure: binary-analysis
// Code origin: original reconstruction from the pinned image listing
// SPDX-License-Identifier: CC0-1.0
// 0x226060 FindNodeAtIndex226060
// Adapted bodies: none
#include "FreeFunction_226060.h"

// Return the node at the given pre-order index among matching subtree nodes.
NiAVObject226060* FindNodeAtIndex226060(NiAVObject226060* obj, std::uint32_t& remaining, bool filterPrefix)
{
    if (!obj)
    {
        return nullptr;
    }
    if (!filterPrefix || (obj->name && _strnicmp(obj->name, gPrefix226060, 5) != 0))
    {
        if (remaining == 0)
        {
            return obj;
        }
        --remaining;
    }
    NiNode226060* node = obj->AsNode();
    if (node)
    {
        for (std::uint32_t i = 0; i < node->childCount; ++i)
        {
            NiAVObject226060* child = node->children[i];
            NiAVObject226060* found = FindNodeAtIndex226060(child, remaining, filterPrefix);
            if (found)
            {
                return found;
            }
        }
    }
    return nullptr;
}
