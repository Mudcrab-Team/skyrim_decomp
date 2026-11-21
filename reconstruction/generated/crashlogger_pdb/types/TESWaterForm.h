// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESWaterForm; size 0x260
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSFixedString.h"
#include "NiColorA.h"
#include "NiPoint3_a7124070.h"
#include "TESAttackDamageForm_70fa2f9d.h"
#include "TESFileContainer_70f0bdf4.h"
#include "TESFullName_88f61e2a.h"
struct BGSMaterialType_c56427e2;
struct BGSSoundDescriptorForm_de361764;
struct BSWaterShaderMaterial;
struct SpellItem;
struct TESAttackDamageForm__VFTable;
struct TESFullName__VFTable;
struct TESImageSpace;
struct TESObjectACTI;
struct TESWaterForm__VFTable;
#pragma pack(push, 1)
struct TESWaterForm {
    float Amplitude_1E4;
    unsigned short AttackDamage_38;
    unsigned char flags;  // TESWaterForm::Flag in the PDB is wider than this slot
    char Alpha_B8;
    unsigned char FormType_1A;
    char _pad_1F4[4];
    TESImageSpace* ImageSpace_240;
    unsigned char undefined_15[11];
    TESFullName_88f61e2a _base_TESFullName;
    TESAttackDamageForm_70fa2f9d _base_TESAttackDamageForm;
    bool needUpdate;
    unsigned char pad41;
    unsigned short pad42;
    unsigned char undefined_44[17];
    NiPoint3_a7124070 LinearVelocity_248;
    BSFixedString Text_28;
    unsigned int FormId_14;
    unsigned char undefined_6d[7];
    unsigned int pad074;
    unsigned char undefined_78[1];
    char _pad_239[7];
    float Lacunarity_1E8;
    int CurrentTextureSelect_1D0[2];
    SpellItem* ContactSpell_1F8;
    char _pad_41[3];
    unsigned char undefined_97[33];
    unsigned char alpha;
    unsigned char flags_2;  // Flag in the PDB is wider than this slot
    unsigned short pad0BA;
    unsigned int pad0BC;
    BGSMaterialType_c56427e2* materialType;
    BGSSoundDescriptorForm_de361764* waterSound;
    unsigned char undefined_d0[175];
    TESWaterForm__VFTable* vftable_TESWaterForm_0;
    char _pad_BA[6];
    bool ResetNoiseTextures_238;
    int FrequencyY_1DC;
    NiColorA TexScroll_44[3];
    int FrequencyX_1D8;
    TESObjectACTI* PlaceableAutoWater_220;
    int Octaves_1E0;
    char _pad_1B[5];
    unsigned char undefined_1d7[1];
    unsigned int frequencyX;
    unsigned int frequencyY;
    unsigned char undefined_1e0[1];
    float Bias_1EC;
    bool NeedUpdate_40;
    unsigned char undefined_1e6[2];
    float lacunarity;
    float bias;
    float gain;
    float Gain_1F0;
    TESFileContainer_70f0bdf4 FormSourceFiles_8;
    BSWaterShaderMaterial* WaterShaderMaterial_230;
    unsigned int FormFlags_10;
    TESFullName__VFTable* vftable_TESFullName_20;
    TESAttackDamageForm__VFTable* vftable_TESAttackDamageForm_30;
    unsigned char undefined_21c[4];
    TESObjectACTI* placeableAutoWater;
    TESObjectACTI* placeableLODWater;
    BSWaterShaderMaterial* waterShaderMaterial;
    bool resetNoiseTextures;
    unsigned char pad239;
    unsigned short pad23A;
    unsigned int pad23C;
    TESImageSpace* imageSpace;
    NiPoint3_a7124070 linearVelocity;
    unsigned char undefined_254[8];
    char _pad_74[4];
};
#pragma pack(pop)
static_assert(sizeof(TESWaterForm) == 608, "TESWaterForm layout differs from the PDB");
