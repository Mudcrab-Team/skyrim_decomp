// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESDescription__VFTable; size 0x20
#pragma once

struct BaseFormComponent_9d659514;
struct TESDescription__VFTable {
    unsigned long long*(*dtor_0)(BaseFormComponent_9d659514* , char);
    int (*InitializeDataComponent_8)(void);
    int (*ClearDataComponent_10)(void);
    void (*CopyComponent_18)(void);
};
static_assert(sizeof(TESDescription__VFTable) == 32, "TESDescription__VFTable layout differs from the PDB");
