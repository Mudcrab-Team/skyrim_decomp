// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSExplosion; size 0xe8
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BGSExplosionData_b4630b42.h"
#include "BGSPreloadable.h"
#include "TESBoundObject.h"
#include "TESEnchantableForm.h"
#include "TESFullName_88f61e2a.h"
#include "TESImageSpaceModifiableForm_92d105a9.h"
#include "TESModel.h"
struct BGSExplosion {
    TESBoundObject _base;
    TESFullName_88f61e2a _base_TESFullName;
    TESModel _base_TESModel;
    TESEnchantableForm _base_TESEnchantableForm;
    BGSPreloadable _base_BGSPreloadable;
    TESImageSpaceModifiableForm_92d105a9 _base_TESImageSpaceModifiableForm;
    BGSExplosionData_b4630b42 data;
};
static_assert(sizeof(BGSExplosion) == 232, "BGSExplosion layout differs from the PDB");
