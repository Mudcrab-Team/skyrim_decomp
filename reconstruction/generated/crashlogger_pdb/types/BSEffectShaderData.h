// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSEffectShaderData; size 0x88
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "AlphaFunction.h"
#include "BSIntrusiveRefCounted_8d4cb673.h"
#include "DepthStencilDepthMode.h"
#include "NiColorA.h"
#include "NiPointer_RE__NiTexture_277bfefd.h"
#include "TextureAddressMode.h"
struct BSEffectShaderData {
    BSIntrusiveRefCounted_8d4cb673 _base;
    unsigned int pad04;
    unsigned char nodeFilterFunction_raw[8];
    NiPointer_RE__NiTexture_277bfefd baseTexture;
    NiPointer_RE__NiTexture_277bfefd paletteTexture;
    NiPointer_RE__NiTexture_277bfefd blockOutTexture;
    TextureAddressMode textureClampMode;
    NiColorA fillColor;
    NiColorA rimColor;
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
static_assert(sizeof(BSEffectShaderData) == 136, "BSEffectShaderData layout differs from the PDB");
