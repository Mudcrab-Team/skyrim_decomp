// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTSmallArrayHeapAllocator<8>; size 0x10
#pragma once

#include "Data_4ffc5112.h"
struct BSTSmallArrayHeapAllocator_8_4a0c2a21 {
    unsigned int _capacity : 31;
    unsigned int _local : 1;
    unsigned char undefined_4[4];
    Data_4ffc5112 _data;
};
static_assert(sizeof(BSTSmallArrayHeapAllocator_8_4a0c2a21) == 16, "BSTSmallArrayHeapAllocator_8_4a0c2a21 layout differs from the PDB");
