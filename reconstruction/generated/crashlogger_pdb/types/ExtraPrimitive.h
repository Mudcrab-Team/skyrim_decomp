// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: ExtraPrimitive; size 0x18
#pragma once

#include "BSExtraData_4ca6af76.h"
struct BGSPrimitive;
struct ExtraPrimitive {
    BSExtraData_4ca6af76 _base;
    BGSPrimitive* primitive;
};
static_assert(sizeof(ExtraPrimitive) == 24, "ExtraPrimitive layout differs from the PDB");
