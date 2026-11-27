// Source exposure: mixed (pinned image, sibling spelling and cited declarations).
// Code origin: original reconstruction from the pinned image, shaped after the cited sibling.
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xee23a0 NiNode::GetObjectByName
// Adapted bodies: NiNode::GetObjectByName follows momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nimain/ninode.cpp
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/gamebryo2.2/corelibs/nimain/ninode.cpp:7
// Adapted bodies: NiNode::GetObjectByName follows momusdigital/fnv_decomp@91e1b6e8 src/gamebryo2.2/corelibs/nimain/ninode.cpp
// Sibling source: momusdigital/fnv_decomp@91e1b6e8 src/gamebryo2.2/corelibs/nimain/ninode.cpp:124
#include "NiNode_ee23a0.h"

NiAVObject* NiNode::GetObjectByName(const BSFixedString& name)
{
    NiAVObject* result = NiAVObject::GetObjectByName(name);
    if (result)
        return result;
    for (std::uint32_t i = 0; i < children.GetFreeIndex(); ++i)
    {
        NiAVObject* child = children[i];
        if (child)
        {
            result = child->GetObjectByName(name);
            if (result)
                return result;
        }
    }
    return nullptr;
}
