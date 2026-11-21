// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTArray<RE::BSNavmeshVertex>; size 0x18
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct BSNavmeshVertex;
struct BSTArray_RE__BSNavmeshVertex_12b8449c {
    BSNavmeshVertex* _data;
    unsigned int _capacity;
    unsigned long pad0C;
    unsigned int _size;
    unsigned long pad14;
};
static_assert(sizeof(BSTArray_RE__BSNavmeshVertex_12b8449c) == 24, "BSTArray_RE__BSNavmeshVertex_12b8449c layout differs from the PDB");
