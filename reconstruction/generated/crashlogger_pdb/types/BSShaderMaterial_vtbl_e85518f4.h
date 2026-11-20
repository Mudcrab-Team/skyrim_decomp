// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSShaderMaterial_vtbl; size 0x40
// one of 2 different PDB types sharing this name
#pragma once

#include "Feature.h"
#include "FunctorType.h"
struct BSShaderMaterial_da61c263;
struct BSShaderMaterial_vtbl_e85518f4 {
    void (*_dtor_BSShaderMaterial)(void);
    BSShaderMaterial_da61c263*(*Create)(void);
    void (*CopyMembers)(BSShaderMaterial_da61c263* );
    bool (*DoIsCopy)(BSShaderMaterial_da61c263* );
    unsigned int (*ComputeCRC32)(unsigned int);
    BSShaderMaterial_da61c263*(*GetDefault)(void);
    Feature (*GetFeature)(void);
    FunctorType (*GetType)(void);
};
static_assert(sizeof(BSShaderMaterial_vtbl_e85518f4) == 64, "BSShaderMaterial_vtbl_e85518f4 layout differs from the PDB");
