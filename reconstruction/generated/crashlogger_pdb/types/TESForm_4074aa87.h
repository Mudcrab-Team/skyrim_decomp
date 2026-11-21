// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESForm; size 0x20
// one of 2 different PDB types sharing this name
#pragma once

#include "TESFileContainer_70f0bdf4.h"
struct TESForm__VFTable;
struct TESForm_4074aa87 {
    TESForm__VFTable* vftable_TESForm_0;
    TESFileContainer_70f0bdf4 FormSourceFiles_8;
    unsigned int FormFlags_10;
    unsigned int FormId_14;
    unsigned short FormGameFlags_18;
    unsigned char FormType_1A;
    char _pad_1B[5];
};
static_assert(sizeof(TESForm_4074aa87) == 32, "TESForm_4074aa87 layout differs from the PDB");
