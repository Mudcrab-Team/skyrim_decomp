// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSProcedureTreeConditionalItem; size 0x10
#pragma once

#include "IProcedureTreeItem.h"
#include "TESCondition_4d3cdc88.h"
struct BGSProcedureTreeConditionalItem {
    IProcedureTreeItem _base;
    TESCondition_4d3cdc88 conditions;
};
static_assert(sizeof(BGSProcedureTreeConditionalItem) == 16, "BGSProcedureTreeConditionalItem layout differs from the PDB");
