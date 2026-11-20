// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSVolumetricLightingRenderData; size 0x30
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSVolumetricLightingRenderData__CustomColorData.h"
#include "BSVolumetricLightingRenderData__DensityData.h"
#include "BSVolumetricLightingRenderData__PhaseFunctionData.h"
#include "BSVolumetricLightingRenderData__SamplingRepartitionData.h"
#include "NiColor.h"
struct BSVolumetricLightingRenderData {
    float intensity;
    BSVolumetricLightingRenderData__CustomColorData customColor;
    NiColor color;
    BSVolumetricLightingRenderData__DensityData density;
    BSVolumetricLightingRenderData__PhaseFunctionData phaseFunction;
    BSVolumetricLightingRenderData__SamplingRepartitionData samplingRepartition;
};
static_assert(sizeof(BSVolumetricLightingRenderData) == 48, "BSVolumetricLightingRenderData layout differs from the PDB");
