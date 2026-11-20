// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: hkLifoAllocator; size 0x50
#pragma once

#include "hkMemoryAllocator.h"
struct Implementation;
struct hkLifoAllocator {
    hkMemoryAllocator _base;
    Implementation* impl;
    int SlabSize;
    unsigned char undefined_14[4];
    void* Cur;
    void* End;
    void* FirstNonLifoEnd;
    void* CachedEmptySlab;
    hkMemoryAllocator* SlabAllocator;
    hkMemoryAllocator* LargeAllocator;
    hkMemoryAllocator* InternalAllocator;
};
static_assert(sizeof(hkLifoAllocator) == 80, "hkLifoAllocator layout differs from the PDB");
