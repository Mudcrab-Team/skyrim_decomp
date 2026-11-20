// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTArray; size 0x18
#pragma once

#include "BSTArrayBase_be13d7a0.h"
#include "BSTArrayHeapAllocator.h"
struct BSTArray {
    BSTArrayHeapAllocator _base;
    BSTArrayBase_be13d7a0 _base_BSTArrayBase;
    unsigned char undefined_14[4];
};
static_assert(sizeof(BSTArray) == 24, "BSTArray layout differs from the PDB");
