// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSDebris; size 0x38
// one of 2 different PDB types sharing this name
#pragma once

#include "BGSPreloadable.h"
#include "BSSimpleList_RE__BGSDebrisData_fb1261c0.h"
#include "TESForm_4074aa87.h"
struct BGSDebris_f2fddb01 {
    TESForm_4074aa87 _base;
    BGSPreloadable _base_BGSPreloadable;
    BSSimpleList_RE__BGSDebrisData_fb1261c0 data;
};
static_assert(sizeof(BGSDebris_f2fddb01) == 56, "BGSDebris_f2fddb01 layout differs from the PDB");
