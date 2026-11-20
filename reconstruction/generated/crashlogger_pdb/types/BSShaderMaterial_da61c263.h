// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSShaderMaterial; size 0x38
// one of 2 different PDB types sharing this name
#pragma once

#include "BSIntrusiveRefCounted.h"
struct BSShaderMaterial_vtbl;
struct BSShaderMaterial_da61c263 {
    BSShaderMaterial_vtbl* __vftable;
    BSIntrusiveRefCounted _base_BSIntrusiveRefCounted;
    unsigned char texCoordOffset_raw[16];
    unsigned char texCoordScale_raw[16];
    unsigned int hashKey;
    unsigned int unk30;
    unsigned int unk34;
};
static_assert(sizeof(BSShaderMaterial_da61c263) == 56, "BSShaderMaterial_da61c263 layout differs from the PDB");
