// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESLandTexture; size 0x50
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSSimpleList_TESGrass_d04eacbc.h"
#include "TESFileContainer_70f0bdf4.h"
#include "TESLandTexture__TextureHavokData.h"
struct BGSMaterialType_c56427e2;
struct BGSTextureSet_d8b0e61f;
struct TESLandTexture__VFTable;
struct TESLandTexture {
    TESLandTexture__VFTable* vftable_TESLandTexture_0;
    TESFileContainer_70f0bdf4 FormSourceFiles_8;
    unsigned int FormFlags_10;
    unsigned int FormId_14;
    unsigned short FormGameFlags_18;
    unsigned char FormType_1A;
    char _pad_1B[5];
    BGSTextureSet_d8b0e61f* TextureSet_20;
    TESLandTexture__TextureHavokData HavokData_28;
    BGSMaterialType_c56427e2* MaterialType_30;
    char SpecularExponent_38;
    char _pad_39[3];
    int ShaderTextureIndex_3C;
    BSSimpleList_TESGrass_d04eacbc TextureGrassList_40;
};
static_assert(sizeof(TESLandTexture) == 80, "TESLandTexture layout differs from the PDB");
