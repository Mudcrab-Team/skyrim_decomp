// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: BGSMovementType; size 0x60
// one of 2 different PDB types sharing this name
#pragma once

#include "TESForm.h"
#include "TypeData.h"
struct BGSMovementType_1a883e57 {
    TESForm _base;
    TypeData movementTypeData;
};
static_assert(sizeof(BGSMovementType_1a883e57) == 96, "BGSMovementType_1a883e57 layout differs from the PDB");
