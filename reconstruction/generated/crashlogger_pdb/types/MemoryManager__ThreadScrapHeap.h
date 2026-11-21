// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MemoryManager::ThreadScrapHeap; size 0xa0
#pragma once

#include "ScrapHeap.h"
struct MemoryManager__ThreadScrapHeap {
    ScrapHeap Heap_0;
    MemoryManager__ThreadScrapHeap* Next_90;
    unsigned int OwningThreadId_98;
    char _pad_9C[4];
};
static_assert(sizeof(MemoryManager__ThreadScrapHeap) == 160, "MemoryManager__ThreadScrapHeap layout differs from the PDB");
