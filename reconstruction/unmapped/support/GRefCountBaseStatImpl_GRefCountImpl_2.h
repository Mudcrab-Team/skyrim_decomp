// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// GRefCountBaseStatImpl_GRefCountImpl_2: GUESS(low) STANDIN
// GRefCountBaseStatImpl_GRefCountImpl_2::dtor: CRASHLOGGER_PDB(59818@2026.10.24)
// Heap121900, gHeap121900, Base121900: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

struct Heap121900
{
    virtual void Slot00() = 0;
    virtual void Slot01() = 0;
    virtual void Slot02() = 0;
    virtual void Slot03() = 0;
    virtual void Slot04() = 0;
    virtual void Slot05() = 0;
    virtual void Slot06() = 0;
    virtual void Slot07() = 0;
    virtual void Slot08() = 0;
    virtual void Slot09() = 0;
    virtual void Slot10() = 0;
    virtual void Slot11() = 0;
    virtual void Free(void* a_ptr) = 0;
};

extern Heap121900* gHeap121900;

struct Base121900
{
    virtual ~Base121900();

    std::uint64_t unk08;  // 0x08
};

class GRefCountBaseStatImpl_GRefCountImpl_2 : public Base121900
{
public:
    GRefCountBaseStatImpl_GRefCountImpl_2();
    // ~GRefCountBaseStatImpl_GRefCountImpl_2() implicit; compared deleting destructor at 0x121900

    static void operator delete(void* a_ptr)
    {
        gHeap121900->Free(a_ptr);
    }
};

static_assert(sizeof(GRefCountBaseStatImpl_GRefCountImpl_2) == 0x10, "GRefCountBaseStatImpl_GRefCountImpl_2 size");
