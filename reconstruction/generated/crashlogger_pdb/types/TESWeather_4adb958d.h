// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESWeather; size 0x8d8
// one of 2 different PDB types sharing this name
#pragma once

#include "BSTArray_RE__TESObjectSTAT_b213d88b.h"
#include "Data_44aaa72b.h"
#include "FogData.h"
#include "TESForm.h"
#include "TESModel_c52655e4.h"
#include "WeatherSoundList.h"
struct BGSLensFlare;
struct BGSReferenceEffect;
struct BGSShaderParticleGeometryData_cc38b210;
struct BGSVolumetricLighting;
struct TESImageSpace_93cfb701;
struct TESWeather_4adb958d {
    TESForm _base;
    unsigned char cloudTextures_raw[512];
    unsigned char cloudLayerSpeedY[32];
    unsigned char cloudLayerSpeedX[32];
    unsigned char cloudColorData_raw[512];
    float cloudAlpha[4][32];
    unsigned int cloudLayerDisabledBits;
    Data_44aaa72b data;
    FogData fogData;
    unsigned char colorData_raw[272];
    WeatherSoundList sounds;
    BSTArray_RE__TESObjectSTAT_b213d88b skyStatics;
    unsigned int numCloudLayers;
    unsigned int pad7D4;
    TESImageSpace_93cfb701* imageSpaces[4];
    unsigned char directionalAmbientLightingColors_raw[128];
    TESModel_c52655e4 aurora;
    BGSLensFlare* sunGlareLensFlare;
    BGSVolumetricLighting* volumetricLighting[4];
    BGSShaderParticleGeometryData_cc38b210* precipitationData;
    BGSReferenceEffect* referenceEffect;
};
static_assert(sizeof(TESWeather_4adb958d) == 2264, "TESWeather_4adb958d layout differs from the PDB");
