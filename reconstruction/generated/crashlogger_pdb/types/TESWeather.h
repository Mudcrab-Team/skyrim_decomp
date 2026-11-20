// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESWeather; size 0x8d8
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSTArray_RE__TESObjectSTAT_b213d88b_a60fa518.h"
#include "FogData.h"
#include "TESFileContainer_70f0bdf4.h"
#include "TESModel.h"
#include "TESTexture1024.h"
#include "TESWeather__WeatherSoundList.h"
struct BGSLensFlare_625055d6;
struct BGSReferenceEffect_f86c67af;
struct BGSShaderParticleGeometryData;
struct BGSVolumetricLighting_806654e3;
struct TESImageSpace;
struct TESWeather__VFTable;
struct TESWeather {
    TESWeather__VFTable* vftable_TESWeather_0;
    TESFileContainer_70f0bdf4 FormSourceFiles_8;
    unsigned int FormFlags_10;
    unsigned int FormId_14;
    unsigned short FormGameFlags_18;
    unsigned char FormType_1A;
    char _pad_1B[5];
    TESTexture1024 CloudTextures_20[32];
    char CloudLayerSpeedY_220[32];
    char CloudLayerSpeedX_240[32];
    unsigned char undefined_260[512];
    float CloudAlpha_460[32][4];
    unsigned int cloudLayerDisabledBits;
    unsigned char data_raw[20];
    FogData fogData;
    unsigned char undefined_698[272];
    TESWeather__WeatherSoundList Sounds_7A8;
    BSTArray_RE__TESObjectSTAT_b213d88b_a60fa518 skyStatics;
    unsigned int numCloudLayers;
    unsigned int pad7D4;
    TESImageSpace* imageSpaces[4];
    unsigned char directionalAmbientLightingColors_raw[128];
    TESModel aurora;
    BGSLensFlare_625055d6* sunGlareLensFlare;
    BGSVolumetricLighting_806654e3* volumetricLighting[4];
    BGSShaderParticleGeometryData* precipitationData;
    BGSReferenceEffect_f86c67af* referenceEffect;
};
static_assert(sizeof(TESWeather) == 2264, "TESWeather layout differs from the PDB");
