// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESModel__VFTable; size 0x38
#pragma once

struct BaseFormComponent_9d659514;
struct TESModel;
struct TESWorldSpace_f9563d31;
struct TESModel__VFTable {
    unsigned long long*(*dtor_0)(BaseFormComponent_9d659514* , char);
    int (*InitializeDataComponent_8)(void);
    int (*ClearDataComponent_10)(void);
    void (*CopyComponent_18)(void);
    long long (*GetModel_20)(TESModel* );
    void*(*SetModel_28)(TESWorldSpace_f9563d31* , unsigned char* );
    long long (*GetAsModelTextureSwap_30)(void);
};
static_assert(sizeof(TESModel__VFTable) == 56, "TESModel__VFTable layout differs from the PDB");
