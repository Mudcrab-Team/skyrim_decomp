// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSDirectionalAmbientLightingColors; size 0x20
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "Color.h"
#include "Directional_7b755dc9.h"
struct BGSDirectionalAmbientLightingColors {
    Directional_7b755dc9 directional;
    Color specular;
    float fresnelPower;
};
static_assert(sizeof(BGSDirectionalAmbientLightingColors) == 32, "BGSDirectionalAmbientLightingColors layout differs from the PDB");
