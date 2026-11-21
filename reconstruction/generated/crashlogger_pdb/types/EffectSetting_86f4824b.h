// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: EffectSetting; size 0x198
// one of 2 different PDB types sharing this name
#pragma once

#include "BGSKeywordForm_9c083c55.h"
#include "BGSMenuDisplayObject.h"
#include "BSFixedString_char_83b572b4.h"
#include "BSSimpleList_RE__EffectSetting_2f2d5c70.h"
#include "BSTArray_RE__EffectSetting__SoundPair_4cb0c419.h"
#include "EffectSettingData.h"
#include "TESCondition_4d3cdc88.h"
#include "TESForm.h"
#include "TESFullName.h"
struct EffectSetting_86f4824b {
    TESForm _base;
    TESFullName _base_TESFullName;
    BGSMenuDisplayObject _base_BGSMenuDisplayObject;
    BGSKeywordForm_9c083c55 _base_BGSKeywordForm;
    unsigned char filterValidationFunction_raw[8];
    void* filterValidationItem;
    EffectSettingData data;
    BSSimpleList_RE__EffectSetting_2f2d5c70 counterEffects;
    BSTArray_RE__EffectSetting__SoundPair_4cb0c419 effectSounds;
    BSFixedString_char_83b572b4 magicItemDescription;
    int effectLoadedCount;
    int associatedItemLoadedCount;
    TESCondition_4d3cdc88 conditions;
};
static_assert(sizeof(EffectSetting_86f4824b) == 408, "EffectSetting_86f4824b layout differs from the PDB");
