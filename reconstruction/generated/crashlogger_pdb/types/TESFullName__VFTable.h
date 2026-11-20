// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESFullName__VFTable; size 0x30
#pragma once

struct BaseFormComponent_9d659514;
struct TESFullName_88f61e2a;
struct TESFullName__VFTable {
    unsigned long long*(*dtor_0)(BaseFormComponent_9d659514* , char);
    int (*InitializeDataComponent_8)(void);
    int (*ClearDataComponent_10)(void);
    void (*CopyComponent_18)(void);
    int (*GetFullNameLength_20)(TESFullName_88f61e2a* );
    long long (*GetFullName_28)(TESFullName_88f61e2a* );
};
static_assert(sizeof(TESFullName__VFTable) == 48, "TESFullName__VFTable layout differs from the PDB");
