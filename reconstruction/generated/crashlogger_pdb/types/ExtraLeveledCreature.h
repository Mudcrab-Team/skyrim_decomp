// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraLeveledCreature; size 0x20
#pragma once

#include "BSExtraData_4ca6af76.h"
struct TESActorBase_199eb558;
struct ExtraLeveledCreature {
    BSExtraData_4ca6af76 _base;
    TESActorBase_199eb558* originalBase;
    TESActorBase_199eb558* templateBase;
};
static_assert(sizeof(ExtraLeveledCreature) == 32, "ExtraLeveledCreature layout differs from the PDB");
