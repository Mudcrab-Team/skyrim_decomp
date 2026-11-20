// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MemoryContextImpl; size 0x60
#pragma once

#include "GPtr_RE__GASRefCountCollector_c750d27a.h"
#include "GPtr_RE__GASStringManager_f3c5d664.h"
#include "HeapLimit.h"
#include "MemoryContext.h"
struct GMemoryHeap;
struct MemoryContextImpl {
    MemoryContext _base;
    GMemoryHeap* heap;
    GPtr_RE__GASRefCountCollector_c750d27a refCountCollector;
    GPtr_RE__GASStringManager_f3c5d664 stringManager;
    unsigned long long unk28;
    HeapLimit heapLimit;
};
static_assert(sizeof(MemoryContextImpl) == 96, "MemoryContextImpl layout differs from the PDB");
