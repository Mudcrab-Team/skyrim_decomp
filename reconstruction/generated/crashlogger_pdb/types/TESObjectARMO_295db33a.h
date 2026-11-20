// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESObjectARMO; size 0x228
// one of 2 different PDB types sharing this name
#pragma once

#include "BGSBipedObjectForm.h"
#include "BGSBlockBashData_e0d1e6c1.h"
#include "BGSDestructibleObjectForm.h"
#include "BGSEquipType.h"
#include "BGSKeywordForm_9c083c55.h"
#include "BGSPickupPutdownSounds_f2d7cfc7.h"
#include "BSTArray_RE__TESObjectARMA_a3447183.h"
#include "TESBipedModelForm.h"
#include "TESBoundObject_fc790793.h"
#include "TESDescription.h"
#include "TESEnchantableForm_beee0919.h"
#include "TESFullName.h"
#include "TESRaceForm.h"
#include "TESValueForm.h"
#include "TESWeightForm.h"
struct TESObjectARMO_295db33a {
    TESBoundObject_fc790793 _base;
    TESFullName _base_TESFullName;
    TESRaceForm _base_TESRaceForm;
    TESEnchantableForm_beee0919 _base_TESEnchantableForm;
    TESValueForm _base_TESValueForm;
    TESWeightForm _base_TESWeightForm;
    BGSDestructibleObjectForm _base_BGSDestructibleObjectForm;
    BGSPickupPutdownSounds_f2d7cfc7 _base_BGSPickupPutdownSounds;
    TESBipedModelForm _base_TESBipedModelForm;
    BGSEquipType _base_BGSEquipType;
    BGSBipedObjectForm _base_BGSBipedObjectForm;
    BGSBlockBashData_e0d1e6c1 _base_BGSBlockBashData;
    BGSKeywordForm_9c083c55 _base_BGSKeywordForm;
    TESDescription _base_TESDescription;
    unsigned int armorRating;
    unsigned int pad204;
    BSTArray_RE__TESObjectARMA_a3447183 armorAddons;
    TESObjectARMO_295db33a* templateArmor;
};
static_assert(sizeof(TESObjectARMO_295db33a) == 552, "TESObjectARMO_295db33a layout differs from the PDB");
