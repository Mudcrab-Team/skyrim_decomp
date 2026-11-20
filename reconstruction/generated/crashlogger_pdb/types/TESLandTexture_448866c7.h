// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESLandTexture; size 0x50
// one of 2 different PDB types sharing this name
#pragma once

#include "BSSimpleList_RE__TESGrass_6beddc36.h"
#include "TESForm.h"
#include "TEXTURE_HAVOK_DATA.h"
struct BGSMaterialType;
struct BGSTextureSet;
struct TESLandTexture_448866c7 {
    TESForm _base;
    BGSTextureSet* textureSet;
    TEXTURE_HAVOK_DATA havokData;
    BGSMaterialType* materialType;
    unsigned char specularExponent;
    unsigned char pad39;
    unsigned short pad3A;
    int shaderTextureIndex;
    BSSimpleList_RE__TESGrass_6beddc36 textureGrassList;
};
static_assert(sizeof(TESLandTexture_448866c7) == 80, "TESLandTexture_448866c7 layout differs from the PDB");
