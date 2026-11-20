// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSBloodSplatterShaderProperty; size 0xb0
#pragma once

#include "BSShaderProperty_a291ab3c.h"
struct BSBloodSplatterShaderProperty {
    BSShaderProperty_a291ab3c _base;
    unsigned char bloodTextures_raw[24];
    int textureClampMode;
    unsigned char undefined_a4[4];
    float* alphaSource;
};
static_assert(sizeof(BSBloodSplatterShaderProperty) == 176, "BSBloodSplatterShaderProperty layout differs from the PDB");
