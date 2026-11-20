// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSMaterialType; size 0x50
// one of 2 different PDB types sharing this name
#pragma once

#include "FLAG.h"
#include "MATERIAL_ID.h"
#include "NiColor.h"
#include "TESForm_4074aa87.h"
struct BGSImpactDataSet;
struct BGSMaterialType_c56427e2 {
    TESForm_4074aa87 _base;
    BGSMaterialType_c56427e2* parentType;
    unsigned char materialName_raw[8];
    MATERIAL_ID materialID;
    NiColor materialColor;
    float buoyancy;
    FLAG flags;
    BGSImpactDataSet* havokImpactDataSet;
};
static_assert(sizeof(BGSMaterialType_c56427e2) == 80, "BGSMaterialType_c56427e2 layout differs from the PDB");
