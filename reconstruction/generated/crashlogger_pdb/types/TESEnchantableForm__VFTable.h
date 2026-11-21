// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESEnchantableForm__VFTable; size 0x28
#pragma once

struct BaseFormComponent_9d659514;
struct TESEnchantableForm;
struct TESEnchantableForm__VFTable {
    unsigned long long*(*dtor_0)(BaseFormComponent_9d659514* , char);
    int (*InitializeDataComponent_8)(void);
    int (*ClearDataComponent_10)(void);
    void (*CopyComponent_18)(void);
    long long (*GetCastingType_20)(TESEnchantableForm* );
};
static_assert(sizeof(TESEnchantableForm__VFTable) == 40, "TESEnchantableForm__VFTable layout differs from the PDB");
