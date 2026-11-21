// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESIcon; size 0x10
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSFixedString.h"
struct TESIcon__VFTable;
struct TESIcon {
    TESIcon__VFTable* vftable_TESIcon_0;
    BSFixedString TextureName_8;
};
static_assert(sizeof(TESIcon) == 16, "TESIcon layout differs from the PDB");
