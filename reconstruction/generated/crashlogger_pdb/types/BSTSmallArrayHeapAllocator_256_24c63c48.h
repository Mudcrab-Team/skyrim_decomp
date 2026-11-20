// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTSmallArrayHeapAllocator<256>; size 0x108
#pragma once

#include "Data.h"
struct BSTSmallArrayHeapAllocator_256_24c63c48 {
    unsigned int _capacity : 31;
    unsigned int _local : 1;
    unsigned char undefined_4[4];
    Data _data;
};
static_assert(sizeof(BSTSmallArrayHeapAllocator_256_24c63c48) == 264, "BSTSmallArrayHeapAllocator_256_24c63c48 layout differs from the PDB");
