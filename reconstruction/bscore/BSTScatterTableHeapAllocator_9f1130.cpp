// Source exposure: mixed (sibling game-code body; the pinned image listing).
// Code origin: adapted from the sibling bodies listed in the header; names and prototypes as labelled there
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// CI hash: 0x9f1130 ?Allocate@?$BSTScatterTableHeapAllocator@U?$BSTScatterTableEntry@PEBVNiAVObject@@PEBVBSISoundOutputModel@@UBSTScatterTableDefaultKVStorage@@@@@@QEBAPEAU?$BSTScatterTableEntry@PEBVNiAVObject@@PEBVBSISoundOutputModel@@UBSTScatterTableDefaultKVStorage@@@@I@Z
// 0x9f1130 BSTScatterTableHeapAllocator<BSTScatterTableEntry<const NiAVObject*, const BSISoundOutputModel*, BSTScatterTableDefaultKVStorage>>::Allocate
// Adapted bodies: BSTScatterTableHeapAllocator::Allocate from fo4-private@1b765c70 src/BSCore/BSTScatterTable.h:145
#include "BSTScatterTableHeapAllocator_9f1130.h"

template BSTScatterTableEntry<const NiAVObject*, const BSISoundOutputModel*, BSTScatterTableDefaultKVStorage>*
BSTScatterTableHeapAllocator<BSTScatterTableEntry<const NiAVObject*, const BSISoundOutputModel*, BSTScatterTableDefaultKVStorage>>::Allocate(unsigned int) const;
