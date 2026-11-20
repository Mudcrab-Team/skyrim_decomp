// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTArray<BSNavmeshVertex>; size 0x18
#pragma once

struct BSNavmeshVertex;
struct BSTArray_BSNavmeshVertex_b859940c {
    BSNavmeshVertex* _data;
    unsigned int _capacity;
    unsigned long pad0C;
    unsigned int _size;
    unsigned long pad14;
};
static_assert(sizeof(BSTArray_BSNavmeshVertex_b859940c) == 24, "BSTArray_BSNavmeshVertex_b859940c layout differs from the PDB");
