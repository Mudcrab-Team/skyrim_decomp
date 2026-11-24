// Source exposure: mixed (sibling game-code body; the pinned image listing).
// Code origin: adapted from the sibling body listed in the header; names and prototypes as labelled there
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// CI hash: 0x11dcb00 ?DestructItems@?$BSTArray@VBSPathingNode@@VBSScrapArrayAllocator@@@@QEAAXII@Z
// 0x11dcb00 BSTArray<BSPathingNode, BSScrapArrayAllocator>::DestructItems
// Adapted bodies: BSTArray::DestructItems from fo4-private@1b765c70 src/BSCore/BSTArray.h:447
#include "BSTArray_11dcb00.h"

template void BSTArray<BSPathingNode, BSScrapArrayAllocator>::DestructItems(unsigned int, unsigned int);
