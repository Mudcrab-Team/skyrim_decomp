// Source exposure: mixed (sibling game-code names and body; compared function from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/BSCore/BSTArray.h:292
// BSTArray, BSTArrayBase, BSTArrayHeapAllocator, BSTSmartPointer, BSTSmartPointerIntrusiveRefCount, AnimationObject, Clear: SIBLING(fo4-private@1b765c70, author-permission) STANDIN; declarations
// iSize, pBuffer, iAllocSize: GUESS(low)
#pragma once

class AnimationObject;
struct BSTSmartPointerIntrusiveRefCount;
template <class T, class R> class BSTSmartPointer;

class BSTArrayHeapAllocator
{
public:
    ~BSTArrayHeapAllocator();

    void* pBuffer;
    unsigned int iAllocSize;
};

class BSTArrayBase
{
public:
    ~BSTArrayBase();

    unsigned int iSize;
};

template <class T, class A>
class BSTArray : public A, public BSTArrayBase
{
public:
    ~BSTArray();
    void Clear(bool abFree);
};

template <class T, class A>
inline BSTArray<T, A>::~BSTArray()
{
    Clear(true);
}
