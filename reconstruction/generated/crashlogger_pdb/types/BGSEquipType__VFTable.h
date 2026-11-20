// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSEquipType__VFTable; size 0x30
#pragma once

struct BGSEquipType_d4d52754;
struct BaseFormComponent_9d659514;
struct BGSEquipType__VFTable {
    unsigned long long*(*dtor_0)(BaseFormComponent_9d659514* , char);
    int (*InitializeDataComponent_8)(void);
    int (*ClearDataComponent_10)(void);
    void (*CopyComponent_18)(void);
    long long (*GetEquipSlot_20)(BGSEquipType_d4d52754* );
    void (*SetEquipSlot_28)(BGSEquipType_d4d52754* , long long);
};
static_assert(sizeof(BGSEquipType__VFTable) == 48, "BGSEquipType__VFTable layout differs from the PDB");
