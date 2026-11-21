// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTArrayHeapAllocator; size 0x10
#pragma once
struct BSTArrayHeapAllocator {
    void* _data;
    unsigned int _capacity;
    unsigned char undefined_c[4];
};
static_assert(sizeof(BSTArrayHeapAllocator) == 16, "BSTArrayHeapAllocator layout differs from the PDB");
