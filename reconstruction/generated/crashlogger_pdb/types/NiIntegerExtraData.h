// CRASHLOGGER_PDB(59818@2026.10.24)
// PDB name: NiIntegerExtraData; size 0x20
#pragma once

#include "NiExtraData_b2385dce.h"
struct NiIntegerExtraData {
    NiExtraData_b2385dce _base;
    int value;
    unsigned int pad1C;
};
static_assert(sizeof(NiIntegerExtraData) == 32, "NiIntegerExtraData layout differs from the PDB");
