// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: HeapBlock; size 0x20
#pragma once

#include "FreeOrUsed.h"
struct HeapBlock {
    unsigned long long memSize;
    HeapBlock* previous;
    FreeOrUsed freeOrUsed;
    HeapBlock* nextFree;
};
static_assert(sizeof(HeapBlock) == 32, "HeapBlock layout differs from the PDB");
