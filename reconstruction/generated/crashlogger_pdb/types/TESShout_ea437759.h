// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESShout; size 0xa8
// one of 2 different PDB types sharing this name
#pragma once

#include "BGSEquipType.h"
#include "BGSMenuDisplayObject.h"
#include "TESDescription.h"
#include "TESForm.h"
#include "TESFullName.h"
struct TESShout_ea437759 {
    TESForm _base;
    TESFullName _base_TESFullName;
    BGSMenuDisplayObject _base_BGSMenuDisplayObject;
    BGSEquipType _base_BGSEquipType;
    TESDescription _base_TESDescription;
    unsigned char variations_raw[72];
};
static_assert(sizeof(TESShout_ea437759) == 168, "TESShout_ea437759 layout differs from the PDB");
