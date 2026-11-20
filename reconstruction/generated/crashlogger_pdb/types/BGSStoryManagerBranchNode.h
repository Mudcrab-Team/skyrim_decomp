// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSStoryManagerBranchNode; size 0x60
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BGSStoryManagerNodeBase_cce81802.h"
#include "BSTArray_RE__BGSStoryManagerNodeBase_d2e17ade_a86facfd.h"
struct BGSStoryManagerBranchNode {
    BGSStoryManagerNodeBase_cce81802 _base;
    BSTArray_RE__BGSStoryManagerNodeBase_d2e17ade_a86facfd children;
};
static_assert(sizeof(BGSStoryManagerBranchNode) == 96, "BGSStoryManagerBranchNode layout differs from the PDB");
