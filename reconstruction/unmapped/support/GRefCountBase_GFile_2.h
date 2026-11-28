// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// GRefCountBase_GFile_2: GUESS(low) STANDIN
// GRefCountBase_GFile_2::dtor: CRASHLOGGER_PDB(59818@2026.10.24)
// Heap121700, gHeap121700, Base121700: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

struct Heap121700
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

extern Heap121700* gHeap121700;

struct Base121700
{
    virtual ~Base121700();

    std::uint64_t unk08;  // 0x08
};

class GRefCountBase_GFile_2 : public Base121700
{
public:
    GRefCountBase_GFile_2();
    // ~GRefCountBase_GFile_2() implicit; compared deleting destructor at 0x121700

    static void operator delete(void* a_ptr)
    {
        gHeap121700->Free(a_ptr);
    }
};

static_assert(sizeof(GRefCountBase_GFile_2) == 0x10, "GRefCountBase_GFile_2 size");
