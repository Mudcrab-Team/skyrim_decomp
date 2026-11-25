// Source exposure: mixed (sibling game-code names and body; compared function from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/BSCore/BSTArray.h:427
// BSTArray, BSTArrayHeapAllocator, BGSImpactManagerDebugDatum, ConstructDefaultItems, QBuffer: SIBLING(fo4-private@1b765c70, author-permission) STANDIN; declarations
// pBuffer, iAllocSize, unk00, unk08, unk10, unk18: GUESS(low)
#pragma once

#include <new>

struct BGSImpactManagerDebugDatum
{
    BGSImpactManagerDebugDatum() : unk00(0), unk08(0), unk10(0), unk18(0) {}

    unsigned long long unk00;
    unsigned long long unk08;
    unsigned long long unk10;
    unsigned long long unk18;
};

class BSTArrayHeapAllocator
{
public:
    void* QBuffer() const { return pBuffer; }

    void* pBuffer;
    unsigned int iAllocSize;
};

template <class T, class A>
class BSTArray : public A
{
public:
    void ConstructDefaultItems(unsigned int aiStart, unsigned int aiCount);
};

template <class T, class A>
inline void BSTArray<T, A>::ConstructDefaultItems(unsigned int aiStart, unsigned int aiCount)
{
    T* pItem = static_cast<T*>(A::QBuffer()) + aiStart;
    for (unsigned int i = 0; i < aiCount; ++i) {
        new (pItem) T;
        ++pItem;
    }
}
