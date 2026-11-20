// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSBlockBashData; size 0x18
// one of 2 different PDB types sharing this name
#pragma once

#include "BaseFormComponent.h"
struct BGSImpactDataSet_e1a4fffc;
struct BGSMaterialType;
struct BGSBlockBashData_e0d1e6c1 {
    BaseFormComponent _base;
    BGSImpactDataSet_e1a4fffc* blockBashImpactDataSet;
    BGSMaterialType* altBlockMaterialType;
};
static_assert(sizeof(BGSBlockBashData_e0d1e6c1) == 24, "BGSBlockBashData_e0d1e6c1 layout differs from the PDB");
