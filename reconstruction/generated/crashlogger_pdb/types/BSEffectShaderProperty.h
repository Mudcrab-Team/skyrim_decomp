// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSEffectShaderProperty; size 0xa0
#pragma once

#include "BSShaderProperty_a291ab3c.h"
#include "RenderPassArray.h"
struct NiColor_e5e1ad7d;
struct BSEffectShaderProperty {
    BSShaderProperty_a291ab3c _base;
    NiColor_e5e1ad7d* emittanceColor;
    RenderPassArray shadowMapOrMaskRenderPassList;
};
static_assert(sizeof(BSEffectShaderProperty) == 160, "BSEffectShaderProperty layout differs from the PDB");
