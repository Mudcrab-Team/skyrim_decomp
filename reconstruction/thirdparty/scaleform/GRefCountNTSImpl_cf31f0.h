// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// GRefCountNTSImpl, GRefCountNTSImpl::GetWeakProxy: CRASHLOGGER_PDB(59818@2026.10.24)
// GMemoryHeap, GWeakPtrProxy, GAllocInfo, gGlobalHeap, AllocAutoHeap, refCount, weakProxy, object: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

struct GAllocInfo
{
    std::uint32_t statId;  // 00
};

class GMemoryHeap
{
public:
    virtual ~GMemoryHeap();
    virtual void Slot01();
    virtual void Slot02();
    virtual void Slot03();
    virtual void Slot04();
    virtual void Slot05();
    virtual void Slot06();
    virtual void Slot07();
    virtual void Slot08();
    virtual void Slot09();
    virtual void Slot0A();
    virtual void Slot0B();
    virtual void Slot0C();
    virtual void Slot0D();
    virtual void* AllocAutoHeap(const void* a_thisPtr, std::size_t a_size, const GAllocInfo* a_info);  // 0E (0x70)
};

extern GMemoryHeap* gGlobalHeap;

class GRefCountNTSImpl;

struct GWeakPtrProxy
{
    explicit GWeakPtrProxy(GRefCountNTSImpl* a_obj) noexcept :
        refCount(1),
        object(a_obj)
    {
    }

    static void* operator new(std::size_t a_size, const void* a_owner) noexcept
    {
        GAllocInfo info;
        info.statId = 2;
        return gGlobalHeap->AllocAutoHeap(a_owner, a_size, &info);
    }

    static void operator delete(void*, const void*) noexcept {}

    std::int32_t refCount;  // 00
    std::uint32_t unk04;  // 04
    GRefCountNTSImpl* object;  // 08
};
static_assert(sizeof(GWeakPtrProxy) == 0x10, "GWeakPtrProxy size");

class GRefCountNTSImpl
{
public:
    virtual ~GRefCountNTSImpl();

    GWeakPtrProxy* GetWeakProxy();  // compared: 0xcf31f0

    std::int32_t refCount;  // 08
    std::uint32_t unk0C;  // 0C
    GWeakPtrProxy* weakProxy;  // 10
};
static_assert(offsetof(GRefCountNTSImpl, weakProxy) == 0x10, "weakProxy offset");
