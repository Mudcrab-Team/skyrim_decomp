// Source exposure: mixed (community headers; the pinned image listing).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Recipe: reconstruction/recipes/msvc-19.16.27054-o2.json
// 0xce0ed0 BGSTypedKeywordValueArray<2>::Clear
// Adapted bodies: BGSTypedKeywordValueArray<2>::Clear follows fo4-private@1b765c70 src/Shared/TESForms/Character/BGSKeyword.h:18
#include "BGSTypedKeywordValueArray_ce0ed0.h"

// The memory manager singleton is initialised on first use.
static inline void* MemoryManagerInstance()
{
    if (MemMgrGuard_369ac98 != 2u)
        MemMgrEnsure_cde810(MemMgrInst_369a810, &MemMgrGuard_369ac98);
    return MemMgrInst_369a810;
}

template <>
void BGSTypedKeywordValueArray<2>::Clear()
{
    BGSTypedKeywordValue<2>* pCurrent = pArray;
    MemMgrDeallocate_cde6a0(MemoryManagerInstance(), pCurrent, false);
    pArray = 0;
    uiSize = 0;
}
