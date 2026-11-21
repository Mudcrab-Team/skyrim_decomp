// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSHazard; size 0xb8
// one of 2 different PDB types sharing this name
#pragma once

#include "BGSHazardData.h"
#include "BGSPreloadable.h"
#include "TESBoundObject.h"
#include "TESFullName_88f61e2a.h"
#include "TESImageSpaceModifiableForm_92d105a9.h"
#include "TESModel.h"
struct BGSHazard_93ffc8c7 {
    TESBoundObject _base;
    TESFullName_88f61e2a _base_TESFullName;
    TESModel _base_TESModel;
    BGSPreloadable _base_BGSPreloadable;
    TESImageSpaceModifiableForm_92d105a9 _base_TESImageSpaceModifiableForm;
    BGSHazardData data;
};
static_assert(sizeof(BGSHazard_93ffc8c7) == 184, "BGSHazard_93ffc8c7 layout differs from the PDB");
