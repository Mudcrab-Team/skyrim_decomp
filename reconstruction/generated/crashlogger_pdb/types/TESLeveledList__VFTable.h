// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESLeveledList__VFTable; size 0x40
#pragma once

struct BaseFormComponent_9d659514;
struct TESLeveledList_072ef37d;
struct TESLeveledList__VFTable {
    unsigned long long*(*dtor_0)(BaseFormComponent_9d659514* , char);
    int (*InitializeDataComponent_8)(void);
    int (*ClearDataComponent_10)(void);
    void (*CopyComponent_18)(void);
    long long (*GetChanceNone_20)(TESLeveledList_072ef37d* );
    char (*GetMultCalc_28)(TESLeveledList_072ef37d* );
    long long (*GetLevDifferenceMax_30)(void);
    int (*GetCanContainFormsOfType_38)(void);
};
static_assert(sizeof(TESLeveledList__VFTable) == 64, "TESLeveledList__VFTable layout differs from the PDB");
