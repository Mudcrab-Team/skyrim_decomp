// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSLightingShaderMaterialLODLandscape; size 0xc8
#pragma once

#include "BSLightingShaderMaterialBase.h"
#include "NiPointer_RE__NiSourceTexture_cf356212.h"
struct BSLightingShaderMaterialLODLandscape {
    BSLightingShaderMaterialBase _base;
    NiPointer_RE__NiSourceTexture_cf356212 parentDiffuseTexture;
    NiPointer_RE__NiSourceTexture_cf356212 parentNormalTexture;
    NiPointer_RE__NiSourceTexture_cf356212 landscapeNoiseTexture;
    float terrainTexOffsetX;
    float terrainTexOffsetY;
    float terrainTexFade;
    unsigned char undefined_c4[4];
};
static_assert(sizeof(BSLightingShaderMaterialLODLandscape) == 200, "BSLightingShaderMaterialLODLandscape layout differs from the PDB");
