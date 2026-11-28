// Source exposure: binary-analysis
// Code origin: written from the pinned image listing; see Adapted bodies.
// Adapted bodies: GString121040::~GString121040, treated as adapted: shaped like GString::DataDesc::Release (CharmedBaryon/CommonLibSSE-NG@b93280e src/RE/G/GString.cpp:24, MIT).
// SPDX-License-Identifier: MIT (CommonLibSSE-NG declarations, Copyright (c) 2018 Ryan-rsm-McKenzie; full text: licenses/CommonLibSSE-NG.txt)
// GMemoryFile: GUESS(low) STANDIN
// GMemoryFile::dtor: CRASHLOGGER_PDB(59818@2026.10.24)
// GMemoryFile::Read: COMMUNITY(meh321/AddressLibraryDatabase@0379cb6, permission)
// Heap121040, gHeap121040, RefData121040, GString121040, Base121040: GUESS(low) STANDIN
#pragma once

#include <cstddef>
#include <cstdint>
#include <cstring>
#include <intrin.h>

struct Heap121040
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

extern Heap121040* gHeap121040;

struct RefData121040
{
    std::uint64_t size;  // 0x00
    long refCount;       // 0x08
};

struct GString121040
{
    std::uintptr_t data;  // 0x00

    ~GString121040()
    {
        RefData121040* block = reinterpret_cast<RefData121040*>(data & ~static_cast<std::uintptr_t>(3));
        if (_InterlockedExchangeAdd(&block->refCount, -1) == 1)  // atomic refcount decrement
        {
            gHeap121040->Free(block);
        }
    }
};

struct Base121040
{
    virtual ~Base121040();

    std::uint64_t unk08;  // 0x08
};

class GMemoryFile : public Base121040
{
public:
    GMemoryFile();
    // ~GMemoryFile() implicit; compared deleting destructor at 0x121040

    std::int32_t Read(std::uint8_t* a_buf, std::int32_t a_bytes);  // compared: 0x120e80

    static void operator delete(void* a_ptr)
    {
        gHeap121040->Free(a_ptr);
    }

    GString121040 filePath;  // 0x10
    const std::uint8_t* fileData;  // 0x18
    std::int32_t fileSize;   // 0x20
    std::int32_t fileIndex;  // 0x24
    std::uint64_t unk28;     // 0x28
};

static_assert(sizeof(GMemoryFile) == 0x30, "GMemoryFile size");
