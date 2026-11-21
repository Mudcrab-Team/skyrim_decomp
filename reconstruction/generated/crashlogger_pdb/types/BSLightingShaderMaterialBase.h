// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSLightingShaderMaterialBase; size 0xa0
#pragma once

#include "BSShaderMaterial_da61c263.h"
#include "NiColor_e5e1ad7d.h"
#include "NiPointer_RE__BSTextureSet_014b85b2.h"
#include "NiPointer_RE__NiSourceTexture_cf356212.h"
struct BSLightingShaderMaterialBase {
    BSShaderMaterial_da61c263 _base;
    NiColor_e5e1ad7d specularColor;
    unsigned int pad44;
    NiPointer_RE__NiSourceTexture_cf356212 diffuseTexture;
    int diffuseRenderTargetSourceIndex;
    unsigned int pad54;
    NiPointer_RE__NiSourceTexture_cf356212 normalTexture;
    NiPointer_RE__NiSourceTexture_cf356212 rimSoftLightingTexture;
    NiPointer_RE__NiSourceTexture_cf356212 specularBackLightingTexture;
    int textureClampMode;
    int pad74;
    NiPointer_RE__BSTextureSet_014b85b2 textureSet;
    float materialAlpha;
    float refractionPower;
    float specularPower;
    float specularColorScale;
    float subSurfaceLightRolloff;
    float rimLightPower;
    unsigned int textureSetLock;
    unsigned char undefined_9c[4];
};
static_assert(sizeof(BSLightingShaderMaterialBase) == 160, "BSLightingShaderMaterialBase layout differs from the PDB");
