// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSBlockBashData; size 0x18
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BaseFormComponent_9d659514.h"
struct BGSImpactDataSet;
struct BGSMaterialType_c56427e2;
struct BGSBlockBashData {
    BaseFormComponent_9d659514 _base;
    BGSImpactDataSet* blockBashImpactDataSet;
    BGSMaterialType_c56427e2* altBlockMaterialType;
};
static_assert(sizeof(BGSBlockBashData) == 24, "BGSBlockBashData layout differs from the PDB");
