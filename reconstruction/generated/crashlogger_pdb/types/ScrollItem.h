// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ScrollItem; size 0x168
#pragma once

#include "BGSLocalizedStringDL_8410e68a.h"
#include "BSFixedString.h"
#include "BSTArray_ActiveEffect__EffectItem.h"
#include "BSTSmartPointer_QueuedFile_22a31e4f.h"
#include "SpellItem__Data.h"
#include "TESBoundObject__Data.h"
#include "TESFileContainer_70f0bdf4.h"
struct BGSDestructibleObjectForm__DestructibleObjectData;
struct BGSDestructibleObjectForm__VFTable;
struct BGSEquipSlot;
struct BGSEquipType__VFTable;
struct BGSKeywordForm__VFTable;
struct BGSKeyword_f67121b2;
struct BGSMenuDisplayObject__VFTable;
struct BGSPickupPutdownSounds__VFTable;
struct BGSSoundDescriptorForm_de361764;
struct BSResource__ID;
struct EffectSetting;
struct ScrollItem__VFTable;
struct TESBoundObject;
struct TESDescription__VFTable;
struct TESFullName__VFTable;
struct TESModelTextureSwap__VFTable;
struct TESValueForm__VFTable;
struct TESWeightForm__VFTable;
struct ScrollItem {
    ScrollItem__VFTable* vftable_ScrollItem_0;
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
    BGSEquipType__VFTable* vftable_BGSEquipType_90;
    BGSEquipSlot* EquipSlot_98;
    BGSMenuDisplayObject__VFTable* vftable_BGSMenuDisplayObject_A0;
    TESBoundObject* MenuDisplayObject_A8;
    TESDescription__VFTable* vftable_TESDescription_B0;
    unsigned int FileOffset_B8;
    BGSLocalizedStringDL_8410e68a DescriptionText_BC;
    SpellItem__Data SpellData_C0;
    TESModelTextureSwap__VFTable* vftable_TESModelTextureSwap_E8;
    BSFixedString ModelName_F0;
    BSResource__ID* Textures_F8;
    void* Addons_100;
    unsigned short NumTextures_108;
    unsigned short NumAddons_10A;
    char _pad_10C[4];
    void* AlternateTextures_110;
    int NumAlternateTextures_118;
    char _pad_11C[4];
    BGSDestructibleObjectForm__VFTable* vftable_BGSDestructibleObjectForm_120;
    BGSDestructibleObjectForm__DestructibleObjectData* Data_128;
    BGSPickupPutdownSounds__VFTable* vftable_BGSPickupPutdownSounds_130;
    BGSSoundDescriptorForm_de361764* PickupSound_138;
    BGSSoundDescriptorForm_de361764* PutdownSound_140;
    TESWeightForm__VFTable* vftable_TESWeightForm_148;
    float WeightValue_150;
    char _pad_154[4];
    TESValueForm__VFTable* vftable_TESValueForm_158;
    unsigned int ValueAmount_160;
    char _pad_164[4];
};
static_assert(sizeof(ScrollItem) == 360, "ScrollItem layout differs from the PDB");
