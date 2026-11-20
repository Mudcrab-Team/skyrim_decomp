// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSLightingShaderProperty; size 0x160
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSShaderProperty.h"
#include "BSShaderPropertyLightData.h"
#include "NiColorA.h"
#include "RenderPassArray.h"
struct BSRenderPass;
struct NiColor;
struct BSLightingShaderProperty {
    BSShaderProperty _base;
    unsigned char arrayQueue_raw[48];
    RenderPassArray shadowMapOrMaskPasses;
    RenderPassArray occlusionPasses;
    RenderPassArray volumetricShadowUtilityPasses;
    BSRenderPass* depthPass;
    NiColor* emissiveColor;
    float emissiveMult;
    float forcedDarkness;
    float specularLODFade;
    float envmapLODFade;
    unsigned int unk108;
    NiColorA projectedUVParams;
    NiColorA projectedUVColor;
    int unk12C;
    unsigned int unk130;
    unsigned int unk134;
    BSShaderPropertyLightData lightingLightData;
};
static_assert(sizeof(BSLightingShaderProperty) == 352, "BSLightingShaderProperty layout differs from the PDB");
