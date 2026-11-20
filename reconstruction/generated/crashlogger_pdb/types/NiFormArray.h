// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiFormArray; size 0x20
// one of 2 different PDB types sharing this name; the fullest
#pragma once

struct NiFormArray__VFTable;
struct NiFormArray {
    NiFormArray__VFTable* vftable_NiFormArray_0;
    void* Data_8;
    int Capacity_10;
    int SparseCount_14;
    int ActualCount_18;
    int GrowCount_1C;
};
static_assert(sizeof(NiFormArray) == 32, "NiFormArray layout differs from the PDB");
