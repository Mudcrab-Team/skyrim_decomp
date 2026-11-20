// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSDirectionalAmbientLightingColors; size 0x20
// one of 2 different PDB types sharing this name
#pragma once

#include "Color_aa361e09.h"
#include "Directional.h"
struct BGSDirectionalAmbientLightingColors_bbed7424 {
    Directional directional;
    Color_aa361e09 specular;
    float fresnelPower;
};
static_assert(sizeof(BGSDirectionalAmbientLightingColors_bbed7424) == 32, "BGSDirectionalAmbientLightingColors_bbed7424 layout differs from the PDB");
