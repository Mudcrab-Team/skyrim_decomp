// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESWaterNormals; size 0x50
#pragma once

#include "NiPointer_RE__NiSourceTexture_cf356212.h"
#include "NiRefObject_f24a9221.h"
struct BSWaterShaderMaterial_a6438530;
struct TESWaterForm_2ffdeaeb;
struct TESWaterNormals {
    NiRefObject_f24a9221 _base;
    unsigned char flags;
    unsigned char undefined_11[7];
    TESWaterForm_2ffdeaeb* waterType;
    unsigned int unk20;
    unsigned char undefined_24[4];
    BSWaterShaderMaterial_a6438530* waterMaterial;
    NiPointer_RE__NiSourceTexture_cf356212 noiseLayer0;
    NiPointer_RE__NiSourceTexture_cf356212 noiseLayer1;
    NiPointer_RE__NiSourceTexture_cf356212 noiseLayer2;
    NiPointer_RE__NiSourceTexture_cf356212 noiseLayer3;
};
static_assert(sizeof(TESWaterNormals) == 80, "TESWaterNormals layout differs from the PDB");
