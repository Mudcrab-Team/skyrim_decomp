// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESLevSpell; size 0x58
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "TESBoundObject__Data.h"
#include "TESFileContainer_70f0bdf4.h"
struct TESGlobal_18239760;
struct TESLevSpell__VFTable;
struct TESLeveledList__VFTable;
struct TESLevSpell {
    TESLevSpell__VFTable* vftable_TESLevSpell_0;
    TESFileContainer_70f0bdf4 FormSourceFiles_8;
    unsigned int FormFlags_10;
    unsigned int FormId_14;
    unsigned short FormGameFlags_18;
    unsigned char FormType_1A;
    char _pad_1B[5];
    TESBoundObject__Data BoundData_20;
    char _pad_2C[4];
    TESLeveledList__VFTable* vftable_TESLeveledList_30;
    void* LeveledListEntriesArray_38;
    unsigned char LeveledListSkipChance_40;
    unsigned char LeveledListFlagsValue_41;
    unsigned char LeveledListEntriesCount_42;
    char _pad_43[13];
    TESGlobal_18239760* LeveledListSkipChanceGlobal_50;
};
static_assert(sizeof(TESLevSpell) == 88, "TESLevSpell layout differs from the PDB");
