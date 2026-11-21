// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTSmallArrayHeapAllocator<16>; size 0x18
#pragma once

#include "Data_ef000c51.h"
struct BSTSmallArrayHeapAllocator_16_6537b4ae {
    unsigned int _capacity : 31;
    unsigned int _local : 1;
    unsigned char undefined_4[4];
    Data_ef000c51 _data;
};
static_assert(sizeof(BSTSmallArrayHeapAllocator_16_6537b4ae) == 24, "BSTSmallArrayHeapAllocator_16_6537b4ae layout differs from the PDB");
