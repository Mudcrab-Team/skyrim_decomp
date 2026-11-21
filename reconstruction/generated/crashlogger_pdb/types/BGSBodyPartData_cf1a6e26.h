// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSBodyPartData; size 0x88
// one of 2 different PDB types sharing this name
#pragma once

#include "BGSPreloadable_c2823740.h"
#include "TESForm.h"
#include "TESModel_c52655e4.h"
struct BGSBodyPart_4f632c83;
struct BGSRagdoll_15ee38fc;
struct BGSBodyPartData_cf1a6e26 {
    TESForm _base;
    TESModel_c52655e4 _base_TESModel;
    BGSPreloadable_c2823740 _base_BGSPreloadable;
    BGSBodyPart_4f632c83* parts[6];
    BGSRagdoll_15ee38fc* ragdoll;
};
static_assert(sizeof(BGSBodyPartData_cf1a6e26) == 136, "BGSBodyPartData_cf1a6e26 layout differs from the PDB");
