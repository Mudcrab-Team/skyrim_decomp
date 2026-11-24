// Source exposure: mixed (sibling source and pinned image listing).
// Code origin: original reconstruction shaped after the cited sibling method.
// Adapted bodies: BSOrderedNode::LoadBinary follows momusdigital/f3_decomp@f5bac1b5 src/bsshader/bsorderednode.cpp
// Sibling source: momusdigital/f3_decomp@f5bac1b5 src/bsshader/bsorderednode.cpp:6
// Recipe: reconstruction/recipes/o2-fpfast.json
// 0x15702b0 BSOrderedNode::LoadBinary
#include "BSOrderedNode_15702b0.h"

namespace
{
    std::uint32_t SetBit(std::uint32_t flags, unsigned int index, bool value)
    {
        const std::uint32_t mask = 1U << index;
        return value ? flags | mask : flags & ~mask;
    }
}

void BSOrderedNode::LoadBinary(NiStream& stream)
{
    NiNode::LoadBinary(stream);
    orderedBound.LoadBinary(stream);
    stream.iStr->Read(useStaticBound);
    flags = SetBit(flags, 13, useStaticBound && orderedBound.radius != 0.0f);
}
