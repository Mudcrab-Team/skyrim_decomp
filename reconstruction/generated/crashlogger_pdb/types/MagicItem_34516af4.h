// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: MagicItem; size 0x90
// one of 2 different PDB types sharing this name
#pragma once

#include "BGSKeywordForm_9c083c55.h"
#include "BSTArray_RE__Effect_a9e8f95f.h"
#include "BSTSmartPointer_RE__QueuedFile_3db2ff8c.h"
#include "TESBoundObject_fc790793.h"
#include "TESFullName.h"
struct EffectSetting_86f4824b;
struct MagicItem_34516af4 {
    TESBoundObject_fc790793 _base;
    TESFullName _base_TESFullName;
    BGSKeywordForm_9c083c55 _base_BGSKeywordForm;
    BSTArray_RE__Effect_a9e8f95f effects;
    int hostileCount;
    unsigned int pad74;
    EffectSetting_86f4824b* avEffectSetting;
    unsigned int preloadCount;
    unsigned int pad84;
    BSTSmartPointer_RE__QueuedFile_3db2ff8c preloadedItem;
};
static_assert(sizeof(MagicItem_34516af4) == 144, "MagicItem_34516af4 layout differs from the PDB");
