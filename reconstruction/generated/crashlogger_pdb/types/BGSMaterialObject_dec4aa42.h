// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSMaterialObject; size 0xb8
// one of 2 different PDB types sharing this name
#pragma once

#include "BSMaterialObject.h"
#include "BSTArray_RE__BGSMaterialObject__FILE_DATA_8db0a7e3.h"
#include "TESForm.h"
#include "TESModel_c52655e4.h"
struct BGSMaterialObject_dec4aa42 {
    TESForm _base;
    TESModel_c52655e4 _base_TESModel;
    BSMaterialObject _base_BSMaterialObject;
    BSTArray_RE__BGSMaterialObject__FILE_DATA_8db0a7e3 fileData;
};
static_assert(sizeof(BGSMaterialObject_dec4aa42) == 184, "BGSMaterialObject_dec4aa42 layout differs from the PDB");
