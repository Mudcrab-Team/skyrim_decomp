// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSEffectShaderData; size 0x88
// one of 2 different PDB types sharing this name
#pragma once

#include "AlphaFunction.h"
#include "BSIntrusiveRefCounted.h"
#include "DepthStencilDepthMode.h"
#include "NiColorA_7eee66f4.h"
#include "NiPointer_RE__NiTexture_277bfefd.h"
#include "TextureAddressMode.h"
struct BSEffectShaderData_e3d33052 {
    BSIntrusiveRefCounted _base;
    unsigned int pad04;
    unsigned char nodeFilterFunction_raw[8];
    NiPointer_RE__NiTexture_277bfefd baseTexture;
    NiPointer_RE__NiTexture_277bfefd paletteTexture;
    NiPointer_RE__NiTexture_277bfefd blockOutTexture;
    TextureAddressMode textureClampMode;
    NiColorA_7eee66f4 fillColor;
    NiColorA_7eee66f4 rimColor;
    float baseFillScale;
    float baseFillAlpha;
    float baseRimAlpha;
    float uOffset;
    float vOffset;
    float uScale;
    float vScale;
    float edgeExponent;
    float boundDiameter;
    AlphaFunction srcBlend;
    AlphaFunction destBlend;
    DepthStencilDepthMode zTestFunc;
    unsigned char alphaTestRef;
    bool grayscaleToColor;
    bool grayscaleToAlpha;
    bool ignoreTextureAlpha;
    bool baseTextureProjectedUVs;
    bool ignoreBaseGeomTexAlpha;
    bool lighting;
    bool alpha;
    unsigned int pad84;
};
static_assert(sizeof(BSEffectShaderData_e3d33052) == 136, "BSEffectShaderData_e3d33052 layout differs from the PDB");
