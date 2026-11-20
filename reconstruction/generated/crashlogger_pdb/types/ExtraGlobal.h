// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraGlobal; size 0x18
#pragma once

#include "BSExtraData_4ca6af76.h"
struct TESGlobal;
struct ExtraGlobal {
    BSExtraData_4ca6af76 _base;
    TESGlobal* global;
};
static_assert(sizeof(ExtraGlobal) == 24, "ExtraGlobal layout differs from the PDB");
