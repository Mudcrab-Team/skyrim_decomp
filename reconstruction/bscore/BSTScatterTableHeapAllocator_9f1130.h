// Source exposure: mixed (sibling game-code names and body; compared function from the pinned image).
// Code origin: original reconstruction from the pinned image listing; names and prototypes as labelled below
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/BSCore/BSTScatterTable.h:145
// Sibling source: fo4-private@1b765c70 src/BSCore/MemoryManager.h:5
// MemoryManager, Instance, Allocate, BSTScatterTableHeapAllocator, BSTScatterTableEntry, BSTScatterTableDefaultKVStorage, Key, Value, pNext: SIBLING(fo4-private@1b765c70, author-permission) STANDIN; declarations
// NiAVObject, BSISoundOutputModel, UpdateInitState, storage: GUESS(low)
#pragma once

class NiAVObject;
class BSISoundOutputModel;

class MemoryManager
{
public:
    static MemoryManager& Instance();
    static void UpdateInitState(void* storage, unsigned int* fence);
    void* Allocate(unsigned long long uiSize, int alignment, bool aligned);

    unsigned char storage[1160];
};

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

template <class T>
struct BSTScatterTableHeapAllocator
{
    T* Allocate(unsigned int auiCount) const;
};

inline MemoryManager& MemoryManager::Instance()
{
    static char cbuffer[sizeof(MemoryManager)];
    static unsigned int uiinitFence;
    if (uiinitFence != 2)
        UpdateInitState(cbuffer, &uiinitFence);
    return *reinterpret_cast<MemoryManager*>(cbuffer);
}

inline void* operator new(unsigned long long uiSize)
{
    return MemoryManager::Instance().Allocate(uiSize, 0, false);
}

template <class T>
inline T* BSTScatterTableHeapAllocator<T>::Allocate(unsigned int auiCount) const
{
    return reinterpret_cast<T*>(::operator new(auiCount * sizeof(T)));
}
