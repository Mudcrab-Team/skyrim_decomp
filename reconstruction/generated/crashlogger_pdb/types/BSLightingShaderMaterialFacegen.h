// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSLightingShaderMaterialFacegen; size 0xb8
#pragma once

#include "BSLightingShaderMaterialBase.h"
#include "NiPointer_RE__NiSourceTexture_cf356212.h"
struct BSLightingShaderMaterialFacegen {
    BSLightingShaderMaterialBase _base;
    NiPointer_RE__NiSourceTexture_cf356212 tintTexture;
    NiPointer_RE__NiSourceTexture_cf356212 detailTexture;
    NiPointer_RE__NiSourceTexture_cf356212 subsurfaceTexture;
};
static_assert(sizeof(BSLightingShaderMaterialFacegen) == 184, "BSLightingShaderMaterialFacegen layout differs from the PDB");
