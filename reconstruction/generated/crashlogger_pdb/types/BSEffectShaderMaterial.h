// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSEffectShaderMaterial; size 0x88
#pragma once

#include "BSFixedString_char_83b572b4.h"
#include "BSShaderMaterial_da61c263.h"
#include "NiColorA_7eee66f4.h"
#include "NiPointer_RE__NiSourceTexture_cf356212.h"
struct BSEffectShaderMaterial {
    BSShaderMaterial_da61c263 _base;
    float falloffStartAngle;
    float falloffStopAngle;
    float falloffStartOpacity;
    float falloffStopOpacity;
    NiColorA_7eee66f4 baseColor;
    NiPointer_RE__NiSourceTexture_cf356212 sourceTexture;
    NiPointer_RE__NiSourceTexture_cf356212 greyscaleTexture;
    float softFalloffDepth;
    float baseColorScale;
    BSFixedString_char_83b572b4 sourceTexturePath;
    BSFixedString_char_83b572b4 greyscaleTexturePath;
    unsigned char effectClampMode;  // TextureAddressMode in the PDB is wider than this slot
    unsigned char unk81;
    unsigned char undefined_82[6];
};
static_assert(sizeof(BSEffectShaderMaterial) == 136, "BSEffectShaderMaterial layout differs from the PDB");
