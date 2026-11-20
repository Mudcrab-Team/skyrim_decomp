// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSLightingShaderMaterialHairTint; size 0xb0
#pragma once

#include "BSLightingShaderMaterialBase.h"
#include "NiColor_e5e1ad7d.h"
struct BSLightingShaderMaterialHairTint {
    BSLightingShaderMaterialBase _base;
    NiColor_e5e1ad7d tintColor;
    unsigned int padAC;
};
static_assert(sizeof(BSLightingShaderMaterialHairTint) == 176, "BSLightingShaderMaterialHairTint layout differs from the PDB");
