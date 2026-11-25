// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original; BSTArray members adapted from the sibling body listed below
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// Sibling source: fo4-private@1b765c70 src/BSCore/BSTArray.h:425
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2-root-includes.json
// Adapted bodies: BSTArray::SetSize, Clear, ConstructDefaultItems, DestructItems from fo4-private@1b765c70 src/BSCore/BSTArray.h:425
// 0x155db00 BSTArray<ShadowmapDescriptor, BSTArrayHeapAllocator>::DestructItems
// CI hash: 0x155db00 ?DestructItems@?$BSTArray@UShadowmapDescriptor@@VBSTArrayHeapAllocator@@@@QEAAXII@Z
#include "BSShadowLight_Members.h"

ShadowmapDescriptor::~ShadowmapDescriptor() noexcept
{
}

template void BSTArray<ShadowmapDescriptor, BSTArrayHeapAllocator>::DestructItems(std::uint32_t, std::uint32_t);
