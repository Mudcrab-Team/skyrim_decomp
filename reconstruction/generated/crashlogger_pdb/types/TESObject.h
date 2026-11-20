// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESObject; size 0x20
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "TESFileContainer_70f0bdf4.h"
struct TESObject__VFTable;
struct TESObject {
    TESObject__VFTable* vftable_TESObject_0;
    TESFileContainer_70f0bdf4 FormSourceFiles_8;
    unsigned int FormFlags_10;
    unsigned int FormId_14;
    unsigned short FormGameFlags_18;
    unsigned char FormType_1A;
    char _pad_1B[5];
};
static_assert(sizeof(TESObject) == 32, "TESObject layout differs from the PDB");
