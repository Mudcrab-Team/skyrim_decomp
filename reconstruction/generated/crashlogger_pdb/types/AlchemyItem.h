// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: AlchemyItem; size 0x168
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "AlchemyItem__AlchemyItemData.h"
#include "BSFixedString.h"
#include "BSTArray_ActiveEffect__EffectItem.h"
#include "BSTSmartPointer_QueuedFile_22a31e4f.h"
#include "TESBoundObject__Data.h"
#include "TESFileContainer_70f0bdf4.h"
#include "TESIcon.h"
struct AlchemyItem__VFTable;
struct BGSDestructibleObjectForm__DestructibleObjectData;
struct BGSDestructibleObjectForm__VFTable;
struct BGSEquipSlot;
struct BGSEquipType__VFTable;
struct BGSKeywordForm__VFTable;
struct BGSKeyword_f67121b2;
struct BGSMessageIcon__VFTable;
struct BGSPickupPutdownSounds__VFTable;
struct BGSSoundDescriptorForm_de361764;
struct BSResource__ID;
struct EffectSetting;
struct TESFullName__VFTable;
struct TESIcon__VFTable;
struct TESModelTextureSwap__VFTable;
struct TESWeightForm__VFTable;
struct AlchemyItem {
    AlchemyItem__VFTable* vftable_AlchemyItem_0;
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
    BGSKeywordForm__VFTable* vftable_BGSKeywordForm_40;
    BGSKeyword_f67121b2** Keywords_48;
    int Count_50;
    char _pad_54[4];
    BSTArray_ActiveEffect__EffectItem Effects_58;
    int HostileCount_70;
    char _pad_74[4];
    EffectSetting* AVEffectSetting_78;
    int PreloadCount_80;
    char _pad_84[4];
    BSTSmartPointer_QueuedFile_22a31e4f PreloadedItem_88;
    TESModelTextureSwap__VFTable* vftable_TESModelTextureSwap_90;
    BSFixedString ModelName_98;
    BSResource__ID* Textures_A0;
    void* Addons_A8;
    unsigned short NumTextures_B0;
    unsigned short NumAddons_B2;
    char _pad_B4[4];
    void* AlternateTextures_B8;
    int NumAlternateTextures_C0;
    char _pad_C4[4];
    TESIcon__VFTable* vftable_TESIcon_C8;
    BSFixedString TextureName_D0;
    BGSMessageIcon__VFTable* vftable_BGSMessageIcon_D8;
    TESIcon Icon_E0;
    TESWeightForm__VFTable* vftable_TESWeightForm_F0;
    float WeightValue_F8;
    char _pad_FC[4];
    BGSEquipType__VFTable* vftable_BGSEquipType_100;
    BGSEquipSlot* EquipSlot_108;
    BGSDestructibleObjectForm__VFTable* vftable_BGSDestructibleObjectForm_110;
    BGSDestructibleObjectForm__DestructibleObjectData* Data_118;
    BGSPickupPutdownSounds__VFTable* vftable_BGSPickupPutdownSounds_120;
    BGSSoundDescriptorForm_de361764* PickupSound_128;
    BGSSoundDescriptorForm_de361764* PutdownSound_130;
    AlchemyItem__AlchemyItemData Data_138;
    TESIcon MessageIcon_158;
};
static_assert(sizeof(AlchemyItem) == 360, "AlchemyItem layout differs from the PDB");
