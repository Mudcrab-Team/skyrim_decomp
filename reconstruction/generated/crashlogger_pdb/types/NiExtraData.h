// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiExtraData; size 0x18
// one of 2 different PDB types sharing this name; the fullest
#pragma once

#include "BSFixedString.h"
struct NiExtraData__VFTable;
struct NiExtraData {
    NiExtraData__VFTable* vftable_NiExtraData_0;
    char _pad_8[8];
    BSFixedString Name_10;
};
static_assert(sizeof(NiExtraData) == 24, "NiExtraData layout differs from the PDB");
