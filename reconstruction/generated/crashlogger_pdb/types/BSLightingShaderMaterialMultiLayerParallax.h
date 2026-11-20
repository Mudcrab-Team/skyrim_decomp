// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSLightingShaderMaterialMultiLayerParallax; size 0xd0
#pragma once

#include "BSLightingShaderMaterialBase.h"
#include "NiPointer_RE__NiSourceTexture_cf356212.h"
struct BSLightingShaderMaterialMultiLayerParallax {
    BSLightingShaderMaterialBase _base;
    NiPointer_RE__NiSourceTexture_cf356212 layerTexture;
    NiPointer_RE__NiSourceTexture_cf356212 envTexture;
    NiPointer_RE__NiSourceTexture_cf356212 envMaskTexture;
    float parallaxLayerThickness;
    float parallaxRefractionScale;
    float parallaxInnerLayerUScale;
    float parallaxInnerLayerVScale;
    float envmapScale;
    unsigned int padCC;
};
static_assert(sizeof(BSLightingShaderMaterialMultiLayerParallax) == 208, "BSLightingShaderMaterialMultiLayerParallax layout differs from the PDB");
