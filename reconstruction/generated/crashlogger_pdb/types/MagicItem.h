// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MagicItem; size 0x90
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSFixedString.h"
#include "BSTArray_ActiveEffect__EffectItem.h"
#include "BSTSmartPointer_QueuedFile_22a31e4f.h"
#include "TESBoundObject__Data.h"
#include "TESFileContainer_70f0bdf4.h"
struct BGSKeywordForm__VFTable;
struct BGSKeyword_f67121b2;
struct EffectSetting;
struct MagicItem__VFTable;
struct TESFullName__VFTable;
struct MagicItem {
    MagicItem__VFTable* vftable_MagicItem_0;
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
};
static_assert(sizeof(MagicItem) == 144, "MagicItem layout differs from the PDB");
