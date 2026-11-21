// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSExplosion; size 0xe8
// one of 2 different PDB types sharing this name
#pragma once

#include "BGSExplosionData.h"
#include "BGSPreloadable_c2823740.h"
#include "TESBoundObject_fc790793.h"
#include "TESEnchantableForm_beee0919.h"
#include "TESFullName.h"
#include "TESImageSpaceModifiableForm.h"
#include "TESModel_c52655e4.h"
struct BGSExplosion_c355258c {
    TESBoundObject_fc790793 _base;
    TESFullName _base_TESFullName;
    TESModel_c52655e4 _base_TESModel;
    TESEnchantableForm_beee0919 _base_TESEnchantableForm;
    BGSPreloadable_c2823740 _base_BGSPreloadable;
    TESImageSpaceModifiableForm _base_TESImageSpaceModifiableForm;
    BGSExplosionData data;
};
static_assert(sizeof(BGSExplosion_c355258c) == 232, "BGSExplosion_c355258c layout differs from the PDB");
