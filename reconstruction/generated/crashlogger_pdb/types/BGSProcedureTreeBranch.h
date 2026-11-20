// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSProcedureTreeBranch; size 0x30
#pragma once

#include "BGSProcedureTreeConditionalItem.h"
#include "BSTArray_RE__BGSProcedureTreeConditionalItem_9168dcd1.h"
struct BGSProcedureTreeBranch {
    BGSProcedureTreeConditionalItem _base;
    BSTArray_RE__BGSProcedureTreeConditionalItem_9168dcd1 conditions;
    unsigned long long unk28;
};
static_assert(sizeof(BGSProcedureTreeBranch) == 48, "BGSProcedureTreeBranch layout differs from the PDB");
