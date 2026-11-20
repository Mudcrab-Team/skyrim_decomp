// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESIcon__VFTable; size 0x38
#pragma once

struct BaseFormComponent_9d659514;
struct TESTexture_fe82fffc;
struct TESIcon__VFTable {
    unsigned long long*(*dtor_0)(BaseFormComponent_9d659514* , char);
    int (*InitializeDataComponent_8)(void);
    int (*ClearDataComponent_10)(void);
    void (*CopyComponent_18)(void);
    long long (*GetMaxAllowedSize_20)(void);
    char*(*GetAsNormalFile_28)(TESTexture_fe82fffc* , long long);
    long long*(*GetDefaultPath_30)(void);
};
static_assert(sizeof(TESIcon__VFTable) == 56, "TESIcon__VFTable layout differs from the PDB");
