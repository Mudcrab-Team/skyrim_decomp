// Source exposure: mixed (sibling game-code body; the pinned image listing).
// Code origin: adapted from the sibling body listed in the header; names and prototypes as labelled there
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// CI hash: 0x62e7f0 ?DestructItems@?$BSTArray@UHolotapeSaveData@@VBSTArrayHeapAllocator@@@@QEAAXII@Z
// 0x62e7f0 BSTArray<HolotapeSaveData, BSTArrayHeapAllocator>::DestructItems
// Adapted bodies: BSTArray::DestructItems from fo4-private@1b765c70 src/BSCore/BSTArray.h:447
#include "BSTArray_62e7f0.h"

template void BSTArray<HolotapeSaveData, BSTArrayHeapAllocator>::DestructItems(unsigned int, unsigned int);
