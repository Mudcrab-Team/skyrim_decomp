// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSLightingShaderMaterialEnvmap; size 0xb8
#pragma once

#include "BSLightingShaderMaterialBase.h"
#include "NiPointer_RE__NiSourceTexture_cf356212.h"
struct BSLightingShaderMaterialEnvmap {
    BSLightingShaderMaterialBase _base;
    NiPointer_RE__NiSourceTexture_cf356212 envTexture;
    NiPointer_RE__NiSourceTexture_cf356212 envMaskTexture;
    float envMapScale;
    unsigned int padB4;
};
static_assert(sizeof(BSLightingShaderMaterialEnvmap) == 184, "BSLightingShaderMaterialEnvmap layout differs from the PDB");
