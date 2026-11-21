// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSWaterShaderMaterial; size 0x180
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "DepthProperties.h"
#include "NiColor.h"
#include "NiColorA.h"
#include "NiPlane.h"
#include "NiPoint2.h"
#include "NiPointer_RE__NiSourceTexture_cf356212.h"
struct BSWaterShaderMaterial__VFTable;
struct BSWaterShaderMaterial {
    BSWaterShaderMaterial__VFTable* vftable_BSWaterShaderMaterial_0;
    int refCount_8;
    NiPoint2 TexCoordOffset_C[2];
    NiPoint2 TexCoordScale_1C[2];
    unsigned int HashKey_2C;
    unsigned char undefined_30[8];
    NiPointer_RE__NiSourceTexture_cf356212 staticReflectionTexture;
    NiPointer_RE__NiSourceTexture_cf356212 normalTexture1;
    NiPointer_RE__NiSourceTexture_cf356212 normalTexture2;
    NiPointer_RE__NiSourceTexture_cf356212 normalTexture3;
    NiPointer_RE__NiSourceTexture_cf356212 normalTexture4;
    NiColor shallowWaterColor;
    float sunSparklePower;
    NiColorA deepWaterColor;
    NiColorA reflectionColor;
    float sunSpecularPower;
    float reflectionAmount;
    float alpha;
    float refractionMagnitude;
    unsigned long long unk0A0;
    float unk0A8;
    unsigned char undefined_ac[4];
    unsigned long long unk0B0;
    unsigned long long unk0B8;
    unsigned long long unk0C0;
    float specularPower;
    unsigned char undefined_cc[4];
    unsigned long long unk0D0;
    unsigned long long unk0D8;
    float noiseFalloff;
    float reflectionMagnitude;
    float sunSparkleMagnitude;
    float unk0EC;
    DepthProperties depthProperties;
    NiPoint2 normalScroll1;
    NiPoint2 normalScroll2;
    NiPoint2 normalScroll3;
    unsigned long long unk118;
    float uvScaleA[3];
    unsigned int unk12C;
    float amplitudeA[3];
    float displacementDampener;
    NiPlane plane;
    unsigned int unk150;
    float flowmapScale;
    float aboveWaterFogDistFar;
    float unk15C;
    float unk160;
    float underwaterFogDistFar;
    float unk168;
    float underwaterFogAmount;
    float fresnelAmount;
    unsigned int unk174;
    unsigned int unk178;
    unsigned char unk17C;
    unsigned char unk17D;
    unsigned char unk17E;
    unsigned char unk17F;
};
static_assert(sizeof(BSWaterShaderMaterial) == 384, "BSWaterShaderMaterial layout differs from the PDB");
