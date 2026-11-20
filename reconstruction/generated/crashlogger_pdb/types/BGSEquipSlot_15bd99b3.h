// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSEquipSlot; size 0x40
// one of 2 different PDB types sharing this name
#pragma once

#include "BSTArray_RE__BGSEquipSlot_f5ce6c70.h"
#include "Flag_a4a94b8a.h"
#include "TESForm.h"
struct BGSEquipSlot_15bd99b3 {
    TESForm _base;
    BSTArray_RE__BGSEquipSlot_f5ce6c70 parentSlots;
    Flag_a4a94b8a flags;
    unsigned int pad3C;
};
static_assert(sizeof(BGSEquipSlot_15bd99b3) == 64, "BGSEquipSlot_15bd99b3 layout differs from the PDB");
