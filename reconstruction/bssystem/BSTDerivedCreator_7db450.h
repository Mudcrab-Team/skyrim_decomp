// Source exposure: mixed (the listing of the pinned image; names and the creator template from the sibling declarations used by the adapted body).
// Code origin: the creator template adapted from the sibling; the allocation path and constructor fields read from the listing
// SPDX-License-Identifier: CC0-1.0
// Sibling source: fo4-private@1b765c70 src/BSSystem/BSTCreateFactory.h:8
// IBSTCreator, BSTDerivedCreator, BSTDerivedCreator::Create, BSTDerivedCreator::Destroy: SIBLING(fo4-private@1b765c70, author-permission)
// BGShkMatFadeController, BShkNonTransformController: EXE_RTTI; the template arguments of the image's instance
// MemoryManager::EnsureInit, MemoryManager::Allocate: CRASHLOGGER_PDB(59818@2026.10.24)
// g_memoryManager, g_memoryManagerGuard, BShkReferencedObject, refCount, unk10, fMaxValue, unk1C, HeapAllocated: GUESS(low)
#pragma once

#include <cstddef>
#include <cstdint>

struct MemoryManager
{
    void EnsureInit(std::uint32_t* guard);
    void* Allocate(std::size_t size, std::int32_t alignment, bool alignmentRequired);
};

extern MemoryManager g_memoryManager;
extern std::uint32_t g_memoryManagerGuard;

// Objects of the controller family come from the general heap.
struct HeapAllocated
{
    static void* operator new(std::size_t size)
    {
        if (g_memoryManagerGuard != 2) {
            g_memoryManager.EnsureInit(&g_memoryManagerGuard);
        }
        return g_memoryManager.Allocate(size, 0, false);
    }
};

struct BShkReferencedObject : public HeapAllocated
{
    BShkReferencedObject() : refCount(0) {}
    virtual ~BShkReferencedObject() {}

    std::uint32_t refCount;  // 08
};

struct BShkNonTransformController : public BShkReferencedObject
{
    BShkNonTransformController() : unk10(nullptr) {}
    ~BShkNonTransformController() override {}

    void* unk10;  // 10
};

struct BGShkMatFadeController : public BShkNonTransformController
{
    BGShkMatFadeController() : fMaxValue(3.40282e+38f) {}
    ~BGShkMatFadeController() override {}

    float fMaxValue;      // 18
    std::uint32_t unk1C;  // 1C
};
static_assert(sizeof(BGShkMatFadeController) == 0x20, "allocation size from the listing");

template <class T>
struct IBSTCreator
{
    virtual ~IBSTCreator() {}
    virtual T* Create() const = 0;
    virtual void Destroy(const T* apObject) const = 0;
};

template <class T, class I>
struct BSTDerivedCreator : public IBSTCreator<I>
{
    virtual I* Create() const { return new T; }
    virtual void Destroy(const I* apObject) const { delete apObject; }
};
