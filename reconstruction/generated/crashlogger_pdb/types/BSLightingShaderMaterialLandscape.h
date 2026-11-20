// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSLightingShaderMaterialLandscape; size 0x158
#pragma once

#include "BSLightingShaderMaterialBase.h"
#include "NiColorA_7eee66f4.h"
#include "NiPointer_RE__NiSourceTexture_cf356212.h"
struct BSLightingShaderMaterialLandscape {
    BSLightingShaderMaterialBase _base;
    unsigned int numLandscapeTextures;
    unsigned int pad0A4;
    unsigned char landscapeDiffuseTexture_raw[40];
    unsigned char landscapeNormalTexture_raw[40];
    NiPointer_RE__NiSourceTexture_cf356212 terrainOverlayTexture;
    NiPointer_RE__NiSourceTexture_cf356212 terrainNoiseTexture;
    NiColorA_7eee66f4 landBlendParams;
    float textureIsSnow[6];
    float textureIsSpecPower[6];
    float terrainTexOffsetX;
    float terrainTexOffsetY;
    float terrainTexFade;
    unsigned int pad154;
};
static_assert(sizeof(BSLightingShaderMaterialLandscape) == 344, "BSLightingShaderMaterialLandscape layout differs from the PDB");
