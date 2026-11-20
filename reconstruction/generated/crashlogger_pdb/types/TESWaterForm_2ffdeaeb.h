// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESWaterForm; size 0x260
// one of 2 different PDB types sharing this name
#pragma once

#include "NiPoint3.h"
#include "TESAttackDamageForm.h"
#include "TESForm.h"
#include "TESFullName.h"
#include "WaterShaderData.h"
struct BGSMaterialType;
struct BGSSoundDescriptorForm;
struct BSWaterShaderMaterial_a6438530;
struct SpellItem_847bf892;
struct TESImageSpace_93cfb701;
struct TESObjectACTI_e432b98e;
struct TESWaterForm_2ffdeaeb {
    TESForm _base;
    TESFullName _base_TESFullName;
    TESAttackDamageForm _base_TESAttackDamageForm;
    bool needUpdate;
    unsigned char pad41;
    unsigned short pad42;
    unsigned char texScroll_raw[48];
    unsigned int pad074;
    unsigned char noiseTextures_raw[64];
    unsigned char alpha;
    unsigned char flags;  // Flag in the PDB is wider than this slot
    unsigned short pad0BA;
    unsigned int pad0BC;
    BGSMaterialType* materialType;
    BGSSoundDescriptorForm* waterSound;
    WaterShaderData data;
    TESWaterForm_2ffdeaeb* waterWeatherControl[3];
    int currentTextureSelect[2];
    unsigned int frequencyX;
    unsigned int frequencyY;
    int octaves;
    float amplitude;
    float lacunarity;
    float bias;
    float gain;
    unsigned int pad1F4;
    SpellItem_847bf892* contactSpell;
    unsigned char noiseTextureData_raw[32];
    TESObjectACTI_e432b98e* placeableAutoWater;
    TESObjectACTI_e432b98e* placeableLODWater;
    BSWaterShaderMaterial_a6438530* waterShaderMaterial;
    bool resetNoiseTextures;
    unsigned char pad239;
    unsigned short pad23A;
    unsigned int pad23C;
    TESImageSpace_93cfb701* imageSpace;
    NiPoint3 linearVelocity;
    NiPoint3 angularVelocity;
};
static_assert(sizeof(TESWaterForm_2ffdeaeb) == 608, "TESWaterForm_2ffdeaeb layout differs from the PDB");
