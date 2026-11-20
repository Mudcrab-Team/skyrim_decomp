// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSMaterialObject; size 0xb8
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSMaterialObject_b118a84b.h"
#include "BSTArray_RE__BGSMaterialObject__FILE_DATA_8db0a7e3_ccd66341.h"
#include "TESForm_4074aa87.h"
#include "TESModel.h"
struct BGSMaterialObject {
    TESForm_4074aa87 _base;
    TESModel _base_TESModel;
    BSMaterialObject_b118a84b _base_BSMaterialObject;
    BSTArray_RE__BGSMaterialObject__FILE_DATA_8db0a7e3_ccd66341 fileData;
};
static_assert(sizeof(BGSMaterialObject) == 184, "BGSMaterialObject layout differs from the PDB");
