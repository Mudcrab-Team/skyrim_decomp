// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiBoneMatrixSetterI_vtbl; size 0x10
#pragma once

struct NiBoneMatrixSetterI;
struct NiSkinInstance;
struct NiTransform;
struct Partition;
struct NiBoneMatrixSetterI_vtbl {
    void (*_dtor_NiBoneMatrixSetterI)(void);
    void (*SetBoneMatrices)(NiBoneMatrixSetterI* , NiSkinInstance* , Partition* , NiTransform* );
};
static_assert(sizeof(NiBoneMatrixSetterI_vtbl) == 16, "NiBoneMatrixSetterI_vtbl layout differs from the PDB");
