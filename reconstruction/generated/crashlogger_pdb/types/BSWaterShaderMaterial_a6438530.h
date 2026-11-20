// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BSWaterShaderMaterial; size 0x180
// one of 2 different PDB types sharing this name
#pragma once

#include "BSShaderMaterial_da61c263.h"
#include "DepthProperties.h"
#include "NiColorA_7eee66f4.h"
#include "NiColor_e5e1ad7d.h"
#include "NiPlane_4e79da03.h"
#include "NiPoint2_6bdffc9f.h"
#include "NiPointer_RE__NiSourceTexture_cf356212.h"
struct BSWaterShaderMaterial_a6438530 {
    BSShaderMaterial_da61c263 _base;
    NiPointer_RE__NiSourceTexture_cf356212 staticReflectionTexture;
    NiPointer_RE__NiSourceTexture_cf356212 normalTexture1;
    NiPointer_RE__NiSourceTexture_cf356212 normalTexture2;
    NiPointer_RE__NiSourceTexture_cf356212 normalTexture3;
    NiPointer_RE__NiSourceTexture_cf356212 normalTexture4;
    NiColor_e5e1ad7d shallowWaterColor;
    float sunSparklePower;
    NiColorA_7eee66f4 deepWaterColor;
    NiColorA_7eee66f4 reflectionColor;
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
    NiPoint2_6bdffc9f normalScroll1;
    NiPoint2_6bdffc9f normalScroll2;
    NiPoint2_6bdffc9f normalScroll3;
    unsigned long long unk118;
    float uvScaleA[3];
    unsigned int unk12C;
    float amplitudeA[3];
    float displacementDampener;
    NiPlane_4e79da03 plane;
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
static_assert(sizeof(BSWaterShaderMaterial_a6438530) == 384, "BSWaterShaderMaterial_a6438530 layout differs from the PDB");
