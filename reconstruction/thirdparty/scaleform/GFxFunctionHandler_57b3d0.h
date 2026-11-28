// Source exposure: mixed (community PDB declarations; compared functions from the pinned image).
// Code origin: original implementation based on the pinned game build.
// SPDX-License-Identifier: CC0-1.0
// GFxFunctionHandler, GFxFunctionHandler::dtor: CRASHLOGGER_PDB(59818@2026.10.24)
// GMemoryHeap, GRefCountImplCore, gGlobalHeap, Free, refCount: GUESS(low)
#pragma once

#include <cstdint>
#include <cstddef>

void operator delete(void*, std::size_t) noexcept;

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
    virtual void Free(void* a_ptr);  // 0C (0x60)
};

extern GMemoryHeap* gGlobalHeap;

class GRefCountImplCore
{
public:
    virtual ~GRefCountImplCore();

    static void operator delete(void* a_ptr)
    {
        gGlobalHeap->Free(a_ptr);
    }

    std::int32_t refCount;  // 08
};
static_assert(sizeof(GRefCountImplCore) == 0x10, "GRefCountImplCore size");

class GFxFunctionHandler : public GRefCountImplCore
{
public:
    GFxFunctionHandler();
    ~GFxFunctionHandler() override;  // compared: 0x57b3d0
};
static_assert(sizeof(GFxFunctionHandler) == 0x10, "GFxFunctionHandler size");
