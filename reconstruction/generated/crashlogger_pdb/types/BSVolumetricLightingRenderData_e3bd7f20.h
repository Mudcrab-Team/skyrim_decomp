// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSVolumetricLightingRenderData; size 0x30
// one of 2 different PDB types sharing this name
#pragma once

#include "CustomColor.h"
#include "Density.h"
#include "NiColor_e5e1ad7d.h"
#include "PhaseFunction.h"
#include "SamplingRepartition.h"
struct BSVolumetricLightingRenderData_e3bd7f20 {
    float intensity;
    CustomColor customColor;
    NiColor_e5e1ad7d color;
    Density density;
    PhaseFunction phaseFunction;
    SamplingRepartition samplingRepartition;
};
static_assert(sizeof(BSVolumetricLightingRenderData_e3bd7f20) == 48, "BSVolumetricLightingRenderData_e3bd7f20 layout differs from the PDB");
