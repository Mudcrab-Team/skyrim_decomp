// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: EnchantmentItem; size 0xc0
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSFixedString.h"
#include "BSTArray_ActiveEffect__EffectItem.h"
#include "BSTSmartPointer_QueuedFile_22a31e4f.h"
#include "TESBoundObject__Data.h"
#include "TESFileContainer_70f0bdf4.h"
struct BGSKeywordForm__VFTable;
struct BGSKeyword_f67121b2;
struct BGSListForm_bac89fb1;
struct EffectSetting;
struct EnchantmentItem__VFTable;
struct TESFullName__VFTable;
struct EnchantmentItem {
    EnchantmentItem__VFTable* vftable_EnchantmentItem_0;
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
    int CostOverride_90;
    unsigned int EnchantFlags_94;
    int CastingType_98;
    int ChargeOverride_9C;
    int Delivery_A0;
    int SpellType_A4;
    float ChargeTime_A8;
    char _pad_AC[4];
    EnchantmentItem* BaseEnchantment_B0;
    BGSListForm_bac89fb1* WornRestrictions_B8;
};
static_assert(sizeof(EnchantmentItem) == 192, "EnchantmentItem layout differs from the PDB");
