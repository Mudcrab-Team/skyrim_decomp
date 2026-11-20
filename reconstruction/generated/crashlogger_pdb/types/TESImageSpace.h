// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESImageSpace; size 0x70
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "TESFileContainer_70f0bdf4.h"
#include "TESImageSpace__BaseData.h"
struct TESImageSpace__VFTable;
struct TESImageSpace {
    TESImageSpace__VFTable* vftable_TESImageSpace_0;
    TESFileContainer_70f0bdf4 FormSourceFiles_8;
    unsigned int FormFlags_10;
    unsigned int FormId_14;
    unsigned short FormGameFlags_18;
    unsigned char FormType_1A;
    char _pad_1B[5];
    TESImageSpace__BaseData ImageSpaceData_20;
};
static_assert(sizeof(TESImageSpace) == 112, "TESImageSpace layout differs from the PDB");
