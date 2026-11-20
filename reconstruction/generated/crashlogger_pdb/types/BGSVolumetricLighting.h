// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSVolumetricLighting; size 0x50
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSVolumetricLightingRenderData_e3bd7f20.h"
#include "TESForm.h"
struct BGSVolumetricLighting {
    TESForm _base;
    BSVolumetricLightingRenderData_e3bd7f20 _base_BSVolumetricLightingRenderData;
};
static_assert(sizeof(BGSVolumetricLighting) == 80, "BGSVolumetricLighting layout differs from the PDB");
