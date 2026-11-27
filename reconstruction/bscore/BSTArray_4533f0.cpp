// Source exposure: mixed (sibling game-code body; the pinned image listing).
// Code origin: adapted from the sibling body listed in the header; names and prototypes as labelled there
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// CI hash: 0x4533f0 ?DestructItems@?$BSTArray@VObjectListItem@@VBSTArrayHeapAllocator@@@@QEAAXII@Z
// 0x4533f0 BSTArray<ObjectListItem, BSTArrayHeapAllocator>::DestructItems
// Adapted bodies: BSTArray::DestructItems from fo4-private@1b765c70 src/BSCore/BSTArray.h:447
#include "BSTArray_4533f0.h"

template void BSTArray<ObjectListItem, BSTArrayHeapAllocator>::DestructItems(unsigned int, unsigned int);
