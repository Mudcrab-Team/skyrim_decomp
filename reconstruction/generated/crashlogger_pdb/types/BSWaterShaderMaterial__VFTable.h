// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSWaterShaderMaterial__VFTable; size 0x40
#pragma once

struct BSShaderMaterial;
struct BSWaterShaderMaterial__VFTable {
    unsigned long long*(*dtor_0)(BSShaderMaterial* , char);
    unsigned long long*(*Create_8)(void);
    void (*CopyMembers_10)(BSShaderMaterial* , long long);
    void (*DoIsCopy_18)(BSShaderMaterial* , long long);
    long long (*ComputeCRC32_20)(BSShaderMaterial* , int);
    BSShaderMaterial*(*GetDefault_28)(void);
    long long (*GetFeature_30)(void);
    long long (*GetType_38)(void);
};
static_assert(sizeof(BSWaterShaderMaterial__VFTable) == 64, "BSWaterShaderMaterial__VFTable layout differs from the PDB");
