// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESPackageData__VFTable; size 0x30
#pragma once

struct TESPackageData;
struct TESPackageData__VFTable {
    unsigned long long*(*dtor_0)(TESPackageData* , char);
    void (*Copy_8)(void);
    char (*Compare_10)(void);
    void (*InitItem_18)(void);
    void (*SaveGame_20)(void);
    void (*LoadGame_28)(void);
};
static_assert(sizeof(TESPackageData__VFTable) == 48, "TESPackageData__VFTable layout differs from the PDB");
