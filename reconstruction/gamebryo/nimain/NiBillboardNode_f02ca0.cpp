// Source exposure: mixed (pinned image and cited public declarations).
// Code origin: original scene data and material methods based on the pinned image.
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// 0xf02ca0 NiBillboardNode::CopyMembers
// 0xf02ce0 NiBillboardNode::LoadBinary
// 0xf02d60 NiBillboardNode::SaveBinary
// Adapted bodies: none
#include "NiBillboardNode_f02ca0.h"

void CopyNodeMembers(NiNode& source, NiNode* dest);

void NiBillboardNode::CopyMembers(NiBillboardNode* dest)
{
    CopyNodeMembers(*this, dest);
    dest->mode = mode;
}

void NiBillboardNode::LoadBinary(NiStream& stream)
{
    NiNode::LoadBinary(stream);
    auto* binary = stream.iStr;
    std::uint32_t width = sizeof(mode);
    using ReadFn = std::uint32_t(NiBinaryStream*, void*, std::uint32_t, std::uint32_t*, std::uint32_t);
    const auto count = reinterpret_cast<ReadFn*>(binary->_readFn)(binary, &mode, sizeof(mode), &width, 1);
    binary->_absoluteCurrentPos += count;
}

void NiBillboardNode::SaveBinary(NiStream& stream)
{
    NiNode::SaveBinary(stream);
    auto* binary = stream.oStr;
    std::uint32_t width = sizeof(mode);
    binary->binary_write(&mode, sizeof(mode), &width);
}
