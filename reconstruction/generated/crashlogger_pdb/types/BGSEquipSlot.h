// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSEquipSlot; size 0x40
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSTArray_RE__BGSEquipSlot_f5ce6c70_5e571a19.h"
#include "Flag_d5bcd2af.h"
#include "TESForm_4074aa87.h"
struct BGSEquipSlot {
    TESForm_4074aa87 _base;
    BSTArray_RE__BGSEquipSlot_f5ce6c70_5e571a19 parentSlots;
    Flag_d5bcd2af flags;
    unsigned int pad3C;
};
static_assert(sizeof(BGSEquipSlot) == 64, "BGSEquipSlot layout differs from the PDB");
