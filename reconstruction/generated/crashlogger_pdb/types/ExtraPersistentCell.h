// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraPersistentCell; size 0x18
#pragma once

#include "BSExtraData_4ca6af76.h"
struct TESObjectCELL_f81013b3;
struct ExtraPersistentCell {
    BSExtraData_4ca6af76 _base;
    TESObjectCELL_f81013b3* persistentCell;
};
static_assert(sizeof(ExtraPersistentCell) == 24, "ExtraPersistentCell layout differs from the PDB");
