// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESFileArray; size 0x10
// one of 2 different PDB types sharing this name; the fullest
#pragma once
struct TESFileArray {
    void* Data_0;
    int Length_8;
    char _pad_C[4];
};
static_assert(sizeof(TESFileArray) == 16, "TESFileArray layout differs from the PDB");
