// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: HeapInfo; size 0x50
#pragma once

#include "HeapDesc.h"
struct GMemoryHeap;
struct HeapInfo {
    HeapDesc desc;
    GMemoryHeap* parent;
    unsigned char* name;
};
static_assert(sizeof(HeapInfo) == 80, "HeapInfo layout differs from the PDB");
