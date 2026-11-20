// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTArray<RE::BSNavmeshTriangle>; size 0x18
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct BSNavmeshTriangle_4576fddd;
struct BSTArray_RE__BSNavmeshTriangle_cedda0c4 {
    BSNavmeshTriangle_4576fddd* _data;
    unsigned int _capacity;
    unsigned long pad0C;
    unsigned int _size;
    unsigned long pad14;
};
static_assert(sizeof(BSTArray_RE__BSNavmeshTriangle_cedda0c4) == 24, "BSTArray_RE__BSNavmeshTriangle_cedda0c4 layout differs from the PDB");
