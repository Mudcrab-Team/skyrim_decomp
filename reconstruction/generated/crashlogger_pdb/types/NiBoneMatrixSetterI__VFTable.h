// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiBoneMatrixSetterI__VFTable; size 0x10
#pragma once

struct NiBoneMatrixSetterI;
struct NiBoneMatrixSetterI_cb2536df;
struct NiSkinInstance;
struct NiTransform;
struct Partition;
struct NiBoneMatrixSetterI__VFTable {
    long long (*dtor_0)(NiBoneMatrixSetterI_cb2536df* , char);
    void (*SetBoneMatrices)(NiBoneMatrixSetterI* , NiSkinInstance* , Partition* , NiTransform* );
};
static_assert(sizeof(NiBoneMatrixSetterI__VFTable) == 16, "NiBoneMatrixSetterI__VFTable layout differs from the PDB");
