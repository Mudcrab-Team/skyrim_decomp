// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSShaderMaterial; size 0x38
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSIntrusiveRefCounted_8d4cb673.h"
struct BSShaderMaterial_vtbl_e85518f4;
struct BSShaderMaterial {
    BSShaderMaterial_vtbl_e85518f4* __vftable;
    BSIntrusiveRefCounted_8d4cb673 _base_BSIntrusiveRefCounted;
    unsigned char texCoordOffset_raw[16];
    unsigned char texCoordScale_raw[16];
    unsigned int hashKey;
    unsigned int unk30;
    unsigned int unk34;
};
static_assert(sizeof(BSShaderMaterial) == 56, "BSShaderMaterial layout differs from the PDB");
