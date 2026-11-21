// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSApparatus; size 0x120
#pragma once

#include "TESDescription.h"
#include "TESObjectMISC.h"
#include "TESQualityForm.h"
struct BGSApparatus {
    TESObjectMISC _base;
    TESQualityForm _base_TESQualityForm;
    TESDescription _base_TESDescription;
};
static_assert(sizeof(BGSApparatus) == 288, "BGSApparatus layout differs from the PDB");
