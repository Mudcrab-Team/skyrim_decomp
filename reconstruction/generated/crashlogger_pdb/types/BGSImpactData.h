// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSImpactData; size 0xb0
#pragma once

#include "DecalData_8ca90d9e.h"
#include "IMPACT_DATA_DATA.h"
#include "TESForm.h"
#include "TESModel_c52655e4.h"
struct BGSHazard;
struct BGSSoundDescriptorForm;
struct BGSTextureSet;
struct BGSImpactData {
    TESForm _base;
    TESModel_c52655e4 _base_TESModel;
    IMPACT_DATA_DATA data;
    BGSTextureSet* decalTextureSet;
    BGSTextureSet* decalTextureSet2;
    BGSSoundDescriptorForm* sound1;
    BGSSoundDescriptorForm* sound2;
    BGSHazard* hazard;
    DecalData_8ca90d9e dData;
    unsigned int padAC;
};
static_assert(sizeof(BGSImpactData) == 176, "BGSImpactData layout differs from the PDB");
