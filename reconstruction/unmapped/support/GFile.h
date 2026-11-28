// Source exposure: binary-analysis
// Code origin: original reconstruction from pinned-image observations
// SPDX-License-Identifier: CC0-1.0
// GFile: GUESS(low) STANDIN
// GFile::dtor: CRASHLOGGER_PDB(59818@2026.10.24)
// Heap120d10, gHeap120d10, Base120d10: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>

struct Heap120d10
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

extern Heap120d10* gHeap120d10;

struct Base120d10
{
    virtual ~Base120d10();

    std::uint64_t unk08;  // 0x08
};

class GFile : public Base120d10
{
public:
    GFile();
    // ~GFile() implicit; compared deleting destructor at 0x120d10

    static void operator delete(void* a_ptr)
    {
        gHeap120d10->Free(a_ptr);
    }
};

static_assert(sizeof(GFile) == 0x10, "GFile size");
