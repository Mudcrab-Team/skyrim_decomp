// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSImpactDataSet; size 0x58
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BGSPreloadable.h"
#include "RE__BSTScatterTable_RE__BSCRC32_RE__BGSMaterialType_std__equal_to_RE__BGSMaterialType_R_494f3e5a.h"
#include "TESForm_4074aa87.h"
struct BGSImpactDataSet {
    TESForm_4074aa87 _base;
    BGSPreloadable _base_BGSPreloadable;
    RE__BSTScatterTable_RE__BSCRC32_RE__BGSMaterialType_std__equal_to_RE__BGSMaterialType_R_494f3e5a impactMap;
};
static_assert(sizeof(BGSImpactDataSet) == 88, "BGSImpactDataSet layout differs from the PDB");
