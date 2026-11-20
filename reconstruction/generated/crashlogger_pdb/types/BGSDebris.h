// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSDebris; size 0x38
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BGSPreloadable_c2823740.h"
#include "BSSimpleList_RE__BGSDebrisData_fb1261c0_dd19eb85.h"
#include "TESForm.h"
struct BGSDebris {
    TESForm _base;
    BGSPreloadable_c2823740 _base_BGSPreloadable;
    BSSimpleList_RE__BGSDebrisData_fb1261c0_dd19eb85 data;
};
static_assert(sizeof(BGSDebris) == 56, "BGSDebris layout differs from the PDB");
