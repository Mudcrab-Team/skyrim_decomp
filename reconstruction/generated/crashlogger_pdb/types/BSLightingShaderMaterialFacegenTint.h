// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSLightingShaderMaterialFacegenTint; size 0xb0
#pragma once

#include "BSLightingShaderMaterialBase.h"
#include "NiColor_e5e1ad7d.h"
struct BSLightingShaderMaterialFacegenTint {
    BSLightingShaderMaterialBase _base;
    NiColor_e5e1ad7d tintColor;
    unsigned int padAC;
};
static_assert(sizeof(BSLightingShaderMaterialFacegenTint) == 176, "BSLightingShaderMaterialFacegenTint layout differs from the PDB");
