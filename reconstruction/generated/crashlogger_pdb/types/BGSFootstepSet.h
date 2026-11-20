// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSFootstepSet; size 0x98
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "TESForm_4074aa87.h"
struct BGSFootstepSet {
    TESForm_4074aa87 _base;
    unsigned char entries_raw[120];
};
static_assert(sizeof(BGSFootstepSet) == 152, "BGSFootstepSet layout differs from the PDB");
