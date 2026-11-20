// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSStoryManagerNodeBase; size 0x48
// one of 2 different PDB types sharing this name
#pragma once

#include "BGSStoryManagerTreeForm.h"
#include "TESCondition_4d3cdc88.h"
struct BGSStoryManagerBranchNode;
struct BGSStoryManagerNodeBase_cce81802 {
    BGSStoryManagerTreeForm _base;
    BGSStoryManagerBranchNode* parent;
    BGSStoryManagerNodeBase_cce81802* previousSibling;
    unsigned int maxQuests;
    unsigned char flags_raw[4];
    TESCondition_4d3cdc88 conditions;
};
static_assert(sizeof(BGSStoryManagerNodeBase_cce81802) == 72, "BGSStoryManagerNodeBase_cce81802 layout differs from the PDB");
