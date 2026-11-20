// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESObjectLIGH; size 0x130
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSFixedString.h"
#include "TESBoundObject__Data.h"
#include "TESFileContainer_70f0bdf4.h"
#include "TESIcon.h"
#include "TESObjectLIGH__Data.h"
struct BGSDestructibleObjectForm__DestructibleObjectData;
struct BGSDestructibleObjectForm__VFTable;
struct BGSEquipSlot;
struct BGSEquipType__VFTable;
struct BGSLensFlare_625055d6;
struct BGSMessageIcon__VFTable;
struct BGSSoundDescriptorForm_de361764;
struct BSResource__ID;
struct TESFullName__VFTable;
struct TESIcon__VFTable;
struct TESModelTextureSwap__VFTable;
struct TESObjectLIGH__VFTable;
struct TESValueForm__VFTable;
struct TESWeightForm__VFTable;
struct TESObjectLIGH {
    TESObjectLIGH__VFTable* vftable_TESObjectLIGH_0;
    TESFileContainer_70f0bdf4 FormSourceFiles_8;
    unsigned int FormFlags_10;
    unsigned int FormId_14;
    unsigned short FormGameFlags_18;
    unsigned char FormType_1A;
    char _pad_1B[5];
    TESBoundObject__Data BoundData_20;
    char _pad_2C[4];
    TESFullName__VFTable* vftable_TESFullName_30;
    BSFixedString Text_38;
    TESModelTextureSwap__VFTable* vftable_TESModelTextureSwap_40;
    BSFixedString ModelName_48;
    BSResource__ID* Textures_50;
    void* Addons_58;
    unsigned short NumTextures_60;
    unsigned short NumAddons_62;
    char _pad_64[4];
    void* AlternateTextures_68;
    int NumAlternateTextures_70;
    char _pad_74[4];
    TESIcon__VFTable* vftable_TESIcon_78;
    BSFixedString TextureName_80;
    BGSMessageIcon__VFTable* vftable_BGSMessageIcon_88;
    TESIcon Icon_90;
    TESWeightForm__VFTable* vftable_TESWeightForm_A0;
    float WeightValue_A8;
    char _pad_AC[4];
    TESValueForm__VFTable* vftable_TESValueForm_B0;
    unsigned int ValueAmount_B8;
    char _pad_BC[4];
    BGSDestructibleObjectForm__VFTable* vftable_BGSDestructibleObjectForm_C0;
    BGSDestructibleObjectForm__DestructibleObjectData* Data_C8;
    BGSEquipType__VFTable* vftable_BGSEquipType_D0;
    BGSEquipSlot* EquipSlot_D8;
    TESObjectLIGH__Data LightData_E0;
    float fade;
    char _pad_10C[4];
    BGSSoundDescriptorForm_de361764* Sound_110;
    unsigned char undefined_118[12];
    unsigned int pad124;
    BGSLensFlare_625055d6* lensFlare;
};
static_assert(sizeof(TESObjectLIGH) == 304, "TESObjectLIGH layout differs from the PDB");
