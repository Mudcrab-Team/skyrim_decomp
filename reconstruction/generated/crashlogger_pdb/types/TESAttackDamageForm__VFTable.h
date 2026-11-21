// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESAttackDamageForm__VFTable; size 0x28
#pragma once

struct BaseFormComponent_9d659514;
struct TESAttackDamageForm_70fa2f9d;
struct TESAttackDamageForm__VFTable {
    unsigned long long*(*dtor_0)(BaseFormComponent_9d659514* , char);
    int (*InitializeDataComponent_8)(void);
    int (*ClearDataComponent_10)(void);
    void (*CopyComponent_18)(void);
    long long (*GetAttackDamage_20)(TESAttackDamageForm_70fa2f9d* );
};
static_assert(sizeof(TESAttackDamageForm__VFTable) == 40, "TESAttackDamageForm__VFTable layout differs from the PDB");
