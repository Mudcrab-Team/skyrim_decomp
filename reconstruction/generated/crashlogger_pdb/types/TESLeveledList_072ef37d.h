// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESLeveledList; size 0x28
// one of 2 different PDB types sharing this name
#pragma once

struct TESGlobal_18239760;
struct TESLeveledList__VFTable;
struct TESLeveledList_072ef37d {
    TESLeveledList__VFTable* vftable_TESLeveledList_0;
    void* LeveledListEntriesArray_8;
    unsigned char LeveledListSkipChance_10;
    unsigned char LeveledListFlagsValue_11;
    unsigned char LeveledListEntriesCount_12;
    char _pad_13[13];
    TESGlobal_18239760* LeveledListSkipChanceGlobal_20;
};
static_assert(sizeof(TESLeveledList_072ef37d) == 40, "TESLeveledList_072ef37d layout differs from the PDB");
