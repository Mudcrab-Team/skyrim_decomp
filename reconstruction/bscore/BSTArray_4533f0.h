// Source exposure: mixed (sibling game-code names and body; compared function from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/BSCore/BSTArray.h:447
// BSTArray, DestructItems, QBuffer: SIBLING(fo4-private@1b765c70, author-permission) STANDIN; declarations
// ObjectListItem, BSTArrayHeapAllocator, unk08, pBuffer, iAllocSize: GUESS(low)
#pragma once

class ObjectListItem
{
public:
    virtual ~ObjectListItem();

    unsigned char unk08[0x28];
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
    void DestructItems(unsigned int aiStart, unsigned int aiCount);
};

template <class T, class A>
inline void BSTArray<T, A>::DestructItems(unsigned int aiStart, unsigned int aiCount)
{
    T* pItem = static_cast<T*>(A::QBuffer()) + aiStart;
    for (unsigned int i = 0; i < aiCount; ++i) {
        pItem->~T();
        ++pItem;
    }
}
