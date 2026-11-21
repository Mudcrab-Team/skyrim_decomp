// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSMenuDisplayObject__VFTable; size 0x28
#pragma once

struct BGSMenuDisplayObject_4c4d25e5;
struct BaseFormComponent_9d659514;
struct BGSMenuDisplayObject__VFTable {
    unsigned long long*(*dtor_0)(BaseFormComponent_9d659514* , char);
    int (*InitializeDataComponent_8)(void);
    int (*ClearDataComponent_10)(void);
    void (*CopyComponent_18)(void);
    long long (*Func4_20)(BGSMenuDisplayObject_4c4d25e5* );
};
static_assert(sizeof(BGSMenuDisplayObject__VFTable) == 40, "BGSMenuDisplayObject__VFTable layout differs from the PDB");
