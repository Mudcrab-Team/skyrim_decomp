// Source exposure: mixed (sibling game-code body; the pinned image listing).
// Code origin: adapted from the sibling body listed in the header; names and prototypes as labelled there
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// CI hash: 0x582580 ?ConstructDefaultItems@?$BSTArray@UTransientRefData@Manager@Explosion@@VBSTArrayHeapAllocator@@@@QEAAXII@Z
// 0x582580 BSTArray<Explosion::Manager::TransientRefData, BSTArrayHeapAllocator>::ConstructDefaultItems
// Adapted bodies: BSTArray::ConstructDefaultItems from fo4-private@1b765c70 src/BSCore/BSTArray.h:427
#include "BSTArray_582580.h"

template void BSTArray<Explosion::Manager::TransientRefData, BSTArrayHeapAllocator>::ConstructDefaultItems(unsigned int, unsigned int);
