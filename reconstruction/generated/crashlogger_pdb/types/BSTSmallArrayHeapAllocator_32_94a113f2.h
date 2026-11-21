// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTSmallArrayHeapAllocator<32>; size 0x28
#pragma once

#include "Data_bf8fbdae.h"
struct BSTSmallArrayHeapAllocator_32_94a113f2 {
    unsigned int _capacity : 31;
    unsigned int _local : 1;
    unsigned char undefined_4[4];
    Data_bf8fbdae _data;
};
static_assert(sizeof(BSTSmallArrayHeapAllocator_32_94a113f2) == 40, "BSTSmallArrayHeapAllocator_32_94a113f2 layout differs from the PDB");
