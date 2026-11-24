// Source exposure: mixed (sibling game-code body; the pinned image listing).
// Code origin: adapted from the sibling body listed in the header; names and prototypes as labelled there
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// CI hash: 0x12b7770 ?GetNewEntry@?$BSTScatterTableKernel@U?$BSTScatterTableTraits@PEBVNiAVObject@@PEBVBSISoundOutputModel@@UBSTScatterTableDefaultKVStorage@@U?$BSTScatterTableDefaultHashPolicy@PEBVNiAVObject@@@@U?$BSTScatterTableHeapAllocator@U?$BSTScatterTableEntry@PEBVNiAVObject@@PEBVBSISoundOutputModel@@UBSTScatterTableDefaultKVStorage@@@@@@$07@@@@QEAAPEAU?$BSTScatterTableEntry@PEBVNiAVObject@@PEBVBSISoundOutputModel@@UBSTScatterTableDefaultKVStorage@@@@PEAU2@@Z
// 0x12b7770 BSTScatterTableKernel<BSTScatterTableTraits<const NiAVObject*, const BSISoundOutputModel*, BSTScatterTableDefaultKVStorage, BSTScatterTableDefaultHashPolicy<const NiAVObject*>, BSTScatterTableHeapAllocator<BSTScatterTableEntry<const NiAVObject*, const BSISoundOutputModel*, BSTScatterTableDefaultKVStorage>>, 8>>::GetNewEntry
// Adapted bodies: BSTScatterTableKernel::GetNewEntry from fo4-private@1b765c70 src/BSCore/BSTScatterTable.h:228
#include "BSTScatterTableKernel_12b7770.h"

typedef BSTScatterTableEntry<const NiAVObject*, const BSISoundOutputModel*, BSTScatterTableDefaultKVStorage> SoundOutputEntry;
typedef BSTScatterTableTraits<const NiAVObject*, const BSISoundOutputModel*, BSTScatterTableDefaultKVStorage, BSTScatterTableDefaultHashPolicy<const NiAVObject*>, BSTScatterTableHeapAllocator<SoundOutputEntry>, 8> SoundOutputTraits;

template SoundOutputEntry* BSTScatterTableKernel<SoundOutputTraits>::GetNewEntry(SoundOutputEntry*);
