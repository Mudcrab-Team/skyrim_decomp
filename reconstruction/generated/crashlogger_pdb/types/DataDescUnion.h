// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: DataDescUnion; size 0x8
#pragma once

#include "HeapType.h"
struct DataDescUnion {
    HeapType heapType;
    unsigned char _pad_0[4];
};
static_assert(sizeof(DataDescUnion) == 8, "DataDescUnion layout differs from the PDB");
