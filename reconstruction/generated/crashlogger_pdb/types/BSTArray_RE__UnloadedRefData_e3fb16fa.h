// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSTArray<RE::UnloadedRefData>; size 0x18
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct UnloadedRefData;
struct BSTArray_RE__UnloadedRefData_e3fb16fa {
    UnloadedRefData* _data;
    unsigned int _capacity;
    unsigned long pad0C;
    unsigned int _size;
    unsigned long pad14;
};
static_assert(sizeof(BSTArray_RE__UnloadedRefData_e3fb16fa) == 24, "BSTArray_RE__UnloadedRefData_e3fb16fa layout differs from the PDB");
