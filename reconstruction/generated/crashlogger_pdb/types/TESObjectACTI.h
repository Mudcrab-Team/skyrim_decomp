// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESObjectACTI; size 0xc8
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSFixedString.h"
#include "TESBoundObject__Data.h"
#include "TESFileContainer_70f0bdf4.h"
struct BGSDestructibleObjectForm__DestructibleObjectData;
struct BGSDestructibleObjectForm__VFTable;
struct BGSKeywordForm__VFTable;
struct BGSKeyword_f67121b2;
struct BGSOpenCloseForm__VFTable;
struct BGSSoundDescriptorForm_de361764;
struct BSResource__ID;
struct TESFullName__VFTable;
struct TESModelTextureSwap__VFTable;
struct TESObjectACTI__VFTable;
struct TESWaterForm;
struct TESObjectACTI {
    TESObjectACTI__VFTable* vftable_TESObjectACTI_0;
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
    BGSDestructibleObjectForm__VFTable* vftable_BGSDestructibleObjectForm_78;
    BGSDestructibleObjectForm__DestructibleObjectData* Data_80;
    BGSOpenCloseForm__VFTable* vftable_BGSOpenCloseForm_88;
    BGSKeywordForm__VFTable* vftable_BGSKeywordForm_90;
    BGSKeyword_f67121b2** Keywords_98;
    int Count_A0;
    char _pad_A4[4];
    BGSSoundDescriptorForm_de361764* SoundLoop_A8;
    BGSSoundDescriptorForm_de361764* SoundActivate_B0;
    TESWaterForm* WaterForm_B8;
    unsigned short flags;  // ActiFlags in the PDB is wider than this slot
    unsigned short padC2;
    unsigned int padC4;
};
static_assert(sizeof(TESObjectACTI) == 200, "TESObjectACTI layout differs from the PDB");
