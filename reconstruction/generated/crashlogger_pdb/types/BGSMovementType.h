// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSMovementType; size 0x60
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "TESForm_4074aa87.h"
struct BGSMovementType {
    TESForm_4074aa87 _base;
    unsigned char movementTypeData_raw[64];
};
static_assert(sizeof(BGSMovementType) == 96, "BGSMovementType layout differs from the PDB");
