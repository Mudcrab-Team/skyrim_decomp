// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSHazard; size 0xb8
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BGSHazardData.h"
#include "BGSPreloadable_c2823740.h"
#include "TESBoundObject_fc790793.h"
#include "TESFullName.h"
#include "TESImageSpaceModifiableForm.h"
#include "TESModel_c52655e4.h"
struct BGSHazard {
    TESBoundObject_fc790793 _base;
    TESFullName _base_TESFullName;
    TESModel_c52655e4 _base_TESModel;
    BGSPreloadable_c2823740 _base_BGSPreloadable;
    TESImageSpaceModifiableForm _base_TESImageSpaceModifiableForm;
    BGSHazardData data;
};
static_assert(sizeof(BGSHazard) == 184, "BGSHazard layout differs from the PDB");
