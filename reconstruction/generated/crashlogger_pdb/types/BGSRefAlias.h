// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSRefAlias; size 0x48
#pragma once

#include "BGSBaseAlias.h"
#include "GenericFillData.h"
struct TESCondition_4d3cdc88;
struct BGSRefAlias {
    BGSBaseAlias _base;
    GenericFillData fillData;
    TESCondition_4d3cdc88* conditions;
};
static_assert(sizeof(BGSRefAlias) == 72, "BGSRefAlias layout differs from the PDB");
