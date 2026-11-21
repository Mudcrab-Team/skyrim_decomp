// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSBodyPartData; size 0x88
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BGSPreloadable.h"
#include "TESForm_4074aa87.h"
#include "TESModel.h"
struct BGSBodyPart;
struct BGSRagdoll;
struct BGSBodyPartData {
    TESForm_4074aa87 _base;
    TESModel _base_TESModel;
    BGSPreloadable _base_BGSPreloadable;
    BGSBodyPart* parts[6];
    BGSRagdoll* ragdoll;
};
static_assert(sizeof(BGSBodyPartData) == 136, "BGSBodyPartData layout differs from the PDB");
