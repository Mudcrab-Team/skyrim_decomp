// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiFloatExtraData; size 0x20
#pragma once

#include "NiExtraData_b2385dce.h"
struct NiFloatExtraData {
    NiExtraData_b2385dce _base;
    float value;
    unsigned char undefined_1c[4];
};
static_assert(sizeof(NiFloatExtraData) == 32, "NiFloatExtraData layout differs from the PDB");
