// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSStoryManagerNodeBase; size 0x48
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BGSStoryManagerTreeForm_f3bb0b5c.h"
#include "TESCondition.h"
struct BGSStoryManagerBranchNode_99515320;
struct BGSStoryManagerNodeBase {
    BGSStoryManagerTreeForm_f3bb0b5c _base;
    BGSStoryManagerBranchNode_99515320* parent;
    BGSStoryManagerNodeBase* previousSibling;
    unsigned int maxQuests;
    unsigned char flags_raw[4];
    TESCondition conditions;
};
static_assert(sizeof(BGSStoryManagerNodeBase) == 72, "BGSStoryManagerNodeBase layout differs from the PDB");
