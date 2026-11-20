// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: TESKey; size 0x100
#pragma once

#include "TESObjectMISC.h"
struct TESKey {
    TESObjectMISC _base;
};
static_assert(sizeof(TESKey) == 256, "TESKey layout differs from the PDB");
