// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: SpellItem; size 0xe8
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BGSLocalizedStringDL_8410e68a.h"
#include "BSFixedString.h"
#include "BSTArray_ActiveEffect__EffectItem.h"
#include "BSTSmartPointer_QueuedFile_22a31e4f.h"
#include "SpellItem__Data.h"
#include "TESBoundObject__Data.h"
#include "TESFileContainer_70f0bdf4.h"
struct BGSEquipSlot;
struct BGSEquipType__VFTable;
struct BGSKeywordForm__VFTable;
struct BGSKeyword_f67121b2;
struct BGSMenuDisplayObject__VFTable;
struct EffectSetting;
struct SpellItem__VFTable;
struct TESBoundObject;
struct TESDescription__VFTable;
struct TESFullName__VFTable;
struct SpellItem {
    SpellItem__VFTable* vftable_SpellItem_0;
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
};
static_assert(sizeof(SpellItem) == 232, "SpellItem layout differs from the PDB");
