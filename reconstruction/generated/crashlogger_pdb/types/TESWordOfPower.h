// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESWordOfPower; size 0x38
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSFixedString.h"
#include "TESFileContainer_70f0bdf4.h"
struct TESFullName__VFTable;
struct TESWordOfPower__VFTable;
struct TESWordOfPower {
    TESWordOfPower__VFTable* vftable_TESWordOfPower_0;
    TESFileContainer_70f0bdf4 FormSourceFiles_8;
    unsigned int FormFlags_10;
    unsigned int FormId_14;
    unsigned short FormGameFlags_18;
    unsigned char FormType_1A;
    char _pad_1B[5];
    TESFullName__VFTable* vftable_TESFullName_20;
    BSFixedString Text_28;
    BSFixedString Translation_30;
};
static_assert(sizeof(TESWordOfPower) == 56, "TESWordOfPower layout differs from the PDB");
