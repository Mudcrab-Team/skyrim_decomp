// Source exposure: mixed (sibling game-code names and body; compared function from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/BSCore/BSTScatterTable.h:228
// BSTScatterTableKernel, BSTScatterTableTraits, BSTScatterTableEntry, BSTScatterTableDefaultKVStorage, BSTScatterTableDefaultHashPolicy, BSTScatterTableHeapAllocator, GetNewEntry, EntryType, Key, Value, uiSize, uiFree, uiLastFree, pNext: SIBLING(fo4-private@1b765c70, author-permission) STANDIN; declarations
// NiAVObject, BSISoundOutputModel, unk00: GUESS(low)
#pragma once

class NiAVObject;
class BSISoundOutputModel;

template <class K, class V>
struct BSTScatterTableDefaultKVStorage
{
    K Key;
    V Value;
};

template <class K, class V, template <class, class> class KVPolicy>
struct BSTScatterTableEntry : public KVPolicy<K, V>
{
    BSTScatterTableEntry* pNext;
};

template <class K>
struct BSTScatterTableDefaultHashPolicy
{
};

template <class T>
struct BSTScatterTableHeapAllocator
{
};

template <class K, class V, template <class, class> class KVPolicy, class HashPolicy, class AllocPolicy, unsigned int N>
struct BSTScatterTableTraits
{
    typedef BSTScatterTableEntry<K, V, KVPolicy> EntryType;
};

template <class Traits>
class BSTScatterTableKernel
{
public:
    typedef typename Traits::EntryType EntryType;

    EntryType* GetNewEntry(EntryType* apTable);

    unsigned int unk00;
    unsigned int uiSize;
    unsigned int uiFree;
    unsigned int uiLastFree;
};

template <class Traits>
inline typename BSTScatterTableKernel<Traits>::EntryType* BSTScatterTableKernel<Traits>::GetNewEntry(EntryType* apTable)
{
    EntryType* pEntry = 0;
    unsigned int uiFreeCount = uiFree;
    if (uiFreeCount) {
        unsigned int uiMask = uiSize - 1;
        do {
            uiLastFree = (uiLastFree - 1) & uiMask;
            EntryType* pCandidate = &apTable[uiLastFree];
            if (!pCandidate->pNext)
                pEntry = pCandidate;
        } while (!pEntry);
        uiFree = uiFreeCount - 1;
    }
    return pEntry;
}
