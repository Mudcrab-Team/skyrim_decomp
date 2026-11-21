// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTSmallArrayHeapAllocator<4>; size 0x10
#pragma once

#include "Data_6d2ef5b4.h"
struct BSTSmallArrayHeapAllocator_4_0d2c2713 {
    unsigned int _capacity : 31;
    unsigned int _local : 1;
    unsigned char undefined_4[4];
    Data_6d2ef5b4 _data;
};
static_assert(sizeof(BSTSmallArrayHeapAllocator_4_0d2c2713) == 16, "BSTSmallArrayHeapAllocator_4_0d2c2713 layout differs from the PDB");
