// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSLightingShaderProperty; size 0x160
// one of 2 different PDB types sharing this name
#pragma once

#include "BSShaderPropertyLightData_d731fdd1.h"
#include "BSShaderProperty_a291ab3c.h"
#include "NiColorA_7eee66f4.h"
#include "RenderPassArray.h"
struct BSRenderPass_87210fc9;
struct NiColor_e5e1ad7d;
struct BSLightingShaderProperty_d06e568e {
    BSShaderProperty_a291ab3c _base;
    unsigned char arrayQueue_raw[48];
    RenderPassArray shadowMapOrMaskPasses;
    RenderPassArray occlusionPasses;
    RenderPassArray volumetricShadowUtilityPasses;
    BSRenderPass_87210fc9* depthPass;
    NiColor_e5e1ad7d* emissiveColor;
    float emissiveMult;
    float forcedDarkness;
    float specularLODFade;
    float envmapLODFade;
    unsigned int unk108;
    NiColorA_7eee66f4 projectedUVParams;
    NiColorA_7eee66f4 projectedUVColor;
    int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    BSShaderPropertyLightData_d731fdd1 lightingLightData;
};
static_assert(sizeof(BSLightingShaderProperty_d06e568e) == 352, "BSLightingShaderProperty_d06e568e layout differs from the PDB");
